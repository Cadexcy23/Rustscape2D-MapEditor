
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Controller.h"
#include "Maps.h"
#include "Menus.h"
#include "Saving.h"

//Keeps track if game is running
bool quit = false;



//Event handler
SDL_Event e;

bool Controller::isRunning()
{
	return !quit;
}



void Controller::controller()
{
	//Declare classes
	Maps Maps;
	Menus Menus;
	Saving Saving;
	//Handle events on queue
	if (SDL_PollEvent(&e) != 0)
	{
		//printf("input detected: %i\n", e.type);
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}

		//User clicks
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			int x, y;
			Uint32 mouseState = SDL_GetMouseState(&x, &y);
			//printf("state: %i\n", mouseState);
			//printf("Mouse X: %i Mouse Y: %i\n", x, y);

			//LEFT CLICK
			if (mouseState == 1)
			{
				//printf("LEFT CLICK\n");

				//placing
				if (x < 720)
				{
					//place tile
					if (Menus.getSidebarState() == 1)
						Maps.setMapTile((x / 36) + Maps.getPlayerX() - 10, (y / 36) + Maps.getPlayerY() - 10, Maps.getSelectedTile());

					//pace entity
					if (Menus.getSidebarState() == 2 && Menus.getPlayerSpawnState() == 0)
						if(x / 36 != Maps.getPlayerSpawnX() || y / 36 != Maps.getPlayerSpawnY())
						Maps.setMapEntity((x / 36) + Maps.getPlayerX() - 10, (y / 36) + Maps.getPlayerY() - 10, Maps.getSelectedEntity());

					//place spawn point
					if (Menus.getSidebarState() == 2 && Menus.getPlayerSpawnState() == 1)
					{
						Maps.setPlayerSpawnX((x / 36) + Maps.getPlayerX() - 10);
						Maps.setPlayerSpawnY((y / 36) + Maps.getPlayerY() - 10);
						Menus.setPlayerSpawnState(0);
						Maps.setMapEntity((x / 36) + Maps.getPlayerX() - 10, (y / 36) + Maps.getPlayerY() - 10, Maps.getEntityFromID(0));
					}
				}

				//options
				if (Menus.getSidebarState() == 9)
				{
					//save button
					if (x >= 897 && x <= 953 && y >= 620 && y <= 653)
					{

						Saving.saveMap();
					}

					//load button
					if (x >= 1047 && x <= 1103 && y >= 620 && y <= 653)
					{

						Saving.loadMap();
					}

					//reset button
					if (x >= 972 && x <= 1028 && y >= 620 && y <= 653)
					{
						Maps.resetMap();
						Maps.setPlayerSpawnX(0);
						Maps.setPlayerSpawnY(0);
					}

					//map size
					// up
					if (x >= 982 && x <= 1018 && y >= 250 && y <= 283)
					{
						Maps.setMapSizeIndex(Maps.getMapSizeIndex() + 1);
					}
					//down
					if (x >= 982 && x <= 1018 && y >= 325 && y <= 358)
					{
						if (Maps.getMapSizeIndex() - 1 > 0)
						{
							Maps.setMapSizeIndex(Maps.getMapSizeIndex() - 1);
						}
						else 
						{
							Maps.setMapSizeIndex(1);
						}
						
					}
					//set
					if (x >= 980 && x <= 1020 && y >= 284 && y <= 324)
					{
						Maps.setMapSize(Maps.getMapSizeIndex());
						Maps.updateMapSize();
						//Maps.resetMap();
					}
				}

				//change selcted tile/entity
				if (x >= 946 && x <= 982 && y >= 286 && y <= 322)
				{
					if (Menus.getSidebarState() == 1)
					{
						Maps.changeSelectedTile(-1);
					}
					else if(Menus.getSidebarState() == 2)
					{
						Maps.changeSelectedEntity(-1);
					}
				}
				if (x >= 1018 && x <= 1054 && y >= 286 && y <= 322)
				{
					if (Menus.getSidebarState() == 1)
					{
						Maps.changeSelectedTile(1);
					}
					else if (Menus.getSidebarState() == 2)
					{
						Maps.changeSelectedEntity(1);
					}
				}

				//Toggle setting player spawn
				if (x >= 982 && x <= 1018 && y >= 336 && y <= 372 && Menus.getSidebarState() == 2)
				{
					if (Menus.getPlayerSpawnState() == 0)
					{
						Menus.setPlayerSpawnState(1);
					}
					else
					{
						Menus.setPlayerSpawnState(0);
					}
				}

				//sidebar bottom buttons
				if (x > 720 && y > 664)
				{
					//Tile
					if (x < 776)
						if (Menus.getSidebarState() == 1)
							Menus.setSidebarState(0);
						else
							Menus.setSidebarState(1);
					//Entities
					if (x >= 776 && x < 832)
						if (Menus.getSidebarState() == 2)
							Menus.setSidebarState(0);
						else
							Menus.setSidebarState(2);
					//quests
					if (x >= 832 && x < 888)
						if (Menus.getSidebarState() == 3)
							Menus.setSidebarState(0);
						else
							Menus.setSidebarState(3);
					//inventory
					if (x >= 888 && x < 944)
						if (Menus.getSidebarState() == 4)
							Menus.setSidebarState(0);
						else
							Menus.setSidebarState(4);
					//equipment
					if (x >= 944 && x < 1000)
						if (Menus.getSidebarState() == 5)
							Menus.setSidebarState(0);
						else
							Menus.setSidebarState(5);
					//prayer
					if (x >= 1000 && x < 1056)
						if (Menus.getSidebarState() == 6)
							Menus.setSidebarState(0);
						else
							Menus.setSidebarState(6);
					//spells
					if (x >= 1056 && x < 1112)
						if (Menus.getSidebarState() == 7)
							Menus.setSidebarState(0);
						else
							Menus.setSidebarState(7);
					//emotes
					if (x >= 1112 && x < 1168)
						if (Menus.getSidebarState() == 8)
							Menus.setSidebarState(0);
						else
							Menus.setSidebarState(8);
					//options
					if (x >= 1168 && x < 1224)
						if (Menus.getSidebarState() == 9)
							Menus.setSidebarState(0);
						else
							Menus.setSidebarState(9);
					//exit
					if (x >= 1224 && x < 1280)
						quit = true;
				}

			}
			
			//RIGHT CLICK
			if (mouseState == 4)
			{
				//printf("RIGHT CLICK\n");
				if (x < 720)
				{
					//remove tile
					if (Menus.getSidebarState() == 1)
						Maps.setMapTile((x / 36) + Maps.getPlayerX() - 10, (y / 36) + Maps.getPlayerY() - 10, Maps.getTileFromID(0));

					//remove entity
					if (Menus.getSidebarState() == 2)
						Maps.setMapEntity((x / 36) + Maps.getPlayerX() - 10, (y / 36) + Maps.getPlayerY() - 10, Maps.getEntityFromID(0));
				}
			}
		}

		const Uint8 *state = SDL_GetKeyboardState(NULL);
		if (state[SDL_SCANCODE_W] && e.type == 768)
		{
			Maps.setPlayerY(Maps.getPlayerY() - 1);
		}
		if (state[SDL_SCANCODE_S] && e.type == 768)
		{
			Maps.setPlayerY(Maps.getPlayerY() + 1);
		}
		if (state[SDL_SCANCODE_A] && e.type == 768)
		{
			Maps.setPlayerX(Maps.getPlayerX() - 1);
		}
		if (state[SDL_SCANCODE_D] && e.type == 768)
		{
			Maps.setPlayerX(Maps.getPlayerX() + 1);
		}
	}
}
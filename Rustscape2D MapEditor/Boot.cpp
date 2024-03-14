
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Artist.h"
#include "Controller.h"
#include "Saving.h"



int main(int argc, char* args[])
{
	//Declare Artist and controller
	Artist Artist;
	Controller Controller;
	Saving Saving;
	//Start up SDL and create window
	if (!Artist.init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!Artist.loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			Saving.loadMap();
			
			
			//While application is running
			while (Controller.isRunning())
			{
				
				
				

				//Checks for user input
				Controller.controller();

				//Clear screen
				Artist.clearScreen();

				//Draw everything
				Artist.draw();
				
				//Update screen
				Artist.updateScreen();
			}
		}
	}

	//Free resources and close SDL
	Artist.close();

	return 0;
}
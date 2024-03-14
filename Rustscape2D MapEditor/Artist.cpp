
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include "Artist.h"
#include "Maps.h"
#include "Menus.h"



//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


//Loads individual image as texture
SDL_Texture* loadTexture(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Initialize textures
SDL_Texture* gPlayer = NULL;

//Tiles
SDL_Texture* gVoidTile = NULL;
SDL_Texture* gStoneTile = NULL;
SDL_Texture* gStoneWallTile = NULL;
SDL_Texture* gWaterTile = NULL;
SDL_Texture* gDirtTile = NULL;
SDL_Texture* gOutOfMapTile = NULL;
//Entities
SDL_Texture* gFurnace = NULL;
SDL_Texture* gAnvil = NULL;
SDL_Texture* gBee = NULL;
SDL_Texture* gHumanEnemy = NULL;
SDL_Texture* gShopKeeper = NULL;
SDL_Texture* gShopKeeperOre = NULL;
SDL_Texture* gShopKeeperBar = NULL;
SDL_Texture* gShopKeeperIcecream = NULL;
SDL_Texture* gClosedDoor = NULL;
SDL_Texture* gOpenDoor = NULL;
SDL_Texture* gEmptyRock = NULL;
SDL_Texture* gCopperRock = NULL;
SDL_Texture* gTinRock = NULL;
SDL_Texture* gIronRock = NULL;
SDL_Texture* gCoalRock = NULL;
SDL_Texture* gMithrilRock = NULL;
SDL_Texture* gAdamantiteRock = NULL;
SDL_Texture* gRuniteRock = NULL;
SDL_Texture* gSilverRock = NULL;
SDL_Texture* gGoldRock = NULL;
//sidebar
SDL_Texture* gSidebarBackground = NULL;
SDL_Texture* gSidebarIconPlate = NULL;
SDL_Texture* gSidebarSelected = NULL;
SDL_Texture* gSidebarInventoryBackground = NULL;
SDL_Texture* gCombatIcon = NULL;
SDL_Texture* gEmotesIcon = NULL;
SDL_Texture* gEquipmentIcon = NULL;
SDL_Texture* gExitIcon = NULL;
SDL_Texture* gInventoryIcon = NULL;
SDL_Texture* gLevelsIcon = NULL;
SDL_Texture* gOptionsIcon = NULL;
SDL_Texture* gPrayerIcon = NULL;
SDL_Texture* gQuestsIcon = NULL;
SDL_Texture* gSpellsIcon = NULL;
SDL_Texture* gTileIcon = NULL;
SDL_Texture* gEntityIcon = NULL;
SDL_Texture* gArrowLeft = NULL;
SDL_Texture* gArrowRight = NULL;
SDL_Texture* gArrowUp = NULL;
SDL_Texture* gArrowDown = NULL;
SDL_Texture* gSaveButton = NULL;
SDL_Texture* gLoadButton = NULL;
SDL_Texture* gResetButton = NULL;

//numbers
SDL_Texture* gCountOne = NULL;
SDL_Texture* gCountTwo = NULL;
SDL_Texture* gCountThree = NULL;
SDL_Texture* gCountFour = NULL;
SDL_Texture* gCountFive = NULL;
SDL_Texture* gCountSix = NULL;
SDL_Texture* gCountSeven = NULL;
SDL_Texture* gCountEight = NULL;
SDL_Texture* gCountNine = NULL;
SDL_Texture* gCountZero = NULL;
SDL_Texture* gCountPengu = NULL;
SDL_Texture* gCountThousand = NULL;
SDL_Texture* gCountMillion = NULL;
SDL_Texture* gCountP = NULL;
SDL_Texture* gCountS = NULL;



//Update screen
void Artist::updateScreen()
{
	SDL_RenderPresent(gRenderer);
}

//Clear screen
void Artist::clearScreen()
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);
}

bool Artist::init()
{

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("RustScape2D MapEditor", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool Artist::loadMedia()
{
	
	//Loading success flag
	bool success = true;
	//Load texture
	//Tiles
	gVoidTile = loadTexture("Resource/tiles/voidTile.png");
	if (gVoidTile == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gStoneTile = loadTexture("Resource/tiles/stoneTile.png");
	if (gStoneTile == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gStoneWallTile = loadTexture("Resource/tiles/stoneWallTile.png");
	if (gStoneWallTile == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gWaterTile = loadTexture("Resource/tiles/waterTile.png");
	if (gWaterTile == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gDirtTile = loadTexture("Resource/tiles/dirtTile.png");
	if (gDirtTile == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gOutOfMapTile = loadTexture("Resource/tiles/OutOfMapTile.png");
	if (gOutOfMapTile == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	//Entitys
	gHumanEnemy = loadTexture("Resource/entities/humanEnemy.png");
	if (gHumanEnemy == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gPlayer = loadTexture("Resource/entities/player.png");
	if (gPlayer == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gFurnace = loadTexture("Resource/entities/furnace.png");
	if (gFurnace == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gAnvil = loadTexture("Resource/entities/anvil.png");
	if (gAnvil == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gBee = loadTexture("Resource/entities/bee.png");
	if (gBee == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gShopKeeper = loadTexture("Resource/entities/shopKeeper.png");
	if (gShopKeeper == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gShopKeeperOre = loadTexture("Resource/entities/shopKeeperOre.png");
	if (gShopKeeperOre == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gShopKeeperBar = loadTexture("Resource/entities/shopKeeperBar.png");
	if (gShopKeeperBar == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gShopKeeperIcecream = loadTexture("Resource/entities/shopKeeperIcecream.png");
	if (gShopKeeperIcecream == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gClosedDoor = loadTexture("Resource/entities/closedDoor.png");
	if (gClosedDoor == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gOpenDoor = loadTexture("Resource/entities/openDoor.png");
	if (gOpenDoor == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gEmptyRock = loadTexture("Resource/entities/emptyRock.png");
	if (gEmptyRock == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gCopperRock = loadTexture("Resource/entities/copperRock.png");
	if (gCopperRock == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gTinRock = loadTexture("Resource/entities/tinRock.png");
	if (gTinRock == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gIronRock = loadTexture("Resource/entities/ironRock.png");
	if (gIronRock == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gCoalRock = loadTexture("Resource/entities/coalRock.png");
	if (gCoalRock == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gMithrilRock = loadTexture("Resource/entities/mithrilRock.png");
	if (gMithrilRock == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gAdamantiteRock = loadTexture("Resource/entities/adamantiteRock.png");
	if (gAdamantiteRock == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gRuniteRock = loadTexture("Resource/entities/runiteRock.png");
	if (gRuniteRock == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gSilverRock = loadTexture("Resource/entities/silverRock.png");
	if (gSilverRock == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gGoldRock = loadTexture("Resource/entities/goldRock.png");
	if (gGoldRock == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	//sidebar
	gSidebarBackground = loadTexture("Resource/sidebar/sidebarBackground.png");
	if (gSidebarBackground == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gSidebarIconPlate = loadTexture("Resource/sidebar/sidebarIconPlate.png");
	if (gSidebarIconPlate == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gSidebarSelected = loadTexture("Resource/sidebar/sidebarSelected.png");
	if (gSidebarSelected == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gSidebarInventoryBackground = loadTexture("Resource/sidebar/sidebarInventoryBackground.png");
	if (gSidebarInventoryBackground == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gCombatIcon = loadTexture("Resource/sidebar/sidebarCombatIcon.png");
	if (gCombatIcon == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gEmotesIcon = loadTexture("Resource/sidebar/sidebarEmotesIcon.png");
	if (gEmotesIcon == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gEquipmentIcon = loadTexture("Resource/sidebar/sidebarEquipmentIcon.png");
	if (gEquipmentIcon == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gExitIcon = loadTexture("Resource/sidebar/sidebarExitIcon.png");
	if (gExitIcon == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gInventoryIcon = loadTexture("Resource/sidebar/sidebarInventoryIcon.png");
	if (gInventoryIcon == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gLevelsIcon = loadTexture("Resource/sidebar/sidebarLevelsIcon.png");
	if (gLevelsIcon == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gOptionsIcon = loadTexture("Resource/sidebar/sidebarOptionsIcon.png");
	if (gOptionsIcon == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gPrayerIcon = loadTexture("Resource/sidebar/sidebarPrayerIcon.png");
	if (gPrayerIcon == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gQuestsIcon = loadTexture("Resource/sidebar/sidebarQuestsIcon.png");
	if (gQuestsIcon == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gSpellsIcon = loadTexture("Resource/sidebar/sidebarSpellsIcon.png");
	if (gSpellsIcon == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gTileIcon = loadTexture("Resource/sidebar/sidebarTileIcon.png");
	if (gTileIcon == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gEntityIcon = loadTexture("Resource/sidebar/sidebarEntityIcon.png");
	if (gEntityIcon == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gArrowLeft = loadTexture("Resource/sidebar/arrowLeft.png");
	if (gArrowLeft == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gArrowRight = loadTexture("Resource/sidebar/arrowRight.png");
	if (gArrowRight == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gArrowUp = loadTexture("Resource/sidebar/arrowUp.png");
	if (gArrowUp == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gArrowDown = loadTexture("Resource/sidebar/arrowDown.png");
	if (gArrowDown == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gSaveButton = loadTexture("Resource/sidebar/sidebarOptionsSaveButton.png");
	if (gSaveButton == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gLoadButton = loadTexture("Resource/sidebar/sidebarOptionsLoadButton.png");
	if (gLoadButton == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	gResetButton = loadTexture("Resource/sidebar/sidebarOptionsResetButton.png");
	if (gResetButton == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	
	//numbers
	gCountOne = loadTexture("Resource/items/count/countOne.png");
	gCountTwo = loadTexture("Resource/items/count/countTwo.png");
	gCountThree = loadTexture("Resource/items/count/countThree.png");
	gCountFour = loadTexture("Resource/items/count/countFour.png");
	gCountFive = loadTexture("Resource/items/count/countFive.png");
	gCountSix = loadTexture("Resource/items/count/countSix.png");
	gCountSeven = loadTexture("Resource/items/count/countSeven.png");
	gCountEight = loadTexture("Resource/items/count/countEight.png");
	gCountNine = loadTexture("Resource/items/count/countNine.png");
	gCountZero = loadTexture("Resource/items/count/countZero.png");
	gCountPengu = loadTexture("Resource/items/count/countPengu.png");
	gCountThousand = loadTexture("Resource/items/count/countThousand.png");
	gCountMillion = loadTexture("Resource/items/count/countMillion.png");
	gCountP = loadTexture("Resource/items/count/countP.png");
	gCountS = loadTexture("Resource/items/count/countS.png");
	return success;
}

void Artist::close()
{
	//Free loaded image
	//Tile
	SDL_DestroyTexture(gVoidTile);
	gVoidTile = NULL;
	SDL_DestroyTexture(gStoneTile);
	gStoneTile = NULL;
	SDL_DestroyTexture(gStoneWallTile);
	gStoneWallTile = NULL;
	SDL_DestroyTexture(gWaterTile);
	gWaterTile = NULL;
	SDL_DestroyTexture(gDirtTile);
	gDirtTile = NULL;
	SDL_DestroyTexture(gOutOfMapTile);
	gOutOfMapTile = NULL;
	//Entities
	SDL_DestroyTexture(gHumanEnemy);
	gHumanEnemy = NULL;
	SDL_DestroyTexture(gPlayer);
	gPlayer = NULL;
	SDL_DestroyTexture(gBee);
	gBee = NULL;
	SDL_DestroyTexture(gFurnace);
	gFurnace = NULL;
	SDL_DestroyTexture(gAnvil);
	gAnvil = NULL;
	SDL_DestroyTexture(gShopKeeper);
	gShopKeeper = NULL;
	SDL_DestroyTexture(gShopKeeperOre);
	gShopKeeperOre = NULL;
	SDL_DestroyTexture(gShopKeeperBar);
	gShopKeeperBar = NULL;
	SDL_DestroyTexture(gShopKeeperIcecream);
	gShopKeeperIcecream = NULL;
	SDL_DestroyTexture(gClosedDoor);
	gClosedDoor = NULL;
	SDL_DestroyTexture(gOpenDoor);
	gOpenDoor = NULL;
	SDL_DestroyTexture(gEmptyRock);
	gEmptyRock = NULL;
	SDL_DestroyTexture(gCopperRock);
	gCopperRock = NULL;
	SDL_DestroyTexture(gTinRock);
	gTinRock = NULL;
	SDL_DestroyTexture(gIronRock);
	gIronRock = NULL;
	SDL_DestroyTexture(gCoalRock);
	gCoalRock = NULL;
	SDL_DestroyTexture(gMithrilRock);
	gMithrilRock = NULL;
	SDL_DestroyTexture(gAdamantiteRock);
	gAdamantiteRock = NULL;
	SDL_DestroyTexture(gRuniteRock);
	gRuniteRock = NULL;
	SDL_DestroyTexture(gSilverRock);
	gSilverRock = NULL;
	SDL_DestroyTexture(gGoldRock);
	gGoldRock = NULL;
	//sidebar
	SDL_DestroyTexture(gSidebarBackground);
	gSidebarBackground = NULL;
	SDL_DestroyTexture(gSidebarIconPlate);
	gSidebarIconPlate = NULL;
	SDL_DestroyTexture(gSidebarSelected);
	gSidebarSelected = NULL;
	SDL_DestroyTexture(gSidebarInventoryBackground);
	gSidebarInventoryBackground = NULL;
	SDL_DestroyTexture(gCombatIcon);
	gCombatIcon = NULL;
	SDL_DestroyTexture(gEmotesIcon);
	gEmotesIcon = NULL;
	SDL_DestroyTexture(gEquipmentIcon);
	gEquipmentIcon = NULL;
	SDL_DestroyTexture(gExitIcon);
	gExitIcon = NULL;
	SDL_DestroyTexture(gInventoryIcon);
	gInventoryIcon = NULL;
	SDL_DestroyTexture(gLevelsIcon);
	gLevelsIcon = NULL;
	SDL_DestroyTexture(gOptionsIcon);
	gOptionsIcon = NULL;
	SDL_DestroyTexture(gPrayerIcon);
	gPrayerIcon = NULL;
	SDL_DestroyTexture(gQuestsIcon);
	gQuestsIcon = NULL;
	SDL_DestroyTexture(gSpellsIcon);
	gSpellsIcon = NULL;
	SDL_DestroyTexture(gTileIcon);
	gTileIcon = NULL;
	SDL_DestroyTexture(gEntityIcon);
	gEntityIcon = NULL;
	SDL_DestroyTexture(gArrowLeft);
	gArrowLeft = NULL;
	SDL_DestroyTexture(gArrowRight);
	gArrowRight = NULL;
	SDL_DestroyTexture(gSaveButton);
	gSaveButton = NULL;
	SDL_DestroyTexture(gArrowUp);
	gArrowUp = NULL;
	SDL_DestroyTexture(gArrowDown);
	gArrowDown = NULL;
	SDL_DestroyTexture(gLoadButton);
	gLoadButton = NULL;
	SDL_DestroyTexture(gResetButton);
	gResetButton = NULL;
	//numbers
	SDL_DestroyTexture(gCountOne);
	gCountOne = NULL;
	SDL_DestroyTexture(gCountTwo);
	gCountTwo = NULL;
	SDL_DestroyTexture(gCountThree);
	gCountThree = NULL;
	SDL_DestroyTexture(gCountFour);
	gCountFour = NULL;
	SDL_DestroyTexture(gCountFive);
	gCountFive = NULL;
	SDL_DestroyTexture(gCountSix);
	gCountSix = NULL;
	SDL_DestroyTexture(gCountSeven);
	gCountSeven = NULL;
	SDL_DestroyTexture(gCountEight);
	gCountEight = NULL;
	SDL_DestroyTexture(gCountNine);
	gCountNine = NULL;
	SDL_DestroyTexture(gCountZero);
	gCountZero = NULL;
	SDL_DestroyTexture(gCountPengu);
	gCountPengu = NULL;
	SDL_DestroyTexture(gCountThousand);
	gCountThousand = NULL;
	SDL_DestroyTexture(gCountMillion);
	gCountMillion = NULL;
	SDL_DestroyTexture(gCountP);
	gCountP = NULL;
	SDL_DestroyTexture(gCountS);
	gCountS = NULL;
	

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

SDL_Texture* getTileTexture(int tileID)
{
	switch (tileID)
	{
	case Maps::TILE_VOID:
		return gVoidTile;
		break;
	case Maps::TILE_STONE:
		return gStoneTile;
		break;
	case Maps::TILE_STONEWALL:
		return gStoneWallTile;
		break;
	case Maps::TILE_WATER:
		return gWaterTile;
		break;
	case Maps::TILE_DIRT:
		return gDirtTile;
		break;
	case 1000:
		return gOutOfMapTile;
		break;
	default:
		return gOutOfMapTile;
		break;
	}

}

SDL_Texture* getEntityTexture(int entityID)
{

	switch (entityID)
	{
	case Maps::ENTITY_NONE:
		return NULL;
		break;
	case Maps::ENTITY_FURNACE:
		return gFurnace;
		break;
	case Maps::ENTITY_BEE:
		return gBee;
		break;
	case Maps::ENTITY_CLOSED_DOOR:
		return gClosedDoor;
		break;
	case Maps::ENTITY_OPEN_DOOR:
		return gOpenDoor;
		break;
	case Maps::ENTITY_EMPTY_ROCK:
		return gEmptyRock;
		break;
	case Maps::ENTITY_COPPER_ROCK:
		return gCopperRock;
		break;
	case Maps::ENTITY_TIN_ROCK:
		return gTinRock;
		break;
	case Maps::ENTITY_IRON_ROCK:
		return gIronRock;
		break;
	case Maps::ENTITY_COAL_ROCK:
		return gCoalRock;
		break;
	case Maps::ENTITY_MITHRIL_ROCK:
		return gMithrilRock;
		break;
	case Maps::ENTITY_ADAMANTITE_ROCK:
		return gAdamantiteRock;
		break;
	case Maps::ENTITY_RUNITE_ROCK:
		return gRuniteRock;
		break;
	case Maps::ENTITY_SILVER_ROCK:
		return gSilverRock;
		break;
	case Maps::ENTITY_GOLD_ROCK:
		return gGoldRock;
		break;
	case Maps::ENTITY_ANVIL:
		return gAnvil;
		break;
	case Maps::ENTITY_ORE_SHOP_KEEPER:
		return gShopKeeperOre;
		break;
	case Maps::ENTITY_BAR_SHOP_KEEPER:
		return gShopKeeperBar;
		break;
	case Maps::ENTITY_GENERAL_SHOP_KEEPER:
		return gShopKeeper;
		break;
	case Maps::ENTITY_ICECREAM_SHOP_KEEPER:
		return gShopKeeperIcecream;
		break;
	default:
		return NULL;
	}

}

void drawImage(int x, int y, int w, int h, SDL_Texture* tex)
{
	SDL_Rect img;
	img.x = x;
	img.y = y;
	img.w = w;
	img.h = h;
	SDL_RenderCopy(gRenderer, tex, NULL, &img);
}

void drawSidebarButtons()
{
	
	Menus Menus;
	//draw icon plates
	for (int a = 0; a < 10; a++)
		drawImage((56 * a) + 720, 664, 56, 56, gSidebarIconPlate);
	//draw if they are hovered over
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x > 720 && y > 664)
	{
		if (x < 776)
			drawImage(722, 666, 52, 52, gSidebarSelected);
		if (x >= 776 && x < 832)
			drawImage(778, 666, 52, 52, gSidebarSelected);
		if (x >= 832 && x < 888)
			drawImage(834, 666, 52, 52, gSidebarSelected);
		if (x >= 888 && x < 944)
			drawImage(890, 666, 52, 52, gSidebarSelected);
		if (x >= 944 && x < 1000)
			drawImage(946, 666, 52, 52, gSidebarSelected);
		if (x >= 1000 && x < 1056)
			drawImage(1002, 666, 52, 52, gSidebarSelected);
		if (x >= 1056 && x < 1112)
			drawImage(1058, 666, 52, 52, gSidebarSelected);
		if (x >= 1112 && x < 1168)
			drawImage(1114, 666, 52, 52, gSidebarSelected);
		if (x >= 1168 && x < 1224)
			drawImage(1170, 666, 52, 52, gSidebarSelected);
		if (x >= 1224 && x < 1280)
			drawImage(1226, 666, 52, 52, gSidebarSelected);
	}
	//draw if one is selected
	switch (Menus.getSidebarState())
	{
	case 0:
		//nothing
		break;
	case 1:
		drawImage(722, 666, 52, 52, gSidebarSelected);
		break;
	case 2:
		drawImage(778, 666, 52, 52, gSidebarSelected);
		break;
	case 3:
		drawImage(834, 666, 52, 52, gSidebarSelected);
		break;
	case 4:
		drawImage(890, 666, 52, 52, gSidebarSelected);
		break;
	case 5:
		drawImage(946, 666, 52, 52, gSidebarSelected);
		break;
	case 6:
		drawImage(1002, 666, 52, 52, gSidebarSelected);
		break;
	case 7:
		drawImage(1058, 666, 52, 52, gSidebarSelected);
		break;
	case 8:
		drawImage(1114, 666, 52, 52, gSidebarSelected);
		break;
	case 9:
		drawImage(1170, 666, 52, 52, gSidebarSelected);
		break;
	}
	//draw the icons
	drawImage(723, 667, 50, 50, gTileIcon);
	drawImage(779, 667, 50, 50, gEntityIcon);
	//drawImage(835, 667, 50, 50, gQuestsIcon);
	//drawImage(891, 667, 50, 50, gInventoryIcon);
	//drawImage(947, 667, 50, 50, gEquipmentIcon);
	//drawImage(1003, 667, 50, 50, gPrayerIcon);
	//drawImage(1059, 667, 50, 50, gSpellsIcon);
	//drawImage(1115, 667, 50, 50, gEmotesIcon);
	drawImage(1171, 667, 50, 50, gOptionsIcon);
	drawImage(1227, 667, 50, 50, gExitIcon);
}

void drawMapFloor()
{
	Maps Maps;
	for (int x = 0; x <= 19; x++)
	{
		for (int y = 0; y <= 19; y++)
		{
			int offSetX = Maps.getPlayerX() - 10, offSetY = Maps.getPlayerY() - 10;
			drawImage(x * 36, y * 36, 36, 36, getTileTexture(Maps.getMapTileID(x + offSetX, y + offSetY)));
		}
	}
}

void drawMapEntities()
{
	Maps Maps;
	int offSetX = Maps.getPlayerX() - 10, offSetY = Maps.getPlayerY() - 10;
	for (int x = 0; x <= 19; x++)
	{
		for (int y = 0; y <= 19; y++)
		{
			
			drawImage(x * 36, y * 36, 36, 36, getEntityTexture(Maps.getMapEntityID(x + offSetX, y + offSetY)));
		}
	}
	drawImage((Maps.getPlayerSpawnX() - offSetX) * 36 , (Maps.getPlayerSpawnY() - offSetY) * 36, 36, 36, gPlayer);
}

void drawNumber(int x, int y, int number)
{
	int ones = number % 10;
	int tens = number % 100 / 10;
	int hundreds = number % 1000 / 100;
	int thousands = number % 10000 / 1000;
	int tenThousands = number % 100000 / 10000;
	int hundredThousands = number % 1000000 / 100000;
	int millions = number % 10000000 / 1000000;
	int tenMillions = number % 100000000 / 10000000;
	int hundredMillions = number % 1000000000 / 100000000;

	if (number < 1000)
	{
		switch (ones)
		{
		case 0:
			drawImage(x, y, 5, 10, gCountZero);
			break;
		case 1:
			drawImage(x, y, 5, 10, gCountOne);
			break;
		case 2:
			drawImage(x, y, 5, 10, gCountTwo);
			break;
		case 3:
			drawImage(x, y, 5, 10, gCountThree);
			break;
		case 4:
			drawImage(x, y, 5, 10, gCountFour);
			break;
		case 5:
			drawImage(x, y, 5, 10, gCountFive);
			break;
		case 6:
			drawImage(x, y, 5, 10, gCountSix);
			break;
		case 7:
			drawImage(x, y, 5, 10, gCountSeven);
			break;
		case 8:
			drawImage(x, y, 5, 10, gCountEight);
			break;
		case 9:
			drawImage(x, y, 5, 10, gCountNine);
			break;
		}
	}

	if (number >= 10 && number < 1000)
	{
		switch (tens)
		{
		case 0:
			drawImage(x - 5, y, 5, 10, gCountZero);
			break;
		case 1:
			drawImage(x - 5, y, 5, 10, gCountOne);
			break;
		case 2:
			drawImage(x - 5, y, 5, 10, gCountTwo);
			break;
		case 3:
			drawImage(x - 5, y, 5, 10, gCountThree);
			break;
		case 4:
			drawImage(x - 5, y, 5, 10, gCountFour);
			break;
		case 5:
			drawImage(x - 5, y, 5, 10, gCountFive);
			break;
		case 6:
			drawImage(x - 5, y, 5, 10, gCountSix);
			break;
		case 7:
			drawImage(x - 5, y, 5, 10, gCountSeven);
			break;
		case 8:
			drawImage(x - 5, y, 5, 10, gCountEight);
			break;
		case 9:
			drawImage(x - 5, y, 5, 10, gCountNine);
			break;
		}
	}

	if (number >= 100 && number < 1000)
	{
		switch (hundreds)
		{
		case 0:
			drawImage(x - 10, y, 5, 10, gCountZero);
			break;
		case 1:
			drawImage(x - 10, y, 5, 10, gCountOne);
			break;
		case 2:
			drawImage(x - 10, y, 5, 10, gCountTwo);
			break;
		case 3:
			drawImage(x - 10, y, 5, 10, gCountThree);
			break;
		case 4:
			drawImage(x - 10, y, 5, 10, gCountFour);
			break;
		case 5:
			drawImage(x - 10, y, 5, 10, gCountFive);
			break;
		case 6:
			drawImage(x - 10, y, 5, 10, gCountSix);
			break;
		case 7:
			drawImage(x - 10, y, 5, 10, gCountSeven);
			break;
		case 8:
			drawImage(x - 10, y, 5, 10, gCountEight);
			break;
		case 9:
			drawImage(x - 10, y, 5, 10, gCountNine);
			break;
		}
		return;
	}

	if (number >= 1000 && number < 1000000)
	{

		drawImage(x - 5, y, 10, 10, gCountThousand);

		switch (thousands)
		{
		case 0:
			drawImage(x - 10, y, 5, 10, gCountZero);
			break;
		case 1:
			drawImage(x - 10, y, 5, 10, gCountOne);
			break;
		case 2:
			drawImage(x - 10, y, 5, 10, gCountTwo);
			break;
		case 3:
			drawImage(x - 10, y, 5, 10, gCountThree);
			break;
		case 4:
			drawImage(x - 10, y, 5, 10, gCountFour);
			break;
		case 5:
			drawImage(x - 10, y, 5, 10, gCountFive);
			break;
		case 6:
			drawImage(x - 10, y, 5, 10, gCountSix);
			break;
		case 7:
			drawImage(x - 10, y, 5, 10, gCountSeven);
			break;
		case 8:
			drawImage(x - 10, y, 5, 10, gCountEight);
			break;
		case 9:
			drawImage(x - 10, y, 5, 10, gCountNine);
			break;
		}

		if (number >= 10000)
		{
			switch (tenThousands)
			{
			case 0:
				drawImage(x - 15, y, 5, 10, gCountZero);
				break;
			case 1:
				drawImage(x - 15, y, 5, 10, gCountOne);
				break;
			case 2:
				drawImage(x - 15, y, 5, 10, gCountTwo);
				break;
			case 3:
				drawImage(x - 15, y, 5, 10, gCountThree);
				break;
			case 4:
				drawImage(x - 15, y, 5, 10, gCountFour);
				break;
			case 5:
				drawImage(x - 15, y, 5, 10, gCountFive);
				break;
			case 6:
				drawImage(x - 15, y, 5, 10, gCountSix);
				break;
			case 7:
				drawImage(x - 15, y, 5, 10, gCountSeven);
				break;
			case 8:
				drawImage(x - 15, y, 5, 10, gCountEight);
				break;
			case 9:
				drawImage(x - 15, y, 5, 10, gCountNine);
				break;
			}
		}

		if (number >= 100000)
		{
			switch (hundredThousands)
			{
			case 0:
				drawImage(x - 20, y, 5, 10, gCountZero);
				break;
			case 1:
				drawImage(x - 20, y, 5, 10, gCountOne);
				break;
			case 2:
				drawImage(x - 20, y, 5, 10, gCountTwo);
				break;
			case 3:
				drawImage(x - 20, y, 5, 10, gCountThree);
				break;
			case 4:
				drawImage(x - 20, y, 5, 10, gCountFour);
				break;
			case 5:
				drawImage(x - 20, y, 5, 10, gCountFive);
				break;
			case 6:
				drawImage(x - 20, y, 5, 10, gCountSix);
				break;
			case 7:
				drawImage(x - 20, y, 5, 10, gCountSeven);
				break;
			case 8:
				drawImage(x - 20, y, 5, 10, gCountEight);
				break;
			case 9:
				drawImage(x - 20, y, 5, 10, gCountNine);
				break;
			}
		}
	}

	if (number >= 1000000)
	{

		drawImage(x - 5, y, 10, 10, gCountMillion);

		switch (millions)
		{
		case 0:
			drawImage(x - 10, y, 5, 10, gCountZero);
			break;
		case 1:
			drawImage(x - 10, y, 5, 10, gCountOne);
			break;
		case 2:
			drawImage(x - 10, y, 5, 10, gCountTwo);
			break;
		case 3:
			drawImage(x - 10, y, 5, 10, gCountThree);
			break;
		case 4:
			drawImage(x - 10, y, 5, 10, gCountFour);
			break;
		case 5:
			drawImage(x - 10, y, 5, 10, gCountFive);
			break;
		case 6:
			drawImage(x - 10, y, 5, 10, gCountSix);
			break;
		case 7:
			drawImage(x - 10, y, 5, 10, gCountSeven);
			break;
		case 8:
			drawImage(x - 10, y, 5, 10, gCountEight);
			break;
		case 9:
			drawImage(x - 10, y, 5, 10, gCountNine);
			break;
		}
		if (number >= 10000000)
		{
			switch (tenMillions)
			{
			case 0:
				drawImage(x - 15, y, 5, 10, gCountZero);
				break;
			case 1:
				drawImage(x - 15, y, 5, 10, gCountOne);
				break;
			case 2:
				drawImage(x - 15, y, 5, 10, gCountTwo);
				break;
			case 3:
				drawImage(x - 15, y, 5, 10, gCountThree);
				break;
			case 4:
				drawImage(x - 15, y, 5, 10, gCountFour);
				break;
			case 5:
				drawImage(x - 15, y, 5, 10, gCountFive);
				break;
			case 6:
				drawImage(x - 15, y, 5, 10, gCountSix);
				break;
			case 7:
				drawImage(x - 15, y, 5, 10, gCountSeven);
				break;
			case 8:
				drawImage(x - 15, y, 5, 10, gCountEight);
				break;
			case 9:
				drawImage(x - 15, y, 5, 10, gCountNine);
				break;
			}
		}

		if (number >= 100000000)
		{
			switch (hundredMillions)
			{
			case 0:
				drawImage(x - 20, y, 5, 10, gCountZero);
				break;
			case 1:
				drawImage(x - 20, y, 5, 10, gCountOne);
				break;
			case 2:
				drawImage(x - 20, y, 5, 10, gCountTwo);
				break;
			case 3:
				drawImage(x - 20, y, 5, 10, gCountThree);
				break;
			case 4:
				drawImage(x - 20, y, 5, 10, gCountFour);
				break;
			case 5:
				drawImage(x - 20, y, 5, 10, gCountFive);
				break;
			case 6:
				drawImage(x - 20, y, 5, 10, gCountSix);
				break;
			case 7:
				drawImage(x - 20, y, 5, 10, gCountSeven);
				break;
			case 8:
				drawImage(x - 20, y, 5, 10, gCountEight);
				break;
			case 9:
				drawImage(x - 20, y, 5, 10, gCountNine);
				break;
			}
		}
	}
	
}

void drawPos()
{
	Maps Maps;
	bool running = true;
	int counter = 0;
	while (running)
	{
		drawNumber(715 - counter * 5, 710, Maps.getPlayerX());
		counter++;
		counter++;
		counter++;
		counter++;
		drawNumber(715 - counter * 5, 710, Maps.getPlayerY());
		counter++;
		counter++;
		counter++;
		counter++;
		drawImage(715 - counter * 5, 710, 5, 10, gCountS);
		counter++;
		drawImage(715 - counter * 5, 710, 5, 10, gCountZero);
		counter++;
		drawImage(715 - counter * 5, 710, 5, 10, gCountP);
		counter++;
		running = false;
	}
}

void drawSidebar()
{
	Maps Maps;
	Menus Menus;
	// draw background and bar
	drawImage(720, 0, 560, 720, gSidebarBackground);
	drawSidebarButtons();
	//get mouse pos
	int x, y;
	SDL_GetMouseState(&x, &y);
	switch (Menus.getSidebarState())
	{
		//Tile
	case 1:
		drawImage(978, 282, 44, 44, gSidebarIconPlate);
		drawImage(982, 286, 36, 36, getTileTexture(Maps.getSelectedTile().id));
		drawNumber(1014, 285, Maps.getSelectedTile().id);
		
		
		if (x >= 946 && x <= 982 && y >= 286 && y <= 322)
		{
			drawImage(944, 286, 36, 36, gArrowLeft);
		}
		else
		{
			drawImage(946, 286, 36, 36, gArrowLeft);
		}
		if (x >= 1018 && x <= 1054 && y >= 286 && y <= 322)
		{
			drawImage(1020, 286, 36, 36, gArrowRight);
		}
		else
		{
			drawImage(1018, 286, 36, 36, gArrowRight);
		}
		
		break;
		//Entity
	case 2:
		//entity select
		drawImage(978, 282, 44, 44, gSidebarIconPlate);
		drawImage(982, 286, 36, 36, getEntityTexture(Maps.getSelectedEntity().id));
		drawNumber(1014, 285, Maps.getSelectedEntity().id);
		if (x >= 946 && x <= 982 && y >= 286 && y <= 322)
		{
			drawImage(944, 286, 36, 36, gArrowLeft);
		}
		else
		{
			drawImage(946, 286, 36, 36, gArrowLeft);
		}
		if (x >= 1018 && x <= 1054 && y >= 286 && y <= 322)
		{
			drawImage(1020, 286, 36, 36, gArrowRight);
		}
		else
		{
			drawImage(1018, 286, 36, 36, gArrowRight);
		}

		//set player spawn
		drawImage(978, 332, 44, 44, gSidebarIconPlate);
		if (x >= 980 && x <= 1020 && y >= 334 && y <= 374 || Menus.getPlayerSpawnState() == 1)
		{
			drawImage(980, 334, 40, 40, gSidebarSelected);
		}
		drawImage(982, 336, 36, 36, gPlayer);
		

		break;
		//UNUSED
	case 3:
		break;
		//UNUSED
	case 4:
		
		break;
		//UNUSED
	case 5:

		break;
		//UNUSED
	case 6:

		break;
		//UNUSED
	case 7:

		break;
		//UNUSED
	case 8:

		break;
		//Options
	case 9:
		//save button
		drawImage(895, 619, 60, 35, gSidebarIconPlate);
		if(x >= 897 && x <= 953 && y >= 620 && y <= 653)
			drawImage(897, 620, 56, 33, gSidebarSelected);
		drawImage(900, 624, 50, 25, gSaveButton);

		//load button
		drawImage(1045, 619, 60, 35, gSidebarIconPlate);
		if (x >= 1047 && x <= 1103 && y >= 620 && y <= 653)
			drawImage(1047, 620, 56, 33, gSidebarSelected);
		drawImage(1050, 624, 50, 25, gLoadButton);

		//reset button
		drawImage(970, 619, 60, 35, gSidebarIconPlate);
		if (x >= 972 && x <= 1028 && y >= 620 && y <= 653)
			drawImage(972, 620, 56, 33, gSidebarSelected);
		drawImage(975, 624, 50, 25, gResetButton);

		//map size
		drawImage(978, 282, 44, 44, gSidebarIconPlate);
		//set
		if (x >= 980 && x <= 1020 && y >= 284 && y <= 324)
		{
			drawImage(980, 284, 40, 40, gSidebarSelected);
		}
		//current number
		drawNumber(1014, 313, Maps.getMapSize());
		//set number
		drawNumber(1014, 285, Maps.getMapSizeIndex());
		//up
		if (x >= 982 && x <= 1018 && y >= 250 && y <= 283)
		{
			drawImage(982, 248, 36, 36, gArrowUp);
		}
		else
		{
			drawImage(982, 250, 36, 36, gArrowUp);
		}
		//down
		if (x >= 982 && x <= 1018 && y >= 325 && y <= 358)
		{
			drawImage(982, 324, 36, 36, gArrowDown);
		}
		else
		{
			drawImage(982, 322, 36, 36, gArrowDown);
		}

		break;
	}
	
}

void Artist::draw()
{
	Maps Maps;
	drawMapFloor();
	drawMapEntities();
	drawSidebar();
	drawPos();
}

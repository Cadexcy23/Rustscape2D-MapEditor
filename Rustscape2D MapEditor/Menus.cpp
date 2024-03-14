#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Menus.h"

enum sidebarStateE{
	SIDEBAR_NONE,
	SIDEBAR_TILE,
	SIDEBAR_ENTITY,
	SIDEBAR_UNUSED1,
	SIDEBAR_UNUSED2,
	SIDEBAR_UNUSED3,
	SIDEBAR_UNUSED4,
	SIDEBAR_UNUSED5,
	SIDEBAR_UNUSED6,
	SIDEBAR_OPTIONS
};

int sidebarState = SIDEBAR_NONE;
int playerSpawnState = 0;

int Menus::getSidebarState()
{
	return sidebarState;
}

void Menus::setSidebarState(int state)
{
	sidebarState = state;
}

int Menus::getPlayerSpawnState()
{
	return playerSpawnState;
}

void Menus::setPlayerSpawnState(int state)
{
	playerSpawnState = state;
}
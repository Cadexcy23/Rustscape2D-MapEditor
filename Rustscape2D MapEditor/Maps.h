#pragma once
#include <SDL.h>
class Maps {

public:
	enum tiles {
		TILE_VOID,
		TILE_STONE,
		TILE_STONEWALL,
		TILE_WATER,
		TILE_DIRT,
		TILE_COUNT
	};
public:
	enum entities {
		ENTITY_NONE,
		ENTITY_FURNACE,
		ENTITY_BEE,
		ENTITY_CLOSED_DOOR,
		ENTITY_OPEN_DOOR,
		ENTITY_EMPTY_ROCK,
		ENTITY_COPPER_ROCK,
		ENTITY_TIN_ROCK,
		ENTITY_IRON_ROCK,
		ENTITY_COAL_ROCK,
		ENTITY_MITHRIL_ROCK,
		ENTITY_ADAMANTITE_ROCK,
		ENTITY_RUNITE_ROCK,
		ENTITY_SILVER_ROCK,
		ENTITY_GOLD_ROCK,
		ENTITY_ANVIL,
		ENTITY_ORE_SHOP_KEEPER,
		ENTITY_BAR_SHOP_KEEPER,
		ENTITY_GENERAL_SHOP_KEEPER,
		ENTITY_ICECREAM_SHOP_KEEPER,
		ENTITY_COUNT
	};

public:
	struct tile {
		int id;
		bool walkable;
	};
public:
	struct entity {
		int id;
		bool walkable;
	};		
public:
	void updateMapSize();
	void resetMap();
	
	int getMapSizeIndex();
	void setMapSizeIndex(int size);
	int getMapSize();
	void setMapSize(int size);
	Maps::tile getSelectedTile();

	Maps::tile getTileFromID(int ID);

	Maps::entity getSelectedEntity();

	Maps::entity getEntityFromID(int ID);

	int getPlayerSpawnX();

	int getPlayerSpawnY();

	void setPlayerSpawnX(int x);

	void setPlayerSpawnY(int y);

		//Gets the tile ID from the map position
		int getMapTileID(int x, int y);

		void setMapTile(int x, int y, tile tile);

		//Gets the entity ID from the map position
		int getMapEntityID(int x, int y);

		void setMapEntity(int x, int y, entity entity);

		//Gets the player's x
public: int getPlayerX();

		//Gets the player's y
public: int getPlayerY();

		//Sets the players x
		void setPlayerX(int x);

		//Sets the players y
		void setPlayerY(int y);

		void changeSelectedTile(int amount);

		

		void changeSelectedEntity(int amount);

};
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Saving.h"
#include "Maps.h"

void Saving::saveMap()
{
	printf("Saving...\n");
	Maps Maps;
	std::ofstream myFile;
	myFile.open("Map.RSM");
	if (myFile.is_open())
	{
		int mapSize = Maps.getMapSize();
		myFile << Maps.getPlayerSpawnX() << "\n";
		myFile << Maps.getPlayerSpawnY() << "\n";
		myFile << mapSize << "\n";
		for (int y = 0; y <= mapSize - 1; y++)
		{
			for (int x = 0; x <= mapSize - 1; x++)
			{
				myFile << Maps.getMapTileID(x, y) << " ";
			}
			myFile << "\n";
		}
		for (int y = 0; y <= mapSize - 1; y++)
		{
			for (int x = 0; x <= mapSize - 1; x++)
			{
				myFile << Maps.getMapEntityID(x, y) << " ";
			}
			myFile << "\n";
		}


		
		printf("Saved!\n");
		myFile.close();
	}
	else
	{
		printf("Unable to save File\n");
	}
}



void Saving::loadMap()
{
	printf("Loading...\n");
	Maps Maps;
	std::ifstream myFile;
	myFile.open("Map.RSM");
	if (myFile.is_open())
	{
		std::string dataS;
		int dataI = 1;
		int mapSize = 1;
		int counter = 1;

		while (counter <= (mapSize*2)+1)
		{
			if (counter == 1)
			{
				getline(myFile, dataS);
				dataI = std::stoi(dataS);
				Maps.setPlayerSpawnX(dataI);
				//std::cout << dataS << "\n";
			}
			if (counter == 2)
			{
				getline(myFile, dataS);
				dataI = std::stoi(dataS);
				Maps.setPlayerSpawnY(dataI);
				//std::cout << dataS << "\n";
			}
			if (counter == 3)
			{
				getline(myFile, dataS);
				dataI = std::stoi(dataS);
				Maps.setMapSize(dataI);
				mapSize = dataI;
				Maps.updateMapSize();
				//Maps.resetMap();
				//std::cout << dataS << "\n";
			}
			if (counter == 4)
			{
				for (int y = 0; y <= mapSize - 1; y++)
				{
					getline(myFile, dataS);
					std::istringstream iss(dataS);
					std::string subS;
					for (int x = 0; x <= mapSize - 1; x++)
					{
						iss >> subS;
						dataI = std::stoi(subS);
						Maps.setMapTile(x, y, Maps.getTileFromID(dataI));
					}
					counter++;
					//std::cout << dataS << "\n";
				}
			}
			if (counter ==  5 + mapSize)
			{
				for (int y = 0; y <= mapSize - 1; y++)
				{
					getline(myFile, dataS);
					std::istringstream iss(dataS);
					std::string subS;
					for (int x = 0; x <= mapSize - 1; x++)
					{
						iss >> subS;
						dataI = std::stoi(subS);
						Maps.setMapEntity(x, y, Maps.getEntityFromID(dataI));
					}
					//std::cout << dataS << "\n";
				}
			}
			
			

			
			counter++;
		}

		//printf("Map Size: %i\n", Maps.getMapSize());
		if (Maps.getPlayerSpawnX() >= Maps.getMapSize())
		{
			Maps.setPlayerSpawnX(0);
		}
		if (Maps.getPlayerSpawnY() >= Maps.getMapSize())
		{
			Maps.setPlayerSpawnY(0);
		}
		printf("Loaded!\n");
		myFile.close();
		
	}
	else
	{
		printf("Unable to open File\n");
	}
	
}
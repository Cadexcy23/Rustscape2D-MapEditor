#pragma once
class Artist{

		//Draws everything
public: void draw();

		//Clears the screen
public: void clearScreen();

		//Updates the screen
public: void updateScreen();

		//Starts up SDL and creates window
public: bool init();

		//Loads media
public: bool loadMedia();

		//Frees media and shuts down SDL
public: void close();


};
#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <fstream>
#include <string>

const int WIDTH = 80;
const int HEIGHT = 25;

class Floor {
	std::fstream f; // fstream for file
	const int width; // width of each floor
	const int height; // height of each floor
	bool floor_existed; // whether the floor existed already
	public:
		char **board; // 2D array of char board
		Floor(); // ctor store floor plan in board
		~Floor(); //dtor
		void openfile(std::string); // open file
		void closefile(); // close file
		void init(std::string,int); // initialize the board
		int getHeight(); // getter for height
		int getWidth(); // getter for width
		void clearfloor(); // clear the current floor
		void display(); // print out the current floor
};

#endif

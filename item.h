#ifndef _ITEM_H_
#define _ITEM_H_

class Game;

class Item {
	protected:
		Game *g; // pointer to game
		const int x; // item's x coordinates
		const int y; // item's y coordinates
		const int value; // item's value
		const char symbol; // item's symbol on floor
	public:
		Item(Game *, const int, const int, const int, char); // ctor
		~Item(); // dtor
		int getX(); // getter for x coordinates
		int getY(); // getter for y coordiantes
		int getValue(); // getter for value 
		char getSym(); // getter for symbol
};

#endif


#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <string>
#include <iostream>

class Game;

class Character {
	protected:
		Game *g; // a pointer to game
		int x; // x coordinates on current floor
		int y; // y coordinates on currect floor
		int HP; // current HP
		int attack; // character's initial attack value
		int defence; // character's initial defence value
		const std::string name; // character's name
		const char symbol; // character's symbol on the floor
		char prev_state; // character's previous symbol
	public:
		Character(Game*, int, int, int, int, int, char, std::string); // ctor
		int getX(); // getter for X
		int getY(); // getter for Y
		int getHP(); // getter for HP
		char getPrev(); // getter for previous state
		char getSym(); // getter for symbol
		int getAtk(); // getter for attack
		int getDef(); // getter for defence
		std::string getName(); // getter for name
		void setAtk(int); // setter for attack
		void setDef(int); // setter for defence
		void setX(int); // setter for X
		void setY(int); // setter for Y
		void setHP(int); // setter for HP
		void setPrev(char); // setter for previous state
		~Character(); // dtor
};

#endif

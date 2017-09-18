#ifndef _DRAGON_H_
#define _DRAGON_H_
#include "enemy.h"

class Gold;

class Dragon : public Enemy {
	int gx; // associated gold x coordinates
	int gy; // associated gold y coordiantes
	public:
		Dragon(Game*,int,int,int,int); // ctor
		~Dragon(); // dtor
		int getGoldX(); // getter for gold x coordiantes
		void setGoldX(int); // setter for gold x coordinates
		int getGoldY(); // getter for gold y coordinates
		void setGoldY(int); // setter for gold y coordinates
		void Attack(Player &); // Attack player
		void BeAttacked(Shade &);
		void BeAttacked(Troll &);
		void BeAttacked(Drow &);
		void BeAttacked(Vampire &);
		void BeAttacked(Goblin &);
};


#endif

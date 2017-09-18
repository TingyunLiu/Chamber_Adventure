#ifndef _HUMAN_H_
#define _HUMAN_H_
#include "enemy.h"

class Human : public Enemy {
	public:
		Human(Game*,int,int);
		~Human();
		void Attack(Player &);
		void BeAttacked(Shade &);
		void BeAttacked(Troll &);
		void BeAttacked(Drow &);
		void BeAttacked(Vampire &);
		void BeAttacked(Goblin &);		
};


#endif

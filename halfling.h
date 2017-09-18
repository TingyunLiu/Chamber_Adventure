#ifndef _HALFLING_H_
#define _HALFLING_H_
#include "enemy.h"

class Halfling : public Enemy {
	public:
		Halfling(Game*,int,int);
		~Halfling();
		void Attack(Player &);
		void BeAttacked(Shade &);
		void BeAttacked(Troll &);
		void BeAttacked(Drow &);
		void BeAttacked(Vampire &);
		void BeAttacked(Goblin &);		
};


#endif


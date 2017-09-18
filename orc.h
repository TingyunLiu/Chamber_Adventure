#ifndef _ORC_H_
#define _ORC_H_
#include "enemy.h"

class Orc : public Enemy {
	public:
		Orc(Game*,int,int);
		~Orc();
		void Attack(Player &);
		void BeAttacked(Shade &);
		void BeAttacked(Troll &);
		void BeAttacked(Drow &);
		void BeAttacked(Vampire &);
		void BeAttacked(Goblin &);
};


#endif

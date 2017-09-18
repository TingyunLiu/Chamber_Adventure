#ifndef _GOBLIN_H_
#define _GOBLIN_H_
#include "player.h"

class Goblin : public Player{
	public:
		Goblin(Game*,int,int);
		~Goblin();
		void Attack(Enemy &);
		void BeAttacked(Elf &);
		void BeAttacked(Orc &);
		void BeAttacked(Halfling &);
		void BeAttacked(Merchant &);
		void BeAttacked(Dragon &);
		void BeAttacked(Human &);
		void BeAttacked(Dwarf &);
};

#endif


#ifndef _TROLL_H_
#define _TROLL_H_
#include "player.h"

class Troll : public Player{
	public:
		Troll(Game*,int,int);
		~Troll();
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

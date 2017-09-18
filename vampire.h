#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_
#include "player.h"

class Vampire : public Player{
	public:
		Vampire(Game*,int,int);
		~Vampire();
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

#ifndef _DROW_H_
#define _DROW_H_
#include "player.h"

class Drow : public Player {
	public:
		Drow(Game*,int,int);
		~Drow();
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

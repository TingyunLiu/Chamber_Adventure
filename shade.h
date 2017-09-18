#ifndef _SHADE_H_
#define _SHADE_H_
#include "player.h"

class Shade : public Player{
	public:
		Shade(Game*,int,int);
		~Shade();
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

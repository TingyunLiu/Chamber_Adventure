#ifndef _ELF_H_
#define _ELF_H_
#include "enemy.h"

class Elf : public Enemy {
	public:
		Elf(Game*,int,int);
		~Elf();
		void Attack(Player &);
		void BeAttacked(Shade &);
		void BeAttacked(Troll &);
		void BeAttacked(Drow &);
		void BeAttacked(Vampire &);
		void BeAttacked(Goblin &);
};


#endif


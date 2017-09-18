#ifndef _DWARF_H_
#define _DWARF_H_
#include "enemy.h"

class Dwarf : public Enemy {
    public:
        Dwarf(Game*,int,int);
        ~Dwarf();
        void Attack(Player &);
		void BeAttacked(Shade &);
		void BeAttacked(Troll &);
		void BeAttacked(Drow &);
		void BeAttacked(Vampire &);
		void BeAttacked(Goblin &);
};


#endif



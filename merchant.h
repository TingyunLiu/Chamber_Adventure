#ifndef _MERCHANT_H_
#define _MERCHANT_H_
#include "enemy.h"

class Merchant : public Enemy {
	public:
		Merchant(Game*,int,int);
		~Merchant();
		void Attack(Player &);
		void BeAttacked(Shade &);
		void BeAttacked(Troll &);
		void BeAttacked(Drow &);
		void BeAttacked(Vampire &);
		void BeAttacked(Goblin &);
};


#endif

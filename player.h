#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "character.h"

class Enemy;
class Elf;
class Orc;
class Halfling;
class Merchant;
class Dragon;
class Human;
class Dwarf;

class Player : public Character{
	protected:
		int gold; // the gold player has currently
		int atkbuff; // atk buff the player get on current floor
		int defbuff; // def buff the player get on current floor
	public:
		Player(Game*,int,int,int,int,int,std::string); // ctor
		int getGold(); // getter for gold
		int getAtkbuff(); // getter for atkbuff
		int getDefbuff(); // getter for defbuff
		void setAtkbuff(int); // setter for atkbuff
		void setDefbuff(int); // setter for defbuff
		void setGold(int); // setter for gold

		virtual void Attack(Enemy &) = 0; // attack enemy
		virtual void BeAttacked(Elf &) = 0; 
		virtual void BeAttacked(Orc &) = 0;
		virtual void BeAttacked(Halfling &) = 0;
		virtual void BeAttacked(Merchant &) = 0;
		virtual void BeAttacked(Dragon &) = 0;
		virtual void BeAttacked(Human &) = 0;
		virtual void BeAttacked(Dwarf &) = 0;
		~Player(); // dtor
};

#endif

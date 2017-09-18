#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "character.h"
#include <string>
#include <iostream>

class Player;
class Shade;
class Troll;
class Drow;
class Vampire;
class Goblin;

class Enemy : public Character {
	public:
		Enemy(Game*,int,int,int,int,int,char,std::string); // ctor
		~Enemy(); // dtor

		virtual void Attack(Player &) = 0; // attack player
		virtual void BeAttacked(Shade &) = 0;
		virtual void BeAttacked(Troll &) = 0;
		virtual void BeAttacked(Drow &) = 0;
		virtual void BeAttacked(Vampire &) = 0;
		virtual void BeAttacked(Goblin &) = 0;	
};


#endif


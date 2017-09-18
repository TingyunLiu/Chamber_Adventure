#include "halfling.h"
#include <cstdlib>

#include <cmath>
#include "player.h"
#include "shade.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "drow.h"

using namespace std;

Halfling::Halfling(Game* g, int x, int y) 
	: Enemy(g,x,y,100,15,20,'L',"Halfling") { }

Halfling::~Halfling() { }

void Halfling::Attack(Player &p) {
	p.BeAttacked(*this);
}

void Halfling::BeAttacked(Shade &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());

   	int x = rand() % 2;
   	if (x == 0) {
	    HP = HP - damage;
	    cout << endl;
		cout << "You caused " << name << " " << damage << " damage!" << endl;
	}
}

void Halfling::BeAttacked(Troll &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    
    int x = rand() % 2;
   	if (x == 0) {
	    HP = HP - damage;
	    e.setHP(e.getHP()+5);
	    if (e.getHP() > 120) e.setHP(120);
	    cout << endl;
	    cout << "You caused " << name << " " << damage << " damage!" << endl;
	}
}

void Halfling::BeAttacked(Drow &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());

   	int x = rand() % 2;
   	if (x == 0) {
	    HP = HP - damage;
	    cout << endl;
	    cout << "You caused " << name << " " << damage << " damage!" << endl;
	}
}

void Halfling::BeAttacked(Vampire &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());

   	int x = rand() % 2;
   	if (x == 0) {
	    HP = HP - damage;
	    e.setHP(e.getHP()+5);
	    cout << endl;
	    cout << "You caused " << name << " " << damage << " damage!" << endl;
	}
}

void Halfling::BeAttacked(Goblin &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());

   	int x = rand() % 2;
   	if (x == 0) {
	    HP = HP - damage;
	    cout << endl;
	 	cout << "You caused " << name << " " << damage << " damage!" << endl;
	}
}




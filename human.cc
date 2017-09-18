#include "human.h"

#include <cmath>
#include "player.h"
#include "shade.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "drow.h"

using namespace std;

Human::Human(Game* g, int x, int y) 
	: Enemy(g,x,y,140,20,20,'H',"Human") { }

Human::~Human() { }

void Human::Attack(Player &p) {
	p.BeAttacked(*this);
}

void Human::BeAttacked(Shade &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}

void Human::BeAttacked(Troll &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    e.setHP(e.getHP()+5);
    if (e.getHP() > 120) e.setHP(120);
    cout << endl;
    cout << "You caused " << name << " " << damage << " damage!" << endl;
}

void Human::BeAttacked(Drow &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    cout << endl;
    cout << "You caused " << name << " " << damage << " damage!" << endl;
}

void Human::BeAttacked(Vampire &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    e.setHP(e.getHP()+5);
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}

void Human::BeAttacked(Goblin &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}



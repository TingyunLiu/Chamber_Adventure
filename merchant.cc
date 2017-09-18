#include "merchant.h"

#include <cmath>
#include "player.h"
#include "shade.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "drow.h"

using namespace std;

Merchant::Merchant(Game* g, int x, int y) 
	: Enemy(g,x,y,30,70,5,'M',"Merchant") { }

Merchant::~Merchant() { }

void Merchant::Attack(Player &p) {
	p.BeAttacked(*this);
}

void Merchant::BeAttacked(Shade &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}

void Merchant::BeAttacked(Troll &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    e.setHP(e.getHP()+5);
    if (e.getHP() > 120) e.setHP(120);
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}

void Merchant::BeAttacked(Drow &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}

void Merchant::BeAttacked(Vampire &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    e.setHP(e.getHP()+5);
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}

void Merchant::BeAttacked(Goblin &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}


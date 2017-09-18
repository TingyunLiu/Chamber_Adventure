#include "dragon.h"
#include "gold.h"

#include <cmath>
#include "player.h"
#include "shade.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "drow.h"

using namespace std;

Dragon::Dragon(Game* g, int x, int y, int gx, int gy) 
	: Enemy(g,x,y,150,20,20,'D',"Dragon"), gx(gx), gy(gy) { }

Dragon::~Dragon() { }

int Dragon::getGoldX() {
	return gx;
}

void Dragon::setGoldX(int x) {
	gx = x;
}

void Dragon::setGoldY(int y) {
	gy = y;
}

int Dragon::getGoldY() {
	return gy;
}

void Dragon::Attack(Player &p) {
	p.BeAttacked(*this);
}

void Dragon::BeAttacked(Shade &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}

void Dragon::BeAttacked(Troll &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    e.setHP(e.getHP()+5);
    if (e.getHP() > 120) e.setHP(120);
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}

void Dragon::BeAttacked(Drow &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}

void Dragon::BeAttacked(Vampire &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    e.setHP(e.getHP()+5);
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}

void Dragon::BeAttacked(Goblin &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}

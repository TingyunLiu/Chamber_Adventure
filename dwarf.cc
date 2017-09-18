#include "dwarf.h"

#include <cmath>
#include "player.h"
#include "shade.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "drow.h"

using namespace std;

Dwarf::Dwarf(Game* g, int x, int y)
        : Enemy(g,x,y,100,20,30,'W',"Dwarf") { }

Dwarf::~Dwarf() { }

void Dwarf::Attack(Player &p) {
	p.BeAttacked(*this);
}

void Dwarf::BeAttacked(Shade &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}

void Dwarf::BeAttacked(Troll &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    e.setHP(e.getHP()+5);
    if (e.getHP() > 120) e.setHP(120);
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}

void Dwarf::BeAttacked(Drow &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}

// Vampires are allergic to dwarves and lose 5HP rather than gain
void Dwarf::BeAttacked(Vampire &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    e.setHP(e.getHP()-5);
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}

void Dwarf::BeAttacked(Goblin &e) {
	double tmp = 100 + defence;
    int damage = ceil(100/tmp) * (e.getAtk() + e.getAtkbuff());
    HP = HP - damage;
    cout << endl;
	cout << "You caused " << name << " " << damage << " damage!" << endl;
}


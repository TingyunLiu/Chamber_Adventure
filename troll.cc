#include "troll.h"

#include <cmath>
#include "enemy.h"
#include "elf.h"
#include "orc.h"
#include "halfling.h"
#include "merchant.h"
#include "dragon.h"
#include "human.h"
#include "dwarf.h"

using namespace std;

Troll::Troll(Game* g,int x, int y)
	: Player(g,x,y,120,25,15,"Troll") { }
	

Troll::~Troll() { }

void Troll::Attack(Enemy &e){
	e.BeAttacked(*this);
}

void Troll::BeAttacked(Elf &e) {
        double tmp = 100 + defence + defbuff;
        int damage = ceil(100/tmp) * e.getAtk();
        HP = HP - damage + 5;
        cout << endl;
        cout << e.getName() << " caused you " << damage << " damage!" << endl;
        HP = HP - damage;
        cout << endl;
        cout << e.getName() << " caused you " << damage << " damage!" << endl;
        if (HP > 120) HP = 120;
}

void Troll::BeAttacked(Orc &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage + 5;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
	if (HP > 120) HP = 120;
}

void Troll::BeAttacked(Halfling &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage + 5;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
	if (HP > 120) HP = 120;
}

void Troll::BeAttacked(Merchant &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage + 5;	
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
	if (HP > 120) HP = 120;
}

void Troll::BeAttacked(Dragon &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage + 5;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
	if (HP > 120) HP = 120;
}

void Troll::BeAttacked(Human &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage + 5;	
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
	if (HP > 120) HP = 120;
}

void Troll::BeAttacked(Dwarf &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage + 5;	
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
	if (HP > 120) HP = 120;
}


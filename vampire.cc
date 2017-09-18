#include "vampire.h"

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

Vampire::Vampire(Game* g,int x, int y)
	: Player(g,x,y,50,25,25,"Vampire") { }
	
Vampire::~Vampire() { }

void Vampire::Attack(Enemy &e){
	e.BeAttacked(*this);
}

void Vampire::BeAttacked(Elf &e) {
        double tmp = 100 + defence + defbuff;
        int damage = ceil(100/tmp) * e.getAtk();
        HP = HP - damage;
        cout << endl;
        cout << e.getName() << " caused you " << damage << " damage!" << endl;
        HP = HP - damage;
        cout << endl;
        cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Vampire::BeAttacked(Orc &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Vampire::BeAttacked(Halfling &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Vampire::BeAttacked(Merchant &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;	
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Vampire::BeAttacked(Dragon &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Vampire::BeAttacked(Human &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Vampire::BeAttacked(Dwarf &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;	
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}



#include "goblin.h"

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

Goblin::Goblin(Game* g,int x, int y)
	: Player(g,x,y,110,15,20,"Goblin") { }
	
Goblin::~Goblin() { }

void Goblin::Attack(Enemy &e){
	e.BeAttacked(*this);
}

void Goblin::BeAttacked(Elf &e) {
        double tmp = 100 + defence + defbuff;
        int damage = ceil(100/tmp) * e.getAtk();
        HP = HP - damage;
        cout << endl;
        cout << e.getName() << " caused you " << damage << " damage!" << endl;
        HP = HP - damage;
        cout << endl;
        cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Goblin::BeAttacked(Orc &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	damage = damage * 1.5;
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Goblin::BeAttacked(Halfling &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Goblin::BeAttacked(Merchant &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;	
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Goblin::BeAttacked(Dragon &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Goblin::BeAttacked(Human &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Goblin::BeAttacked(Dwarf &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;	
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}


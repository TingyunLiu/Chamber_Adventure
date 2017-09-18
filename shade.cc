#include "shade.h"

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

Shade::Shade(Game* g,int x, int y)
	: Player(g,x,y,125,25,25,"Shade") { }
	

Shade::~Shade() { }

void Shade::Attack(Enemy &e){
	e.BeAttacked(*this);
}

void Shade::BeAttacked(Elf &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Shade::BeAttacked(Orc &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Shade::BeAttacked(Halfling &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Shade::BeAttacked(Merchant &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Shade::BeAttacked(Dragon &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Shade::BeAttacked(Human &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;	
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Shade::BeAttacked(Dwarf &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;	
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

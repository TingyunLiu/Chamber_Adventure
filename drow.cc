#include "drow.h"

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

Drow::Drow(Game* g,int x, int y)
	: Player(g,x,y,150,25,15,"Drow") { }
	

Drow::~Drow() { }

void Drow::Attack(Enemy &e){
	e.BeAttacked(*this);
}

void Drow::BeAttacked(Elf &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Drow::BeAttacked(Orc &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Drow::BeAttacked(Halfling &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Drow::BeAttacked(Merchant &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;	
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Drow::BeAttacked(Dragon &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Drow::BeAttacked(Human &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;	
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}

void Drow::BeAttacked(Dwarf &e) {
	double tmp = 100 + defence + defbuff;
	int damage = ceil(100/tmp) * e.getAtk();
	HP = HP - damage;	
	cout << endl;
	cout << e.getName() << " caused you " << damage << " damage!" << endl;
}



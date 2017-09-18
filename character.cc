
#include "character.h"
using namespace std;

Character::Character(Game *g, int x, int y, int hp, int attack, int defence, char sym, string name)
 : g(g), x(x), y(y), HP(hp), attack(attack), defence(defence), symbol(sym), prev_state('.'), name(name) { }

int Character::getX(){
	return x;
}

void Character::setX(int x) {
	this->x = x;
}

int Character::getY(){
	return y;
}

string Character::getName() {
	return name;
}

void Character::setY(int y) {
	this->y = y;
}

char Character::getSym() {
	return symbol;
}

void Character::setPrev(char c) {
	prev_state = c;
}

char Character::getPrev() {
	return prev_state;
}

int Character::getHP() {
	return HP;
}

void Character::setHP(int hp) {
	HP = hp;
}

int Character::getAtk() {
	return attack;
}

void Character::setAtk(int a) {
	attack = a;
}

int Character::getDef() {
	return defence;
}

void Character::setDef(int d) {
	defence = d;
}

Character::~Character(){}

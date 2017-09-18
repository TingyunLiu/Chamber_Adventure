
#include "player.h"
using namespace std;

Player::Player(Game *g, int x, int y, int hp, int attack, int defence, string name)
 : Character(g,x,y,hp,attack,defence,'@',name), gold(8), atkbuff(0), defbuff(0){ }

int Player::getGold() {
	return gold;
}

void Player::setGold(int g) {
	gold = g;
}

int Player::getAtkbuff() {
	return atkbuff;
}

int Player::getDefbuff() {
	return defbuff;
}

void Player::setAtkbuff(int a) {
	atkbuff = a;
}

void Player::setDefbuff(int d) {
	defbuff = d;
}

Player::~Player() { }

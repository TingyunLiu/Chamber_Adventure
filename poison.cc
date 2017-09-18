#include "poison.h"
using namespace std;


Poison::Poison(Game *g, const int x, const int y, const int value, const string type,const bool positive)
	: Item(g,x,y,value,'P'), type(type), positive(positive) { }

Poison::~Poison() { }


string Poison::getType() {
	return type;
}

bool Poison::getPositive() {
	return positive;
}



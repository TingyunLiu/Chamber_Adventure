#include "item.h"
#include "game.h"
using namespace std;


Item::Item(Game *g, const int x, const int y, const int v, char sym)
	: g(g), x(x), y(y), value(v), symbol(sym) { }


Item::~Item() { }

int Item::getX() {
	return x;
}

int Item::getY() {
	return y;
}

int Item::getValue() {
	return value;
}

char Item::getSym() {
	return symbol;
}


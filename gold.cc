#include "gold.h"
using namespace std;

Gold::Gold(Game *g, const int x, const int y, const int value, bool pickable)
	: Item(g,x,y,value,'G'), pickable(pickable) { }

Gold::~Gold() { }

bool Gold::getPickable() {
	return pickable;
}

void Gold::setPickable(bool p) {
	pickable = p;
	
}


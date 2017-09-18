#include "character.h"
#include "enemy.h"
using namespace std;

Enemy::Enemy(Game *g, int x, int y, int hp, int attack, int defence, char sym, string name)
 : Character(g,x,y,hp,attack,defence,sym,name) { }

Enemy::~Enemy() { }


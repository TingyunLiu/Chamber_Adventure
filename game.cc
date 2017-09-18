#include <cstdlib>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

#include "game.h"
#include "floor.h"
#include "player.h"
#include "enemy.h"
#include "item.h"
#include "poison.h"
#include "gold.h"

#include "vampire.h"
#include "shade.h"
#include "troll.h"
#include "drow.h"
#include "goblin.h"

#include "dwarf.h"
#include "dragon.h"
#include "human.h"
#include "halfling.h"
#include "orc.h"
#include "elf.h"
#include "merchant.h"

using namespace std;

bool bought = false;
int starttime = -1;

Game::Game(string file, bool b) : file_name(file), cur_floor(1), p(NULL), hostile(false),num_enemy(0) { 
	fl = new Floor;
	fl->init(file_name, cur_floor);
	bonus = b;
}

Game::~Game() {
	Game::clearfloor();
	delete p;
}

Player* Game::getPC() {
	return p;
} 

string Game::getFile_name() {
	return file_name;
}

void Game::clearfloor() {
	for (int i = 0; i < poison.size(); ++i) {
		delete poison.at(i);
	}
	poison.clear();

	for (int i = 0; i < dragon.size(); ++i) {
		delete dragon.at(i);
	}
	dragon.clear();

	for (int i = 0; i < gold.size(); ++i) {
		delete gold.at(i);
	}
	gold.clear();
	
	for (int i = 0; i < enemy.size(); ++i) {
		delete enemy.at(i);
	}
	enemy.clear();
	
	delete fl;

	bought = false;
}

void Game::chooseplayer(string race) {
	int x = rand() % 25;
	int y = rand() % 80;
	while (fl->board[x][y] != '.') {
		x = rand() % 25;
		y = rand() % 80;
	} // while

	if (race == "d") {
		p = new Drow(this,x,y);
	} else if (race == "v") {
		p = new Vampire(this,x,y);
	} else if (race == "g") {
		p = new Goblin(this,x,y);
	} else if (race == "t") {
		p = new Troll(this,x,y); 
	} else {
		p = new Shade(this,x,y);
		cerr << "You are default player character Shade!" << endl;
	} // inner if

	fl->board[x][y] = p->getSym();

	Game::init_stairs();
	Game::init_poison();
	Game::init_gold();
	Game::init_enemy();
}

void Game::chooseplayer_file(string race) {
	for (int i = 0; i < fl->getHeight(); ++i) {
		for (int j = 0; j < fl->getWidth(); ++j) {
			// initialize player
			if (fl->board[i][j] == '@') {
				if (race == "d") {
					p = new Drow(this,i,j);
				} else if (race == "v") {
					p = new Vampire(this,i,j);
				} else if (race == "g") {
					p = new Goblin(this,i,j);
				} else if (race == "t") {
					p = new Troll(this,i,j); 
				} else {
					p = new Shade(this,i,j);
					cout << "You are default player character Shade!" << endl;
				} // inner if
			} // outter if
		} // inner for
	} // outter for
	Game::chooseobject_file();
}

void Game::chooseobject_file() {
	Poison *po;
	Gold *g;
	Dragon *d;
	Enemy *e;
	for (int i = 0; i < fl->getHeight(); ++i) {
		for (int j = 0; j < fl->getWidth(); ++j) {
			// initialize poison
			if (fl->board[i][j] == '0' || fl->board[i][j] == '1' ||
		    	fl->board[i][j] == '2' || fl->board[i][j] == '3' ||
	   	    	fl->board[i][j] == '4' || fl->board[i][j] == '5') {

					if (fl->board[i][j] == '0') { // pos hp
						po = new Poison(this,i,j,10,"hp",true);
					} else if (fl->board[i][j] == '1') { // pos atk
						po = new Poison(this,i,j,5,"attack",true);			
					} else if (fl->board[i][j] == '2') { // pos def
						po = new Poison(this,i,j,5,"defence",true);
					} else if (fl->board[i][j] == '3') { // neg hp
						po = new Poison(this,i,j,10,"hp",false);
					} else if (fl->board[i][j] == '4') { // neg atk
						po = new Poison(this,i,j,5,"attack",false);
					} else { // fl->board[i][j] == '5' neg def
						po = new Poison(this,i,j,5,"defence",false);
					} // inner if

					poison.push_back(po);
					fl->board[i][j] = po->getSym();

			// initialize gold
			} else if (fl->board[i][j] == '6' || fl->board[i][j] == '7' ||
					   fl->board[i][j] == '8' || fl->board[i][j] == '9') {
					
					if (fl->board[i][j] == '6') { // normal gold
						g = new Gold(this,i,j,2,true);
					} else if (fl->board[i][j] == '7') { // small gold
						g = new Gold(this,i,j,1,true);
					} else if (fl->board[i][j] == '8') { // merchant gold
						g = new Gold(this,i,j,4,true);
					} else { // fl->board[i][j] == '9'   dragon gold
						g = new Gold(this,i,j,6,false);

						// initialize dragon
						// position of dragon
						int dx = -1;
						int dy = -1;
						if (fl->board[i-1][j-1] == 'D') {
							dx = i-1;
							dy = j-1;
						} else if (fl->board[i-1][j] == 'D') {
							dx = i-1;
							dy = j;
						} else if (fl->board[i-1][j+1] == 'D') {
							dx = i-1;
							dy = j+1;
						} else if (fl->board[i][j-1] == 'D') {
							dx = i;
							dy = j-1;
						} else if (fl->board[i][j+1] == 'D') {
							dx = i;
							dy = j+1;
						} else if (fl->board[i+1][j-1] == 'D') {
							dx = i+1;
							dy = j-1;
						} else if (fl->board[i+1][j] == 'D') {
							dx = i+1;
							dy = j;
						} else if (fl->board[i+1][j] == 'D') {
							dx = i+1;
							dy = j+1;
						} else {					
							cerr << "Wrong dragon position! No Dragon around Dragon Hoard!" << endl;
						}

						if (dx != -1 && dy != -1) {
							d = new Dragon(this,dx,dy,i,j);
							dragon.push_back(d);
						} // inner if
					} // outter if

					gold.push_back(g);
					fl->board[i][j] = g->getSym();

			// initialize enemies
			} else if (fl->board[i][j] == 'E' || fl->board[i][j] == 'O' ||
		       fl->board[i][j] == 'M' || fl->board[i][j] == 'H' ||
		       fl->board[i][j] == 'W' || fl->board[i][j] == 'L') {
				
					if (fl->board[i][j] == 'E') {	
						e = new Elf(this,i,j); 
					} else if (fl->board[i][j] == 'O') {
						e = new Orc(this,i,j); 	
					} else if (fl->board[i][j] == 'M') {
						e = new Merchant(this,i,j);	
					} else if (fl->board[i][j] == 'H') {
						e = new Human(this,i,j);			
					} else if (fl->board[i][j] == 'W') {
						e = new Dwarf(this,i,j);
					} else if (fl->board[i][j] == 'L') {
						e = new Halfling(this,i,j);
					} // inner if

					enemy.push_back(e);

			} // if
		} // inner for
	} // outter for
}

void Game::p_movable(int x, int y) { 
	if (fl->board[x][y] == '\\') { // stairs
		Game::nextfloor();
		if (cur_floor <= 5)
		cout << "You are on " << cur_floor <<" floor" << endl;
	} else {

		int index = 0;
		for (int i = 0; i < gold.size(); ++i) {
			if (x == gold.at(i)->getX() && y == gold.at(i)->getY()) {
				index = i;
				break;
			} // if
		} // for
	
		if (fl->board[x][y] == '.' || 
			fl->board[x][y] == '+' ||
			fl->board[x][y] == '#' || 
			(fl->board[x][y] == 'G')) {
				
				fl->board[p->getX()][p->getY()] = p->getPrev();

				if (fl->board[x][y] == 'G' && gold.at(index)->getPickable()) {
					p->setGold(p->getGold() + gold.at(index)->getValue());
					cout << "You got " << gold.at(index)->getValue() << " gold" << endl;
					delete gold.at(index);
					gold.erase(gold.begin()+index);
					p->setPrev('.');
				} else { 
					if (fl->board[x][y] == 'G') {
						cout << "You cannot take the money away!" << endl;	
						cout << "Dragon is protecting it! Beat the dragon first!!!" << endl;
					}
					p->setPrev(fl->board[x][y]);
				} // if

			cout << "You were standing at " << p->getX() << ", " << p->getY() << endl;

				p->setX(x);
				p->setY(y);
				fl->board[x][y] = p->getSym();
				
			cout << "You are now standing at " << p->getX() << ", " << p->getY() << endl;
		
		} else {
			cout << "Watch your step!!! You cannot go there!!!" << endl;
		} // inner if
	} // outter if
}


bool Game::stairs_diff_chamber(int x, int y) {
	int difference = ((p->getX()-x)*(p->getX()-x) +
					  (p->getY()-y)*(p->getY()-y));
	if (difference <= 900) return false;
	return true;
}

void Game::init_stairs() {

	int x = rand() % 25;
	int y = rand() % 80;

	while (fl->board[x][y] != '.'
		|| (!Game::stairs_diff_chamber(x,y))) {
		x = rand() % 25;
		y = rand() % 80;
	} // while

	fl->board[x][y] = '\\';
}

void Game::init_gold() {
	for (int i = 0; i < 10; ++i) {
		int prob = rand() % 8 + 1;

		int x = rand() % 25;
		int y = rand() % 80;

		while (fl->board[x][y] != '.') {
			x = rand() % 25;
			y = rand() % 80;
		} // while

		Gold *g;
		if (prob == 1) { // dragon hoard
			g = new Gold(this,x,y,6,false);

			// position of dragon
			int dx = -1;
			int dy = -1;
			if (fl->board[x-1][y-1] == '.') {
				dx = x-1;
				dy = y-1;
			} else if (fl->board[x-1][y] == '.') {
				dx = x-1;
				dy = y;
			} else if (fl->board[x-1][y+1] == '.') {
				dx = x-1;
				dy = y+1;
			} else if (fl->board[x][y-1] == '.') {
				dx = x;
				dy = y-1;
			} else if (fl->board[x][y+1] == '.') {
				dx = x;
				dy = y+1;
			} else if (fl->board[x+1][y-1] == '.') {
				dx = x+1;
				dy = y-1;
			} else if (fl->board[x+1][y] == '.') {
				dx = x+1;
				dy = y;
			} else if (fl->board[x+1][y+1] == '.') {
				dx = x+1;
				dy = y+1;
			} else {
				cerr << "There is no available space for dragon" << endl;
			} // if

			if (dx != -1 && dy != -1) {
				Dragon *d = new Dragon(this,dx,dy,x,y);
				dragon.push_back(d);
				fl->board[dx][dy] = d->getSym();
			} // if

		} else if (prob >= 2 && prob <= 3) { // small gold
			g = new Gold(this,x,y,1,true);
		} else { // normal gold
			g = new Gold(this,x,y,2,true);
		}

		gold.push_back(g);
		fl->board[x][y] = g->getSym();
	}
}

void Game::init_poison() {
	for (int i = 0; i < 10; ++i) {

		int prob = rand() % 6 + 1;

		int x = rand() % 25;
		int y = rand() % 80;

		while (fl->board[x][y] != '.') {
			x = rand() % 25;
			y = rand() % 80;
		} // while

		Poison *po;
		if (prob == 1) { // pos atk
			po = new Poison(this,x,y,5,"attack",true);
		} else if (prob == 2) { // neg atk
			po = new Poison(this,x,y,5,"attack",false);
		} else if (prob == 3) { // pos def
			po = new Poison(this,x,y,5,"defence",true);
		} else if (prob == 4) { // neg def
			po = new Poison(this,x,y,5,"defence",false);
		} else if (prob == 5) { // pos hp
			po = new Poison(this,x,y,10,"hp",true);
		} else { // neg hp
			po = new Poison(this,x,y,10,"hp",false);
		}

		poison.push_back(po);
		fl->board[x][y] = po->getSym();
	}
}

void Game::init_enemy() {
	for (int i = 0; i < 20; ++i) {
		
		int prob = rand() % 18 + 1;
		
		int x = rand() % 25;
		int y = rand() % 80;

		while (fl->board[x][y] != '.') {
			x = rand() % 25;
			y = rand() % 80;
		} // while

		Enemy *e;
		if (prob >= 1 && prob <= 2) {	
			e = new Elf(this,x,y); 
		} else if (prob >= 3 && prob <=4) {
			e = new Orc(this,x,y); 
		} else if (prob >= 5 && prob <= 6) {
			e = new Merchant(this,x,y);	
		} else if (prob >= 7 && prob <= 10) {
			e = new Human(this,x,y);
		} else if (prob >= 11 && prob <= 13) {
			e = new Dwarf(this,x,y);
		} else { // prob >= 14 && prob <= 18
			e = new Halfling(this,x,y);
		}
		
		enemy.push_back(e);
		fl->board[x][y] = e->getSym();

	} // for
}

bool Game::one_block_rad(Enemy *e, Player *p) {
	if (((e->getX() == p->getX()-1) && (e->getY() == p->getY()-1)) ||
		((e->getX() == p->getX()-1) && (e->getY() == p->getY())) ||
		((e->getX() == p->getX()-1) && (e->getY() == p->getY()+1)) ||
		((e->getX() == p->getX()) && (e->getY() == p->getY()-1)) ||
		((e->getX() == p->getX()) && (e->getY() == p->getY()+1)) ||
		((e->getX() == p->getX()+1) && (e->getY() == p->getY()-1)) ||
		((e->getX() == p->getX()+1) && (e->getY() == p->getY())) ||
		((e->getX() == p->getX()+1) && (e->getY() == p->getY()+1))) {
		return true;
	} else {
		return false;
	} // if
}

void Game::e_move() { // move a vector of enemies
	for (int i = 0; i < enemy.size(); ++i) {
		if (!one_block_rad(enemy.at(i),p)) {

			int x, y;
			
			while (true) {

				int prob = rand() % 8 + 1;

				if (prob == 1) {
					x = enemy.at(i)->getX()-1;
					y = enemy.at(i)->getY()-1;
				} else if (prob == 2) {
					x = enemy.at(i)->getX()-1;
					y = enemy.at(i)->getY();
				} else if (prob == 3) {
					x = enemy.at(i)->getX()-1;
					y = enemy.at(i)->getY()+1;
				} else if (prob == 4) {
					x = enemy.at(i)->getX();
					y = enemy.at(i)->getY()-1;
				} else if (prob == 5) {
					x = enemy.at(i)->getX();
					y = enemy.at(i)->getY()+1;
				} else if (prob == 6) {
					x = enemy.at(i)->getX()+1;
					y = enemy.at(i)->getY()-1;
				} else if (prob == 7) {
					x = enemy.at(i)->getX()+1;
					y = enemy.at(i)->getY();
				} else { // (prob == 8) 
					x = enemy.at(i)->getX()+1;
					y = enemy.at(i)->getY()+1;
				}

				if (fl->board[x][y] != '.') continue; // cannot move there
				break; // not occupied

			} // while		

			fl->board[enemy.at(i)->getX()][enemy.at(i)->getY()] = enemy.at(i)->getPrev();
			fl->board[x][y] = enemy.at(i)->getSym();

			enemy.at(i)->setX(x);
			enemy.at(i)->setY(y);

		} //if
	} // for
}

void Game::p_move(string direction) { // move player
	if (direction == "no")  {
		p_movable(p->getX()-1,p->getY());
	} else if (direction == "so") {
		p_movable(p->getX()+1,p->getY());
	} else if (direction == "ea") {
		p_movable(p->getX(),p->getY()+1);
	} else if (direction == "we") {
		p_movable(p->getX(),p->getY()-1);
	} else if (direction == "ne") {
		p_movable(p->getX()-1,p->getY()+1);
	} else if (direction == "nw") {
		p_movable(p->getX()-1,p->getY()-1);
	} else if (direction == "se") {
		p_movable(p->getX()+1,p->getY()+1);
	} else if (direction == "sw") {
		p_movable(p->getX()+1,p->getY()-1);
	}
}

void Game::change_atk(int value, bool positive) {
	int tmp = value;
	if (!positive) tmp = - value;
	p->setAtkbuff(p->getAtkbuff()+tmp);
	if ((p->getAtk() + p->getAtkbuff()) < 0) { // cannot less than 0 
		p->setAtkbuff(-p->getAtk());
		cerr << "You have no attack ability right now" << endl;
	}
}

void Game::change_def(int value, bool positive) {
	int tmp = value;
	if (!positive) tmp = - value;
	p->setDefbuff(p->getDefbuff()+tmp);
	if ((p->getDef() + p->getDefbuff()) < 0) { // cannot less than 0 
		p->setDefbuff(-p->getDef());
		cerr << "You have no defence ability right now" << endl;
	}
}

void Game::change_hp(int value, bool positive) {
	int tmp = value;
	if (!positive) tmp = - value;

	p->setHP(p->getHP()+tmp);

	int cap;
	if (p->getName() == "Shade") {
		cap = 125;
	} else if (p->getName() == "Goblin") {
		cap = 110;
	} else if (p->getName() == "Troll") {
		cap = 120;
	} else if (p->getName() == "drow") {
		cap = 150;
	} else if (p->getName() == "Vampire") { // no cap
		cap = INT_MAX;
	}

	if (p->getHP() < 0) p->setHP(0); // lower limit
	if (p->getHP() > cap) { // upper limit
		p->setHP(cap);
		cerr << "You are full of blood!!!" << endl;
	} // if
}

bool Game::IsGameOver() {
	if (p->getHP() <= 0)  {
		cout << endl;
		cout << "Sorry !!! You are dead!" << endl;
		cout << "Try to type r to play again" << endl;
		cout << "Try to type q to quit" << endl;
		cout << endl;
		cout << "Total Gold : " << p->getGold() << endl;
		cout << "Total Enemies You Killed : " << num_enemy << endl;
		cout << "Total Score : " << (p->getGold() * 10 + num_enemy * 10) << endl;
		cout << endl;
		return true;
	} else if (cur_floor >= 5) {
		return true;
	}
	return false;
}

void Game::findnext(string direction, int &x, int &y) {
	if (direction == "no")  {
		x = p->getX()-1;
		y = p->getY();
	} else if (direction == "so") {
		x = p->getX()+1;
		y = p->getY();	
	} else if (direction == "ea") {
		x = p->getX();
		y = p->getY()+1;	
	} else if (direction == "we") {
		x = p->getX();
		y = p->getY()-1;	
	} else if (direction == "ne") {
		x = p->getX()-1;
		y = p->getY()+1;	
	} else if (direction == "nw") {
		x = p->getX()-1;
		y = p->getY()-1;	
	} else if (direction == "se") {
		x = p->getX()+1;
		y = p->getY()+1;
	} else if (direction == "sw") {
		x = p->getX()+1;
		y = p->getY()-1;
	} else {
		x = -1;
		y = -1;
	}
}

void Game::usepoison(string direction) {
	int x = 0;
	int y = 0;
	Game::findnext(direction,x,y);
	if (x == -1 && y == -1) {
		cerr << "Invalid move" << endl;
		return;
	}
	if (fl->board[x][y] != 'P') {
		cerr << "There is no poison at your " << direction << endl;
		return;
	}

	for (int i = 0; i < poison.size(); ++i) {
		if (poison.at(i)->getX() == x &&
		    poison.at(i)->getY() == y) {
			string tmp = poison.at(i)->getType();

			int p_value = poison.at(i)->getValue();
			if (p->getName() == "Drow") p_value = p_value * 1.5;
			if (tmp == "attack" || tmp == "defence" || tmp == "hp") {
				if (tmp == "attack") {
					Game::change_atk(p_value,poison.at(i)->getPositive());
				} else if (tmp == "defence") {
					Game::change_def(p_value,poison.at(i)->getPositive());
				} else { // (tmp == "hp")
					Game::change_hp(p_value,poison.at(i)->getPositive());
				} // inner if
				cout << "How was that " << ((poison.at(i)->getPositive()) ? "positive" : "negative") << " " << tmp << " poison taste? :)" << endl;	
				// remove from floor board
				fl->board[x][y] = '.';
			} else {
				cerr << "INVALID POISON" << endl;
			} // inner if
			break;
		} // outter if
	} // for

}

void Game::enemy_dead(Enemy *e, int index) {
	if (e->getHP() <= 0) {
		fl->board[enemy.at(index)->getX()][enemy.at(index)->getY()] = '.';

		cout << e->getName() << " is dead! You kill it!! How dare you!!!" << endl;
		cout << "Great job!!!" << endl;

		if (p->getName() == "Goblin") p->setGold(p->getGold()+5);
		if (e->getName() == "Human") {
			int x = e->getX();
			int y = e->getY();

			delete enemy.at(index);
			enemy.erase(enemy.begin()+index);

			// first pile dropped at the human position
			Gold *g1 = new Gold(this,x,y,2,true);
			gold.push_back(g1);
			fl->board[x][y] = g1->getSym(); 

			// position of second gold
			int dx = -1;
			int dy = -1;
			if (fl->board[x-1][y-1] == '.') {
				dx = x-1;
				dy = y-1;
			} else if (fl->board[x-1][y] == '.') {
				dx = x-1;
				dy = y;
			} else if (fl->board[x-1][y+1] == '.') {
				dx = x-1;
				dy = y+1;
			} else if (fl->board[x][y-1] == '.') {
				dx = x;
				dy = y-1;
			} else if (fl->board[x][y+1] == '.') {
				dx = x;
				dy = y+1;
			} else if (fl->board[x+1][y-1] == '.') {
				dx = x+1;
				dy = y-1;
			} else if (fl->board[x+1][y] == '.') {
				dx = x+1;
				dy = y;
			} else if (fl->board[x+1][y+1] == '.') {
				dx = x+1;
				dy = y+1;
			} else {
				cerr << "There is no available space for second pile of normal gold!" << endl;
				cerr << "A normal pile of gold has been automatically added to you!" << endl;
				p->setGold(p->getGold()+2);
			} // if

			if (dx != -1 && dy != -1) {
				Gold *g2 = new Gold(this,e->getX(),e->getY(),2,true);
				gold.push_back(g2);
				fl->board[dx][dy] = g2->getSym();
			} // if

		} else if (e->getName() == "Merchant") {
			int x = e->getX();
			int y = e->getY();

 			delete enemy.at(index);
			enemy.erase(enemy.begin()+index);

			Gold *g = new Gold(this,x,y,4,true);
			gold.push_back(g);

			fl->board[x][y] = g->getSym();
		} else {
			int prob = rand() % 2 + 1;
			if (prob == 1) { // small gold
				p->setGold(p->getGold()+1);
			} else {
				p->setGold(p->getGold()+2);
			}
			cout << "You got " << prob << " gold" << endl;
			
			int x = e->getX();
			int y = e->getY();
 			delete enemy.at(index);
			enemy.erase(enemy.begin()+index);

			fl->board[x][y] = '.';
		}
		++num_enemy;
	}
}

void Game::dragon_dead(Dragon *d, int index) {
	if (d->getHP() <= 0) {
		fl->board[dragon.at(index)->getX()][dragon.at(index)->getY()] = '.';

		cout << d->getName() << " is dead! You can steal that dragon hoard!!!" << endl;

		for (int i = 0; i < gold.size(); ++i) {
			if (gold.at(i)->getX() == d->getGoldX() &&
				gold.at(i)->getY() == d->getGoldY()) {
					gold.at(i)->setPickable(true);
					break;
			} // if
		} // for
	
		delete dragon.at(index);
		dragon.erase(dragon.begin()+index);
		++num_enemy;
	} // if
}


void Game::e_attack() {
	int endtime = time(NULL);
	if ((endtime - starttime) <= 20) {
		cout << endl;
		cout << "Time left : " << 20-(endtime-starttime) << " seconds" << endl;
		if ((20-(endtime-starttime)) <= 0) cout << "Times up! You are no undefeated any more!" << endl;
		cout << endl;
		return;
	} // if

	for (int i = 0; i < enemy.size(); ++i) {
		if (enemy.at(i)->getName() == "Merchant") {

			// BONUS PART!!!
			if (!hostile && one_block_rad(enemy.at(i),p) && !bought && bonus) {
				cout << "Can I help you, sir?" << endl;
				cout << "Clairvoyance($5)：All poisons on current floor are visible to you!" << endl;
				cout << "Undefeated($10): All enemies (except for dragon) stop hiiting you in 20 seconds" << endl;
				cout << "Type cl for Clairvoyance" << endl;
				cout << "Type un for Undefeated" << endl;
				string trans;
				cin >> trans;
				if (trans != "un" && trans != "cl") {
					cout << "Are you sure? You will regret!!!" << endl;
					continue;
				}
				if (trans == "un") {
					if (p->getGold() < 10) {
						cout << "Sorry, you are not afford!" << endl;
						if (p->getGold() >= 5) {
							cout << "You can try Clairvoyance" << endl;
							cin >> trans;
						}
					} else {
						p->setGold(p->getGold()-10);
						starttime = time(NULL);
						cout << endl;
						cout << "You are 20 seconds undefeated from now on!" << endl;
						cout << "Come on! Beat all beasts!" << endl;
						cout << endl;
						bought = true;
					}
				}
				if (trans == "cl") {
					if (p->getGold() < 5) {
						cout << "Sorry, you don't have enough money!" << endl;
						cout << "See you next time" << endl;
					} else {
						p->setGold(p->getGold()-5);
						for (int i = 0; i < poison.size(); ++i) {
							Poison *tmp = poison.at(i);
							if (tmp->getType() == "hp" && tmp->getPositive() == true) {
								fl->board[tmp->getX()][tmp->getY()] = '0';
							} else if (tmp->getType() == "attack" && tmp->getPositive() == true) {
								fl->board[tmp->getX()][tmp->getY()] = '1';
							} else if (tmp->getType() == "defence" && tmp->getPositive() == true) {
								fl->board[tmp->getX()][tmp->getY()] = '2';
							} else if (tmp->getType() == "hp" && tmp->getPositive() == false) {
								fl->board[tmp->getX()][tmp->getY()] = '3';
							} else if (tmp->getType() == "attack" && tmp->getPositive() == false) {
								fl->board[tmp->getX()][tmp->getY()] = '4';
							} else if (tmp->getType() == "defence" && tmp->getPositive() == false) {
								fl->board[tmp->getX()][tmp->getY()] = '5';
							} else {
								cerr << "Invalid Poison" << endl;
							} // if
						} // for
						cout << endl;
						cout << "0 : Restore health (RH): restore up to 10 HP (cannot exceed maximum prescribed by race)" << endl;
						cout << "1 : Boost Atk (BA): increase ATK by 5" << endl;
						cout << "2 : Boost Def (BD): increase Def by 5" << endl;
						cout << "3 : Poison health (PH): lose up to 10 HP (cannot fall below 0 HP)" << endl;
						cout << "4 : Wound Atk (WA): decrease Atk by 5" << endl;
						cout << "5 : Wound Def (WD): decrease Def by 5" << endl;
						cout << endl;
						bought = true;
					} // inner if
				}
			}
			// BONUS ENDS

			if (!hostile) continue; // merchant is not hostile yet
		}
		if (one_block_rad(enemy.at(i),p)) {
			int prob = rand() % 10;
			if (prob >= 0 && prob <= 4) {
				cout << endl;
				cout << enemy.at(i)->getName() << " missed hitting you!" << endl;
			} else {
				enemy.at(i)->Attack(*p);
			} // inner if
		} // outter if
	} // for
}


void Game::d_attack() {
	for (int i = 0 ; i < dragon.size(); ++i) {
		int x = dragon.at(i)->getGoldX();
		int y = dragon.at(i)->getGoldY();
		bool close_to_gold = false;

		if (((x == p->getX()-1) && (y == p->getY()-1)) ||
			((x == p->getX()-1) && (y == p->getY())) ||
			((x == p->getX()-1) && (y == p->getY()+1)) ||
			((x == p->getX()) && (y == p->getY()-1)) ||
			((x == p->getX()) && (y == p->getY()+1)) ||
			((x == p->getX()+1) && (y == p->getY()-1)) ||
			((x == p->getX()+1) && (y == p->getY())) ||
			((x == p->getX()+1) && (y == p->getY()+1))) close_to_gold = true;

		if (one_block_rad(dragon.at(i),p) || close_to_gold) {
			int prob = rand() % 2;
			if (prob == 0) {
				cout << endl;
				cout << dragon.at(i)->getName() << " missed hitting you!" << endl;
			} else {
				dragon.at(i)->Attack(*p);
			} // inner if
		} // if
	} // for
}

void Game::attack(string direction) {
	int x = 0;
	int y = 0;
	Game::findnext(direction,x,y);
	if (x == -1 && y == -1) {
		cerr << "Invalid move" << endl;
		return;
	}
	if (fl->board[x][y] != 'W' && fl->board[x][y] != 'D' &&
		fl->board[x][y] != 'H' && fl->board[x][y] != 'L' &&
		fl->board[x][y] != 'E' && fl->board[x][y] != 'O' &&
		fl->board[x][y] != 'M') {
			cerr << "There is no enemy at your " << direction << endl;
			return;
	}
	int index = 0;

	if (fl->board[x][y] == 'D') {
		for (int i = 0; i < dragon.size(); ++i) {
			if(x == dragon.at(i)->getX() && y == dragon.at(i)->getY()) {
				index = i;
				break;
			} // if
		} // for

		p->Attack(*dragon.at(index));
		cout << endl;
		cout << "You are fearlessly hitting " << dragon.at(index)->getName() << endl;
		Game::dragon_dead(dragon.at(index),index);

	} else {
		for (int i = 0; i < enemy.size(); ++i) {
			if (x == enemy.at(i)->getX() && y == enemy.at(i)->getY()) {
				index = i;
				break;
			} // if
		} // for

		p->Attack(*enemy.at(index));
		cout << endl;
		if (enemy.at(index)->getName() == "Merchant") {
			if (!hostile) {
				cout << "Wow!!! You are in trouble!!!" << endl;
				cout << "You hit " << enemy.at(index)->getName() << "!!!" << endl;
				cout << "Watch out!!! All " << enemy.at(index)->getName()
					 << "s are gonna start attack you!" << endl;
			} // if
			hostile = true; // merchant is hostile from now
		} else {
			cout << "You are hitting that " << enemy.at(index)->getName() << endl;
		} // if
		Game::enemy_dead(enemy.at(index),index);
	} // if
}

void Game::nextfloor() {
	++cur_floor;
	if (cur_floor == 6) {
		cout << "You have completed the game!" << endl;
		cout << "Time to buy full version!!!" << endl;
	} else {
		p->setAtkbuff(0);
		p->setDefbuff(0);
		Game::clearfloor();
		fl = new Floor;
		fl->init(file_name, cur_floor);
		if (file_name == "default.txt") { // default file
			int x = rand() % 25;
			int y = rand() % 80;
			while (fl->board[x][y] != '.') {
				x = rand() % 25;
				y = rand() % 80;
			} // while
			p->setX(x);
			p->setY(y);
			fl->board[x][y] = p->getSym();
			Game::init_stairs();
			Game::init_poison();
			Game::init_gold();
			Game::init_enemy();
		} else { // file provided
			for (int i = 0; i < fl->getHeight(); ++i) {
				for (int j = 0; j < fl->getWidth(); ++j) {
					if (fl->board[i][j] == '@') {
						p->setX(i);
						p->setY(j);
						fl->board[i][j] = p->getSym();
					} // if
				} // inner for
			} // outter for
			Game::chooseobject_file();
		} // inner if
	} // outter if
}

void Game::display_stats() {
	if (p->getHP() <= 0) p->setHP(-10000000);
	cout << "Race : " << p->getName() << "                           ";
	cout << "                              Floor " << cur_floor << endl; 
	cout << "Gold : " << p->getGold() << endl;
	cout << "HP : " << p->getHP() << endl;
	cout << "Atk : " << p->getAtk()+p->getAtkbuff() << endl;
	cout << "Def : " << p->getDef()+p->getDefbuff() << endl;
}

void Game::display() {
	fl->display();
	Game::display_stats();
}

void Game::display_ending() {
	cout << endl;
	cout << "Remember subscribe us on Youtube or like us on Facebook!" << endl;
	cout << "Welcome to play again!" << endl;
	cout << endl;
                                                                                           
	cout << " _|_|_|_|_|  _|                            _|             _|      _|                   " << endl;
	cout << "     _|      _|_|_|      _|_|_|  _|_|_|    _|  _|           _|  _|    _|_|    _|    _| " << endl;
	cout << "     _|      _|    _|  _|    _|  _|    _|  _|_|               _|    _|    _|  _|    _| " << endl;
	cout << "     _|      _|    _|  _|    _|  _|    _|  _|  _|             _|    _|    _|  _|    _| " << endl;
	cout << "     _|      _|    _|    _|_|_|  _|    _|  _|    _|           _|      _|_|      _|_|_| " << endl;                                                                     cout << endl;
}

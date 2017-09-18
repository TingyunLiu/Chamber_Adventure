#ifndef _GAME_H_
#define _GAME_H_
#include <string>
#include <vector>

class Floor;
class Player;
class Enemy;
class Item;
class Poison;
class Gold;
class Dragon;

class Game {
	Floor *fl; // pointer to the currect floor
	Player *p; // pointer to the player character
	std::vector<Enemy *> enemy; // a vector of enemy
	std::vector<Poison *> poison; // a vector of poison
	std::vector<Dragon *> dragon; // a vector of dragon
	std::vector<Gold *> gold; // a vector of gold
	const std::string file_name; // store the file name
	int cur_floor; // keep track of the current floor
	int num_enemy; // keep track of number of enemy
	bool hostile; // merchant's hostile
	bool bonus; // bonus controller
	public:
		Game(std::string, bool); // ctor take in file_name
		~Game(); // dtor
		std::string getFile_name(); // getter for file name
		Player* getPC(); // getter for the player character
		void clearfloor(); // clear the current cloor
		void chooseplayer(std::string); // choose the player character race from default
		void chooseplayer_file(std::string); // choose the player character race from other files
		void chooseobject_file(); // initialize all poison, gold, enemies if read from other files
		bool IsGameOver(); // Check whether the player is dead or won
		void init_stairs(); // initialize stairway
		bool one_block_rad(Enemy *,Player *); // check whether the player is within one block radius of enemy
		bool stairs_diff_chamber(int,int); // place stairway in different chamber with player
		void init_enemy(); // initialize enemies
		void init_poison(); // initialize posions
		void init_gold(); // initialize golds
		void dragon_dead(Dragon*,int); // check whether the dragon is dead
		void p_move(std::string); // move player
		void p_movable(int,int); // check whether player is movable with designated direction
		void e_move(); // move a vector of enemies
		void findnext(std::string,int &,int &); // find the next available space around the coordnates
		void change_atk(int,bool); // updates player's attack buff value
		void change_def(int,bool); // updates player's defence buff value
		void change_hp(int,bool); // updates player's hp
		void usepoison(std::string); // use poison
		void attack(std::string); // attack a enemy at specific direction
		void e_attack(); // a vector of enemies check attack player
		void d_attack(); // a vector of dragons check attack player
		void enemy_dead(Enemy *, int); // check whether enemy is dead
		void nextfloor(); // go to next floor
		void display(); // display general info
		void display_stats(); // display player stats after each action
		void display_ending(); // display the ending info
};

#endif

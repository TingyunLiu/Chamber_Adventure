#include "game.h"
#include "sstream"
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


// BONUS CONTROLLER
// change false to true to make the bonus mode on
const bool bonus = true;



// welcome message and output player character races's properties and command manual
void welcome() {
	cout << endl;
	cout << "               .__" << endl;
    	cout << "__  _  __ ____ |  |   ____  ____   _____   ____" << endl;
    	cout << "\\ \\/ \\/ // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\ " << endl;
    	cout << " \\     /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/" << endl;
    	cout << "  \\/\\_/  \\___  >____/\\___  >____/|__|_|  /\\___  >" << endl;
    	cout << "             \\/          \\/            \\/     \\/" << endl;
    	cout << endl;

	cout << endl;
	cout << "Default player character is Shade" << endl;
	cout << "Your could choose your player character: s, d, v, g, t" << endl;
	cout << endl;

	cout << "Shade(s):" << endl;
	cout << "attack: 25,   defense: 25,   HP: 125" << endl;
	cout << endl;

	cout << "Drow(d):" << endl; 
	cout << "attack: 25,   defense: 15,   HP: 150" << endl; 
	cout << "All poison have their effect magnified by 1.5" << endl;
	cout << endl;

    	cout << "Vampire(v):" << endl; 
    	cout << "attack: 25,   defense: 25,   HP: 50" << endl;
	cout << "Gains 5 HP every successful attack and has no maximum HP" << endl;
	cout << endl;

    	cout << "Goblin(g):" << endl;
    	cout << "attack: 15,   defense: 20,   HP: 110" << endl;
	cout << "Steals 5 gold from every slain enemy" << endl;
	cout << endl;

    	cout << "Troll(t):" << endl; 
    	cout << "attack: 25,   defense: 15,   HP: 120" << endl;
	cout << "Regains 5 HP every turn" << endl;
	cout << endl;
	
	cout << "----------------------------------------------" << endl;
	cout << endl;
	cout << "Command Options :" << endl;
	cout << "no,ea,we,so,ne,nw,se,sw  are direction" << endl;
	cout << "u <direction> -- use poison" << endl;
	cout << "a <direction> -- attack enemy" << endl;
	cout << "r -- restart" << endl;
	cout << "q -- quit" << endl;
	cout << endl;
}

int main(int argv, char* argc[]) {
	srand(time(NULL));
	string file_name, command;
	bool choosed = false;

	// check if a file provided as an argument
	if (1 == argv) { // no file provided, read from default file
		file_name = "default.txt";
	} else { // file provided
		file_name = argc[1];
	} // if
		
	welcome();
	if (bonus) {
		cout << "*************" << endl;
		cout << "BONUS MODE ON" << endl;
		cout << "*************" << endl;
	} // if

	Game *game = new Game(file_name, bonus);

	while (true) {
		cin >> command;
		if (cin.eof() || command == "q") { // quit
			break;
		} else if (command == "r") { // restart
			delete game;
			game = new Game(file_name, bonus);
			welcome();
			choosed = false;
		} else if (command == "s" || command == "d" ||
				   command == "v" || command == "g" ||
			       command == "t") {
					if (choosed) {
						cout << endl;
						cout << "You have choosed your player" << endl;
						continue;
					} else {
						if (game->getFile_name() == "default.txt") {
							game->chooseplayer(command);
						} else {
							game->chooseplayer_file(command);
							game->chooseobject_file();
						}
						choosed = true;
						game->display();
					} //  inner if
		} else if (command == "u") {                   
            string pos;
            cin >> pos;
            game->usepoison(pos);
            game->d_attack();
            game->e_move();
            game->e_attack();
            game->display();  
        } else if (command == "a") {
            string pos;
            cin >> pos;
            game->attack(pos);
            game->d_attack();
            game->e_move();
            game->e_attack();
            game->display();
        } else if (command == "ea" || command == "no" ||
        		   command == "so" || command == "we" ||
        		   command == "ne" || command == "se" ||
        		   command == "nw" || command == "sw") {
		            if (choosed) {
						game->p_move(command);
						game->d_attack();
			 			game->e_move();
			 			game->e_attack();
					} else {
					    // default shade
						if (game->getFile_name() == "default.txt") {
							game->chooseplayer("s");
						} else {
							game->chooseplayer_file("s");		
							game->chooseobject_file();
						}
						choosed = true;
						game->p_move(command);
						game->d_attack();
		 				game->e_move();
		 				game->e_attack();
					} // inner if
					game->display();
		} else {
			cerr << "Invalid Command" << endl;
		} // outter if
		if (game->getPC() != NULL && game->IsGameOver()) continue;
	} // while
	if (game->getPC() != NULL) {
		game->display_ending();
	} else {
		cout << endl;
		cout << "Why don't you play?" << endl;
		cout << "Any advice to improve our game ? " << endl;
		cout << endl;
	}
	delete game;
	return 0;
}

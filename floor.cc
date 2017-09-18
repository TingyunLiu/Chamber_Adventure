#include "floor.h"
#include <iostream>
#include <string>
using namespace std;

Floor::Floor() : height(HEIGHT), width(WIDTH), floor_existed(false) { }

Floor::~Floor() { 
	Floor::clearfloor();
}

void Floor::clearfloor() {
	for (int i  = 0; i < height; ++i) {
		delete [] board[i];
	} // for
	delete [] board;
}

void Floor::init(string file, int cur_floor) {
	char tmp;
	ifstream myfile(file.c_str());
	Floor::openfile(file);

	int to_skip = width * height * cur_floor;
	// skips previous floors if needed
	for (int i = 0; i < to_skip; ++i) {
		myfile.get(tmp);
	}

	if(floor_existed) clearfloor();
	floor_existed = true;
	board = new char*[height];
	for (int i = 0; i < height; ++i) {
		board[i] = new char[width];
		for (int j = 0; j < width; ++j) {
			myfile.get(tmp);
			board[i][j] = tmp;
			/*
			if (tmp == '0' || tmp == '1' || tmp == '2' ||
			 tmp == '3' || tmp == '4' || tmp == '5') {
				board[i][j] = 'P'; // poison
			} else if (tmp == '6' || tmp == '7' ||
				tmp == '8' || tmp == '9') {
				board[i][j] = 'G'; // gold
			} else {
				board[i][j] = tmp;
			}
			*/
		} // inner for
	} // outer for

	Floor::closefile();
}

int Floor::getHeight() {
	return height;
}

int Floor::getWidth() {
	return width;
}

void Floor::openfile(string file) {
	f.open(file.c_str());
}

void Floor::closefile() {
	f.close();
}



void Floor::display() {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			cout << board[i][j];
		} // inner for
	} // outter for
}

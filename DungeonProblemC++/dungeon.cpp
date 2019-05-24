#include "dungeon.h"



dungeon::dungeon()
{
	std::vector<int> values;
	std::ifstream file("../matrix.ini");
	std::string temp;

	while (std::getline(file, temp)) {
		//Do with temp
		std::stringstream stream;
		std::string ch;
		stream << temp;
		int value = 0;
		while (!stream.eof()) {
			stream >> ch;
			std::stringstream(ch) >> value;
			values.push_back(value);
		}
	}
	row = sqrt(values.size());
	column = row;
	int x = 0;
	layout = new int* [row];
	for (int i = 0; i < column; i++) {
		layout[i] = new int[column];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			layout[i][j] = values[x];
			x++;
		}
	}
}


dungeon::~dungeon()
{
	for (int i = 0; i < column; ++i) {
		delete[] layout[i];
	}
	delete[] layout;
}


std::pair<int,int> dungeon::findPosition(int value) {
	auto position = std::make_pair(-1, -1);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (layout[i][j] == value) {
				position.first = i;
				position.second = j;
			}
		}
	}
	return position;
}


void dungeon::print() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			std::cout << layout[i][j] << "\t";
		}
		std::cout << "\n";
	}
}


bool dungeon::solve(int i, int j) {
	if (layout[i][j] == 9) {
		return true;
	}
	if (layout[i][j] == 1) {
		layout[i][j] = 0;
		if (i < row - 1) {
			if (solve(i + 1, j)) return true;
		}
		if (j < column - 1) {
			if (solve(i, j + 1)) return true;
		}
		if (i > 0) {
			if (solve(i - 1, j)) return true;
		}
		if (j > 0) {
			if (solve(i, j - 1)) return true;
		}
	}
	return false;
}


bool dungeon::finish(int value) {
	if (value == 9) {
		return true;
	}
	else {
		return false;
	}
}


bool dungeon::canMove(int value) {
	if (value == 1) {
		return true;
	}
	else {
		return false;
	}
}


bool dungeon::solve2(int i, int j) {
	bool done = true;
	while (done) {
		if (canMove(layout[i][j])) {
			if (i < row - 1 && (canMove(layout[i + 1][j]) || finish(layout[i + 1][j]))) {
				layout[i][j] = 0;
				i++;
			}
			else if (j < column - 1 && (canMove(layout[i][j + 1]) || finish(layout[i][j + 1]))) {
				layout[i][j] = 0;
				j++;
			}
			else if (i > 0 && (canMove(layout[i - 1][j]) || finish(layout[i - 1][j]))) {
				layout[i][j] = 0;
				i--;
			}
			else if (j > 0 && (canMove(layout[i][j - 1]) || finish(layout[i][j - 1]))) {
				layout[i][j] = 0;
				j--;
			}
			else {
				return false;
			}
		}
		if (finish(layout[i][j])) {
			done = false;
		}
	}
	return !done;
}

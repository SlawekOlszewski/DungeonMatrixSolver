#include <utility>
#include <iostream>
#include "dungeon.h"


int main() {

	dungeon game;

	int choice = 0;
	game.print();
	std::pair<int, int> position = game.findPosition(9);
	std::cout << "Position of exit is: (" << position.first << ", " << position.second << ")\n";
	std::cout << "Choose algorithm 1 or 2: ";
	std::cin >> choice;
	switch (choice) {
		case 1:
			//in this algorithms the default starting point is set to (0,0), you can change it by passing arguments to method
			std::cout << "The path was found: " << game.solve() << "\n";
			break;
		case 2:
			std::cout << "The path was found:  " << game.solve2() << "\n";
			break;
	}
	return 0;
}
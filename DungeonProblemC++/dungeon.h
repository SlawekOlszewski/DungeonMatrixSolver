#pragma once
#include <utility>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
class dungeon
{
public:
	dungeon();
	~dungeon();
	std::pair<int, int> findPosition(int value);
	void print();
	bool solve(int i = 0, int j = 0);
	bool solve2(int i = 0, int j = 0);
private:
	int row;
	int column;
	int** layout;
	bool finish(int value);
	bool canMove(int value);
};


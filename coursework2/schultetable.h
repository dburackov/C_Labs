#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "button.h"

using namespace std;

class SchulteTable {
private:
	int current = 1;
	int size;
	std::vector<Button> table;

public:
	SchulteTable(int);
	void resetColor();
	void cleaked(RenderWindow&);
	bool end();
	void display(RenderWindow&);
};


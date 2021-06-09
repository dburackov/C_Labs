#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "button.h"

class LineOfSight{
private:
	int number = 15;
	int correct = 0;
	int total = 0;
	int size;
	bool diff;
	std::vector<Button> table;
public:
	LineOfSight(int);
	void pressed();
	void update();
	void display(RenderWindow&);
	bool end();
	int result();
};


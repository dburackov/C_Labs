#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "button.h"

using namespace sf;

class RunningWords {
private:
	std::vector<std::string> vocabulary;
	std::vector<std::pair<Button, std::string>> words;
	int index = 0;
	int position = 0;
public:
	RunningWords();
	void display(RenderWindow&);
	void update();
	void displayAll(RenderWindow&);
	void check(RenderWindow&);
};


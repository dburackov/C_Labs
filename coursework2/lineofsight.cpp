#include "lineofsight.h"
#include <ctime>

#define START_POSITION 200

LineOfSight::LineOfSight(int size) : size(size) {
	srand(time(0));
	for (int i = 0; i < size * size; ++i) {
		table.push_back(Button("images/button.png", 50, 50, START_POSITION + 50 * (i % size), START_POSITION + 50 * (i / size)));
		table.back().setText(std::to_string(std::rand() % 26 + 65), 30, Color::Blue);
	}
}

void LineOfSight::update() {
	int ch1 = std::rand() % 26 + 65;
	int ch2 = ch1;
	diff = false;
	if (std::rand() % 2) {
		ch2 = std::rand() % 26 + 65;
		if (ch2 != ch1) {
			diff = true;
			++total;
		}
	}
	table[size / 2].setText(std::to_string(ch1), 30, Color::Blue);
	table[size / 2 * size].setText(std::to_string(ch1), 30, Color::Blue);
	table[size * (size / 2 + 1) - 1].setText(std::to_string(ch1), 30, Color::Blue);
	table[size * size - size / 2 - 1].setText(std::to_string(ch1), 30, Color::Blue);
	switch (std::rand() % 4) {
	case 0:
		table[size / 2].setText(std::to_string(ch2), 30, Color::Blue);
		break;
	case 1:
		table[size / 2 * size].setText(std::to_string(ch2), 30, Color::Blue);
		break;
	case 2:
		table[size / 2 * size].setText(std::to_string(ch2), 30, Color::Blue);
		break;
	case 3:
		table[size * size - size / 2 - 1].setText(std::to_string(ch2), 30, Color::Blue);
		break;
	}
	--number;
}

void LineOfSight::pressed() {
	if (diff) {
		++correct;
	} else {
		--correct;
	}
}

bool LineOfSight::end() {
	return number == 0;
}

int LineOfSight::result() {
	return correct * 100 / total;
}

void LineOfSight::display(RenderWindow& window) {
	for (int i = 0; i < size * size; ++i) {
		table[i].draw(window);
	}
}
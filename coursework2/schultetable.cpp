#include "schultetable.h"
#include <ctime>

#define START_POSITION 200

SchulteTable::SchulteTable(int size) : size(size) {
	srand(time(0));
	int* arr = new int[size * size];
	for (int i = 0; i < size * size; ++i) {
		arr[i] = i + 1;
	}
	for (int i = 0; i < size * size; ++i) {
		std::swap(arr[i], arr[std::rand() % (size * size)]);
	}
	for (int i = 0; i < size * size; ++i) {
		table.push_back(Button("images/button.png", 50, 50, START_POSITION + 50 * (i % size), START_POSITION + 50 * (i / size)));
		table.back().setText(std::to_string(arr[i]), 30, Color::Blue);
		table.back().id = arr[i];
	}
}

void SchulteTable::resetColor() {
	for (int i = 0; i < size * size; ++i) {
		table[i].setColor(Color::White);
	}
}

void SchulteTable::cleaked(RenderWindow& window) {
	for (int i = 0; i < size * size; ++i) {
		if (table[i].cleaked(window)) {
			if (table[i].id == current) {
				table[i].setColor(Color::Green);
				++current;
			} else {
				table[i].setColor(Color::Red);
			}
		}
	}
}

void SchulteTable::display(RenderWindow& window) {
	for (int i = 0; i < size * size; ++i) {
		table[i].draw(window);
	}
}

bool SchulteTable::end() {
	return current > size * size;
}
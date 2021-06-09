#include "runningwords.h"
#include <fstream>
#include <ctime>

#define START_POSITION 200

RunningWords::RunningWords() {
	std::ifstream input("words.txt");
	std::string word;
	while (input >> word) {
		vocabulary.push_back(word);
	}
	srand(time(0));
	for (int i = 0; i < 6; ++i) {
		words.push_back(std::make_pair(Button("images/button.png", 100, 40, 0, 0),
		vocabulary[std::rand() % vocabulary.size()]));
		words.back().first.setText(words.back().second, 30, Color::Blue);
	}
}

void RunningWords::display(RenderWindow& window) {
	words[index].first.setPosition(START_POSITION + position / 3 * 100, START_POSITION + position % 3 * 40);
	words[index].first.draw(window);
}

void RunningWords::update() {
	index = (index + 1) % words.size();
	position = (position + 1) % 9;
}

void RunningWords::check(RenderWindow& window) {
	bool result = true;
	bool display = false;
	for (int i = 0; i < words.size(); ++i) {
		if (words[i].first.cleaked(window) && i != index) {
			result = false;
		}
		if (words[i].first.cleaked(window)) {
			display = true;
		}
		if (words[i].first.mouseIn(window)) {
			words[i].first.setColor(Color::Blue);
		}
		words[i].first.draw(window);
	}

	if (display) {
		std::string answer = result ? "Correct" : "Uncorrect";
		Font font;
		Text text;
		font.loadFromFile("font.ttf");
		text.setCharacterSize(30);
		text.setFont(font);
		text.setString(answer);
		text.setPosition(350, 550);
		text.setStyle(Text::Bold);
		window.draw(text);
	}
}

void RunningWords::displayAll(RenderWindow& window) {
	for (int i = 0; i < words.size(); ++i) {
		words[i].first.setColor(Color::White);
		words[i].first.setPosition(START_POSITION + i / 3 * 100, START_POSITION + i % 3 * 40);
		words[i].first.draw(window);
	}
}


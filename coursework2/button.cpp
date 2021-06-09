#include "button.h"
using namespace sf;

Button::Button(std::string file, int w, int h, int x, int y) : width(w), height(h), posX(x), posY(y), file(file) {
	texture.loadFromFile(file);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	sprite.setScale(w / sprite.getGlobalBounds().width, h / sprite.getGlobalBounds().height);
}

void Button::setPosition(int x, int y) {
	sprite.setPosition(x, y);
	text.setPosition(x, y);
	posX = x;
	posY = y;
}

void Button::setColor(Color color) {
	sprite.setColor(color);
}

void Button::draw(RenderWindow& window) {
	window.draw(sprite);
	window.draw(text);
}

bool Button::mouseIn(RenderWindow& window) {
	return IntRect(posX, posY, width, height).contains(Mouse::getPosition(window));
}

bool Button::cleaked(RenderWindow& window) {
	return mouseIn(window) && Mouse::isButtonPressed(Mouse::Left);
}

void Button::setText(std::string content, int size, Color color) {
	font.loadFromFile("font.ttf");
	text.setCharacterSize(size);
	text.setFont(font);
	text.setString(content);
	text.setPosition(posX, posY);
	text.setStyle(Text::Bold);
	text.setFillColor(color);
}

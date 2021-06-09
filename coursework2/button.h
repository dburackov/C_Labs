#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Button {
private:
	Texture texture;
	Sprite sprite;
	Font font;
	Text text;
	int width;
	int height;
	int posX;
	int posY;
	std::string file;
public:
	Button(std::string, int, int, int, int);
	void setPosition(int, int);
	void setColor(Color);
	void draw(RenderWindow&);
	bool mouseIn(RenderWindow&);
	bool cleaked(RenderWindow&);
	void setText(std::string, int, Color);
	int id;
	Button& operator=(const	Button& button) {
		width = button.width;
		height = button.height;
		posX = button.posX;
		posY = button.posY;
		id = button.id;
		file = button.file;
		texture.loadFromFile(file);
		sprite.setTexture(texture);
		sprite.setPosition(posX, posY);
		sprite.setScale(width / sprite.getGlobalBounds().width, height / sprite.getGlobalBounds().height);
		font.loadFromFile("font.ttf");
		text.setCharacterSize(button.text.getCharacterSize());
		text.setFont(font);
		text.setString(button.text.getString());
		text.setPosition(posX, posY);
		text.setStyle(Text::Bold);
		text.setFillColor(button.text.getFillColor());
		return *this;
	}
	Button(const Button& button) {
		width = button.width;
		height = button.height;
		posX = button.posX;
		posY = button.posY;
		id = button.id;
		file = button.file;
		texture.loadFromFile(file);
		sprite.setTexture(texture);
		sprite.setPosition(posX, posY);
		sprite.setScale(width / sprite.getGlobalBounds().width, height / sprite.getGlobalBounds().height);
		font.loadFromFile("font.ttf");
		text.setCharacterSize(button.text.getCharacterSize());
		text.setFont(font);
		text.setString(button.text.getString());
		text.setPosition(posX, posY);
		text.setStyle(Text::Bold);
		text.setFillColor(button.text.getFillColor());
	}
};


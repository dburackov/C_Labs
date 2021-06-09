#include <SFML/Graphics.hpp>
#include "button.h"
#include "schultetable.h"
#include "lineofsight.h"
#include "runningwords.h"
#include <Windows.h>
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    Button menu1("images/1schultetable.png", 400, 100, 200, 30);
    Button menu2("images/2lineofsight.png", 400, 100, 200, 130);
    Button menu3("images/3runningwords.png", 400, 100, 200, 230);
    Button menu4("images/4exit.png", 400, 100, 200, 330);
    Button x5("images/button.png", 70, 70, 30, 30);
    x5.setText("5x5", 50, Color::White);
    Button x7("images/button.png", 70, 70, 110, 30);
    x7.setText("7x7", 50, Color::White);
    Button error("images/button.png", 100, 70, 350, 30);
    error.setText("Error", 50, Color::White);
    Button start("images/button.png", 100, 70, 350, 30);
    start.setText("Start", 50, Color::White);

    int index = 0;
    bool menu = true;
    bool schulteTable = false;
    bool lineOfSight = false;
    bool runningWords = false;
    bool display = false;
    bool unpressed = false;
    bool displayAnswer = false;
    int sizeTable = 0;
    SchulteTable* schTable = nullptr;
    Clock clock;
    LineOfSight* sight = nullptr;
    RunningWords *runword = nullptr;
    int timer = 0;
    int old = 0;

    while (window.isOpen()) {
        window.clear(Color(129, 181, 223));
        if (menu) {
            menu1.setColor(Color::White);
            menu2.setColor(Color::White);
            menu3.setColor(Color::White);
            menu4.setColor(Color::White);
            index = 0;
            if (menu1.mouseIn(window)) {
                menu1.setColor(Color::Blue);
                index = 1;
            }
            if (menu2.mouseIn(window)) {
                menu2.setColor(Color::Blue);
                index = 2;
            }
            if (menu3.mouseIn(window)) {
                menu3.setColor(Color::Blue);
                index = 3;
            }
            if (menu4.mouseIn(window)) {
                menu4.setColor(Color::Blue);
                index = 4;
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                switch (index) {
                case 1:
                    menu = false;
                    schulteTable = true;
                    break;
                case 2:
                    menu = false;
                    lineOfSight = true;
                    break;
                case 3:
                    menu = false;
                    runningWords = true;
                    break;
                case 4:
                    window.close();
                    break;
                }
            } 
            menu1.draw(window);
            menu2.draw(window);
            menu3.draw(window);
            menu4.draw(window);
        } else if (schulteTable) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                menu = true;
                schulteTable = false;
                if (schTable != nullptr) {
                    delete schTable;
                    schTable = nullptr;
                    display = false;
                }
            }
            x5.setColor(Color::White);
            x7.setColor(Color::White);
            if (x5.mouseIn(window)) {
                x5.setColor(Color::Blue);
            }
            if (x7.mouseIn(window)) {
                x7.setColor(Color::Blue);
            }
            if (x5.cleaked(window) && !display) {
                display = true;
                if (schTable != nullptr) {
                    delete schTable;
                    schTable = nullptr;
                }
                schTable = new SchulteTable(5);
                clock.restart();
            } 
            if (x7.cleaked(window) && !display) {
                display = true;
                if (schTable != nullptr) {
                    delete schTable;
                    schTable = nullptr;
                }
                schTable = new SchulteTable(7);
                clock.restart();;
            }
            if (display) {
                schTable->resetColor();
                schTable->cleaked(window);
                schTable->display(window);
            }
            if (schTable != nullptr) {
                if (schTable->end()) {
                    display = false;
                    Font font;
                    Text text;
                    font.loadFromFile("font.ttf");
                    text.setCharacterSize(30);
                    text.setFont(font);
                    text.setString(std::to_string(timer) + 's');
                    text.setPosition(400, 100);
                    text.setStyle(Text::Bold);
                    window.draw(text);
                } else {
                    timer = clock.getElapsedTime().asSeconds();
                }
            }
            x5.draw(window);
            x7.draw(window);
            Sleep(120);
        } else if (lineOfSight) {
            old = -1;
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                menu = true;
                lineOfSight = false;
                if (sight != nullptr) {
                    delete sight;
                    sight = nullptr;
                    display = false;
                }
            }
            x5.setColor(Color::White);
            x7.setColor(Color::White);
            if (x5.mouseIn(window)) {
                x5.setColor(Color::Blue);
            }
            if (x7.mouseIn(window)) {
                x7.setColor(Color::Blue);
            }
            if (x5.cleaked(window) && !display) {
                display = true;
                if (sight != nullptr) {
                    delete sight;
                    sight = nullptr;
                }
                sight = new LineOfSight(5);
                timer = clock.getElapsedTime().asSeconds();
            }
            if (x7.cleaked(window) && !display) {
                display = true;
                if (sight != nullptr) {
                    delete sight;
                    sight = nullptr;
                }
                sight = new LineOfSight(7);
                timer = clock.getElapsedTime().asSeconds();
            }
            if (display) {
                error.setColor(Color::White);
                if (clock.getElapsedTime().asSeconds() - timer >= 1) {
                    timer = clock.getElapsedTime().asSeconds();
                    sight->update();
                }
                sight->display(window);
                if (error.cleaked(window) && old != timer) {
                    error.setColor(Color::Blue);
                    sight->pressed();
                    old = timer;
                }
                error.draw(window);
            }
            if (sight != nullptr) {
                if (sight->end()) {
                    display = false;
                    Font font;
                    Text text;
                    font.loadFromFile("font.ttf");
                    text.setCharacterSize(30);
                    text.setFont(font);
                    text.setString(std::to_string(sight->result()) + '%');
                    text.setPosition(400, 100);
                    text.setStyle(Text::Bold);
                    window.draw(text);
                }
            }
            x5.draw(window);
            x7.draw(window);
        } else if (runningWords) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                menu = true;
                runningWords = false;
                if (runword != nullptr) {
                    delete runword;
                    runword = nullptr;
                    display = false;
                }
            }
            start.setColor(Color::White);
            if (start.mouseIn(window)) {
                start.setColor(Color::Blue);
            }
            if (start.cleaked(window)) {
                display = true;
                clock.restart();
                timer = clock.getElapsedTime().asSeconds();
                if (runword != nullptr) {
                    delete runword;
                    runword = nullptr;
                }
                runword = new RunningWords();
                displayAnswer = false;
            }
            if (display) {
                if (clock.getElapsedTime().asSeconds() - timer >= 0.7) {
                    runword->update();
                    timer = clock.getElapsedTime().asSeconds();
                }
                runword->display(window);
                if (timer > 15) {
                    display = false;
                }
            } else if (runword != nullptr) {
                runword->displayAll(window);
                runword->check(window);
            }
            start.draw(window);
        }
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        window.display();   
    }
    return 0;
}
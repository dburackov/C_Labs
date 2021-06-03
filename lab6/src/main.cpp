#include <iostream>
#include <string>
#include "MultiSet.h"

int main() {
	char letter;
	MultiSet<char> ms;
	std::string line;
	std::getline(std::cin, line);
	for (int i = 0; i < line.length(); i++) {
		ms.insert(line[i]);
	}
	auto it = ms.begin();
	for (; it != ms.end(); it++) {
		std::cout << (*it).first << " " << (*it).second << '\n';
	}
	std::cout << (*it).first << " " << (*it).second << '\n';
}
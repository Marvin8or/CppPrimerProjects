#include "interface.h"

void exercise_12_24()
{
	std::cout << "Input string length: ";
	size_t len;
	std::cin >> len;
	std::cin.ignore();
	char* cp = new char[len + 1];
	std::cin.get(cp, len + 1);
	std::cout << "The input string is: " << cp << "\n" << std::endl;
}
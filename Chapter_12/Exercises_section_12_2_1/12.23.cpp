#include "interface.h"

void exercise_12_23_1(const char* s1, const char* s2)
{
	char* s3 = new char[std::strlen(s1) + std::strlen(s2) + 1];
	std::strcpy(s3, s1);
	std::strcat(s3, s2);
	std::cout << s3 << std::endl;
	delete[] s3;
}

void exercise_12_23_2(std::string s1, std::string s2)
{
	std::string s3 = s1 + s2;
	std::cout << s3 << std::endl;
}
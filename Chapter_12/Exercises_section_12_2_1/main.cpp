#include "interface.h"

inline void print(std::unique_ptr<char[]>& cp, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << cp[i];
	}
}

int main()
{
	const char* cs1 = "First string";
	const char* cs2 = "Second string";
	exercise_12_23_1(cs1, cs2);

	std::string s1 = "First string";
	std::string s2 = "Second string";
	exercise_12_23_2(s1, s2);

	exercise_12_24();
}
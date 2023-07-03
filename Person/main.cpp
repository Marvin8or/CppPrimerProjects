#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
	Person* p = new Person("Gabriel", "Sukošanska Ulica 14");
	std::cout << "Name: " << p->getName() << std::endl;
	std::cout << "Address: " << p->getAddress() << std::endl;

	read(std::cin, *p);
	print(std::cout, *p);
	return 0;
}
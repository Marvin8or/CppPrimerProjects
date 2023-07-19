#include <iostream>
#include "Person.h"
#include "Sales_data.h"
#include "Screen.h"
using namespace std;

int main()
{
	//Usage of Sales_data class

	//Sales_data total(std::cin);
	//
	//if(total.isbn().length() != 0)
	//{
	//	while(true)
	//	{
	//		Sales_data trans(std::cin);
	//		if(trans.isbn().length() != 0)
	//		{
	//			if (total.isbn() == trans.isbn())
	//			{
	//				std::cout << "Combine total + trans..." << std::endl;
	//				total.combine(trans);
	//				print(cout, total);
	//			}
	//			else
	//			{
	//				std::cout << "Printing total..." << std::endl;
	//				print(cout, total) << endl;
	//				total = trans;
	//			}
	//		}
	//		else
	//		{
	//			std::cout << "Breaking..." << std::endl;
	//			break;
	//		}

	//	}
	//}

/*	Sales_data total;

	if(read(cin, total))
	{
		Sales_data trans;
		while(read(cin, trans))
		{
			if(total.isbn() == trans.isbn())
			{
				std::cout << "Combine total + trans..." << std::endl;
				total.combine(trans);
				print(cout, total);
			}
			else
			{
				std::cout << "Printing total..." << std::endl;
				print(cout, total) << endl;
				total = trans;
			}
		}

		print(cout, total) << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
	}*/

	//Sales_data s1("12345");
	//Sales_data s2("12345", 2, 12.99);
	//Sales_data s3(std::cin);

	//print(std::cout, s1) << std::endl;
	//print(std::cout, s2) << std::endl;
	//print(std::cout, s3) << std::endl;
	//Person* p = new Person("Gabriel", "Sukošanska Ulica 14");
	//std::cout << "Name: " << p->getName() << std::endl;
	//std::cout << "Address: " << p->getAddress() << std::endl;

	//read(std::cin, *p);
	//print(std::cout, *p);

	//Screen s1(10, 30, 'X');
	//s1.move(4, 0).set('#').display(std::cout);
	//std::cout << "\n";
	//s1.display(std::cout);
	//std::cout << "\n";

	//Sales_data s();
	return 0;
}
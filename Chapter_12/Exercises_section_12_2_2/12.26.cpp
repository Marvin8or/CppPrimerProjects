#include <iostream>
#include <memory>
#include <string>
int main()
{
	/*
	 *Rewrite this program using allocator
	
	string* const p = new string[n]; // construct n empty strings
	strin s;
	string* q = p;					// q points to the first string
	while (cin >> s && q != p + n)
		*q++ = s;					//assign a new value to *q
	const size_t size = q - p;		// remember how many strings we read
	//use array ...
	delete[] p;						// p points to an array; must remember to delete []
	*/

	int n = 4;		// We want to allocate the raw memory that can hold 10 strings
	std::allocator<std::string> alloc; // Object that can allocate strings
	auto const p = alloc.allocate(n);  // allocate n unconstructed strings
	auto q = p;
	std::string s;
	while (std::cin >> s && q < p + n)
		alloc.construct(q++, s);
	const size_t size = q - p;
	for (int i = 0; i < size; i++)
		std::cout << p[i] << std::endl;

	while (q != p)
		alloc.destroy(--q);
	alloc.deallocate(p, n);
	return 0;
}
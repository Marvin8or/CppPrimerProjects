#include "Exercises_section_12_1_2/section_interface.h"
#include "StrBlob/test.h"
#include <fstream>

int main()
{
	/*
	 * Exrcise 12.6
	vector<int>* vptr = getDynamicallyAllocatedVector(5);
	fillVectorWithValues(vptr);
	printVectorValues(vptr);
	delete vptr;
	printVectorValues(vptr);
	*/

	/*
	* Exrcise 12.7
	*/
	//{
		// Execute in scope to see effect of shared_ptr
	//	shared_ptr<vector<int>> vptr;
	//	vptr = getSafeDynamicallyAllocatedVector(5);

	//	{
	//		shared_ptr<vector<int>> vptr2 = vptr;
	//	}

	//	fillSafeVectorWithValues(vptr);
	//	printSafeVectorValues(vptr);
	//}

	//Exercise 12.19
	//testAllBlob();

	//Exercise 12.20
	std::cout << "Input the file name: ";
	std::string filename;
	std::cin >> filename;
	std::ifstream in(filename);
	if (!in.is_open()) {
		std::cerr << "Cannot open file: " << filename << std::endl;
		return -1;
	}

	StrBlob texts;
	for (std::string line; std::getline(in, line); texts.push_back(line)) {}
	StrBlobPtr p = texts.begin();
	for (StrBlob::size_type pos = 0; pos != texts.size(); ++pos, p.incr())
		std::cout << pos + 1 << ":\t" << p.deref() << std::endl;
	// The following loop cannot be compiled, because we don't define the `!=`
	// operator for `StrBlobPtr`
	//for (StrBlobPtr p = texts.begin(); p != texts.end(); p.inc())
	return 0;
}
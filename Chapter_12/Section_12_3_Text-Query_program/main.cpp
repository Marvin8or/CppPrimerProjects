#include <iostream>
#include <string>
#include "TextQuery.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>


void runQueries(std::ifstream& infile)
{
	// infile is an ifstream that is the file we want to query
	TextQuery tq(infile); // store the file and build the query map
	//iterate with user: prompt for a word to find and print results
	while(true)
	{
		std::cout << "Enter word to look for, or q to quit: " << std::endl;
		std::string s;
		//stop if we hit EOF on the input or if a 'q' is enterend
		if (!(std::cin >> s) || s == "q") break;
		// run the query and print the results
		std::cout << tq.query(s) << std::endl;
	}

}
int main()
{
	std::ifstream myfile("C:/Users/GabrielM/Documents/Projects/CppPrimerProjects/Chapter_12/Section_12_3_Text-Query_program/text_examples/Fox.txt");
	runQueries(myfile);
	return 0;
}
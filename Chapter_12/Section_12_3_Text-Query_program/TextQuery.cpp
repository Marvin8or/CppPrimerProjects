#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "TextQuery.h"

void TextQuery::parseLine(std::string& line, int& line_indx) const
{
	// Used to split string around spaces.
	std::istringstream ss(line);

	std::string word; // for storing each word

	// Traverse through all words
	// while loop till we get 
	// strings to store in string word
	while (ss >> word)
	{
		std::transform(word.cbegin(), word.cend(),
			word.begin(), // write to the same location
			[](unsigned char c) { return tolower(c); });

		size_t end = word.find_last_not_of(",.");
		if (end == std::string::npos)
		{
			word = "";
		}
		else
		{
			word = word.substr(0, end + 1);
			(*map_str_set_ptr)[word].insert(line_indx);
			(*map_str_int_ptr)[word]++;
		}
		
		
	}
}

TextQuery::TextQuery(std::ifstream& infile)
{
	text_ptr = std::make_shared<std::vector<std::string>>();
	map_str_set_ptr = std::make_shared<std::map<std::string, std::set<int>>>();
	map_str_int_ptr = std::make_shared<std::map<std::string, int>>();

	std::istringstream ss;
	std::string line;
	int line_indx = 0;

	if (infile.is_open())
	{
		while (std::getline(infile, line))
		{
			text_ptr->push_back(line);

		}
		infile.close();

		for (auto line : *text_ptr)
		{

			parseLine(line, line_indx);
			line_indx++;
		}
	}
	else
	{
		std::cout << "Unable to open file.";
	}

}

QueryResult TextQuery::query(std::string& word) const
{
	return QueryResult(word, text_ptr, map_str_set_ptr, map_str_int_ptr);
}

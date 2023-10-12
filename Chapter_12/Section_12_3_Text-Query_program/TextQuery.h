#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H
#include <vector>
#include <set>
#include <map>
#include "QueryResult.h"

class TextQuery
{
private:
	std::shared_ptr<std::vector<std::string>>			  text_ptr;
	std::shared_ptr<std::map<std::string, std::set<int>>> map_str_set_ptr;
	std::shared_ptr<std::map<std::string, int>>			  map_str_int_ptr;

public:
	TextQuery(std::ifstream& infile);
	QueryResult query(std::string& word) const;
	void parseLine(std::string& line, int& line_indx) const;


};
#endif
 
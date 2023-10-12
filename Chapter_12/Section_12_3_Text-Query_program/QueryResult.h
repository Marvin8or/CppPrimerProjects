#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H
#include <vector>
#include <map>
#include <set>

class QueryResult
{
public:
	QueryResult(std::string& word,
		std::shared_ptr<std::vector<std::string>>			  text_ptr,
		std::shared_ptr<std::map<std::string, std::set<int>>> map_str_set_ptr,
		std::shared_ptr<std::map<std::string, int>>			  map_str_int_ptr)
		: word_(word), text_ptr_(text_ptr), map_str_set_ptr_(map_str_set_ptr), map_str_int_ptr_(map_str_int_ptr) {}

	void print() const;

private:
	std::string word_;
	std::shared_ptr<std::vector<std::string>>			  text_ptr_;
	std::shared_ptr<std::map<std::string, std::set<int>>> map_str_set_ptr_;
	std::shared_ptr<std::map<std::string, int>>			  map_str_int_ptr_;

};

inline
std::ostream& operator<<(std::ostream& flux, const QueryResult& m)
{
	m.print();
	return flux;
}

#endif

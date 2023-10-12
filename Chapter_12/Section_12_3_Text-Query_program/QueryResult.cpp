#include <string>
#include <iostream>
#include "QueryResult.h"

void QueryResult::print() const
{
	std::cout << word_ << " occurs " << (*map_str_int_ptr_)[word_] << " times:" << std::endl;
	for(auto line_indx : (*(*map_str_set_ptr_)[word_]))
	{
		std::cout << "(line " << line_indx << ") " << (*text_ptr_)[line_indx] << std::endl;
	}
}	

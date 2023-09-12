#include "StrBlob.h"

void StrBlob::check(size_type i, const std::string& msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

std::string& StrBlob::front()
{
	// if the vector is empty, check will throw
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

std::string& StrBlob::front() const
{
	// if the vector is empty, check will throw
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}



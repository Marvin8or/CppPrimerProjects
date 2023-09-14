#ifndef STR_BLOB_H
#define STR_BLOB_H

class StrBlobPtr;
class ConstStrBlobPtr;

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include "StrBlobPtr.h"

class StrBlob
{
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlobPtr begin();
	StrBlobPtr end();
	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;
	StrBlob() : data(std::make_shared<std::vector<std::string>>()){};
	StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)){};
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// add and remove elements
	inline void push_back(const std::string& t) { data->push_back(t); }
	void pop_back();
	// element access
	std::string& front();
	std::string& back();
	const std::string& front() const;
	const std::string& back() const;
	
private:
	std::shared_ptr<std::vector<std::string>> data;
	// throws msg if data[i] isn't invalid
	void check(size_type i, const std::string& msg) const;
};

#endif //STR_BLOB_H

#include "StrBlobPtr.h"

#include "StrBlob.h"

StrBlobPtr::StrBlobPtr() : wptr(), curr(0) {}

StrBlobPtr::StrBlobPtr(StrBlob& sb, std::size_t sz)
	: wptr(sb.data), curr(sz) {}

std::string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;	// Increment current state
	return *this;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
	auto ret = wptr.lock(); // Is the vector still around?
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return std::shared_ptr<std::vector<std::string>>();
}

#ifndef CONST_STR_BLOB_PTR_H
#define CONST_STR_BLOB_PTR_H

class StrBlob;

#include <string>
#include <utility>
#include <vector>

// Throws and exeption on attempts to access a nonexistent element
class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr();
	ConstStrBlobPtr(const StrBlob& a, std::size_t sz = 0);
	const std::string& deref() const;
	ConstStrBlobPtr& incr(); // prefix version
private:
	// Check returns a shared_ptr to the vector if the check succeeds
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;

	// Store a weak_ptr, which the underlying vector might be destroyed
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr; // Current position in the array
};
#endif

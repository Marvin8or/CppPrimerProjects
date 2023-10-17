#include <iostream>
#include <string>
class HasPtr
{
public:
	HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}

	//copy constructor
	HasPtr(const HasPtr& hasptr)
	{
		i = hasptr.i;
		ps = new std::string(*(hasptr.ps));
	}
	const std::string& get() const { return *ps; }
	void set(const std::string& s) const { *ps = s; }
private:
	std::string* ps;
	int i;
};






int main()
{

	HasPtr s1 = "Hello";
	HasPtr s2 = s1;

	s2.set("World");
	std::cout << s1.get() << " " << s2.get() << std::endl;
	return 0;
}
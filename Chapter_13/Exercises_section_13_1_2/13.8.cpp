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
	HasPtr& operator=(const HasPtr& other)
	{
		delete ps;
		auto newps = new std::string(*(other.ps));
		ps = newps;
		i = other.i;
		return *this;
	}

private:
	std::string* ps;
	int i;
};






int main()
{
	HasPtr hp1 = "World";
	HasPtr hp2 = hp1;
	HasPtr hp3;
	hp3 = hp1;
	hp1.set("Hello");

	std::cout << hp1.get() << std::endl;
	std::cout << hp2.get() << std::endl;
	std::cout << hp3.get() << std::endl;

	hp1 = hp1;
	std::cout << "After `hp1 = hp1`: " << hp1.get() << std::endl;
	return 0;
}
#include <iostream>5

/*
 * Assume we have a class named NoDefault that has a constructor that
 * takes an int, but has no default constructor. Define a class C that has a member of type
 * NoDefault. Define the default constructor of C.
 */

class NoDefault
{
public:
	NoDefault(int i) : i_(i){};

private:
	int i_;
};

class C
{
public:
	C() : nodefault(0){};
private:
	NoDefault nodefault;
};

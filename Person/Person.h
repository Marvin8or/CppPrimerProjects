#pragma once
#include <iostream>
#include <string>

class Person
{
private:
	std::string name;
	std::string address;
public:
	Person()=default;
	Person(std::string name, std::string address);
	std::string getName() const;
	std::string getAddress();
	void setAddress(std::string newAddress);
};

std::istream& read(std::istream& is, Person& person);
std::ostream& print(std::ostream& os, const Person& person);
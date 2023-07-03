#include "Person.h"
#include <iostream>

Person::Person(std::string name, std::string address)
{
	this->name = name;
	this->address = address;
}

std::string Person::getName() const
{
	// this = const Person* const
	//this->name = "nesto drugo";
	return name;
}

std::string Person::getAddress()
{
	// this = Person* const
	//this->name = "nesto treæe";
	return address;
}

void Person::setAddress(std::string newAddress)
{
	this->address = newAddress;
}

std::istream& read(std::istream& is, Person& person)
{
	std::string newAddress;
	std::cout << "Enter new address: ";
	is >> newAddress;
	std::cout << std::endl;

	person.setAddress(newAddress);
	std::cout << "New address is " << person.getAddress() << std::endl;
	return is;
}

std::ostream& print(std::ostream& os, const Person& person)
{
	os << "Person's name: " << person.getName() << " ";
	Person newPerson = person;
	os << "Person's address: " << newPerson.getAddress();
	return os;
}

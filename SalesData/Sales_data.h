#pragma once
#include <iostream>
#include <string>


class Sales_data
{
friend std::istream& read(std::istream& is, Sales_data& sd);
friend Sales_data add(const Sales_data& sd1, const Sales_data& sd2);
friend std::ostream& print(std::ostream& os, const Sales_data& sd);
public:
	//Constructors
	// Defines the default constructor as well as one that takes a string argument
	Sales_data(const std::string& s, unsigned cnt, double price) : bookNo(s), units_sold(cnt), revenue(price*cnt)
	{
		std::cout << "Executing constructor 'Sales_data(const std::string& s=" << bookNo << ", unsigned cnt=" <<
			units_sold << ", double price=" << revenue << ")" << std::endl;
	}

	// Remaining constructors all delegate to another constructor
	Sales_data() : Sales_data("", 0, 0)
	{
		std::cout << "Executing constructor Sales_data()" << std::endl;
	}

	Sales_data(const std::string& s) : Sales_data(s, 0, 0)
	{
		std::cout << "Executing constructor Sales_data(const std::string& s=" << s << ")" << std::endl;

	}
	Sales_data(std::istream& is) : Sales_data()
	{
		std::cout << "Executing constructor Sales_data(std::istream& is)" << std::endl;
		read(is, *this);
	}
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data& rhs);
private:
	inline double avg_price() const;
	std::string bookNo;
	double price_per_unit = 10.00;
	unsigned units_sold = 0;
	double revenue = 0.0;

};

std::istream& read(std::istream& is, Sales_data& sd);
Sales_data add(const Sales_data& sd1, const Sales_data& sd2);
std::ostream& print(std::ostream& os, const Sales_data& sd);
#pragma once
#include <iostream>


struct Sales_data
{
	//Constructors
	Sales_data();
	Sales_data(const std::string& s) : bookNo(s) {}
	Sales_data(const std::string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p*n) {}
	Sales_data(std::istream& is);
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data& rhs);
	double avg_price() const;
	std::string bookNo;
	double price_per_unit = 10.00;
	unsigned units_sold = 0;
	double revenue = 0.0;

};

std::istream& read(std::istream& is, Sales_data& sd);
Sales_data add(const Sales_data& sd1, const Sales_data& sd2);
std::ostream& print(std::ostream& os, const Sales_data& sd);
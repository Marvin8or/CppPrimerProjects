#include "Sales_data.h"
#include <iostream>
#include <string>

/*Sales_data::Sales_data(std)
{
	bookNo = "";
}*/


//Sales_data::Sales_data(std::istream& is)
//{
//	read(is, *this);
//}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
 double Sales_data::avg_price() const
 {
	 return revenue / units_sold;
 }

Sales_data add(const Sales_data& sd1, const Sales_data& sd2)
{
	if(sd1.isbn() != sd2.isbn())
	{
		std::cerr << "Can't add two different Sales_data objects" << std::endl;
	}
	Sales_data sd(
		sd1.isbn(),
		/*Units sold*/sd1.units_sold + sd2.units_sold,
		/*Price per unit*/ sd1.price_per_unit);

	return sd;
}

std::istream& read(std::istream& is, Sales_data& sd)
{
	std::cout << "Enter isbn: ";
	std::string isbn;
	is >> sd.bookNo;
	std::cout << std::endl;

	std::cout << "Enter copies sold: ";
	is >> sd.units_sold;
	std::cout << std::endl;
	sd.revenue = sd.units_sold * sd.price_per_unit;
	return is;
}
std::ostream& print(std::ostream& os, const Sales_data& sd)
{
	os << "Isbn: " << sd.isbn() << std::endl;
	os << "Price per unit: " << sd.price_per_unit << std::endl;
	os << "Units sold: " << sd.units_sold << std::endl;
	os << "Revenue: " << sd.revenue << std::endl;
	return os;
}



#include "Screen.h"

char Screen::get(position r, position c) const
{
	position row = r * width;
	return contents[cursor + c];
}

Screen& Screen::move(position r, position c)
{
	position row = r * width;
	cursor = row + c;
	return *this;
}

std::istream& writeContents(std::istream& is, Screen& sc)
{
	std::string newContents;
	is >> newContents;
	sc.contents = newContents;
	return is;
}

std::ostream& readContents(std::ostream& os, Screen& sc)
{
	os << sc.contents << std::endl;
	return os;
}

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

Screen& Screen::set(char ch)
{
	contents[cursor] = ch;
	return *this;
}

Screen& Screen::set(position r, position c, char ch)
{
	contents[r * width + c] = ch;
	return *this;
}

Screen& Screen::display(std::ostream& os)
{
	do_display(os);
	return *this;
}

const Screen& Screen::display(std::ostream& os) const
{
	do_display(os);
	return *this;
}


std::istream& writeContents(std::istream& is, Screen& sc)
{
	std::string newContents;
	is >> newContents;
	sc.contents = newContents;
	return is;
}

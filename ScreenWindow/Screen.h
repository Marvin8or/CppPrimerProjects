#pragma once
#include <string>
#include <iostream>

/*
 * The Screen a User can see
 */
class Screen
{
	
	friend std::ostream& readContents(std::ostream& os, Screen& sc);
	friend std::istream& writeContents(std::istream& is, Screen& sc);

public:
	typedef std::string::size_type position;
	// using position = std::string::size_type;
	Screen() = default;
	Screen(position ht, position wt) : height(ht), width(wt), contents(" ") {};
	Screen(position ht, position wt, std::string c) : height(ht), width(wt), contents(c) {};
	char get() { return contents[cursor]; }
	inline char get(position r, position c) const;
	Screen& move(position r, position c);
private:
	
	position cursor = 0;
	position height = 0, width = 0;
	std::string contents;
	Screen& setContents(const std::string& newContents);
};

std::istream& writeContents(std::istream& is, Screen& sc);
std::ostream& readContents(std::ostream& os, Screen& sc);


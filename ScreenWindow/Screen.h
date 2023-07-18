#pragma once
#include <string>
#include <iostream>
#include "Window_mgr.h"


/*
 * The Screen a User can see
 */
class Screen
{
	
	friend std::ostream& readContents(std::ostream& os, Screen& sc);
	friend std::istream& writeContents(std::istream& is, Screen& sc);
	friend void Window_mgr::clear(Window_mgr::ScreenIndex);

public:
	typedef std::string::size_type position;
	// using position = std::string::size_type;
	Screen() = default;
	Screen(position ht, position wt) : height(ht), width(wt), contents(" ") {};
	Screen(position ht, position wt, char c) : height(ht), width(wt)
	{
		std::string intialized_contents(height * width, c);
		contents = intialized_contents;
	};
	char get() { return contents[cursor]; }
	inline char get(position r, position c) const;
	Screen& move(position r, position c);

	Screen& set(char ch);
	Screen& set(position, position, char);

	Screen& display(std::ostream& os);
	const Screen& display(std::ostream& os) const;

private:
	
	position cursor = 0;
	position height = 0, width = 0;
	std::string contents;

	// Function to do the work of displaying a Screen
	void do_display(std::ostream& os) const
	{
		for(int r=0; r<height; r++)
		{
			for(int c=0; c<width; c++)
			{
				os << contents[r * width + c];
			}
			os << std::endl;
		}
	}
};

std::istream& writeContents(std::istream& is, Screen& sc);



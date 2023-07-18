#include "Window_mgr.h"
#include <string>

void Window_mgr::clear(ScreenIndex si)
{
	// s is a reference to the Screen we want to clear
	Screen& s = screens_[si];
	// reset the contents of that Screen to all blanks
	s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& s)
{
	screens_.push_back(s);
	return screens_.size() - 1;
}


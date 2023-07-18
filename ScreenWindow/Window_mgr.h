#pragma once
#include "Screen.h"
#include <vector>

class Window_mgr
{
private:
	std::vector<Screen> screens_{ Screen(24, 80, ' ') };
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
};
#pragma once
#include "Screen.h"
#include <vector>

class Window_mgr
{
private:
	std::vector<Screen> screens_{ Screen(24, 80, ' ') };
};
#pragma once
#include <iostream>

namespace human
{
	void greeting()
	{
		std::cout << "Hello!" << std::endl;
	}
}

namespace alien
{
	void greeting()
	{
		std::cout << "Hello Humans!" << std::endl;
	}
}
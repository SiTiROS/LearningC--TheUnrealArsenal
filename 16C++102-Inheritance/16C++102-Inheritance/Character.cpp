#include "Character.h"
#include <iostream>

Character::Character()
{
	std::cout << "Character Constructed." << std::endl;
}

Character::~Character()
{
	std::cout << "Character Destroyed." << std::endl;
}

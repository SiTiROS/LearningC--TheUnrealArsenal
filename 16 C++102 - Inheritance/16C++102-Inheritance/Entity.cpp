#include "Entity.h"
#include <iostream>

Entity::Entity(int memberP)
	:member(memberP)
{
}

void Entity::toString()
{
	std::cout << member << std::endl;
}
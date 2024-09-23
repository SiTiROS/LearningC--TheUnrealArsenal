#pragma once
#include <iostream>

struct Vector
{
	Vector() { std::cout << "Vector Constructed." << std::endl; }
	~Vector() { std::cout << "Vector Destroyed." << std::endl; }

	int x;
	int y;
};
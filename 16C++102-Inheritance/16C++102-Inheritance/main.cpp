#include <iostream>
#include "Entity.h"
#include "PlayerCharacter.h"

using namespace std;

// extern int var;

struct StructA { int x{ 1 }; };
struct StructB { int x{ 2 }; };
struct StructC : public StructA, public StructB
{
	int y{ 5 };
};


struct StructA2 { int x{ 1 }; };
struct StructB2 : public StructA2
{
	int y{ 2 };
};
struct StructC2 : public StructA2
{
	int z{ 3 };
};
struct StructD2 : public StructB2, public StructC2
{};


int main()
{
	//147. Interface and Implementation Files

	// Entity entity1(6);
	// entity1.toString();



	// 148. Types of Inheritance

	// StructC c;
	// std::cout << c.StructA::x << std::endl;
	// std::cout << c.StructB::x << std::endl;
	//
	//
	// StructD2 d;
	// d.StructB2::x = 55;
	// cout << d.StructB2::x << endl;
	// cout << d.StructC2::x << endl;
	//
	//
	//PlayerCharacter player;



	std::cout << "END" << std::endl;
	return 0;
}


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


namespace DemoNamespaces
{
	int var;

	struct Entity
	{
		int member;
	};

	void hello()
	{
		std::cout << "Hello." << std::endl;
	}

	enum EGameDifficulty
	{
		Easy,
		Normal,
		Hard
	};
}

enum class ETerrainDifficulty
{
	Easy,
	Normal,
	Hard
};

int var = 44;

namespace DemoNamespace2
{
	void hello2();
}

namespace ParentNamespace
{
	inline namespace NestedNamespace
	{
		int var3 = 55;

		void hello() { std::cout << "Hello" << std::endl; }
	}

	void printVar() { std::cout << var3 << std::endl; }
}

namespace n = ParentNamespace;

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



	// 149. Namespaces

	//using std::cout;
	//using std::endl;
	//
	//using DemoNamespaces::Entity;
	////using DemoNamespaces::var;
	//
	//int var = 33;
	//
	//// DemoNamespaces::var = 5;
	//DemoNamespaces::var = 5;
	//::var = 22;
	//
	//// DemoNamespaces::Entity entity;
	//Entity entity;
	//
	//entity.member = 55;
	//
	//cout << entity.member << endl;
	//cout << DemoNamespaces::var << endl;
	//cout << ::var << endl;
	//cout << var << endl;
	//
	//DemoNamespaces::EGameDifficulty difficulty = DemoNamespaces::EGameDifficulty::Hard;
	//DemoNamespaces::EGameDifficulty difficulty = DemoNamespaces::Hard;
	//	
	//DemoNamespaces::hello();
	//DemoNamespace2::hello2();
	//
	ParentNamespace::NestedNamespace::hello();
	ParentNamespace::printVar();

	n::NestedNamespace::hello();
	n::printVar();


	std::cout << "END" << std::endl;
	return 0;
}

namespace DemoNamespace2
{
	void hello2() { cout << "Hello2." << endl; }
}
#include <iostream>

class BaseClass_1
{
protected:
	void hello() { std::cout << "Hello world" << std::endl; }
};

class DerivedClass_1 : public BaseClass_1
{
public:
	void toString()
	{
		hello();
	}
};


class BaseClass
{
public:
	int x { 1 };
protected:
	int y { 2 };
private:
	int z { 3 };
};

class DerivedCLass_public : public BaseClass
{
public:
	void toString()
	{
		std::cout << x << std::endl;
		std::cout << y << std::endl;
		// std::cout << z << std::endl;
	}
};

class DerivedCLass_protected : protected BaseClass
{
public:
	void toString()
	{
		std::cout << x << std::endl;
		std::cout << y << std::endl;
		// std::cout << z << std::endl;
	}
};

class DerivedCLass_private : private BaseClass
{
public:
	void toString()
	{
		std::cout << x << std::endl;
		std::cout << y << std::endl;
		// std::cout << z << std::endl;
	}
};

class ChildDerivedCLass : public DerivedCLass_protected
{
public:
	void toString()
	{
		std::cout << x << std::endl;
		std::cout << y << std::endl;
		// std::cout << z << std::endl;
	}
};


class Base
{
public:
	Base()
	{
		std::cout << "Base Class Constructor Invoked." << std::endl;
	}
	~Base()
	{
		std::cout << "Base Class Destructor Invoked." << std::endl;
	}

private:
	int x{ 1 };
};

class Derived : public Base
{
public:
	Derived()
	{
		std::cout << "Derived Class Constructor Invoked." << std::endl;
	}
	~Derived()
	{
		std::cout << "Derived Class Destructor Invoked." << std::endl;
	}

private:
	int y{ 2 };
};


class Base2
{
public:
	Base2()
		: x(1)
	{
		std::cout << "Base Class Default Constructor Invoked." << std::endl;
	}

	Base2(int xP)
		: x(xP)
	{
		std::cout << "Base Class Overloaded Constructor Invoked." << std::endl;
	}

protected:
	int x;
};

class Derived2 : public Base2
{
public:
	Derived2()
		:y(2)
	{
		std::cout << "Derived Class Default Constructor Invoked." << std::endl;
	}

	Derived2(int yP)
		:y(yP)
	{
		std::cout << "Derived Class Overloaded Constructor Invoked." << std::endl;
	}

	Derived2(int xP, int yP)
		:Base2(xP), y(yP)
	{
		std::cout << "Derived Class Overloaded Constructor Invoked." << std::endl;
	}

	void toString() { std::cout << "x: " << x << '\t' << "y: " << y << std::endl; }

private:
	int y;
};


class NBase
{
public:
	NBase(int xP = 1) : x(xP) {}

	void toString()
	{
		std::cout << "---Base Class---\nx: " << x << std::endl;
	}

private:
	int x;
};

class NDerived : public NBase
{
public:
	NDerived(int xP = 1, int yP = 2) : NBase(xP), y(yP) {}

	void toString()
	{
		//NBase::toString();
		std::cout << "---Derived Class---" << '\n' << "y: " << y << std::endl;
		//std::cout << "---Derived Class---\nx: " << x << '\n' << "y: " << y << std::endl;
	}

private:
	int y;
};


class Character
{
public:
	Character(int healthP = 100, int armorP = 0)
		: health(healthP), armor(armorP)
	{}

	void setStats(int healthP)
	{
		health = healthP;
	}

	void setStats(int healthP, int armorP)
	{
		health = healthP;
		armor = armorP;
	}

	void printStats()
	{
		std::cout << "Health: " << health << "\nArmor: " << armor << std::endl;
	}

protected:
	int health;
	int armor;
};

class PlayerCharacter : public Character
{
public:
	PlayerCharacter(int healthP = 100, int armorP = 0, int xpP = 0)
		: Character(healthP, armorP), xp(xpP)
	{}

	void setStats(int healthP, int armorP, int xpP)
	{
		health = healthP;
		armor = armorP;
		xp = xpP;
	}

	void printStats()
	{
		std::cout << "Health: " << health << "\nArmor: " << armor << "\nXP: " << xp << std::endl;
	}

private:
	int xp;
};


class FriendBaseF
{
	friend class BaseF;

private:
	int friendMember{ 5 };
};

class BaseF
{
public:
	void toString(const FriendBaseF& friendBaseP)
	{
		std::cout << friendBaseP.friendMember << std::endl;
	}
};

class DerivedF : public BaseF
{
public:
	// void toString(const FriendBaseF& friendBaseP)
	// {
	// 	std::cout << friendBaseP.friendMember << std::endl; // не будет работать наследование дружественных классов
	// }
};


int main()
{
	// 142. An Introduction to Inheritance

	// DerivedClass_1 derived;
	// derived.toString();



	// 143. Public and Private Derivation

	// BaseClass base;
	// //std::cout << base.x << std::endl;
	//
	// //DerivedCLass_public derivedPublic;
	// //derivedPublic.toString();
	// //std::cout << derivedPublic.x << std::endl;
	//
	// //DerivedCLass_protected derivedProtected;
	// //derivedProtected.x; // не доступен так как теперь это protected
	// //derivedProtected.toString();
	//
	// DerivedCLass_private derivedPrivate;
	// //derivedPrivate.x; // так же не доступен и теперь это private
	// derivedPrivate.toString();



	// 144. Initialization with Inheritance.mp4

	// //Base base;
	// // Derived derived;
	//
	// //Derived2 derived2;
	// //Derived2 derived2(5);
	// Derived2 derived2(2, 3);
	// derived2.toString();



	// 145. Redefining Base Class Member Functions

	// NBase base(4);
	// base.toString();
	// NDerived derived(33, 55);
	// derived.toString();
	// derived.NBase::toString();
	//
	//
	// // Character npc;
	// // npc.setStats(100, 22);
	// // npc.printStats();
	// PlayerCharacter player;
	// player.Character::setStats(2, 2);
	// player.setStats(200, 100, 1000);
	// player.Character::printStats();
	// player.printStats();



	// 146. Friendship with Inheritance

	// BaseF base;
	// FriendBaseF friendBase;
	// //base.toString(friendBase);
	//
	// DerivedF derived;
	// derived.toString(friendBase);
	// derived.BaseF::toString(friendBase);






	std::cout << "END" << std::endl;
	return 0;
}
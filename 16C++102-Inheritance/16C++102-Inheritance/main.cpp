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





	std::cout << "END";
	return 0;
}
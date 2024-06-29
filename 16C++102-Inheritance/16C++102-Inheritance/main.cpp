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

	// ~Base2()
	// {
	// 	std::cout << "Base Class Destructor Invoked." << std::endl;
	// }

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

	// ~Derived2()
	// {
	// 	std::cout << "Derived Class Destructor Invoked." << std::endl;
	// }

private:
	int y;
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




	std::cout << "END" << std::endl;
	return 0;
}
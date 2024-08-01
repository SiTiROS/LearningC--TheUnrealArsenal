#include <iostream>

class Base
{
public:
	virtual void toString() const
	{
		std::cout << "Base::toString()" << std::endl;
	}
};

class Derived : public Base
{
public:
	 virtual void toString() const
	{
		std::cout << "Derived::toString()" << std::endl;
	}
};

void display(const Base& baseP)
{
	baseP.toString();
}

int main()
{
	// 151. Polymorphism and the virtual keyword

	//Base base;
	//Derived derived;
	//
	////base.toString();
	////derived.toString();
	//
	//display(base);
	//display(derived);
	//
	//Base* basePtr = new Derived;
	//basePtr->toString();
	//delete basePtr;

	Base* basePtr = new Base;
	Base* basePtr2 = new Derived;

	Base* ptrArray[] = { basePtr, basePtr2, basePtr, basePtr2 };

	for (int i = 0; i < 4; i++)
	{
		ptrArray[i]->toString();
	}

	delete basePtr;
	delete basePtr2;



	std::cout << "\nEND" << std::endl;
	return 0;
}
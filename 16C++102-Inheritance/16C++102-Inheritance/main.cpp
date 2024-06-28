#include <iostream>

class BaseClass
{
protected:
	void hello() { std::cout << "Hello world" << std::endl; }
};

class DerivedClass : public BaseClass
{
public:
	void toString()
	{
		hello();
	}
};


int main()
{
	// 142. An Introduction to Inheritance

	DerivedClass derived;
	derived.toString();


	std::cout << "END";
	return 0;
}
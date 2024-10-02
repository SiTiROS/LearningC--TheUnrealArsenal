// 197. Unique Pointers and Polymorphism

#include <iostream>
#include <memory>

using namespace std;

//example1
class Base
{
public:
	virtual ~Base() { cout << "Base Destructor invoked" << endl; }

	virtual void toString() const { cout << "Base::toString" << endl; }
};

class Derived : public Base
{
public:
	virtual ~Derived() { cout << "Derived Destructor invoked" << endl; }

	virtual void toString() const override { cout << "Derived::toString" << endl; }
};


//example2
class Abstract
{
public:
	virtual ~Abstract() { cout << "Abstract Destructor invoked" << endl; }

	// Pure virtual function
	virtual void toString() const = 0;
};

class Concrete : public Abstract
{
public:
	virtual ~Concrete() { cout << "Concrete Destructor invoked" << endl; }

	virtual void toString() const override { cout << "Concrete::toString" << endl; }
};

void display(const unique_ptr<Abstract>& uPtrP)
{
	if (uPtrP != nullptr)
		uPtrP->toString();
	else
		cout << "nullptr!" << endl;
}


int main()
{
#if 0
	unique_ptr<Base> uPtr = make_unique<Derived>();
	uPtr->toString();

	uPtr.reset(new Base);
	uPtr->toString();
#endif

#if 1
	unique_ptr<Abstract> uPtr = make_unique<Concrete>();
	//unique_ptr<Abstract> uPtr{ new Concrete };

	uPtr->toString();

	display(uPtr);

	display(make_unique<Concrete>());
#endif


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
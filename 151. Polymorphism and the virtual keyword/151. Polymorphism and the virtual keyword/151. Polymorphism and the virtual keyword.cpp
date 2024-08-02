#include <iostream>

namespace Lesson151
{
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
}

namespace Lesson152
{
	class Base
	{
	public:
		int x{ 1 };
	};

	class Derived : public Base
	{
		int y{ 2 };
	};
}

namespace Lesson152v2
{
	class Base
	{
	public:
		Base(int xP = 1) : x(xP) {}

		virtual void toString()
		{
			std::cout << "Base Class\nx: " << x << std::endl;
		}

	protected:
		int x;
	};

	class Derived : public Base
	{
	public:
		Derived(int xP = 1, int yP = 2) : Base(xP), y(yP) {}

		virtual void toString()
		{
			std::cout << "Derived Class\nx: " << x << "\ny: " << y << std::endl;
		}

	private:
		int y;
	};

	void display(Base& baseP)
	{
		baseP.toString();
	}

	void display2(Base* baseP)
	{
		baseP->toString();
	}
}

int main()
{
	// 151. Polymorphism and the virtual keyword
	{
		//using namespace Lesson151;
		//Base base;
		//Derived derived;

		////base.toString();
		////derived.toString();

		//display(base);
		//display(derived);

		////Base* basePtr = new Derived;
		////basePtr->toString();
		////delete basePtr;

		//Lesson151::Base* basePtr = new Lesson151::Base;
		//Lesson151::Base* basePtr2 = new Lesson151::Derived;

		//Lesson151::Base* ptrArray[] = { basePtr, basePtr2, basePtr, basePtr2 };

		//for (int i = 0; i < 4; i++)
		//{
		//	ptrArray[i]->toString();
		//}

		//delete basePtr;
		//delete basePtr2;
	}


	// 152. Object Slicing with Upcasting and Downcasting
	{
		//using namespace Lesson152;

		//Derived derived;
		//Base base;

		//derived.x = 55;

		//base = derived;

		//std::cout << "\n" << std::endl;
	}

	{
		//using namespace Lesson152v2;

		//Base base;
		//Derived derived;

		//display(derived);
		//display2(&derived);

		////
		//Base* base2 = new Base(5);
		//Derived* derived2 = new Derived(33, 55);
		//
		//display(*base2);
		//display2(derived2);

		//delete base2;
		//delete derived2;
	}

	{
		using namespace Lesson152v2;

		//Derived* derived = new Derived(33, 55);
		//Base* base = (Base*)derived; //upcast from derived to base
		//base->toString();

		//
		//Base* base = new Derived(33, 55); //upcast implicitly from derived to base
		//base->toString();

		//Derived* derived = (Derived*)base;
		//derived->toString();

		//
		Base* base = new Base(33); 
		base->toString();

		Derived* derived = (Derived*)base; //downcast 
		derived->toString(); 
	}




















	std::cout << "\nEND" << std::endl;
	return 0;
}
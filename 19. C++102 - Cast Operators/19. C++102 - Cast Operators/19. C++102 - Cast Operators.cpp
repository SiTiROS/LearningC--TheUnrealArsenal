#include <iostream>

namespace L2
{
	class EntityOne
	{
	public:
		void toString() const
		{
			std::cout << "EntityOne::toString()" << std::endl;
		}
	};

	class EntityTwo
	{
	public:
		void toString() const
		{
			std::cout << "EntityTwo::toString()" << std::endl;
		}
	};
}

namespace L2v2
{
	class Base {};

	class Derived : public Base
	{
	public:
		void toString() const
		{
			std::cout << "x: " << x << std::endl;
		}

	private:
		int x{ 5 };
	};
}

namespace L2v3
{
	class Base {};
	class Derived : private Base {}; // всё кроме public будет при касте не работать!
}

namespace L2v4
{
	class Entity
	{
	public:
		// Conversation Constructor
		Entity(const int& intP)
		{
			std::cout << "Conversation Constructor Invoked." << std::endl;
			member = intP;
		}

		// Conversion Assignment Operator
		Entity& operator=(const int& rho)
		{
			std::cout << "Conversion Assignment Operator Invoked." << std::endl;
			member = rho;
			return *this;
		}

		// Conersion Operator
		operator int() const
		{
			std::cout << "Conversion Operator Invoked." << std::endl;
			return member;
		}

	private:
		int member;
	};

}


int main()
{
	// 2. The static_cast() Operator
	{
		//double d{ 3.14143 };

		//// C-style implicit conversation
		//short s = d;

		//// Explicit C-style cast
		//int i1 = (int)d;

		//// Explicit cast whith static_cast
		//int i2 = static_cast<int>(d);
	}

	//
	{
		using namespace L2;
		//EntityOne E1;

		// Avoid This...
		//EntityTwo* pE2 = (EntityTwo*)&E1;

		// EntityTwo* pE2 = static_cast<EntityTwo*>(&E1); // не будет работать!

		//pE2->toString();
	}

	//
	{
		using namespace L2v2;

		//Base* pBase = new Base;

		//// Not Safe!
		//// Derived can have members that are not in Base.
		//Derived* pDerived = static_cast<Derived*>(pBase);

		//pDerived->toString();
	}

	//
	{
		using namespace L2v3;
		//Derived* pDerived = new Derived;

		//// C-style implicit conversation
		//Base* pBase1 = pDerived;

		//// Explicit C-style cast
		//Base* pBase2 = (Base*)pDerived;

		//Base* pBase3 = static_cast<Base*>(pDerived);

		//delete pDerived;
	}

	//
	{
		using namespace L2v4;

		Entity entity(3);

		entity = 55;

		std::cout << "\nEntity.member is: " << entity << std::endl << std::endl;

		int x = static_cast<int>(entity);

		entity = static_cast<Entity>(47);

		std::cout << "\nEntity.member is: " << entity << std::endl;
	}

	std::cout << "End of Program\n";
	return 0;
}
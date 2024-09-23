#include <iostream>

// 2. The static_cast() Operator
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


// 3. The dynamic_cast() Operator
namespace L3
{
	class Base
	{
	public:
		Base() = default;
		virtual ~Base() {};

		virtual void toString() const
		{
			std::cout << "Base::toString()" << std::endl;
		}
	};

	class Derived : public Base
	{
	public:
		Derived() = default;
		virtual ~Derived() {};

		virtual void toString() const
		{
			std::cout << "Derived::toString()" << std::endl;
		}

		int getMember() const { return member; }

	private:
		int member{ 3 };
	};

	void displayPtr(Base* pBaseP)
	{
		Derived* pDerived = dynamic_cast<Derived*>(pBaseP);

		if (pDerived)
		{
			std::cout << "Derived Member is: " << pDerived->getMember() << std::endl;
			pDerived->toString();
		}
		else
		{
			std::cout << "nullptr" << std::endl;
		}
	}

	void displayRef(Base& rBaseP)
	{
		Derived& rDerived = dynamic_cast<Derived&>(rBaseP);

		// Convert Reference Into Pointer...
		Derived* pDerived = dynamic_cast<Derived*>(&rDerived);

		if (pDerived)
		{
			std::cout << "Derived Member is: " << pDerived->getMember() << std::endl;
			pDerived->toString();
		}
		else
		{
			std::cout << "nullptr" << std::endl;
		}
	}
}

namespace L3v2
{
	class EntityOne
	{
	public:
		EntityOne() = default;
		virtual ~EntityOne() {};

		virtual void toString() const
		{
			std::cout << "EntityOne::toString()" << std::endl;
		}
	};

	class EntityTwo
	{
	public:
		EntityTwo() = default;
		virtual ~EntityTwo() {};

		void toString() const
		{
			std::cout << "EntityTwo::toString()" << std::endl;
		}
	};
}

namespace L3v3
{
	class A
	{
		virtual void toString() const
		{
			std::cout << "Base::toString()" << std::endl;
		}
	};

	class B : public A {};

	class C : public A {};

	class D : public B, public C {};

}

namespace L3v4
{
	class A { virtual void toString() const {} };

	class B : public A {};

	class C : public A {};

	class D { virtual void toString() const {} };

	class E : public B, public C, public D {};
}


// 4. The typeid Operator
namespace L4
{
	class Entity {};
}

namespace L4v2
{
	class Base
	{
	public:
		Base() = default;
		virtual ~Base() = default;

		virtual void toString() const
		{
			std::cout << "Base::toString()." << std::endl;
		}
	};

	class Derived : public Base
	{
	public:
		Derived() = default;
		virtual ~Derived() = default;

		virtual void toString() const override
		{
			std::cout << "Derived::toString()." << std::endl;
		}
	};
}


//5. The const_cast() Operator
namespace L5
{
	void display(int* ptr)
	{
		std::cout << *ptr << std::endl;
	}
}

namespace L5v2
{
	class Entity
	{
	public:
		Entity(int memberP = 0)
			: member(memberP)
		{ }

		// const function that modifies the state of the Entity object...
		void ModifyMemberConst(const int intP) const
		{
			(const_cast<Entity*>(this))->member = intP;
		}

		void toString()const { std::cout << member << std::endl; }
		void setMember(int memberP) { member = memberP; }

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
		//using namespace L2v4;

		//Entity entity(3);

		//entity = 55;

		//std::cout << "\nEntity.member is: " << entity << std::endl << std::endl;

		//int x = static_cast<int>(entity);

		//entity = static_cast<Entity>(47);

		//std::cout << "\nEntity.member is: " << entity << std::endl;
	}


	// 3. The dynamic_cast() Operator
	{
		//using namespace L3;

		//Base* pBase = new Base;
		////Base* pBase = new Derived;
		//pBase->toString();

		////std::cout << "Derived Member is: " << pBase->getMember() << std::endl;

		//Derived* pDerived = dynamic_cast<Derived*>(pBase);

		//if (pDerived)
		//{
		//	std::cout << "Derived Member is: " << pDerived->getMember() << std::endl;
		//	pDerived->toString();
		//}
		//else
		//{
		//	std::cout << "nullptr" << std::endl;
		//}

		//delete pDerived;
	}

	{
		//using namespace L3;

		////Pointers
		//Base* pBase = new Derived;
		//displayPtr(pBase);

		////References
		//Derived derived{};
		//Base& rBase = derived;
		//displayRef(rBase);

		//delete pBase;
	}

	{
		//using namespace L3v2;

		//EntityOne E1;

		////Fail at compile-time
		////EntityTwo* pE2 = static_cast<EntityTwo*>(&E1);

		////Fail at run-time - return nullptr
		//EntityTwo* pE2 = dynamic_cast<EntityTwo*>(&E1);

		//if (pE2)
		//{
		//	pE2->toString();
		//}
	}

	{
		//double d{ 3.14 };
		////int i = dynamic_cast<int>(d);//nope
		//int i = static_cast<int>(d);//yeap
	}

	{
		//using namespace L3v2;

		//EntityOne* pEOne = new EntityOne;
		//EntityTwo* pETwo = new EntityTwo;

		//void* pVoid = dynamic_cast<void*>(pEOne);

		////Error - must be a pointer to a complete class type
		////EntityOne* pEOne2 = dynamic_cast<EntityOne*>(pVoid);

		//EntityOne* pEOne2 = static_cast<EntityOne*>(pVoid);

		//if (pEOne2)
		//{
		//	pEOne2->toString();
		//}
		//else
		//{
		//	std::cout << "nullptr" << std::endl;
		//}

		//pVoid = dynamic_cast<void*>(pETwo);

		//EntityTwo* pETwo2 = static_cast<EntityTwo*>(pVoid);

		//if (pETwo2)
		//{
		//	pETwo2->toString();
		//}
		//else
		//{
		//	std::cout << "nullptr" << std::endl;
		//}

		//delete pEOne;
		//delete pETwo;
	}

	{
		//using namespace L3v3;

		//D* pD = new D;

		//// Ambiguous Cast
		//A* pA = dynamic_cast<A*>(pD);
		//if (pA == nullptr)
		//{
		//	std::cout << "nullptr" << std::endl;
		//}

		////Multiple Upcast for Unambiguous Cast
		//B* pB = dynamic_cast<B*>(pD);
		//A* pA2 = dynamic_cast<A*>(pB);

		//delete pD;
	}

	{
		//using namespace L3v4;

		//D* pD = new E;

		//// Ambiguous Cast
		//A* pA = dynamic_cast<A*>(pD);
		//if (pA == nullptr)
		//{
		//	std::cout << "nullptr" << std::endl;
		//}

		////Downcast followed by Upcast for Unambiguous Cast
		//E* pE = dynamic_cast<E*>(pD);
		//B* pB = dynamic_cast<B*>(pE);
		//A* pA2 = dynamic_cast<A*>(pB);
		////A* pA2 = pB;


		//// Cross-Cast followed by Upcast for Unambiguous Cast
		//B* pB2 = dynamic_cast<B*>(pD);
		//A* pA3 = dynamic_cast<A*>(pB2);
		////A* pA3 = pB2;

		//delete pE;
	}


	// 4. The typeid Operator
	{
		//using namespace L4;

		//int* x{}, y{};
		//Entity entity{};
		//const Entity* const ptr1{};
		//Entity* const ptr2{};
		//Entity* ptr3 = new Entity{};

		//std::cout << "Types" << std::endl;
		//std::cout << "43: " << typeid(43).name() << std::endl;
		//std::cout << "x: " << typeid(x).name() << std::endl;
		//std::cout << "y: " << typeid(y).name() << std::endl;

		//std::cout << "entity: " << typeid(entity).name() << std::endl;
		//std::cout << "ptr1: " << typeid(ptr1).name() << std::endl;
		//std::cout << "ptr2: " << typeid(ptr2).name() << std::endl;
		//std::cout << "ptr3->: " << typeid(*ptr3).name() << std::endl;

		//delete ptr3;
	}

	{
		//int* x{}, y{};

		//if (typeid(x) != typeid(y))
		//{
		//	std::cout << "Types are not the same!" << std::endl;
		//}
		//else
		//{
		//	std::cout << "Types are the same." << std::endl;
		//}
	}

	{
		//using namespace L4v2;

		//Base* pBase1 = new Base;
		//Base* pBase2 = new Derived;

		//std::cout << "pBase1: " << typeid(pBase1).name() << std::endl;
		//std::cout << "pBase2: " << typeid(pBase2).name() << std::endl;

		//std::cout << "*pBase1: " << typeid(*pBase1).name() << std::endl;
		//std::cout << "*pBase2: " << typeid(*pBase2).name() << std::endl;

		//Derived derived;
		//Base& rBase = derived;
		//std::cout << "derived: " << typeid(derived).name() << std::endl;
		//std::cout << "rBase: " << typeid(rBase).name() << std::endl;

		//delete pBase1;
		//delete pBase2;
	}


	//5. The const_cast() Operator
	{
		//const int x = 33;

		//// Error...
		//// int y = const_cast<int>(x); 

		//int* ptr = const_cast<int*>(&x);

		//std::cout << *ptr << std::endl;

		////Undefined behaviour!
		//*ptr = 1;

		//std::cout << *ptr << std::endl;
		//std::cout << x << std::endl;
	}

	{
		//int x = 33;

		//const int* cptr = &x;
		//int* ptr = const_cast<int*>(cptr);

		//*ptr = 47;
		//std::cout << *ptr << std::endl;
		//std::cout << x << std::endl;
	}

	{
		//using namespace L5;
		//int x = 33;

		//const int* cptr = &x;
		////display(cptr);
		//int* ptr = const_cast<int*>(cptr);
		//display(ptr);

		//*ptr = 47;
		//std::cout << *ptr << std::endl;
		//std::cout << x << std::endl;
	}

	{
		//using namespace L5v2;

		//Entity entity{};

		//entity.toString();

		//entity.ModifyMemberConst(47);

		//entity.toString();
	}

	{
		int x{ 47 };
		const int* cPtr{ &x };
		volatile int* vPtr{ &x };

		std::cout << "Types." << std::endl;
		std::cout << "x: " << typeid(x).name() << std::endl;
		std::cout << "vPtr: " << typeid(vPtr).name() << std::endl;

		int* ptr = const_cast<int*>(vPtr);
		std::cout << "ptr: " << typeid(ptr).name() << std::endl;

		std::cout << "cPtr: " << typeid(cPtr).name() << std::endl;
		ptr = const_cast<int*>(cPtr);
		std::cout << "ptr: " << typeid(ptr).name() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "End of Program\n";
	return 0;
}
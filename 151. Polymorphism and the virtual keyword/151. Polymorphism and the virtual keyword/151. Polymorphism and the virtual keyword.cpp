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

namespace Lesson153
{
	class Base
	{
	public:
		virtual void toString() const
		{
			std::cout << "Base:toString()" << std::endl;
		}
	};

	class Derived : public Base
	{
	public:
		virtual void toString() const
		{
			std::cout << "Derived:toString()" << std::endl;
		}
	};

	class Parent
	{
	public:
		virtual void toString() const
		{
			std::cout << "Parent:toString()" << std::endl;
		}
	};

	class Child : public Parent
	{
	public:
		virtual void toString() const
		{
			std::cout << "Child:toString()" << std::endl;
		}
	};

	class GrandChild : public Child
	{
	public:
		virtual void toString() const
		{
			std::cout << "GrandChild:toString()" << std::endl;
		}
	};

	//
	class VirtualEntity
	{
	public:
		virtual void toString() const
		{
			std::cout << "Entity:toString()" << std::endl;
		}

	private:
		double d;
		float f;
	};

	class NonVirtualEntity
	{
	public:
		void toString() const
		{
			std::cout << "Entity:toString()" << std::endl;
		}

	private:
		double d;
		float f;
	};
}

namespace Lesson154
{
	class Base
	{
	public:
		virtual ~Base()
		{
			std::cout << "Base Destructor Invoked" << std::endl;
		}
	};

	class Derived : public Base
	{
	public:
		virtual ~Derived()
		{
			std::cout << "Derived Destructor Invoked" << std::endl;
		}
	};
}

namespace Lesson155
{
	class Base
	{
	public:
		virtual ~Base() {};

		virtual void toString() const
		{
			std::cout << "Base::toString()" << std::endl;
		}
	};

	class Derived : public Base
	{
	public:
		virtual ~Derived() {};

		virtual void toString() const override
		{
			std::cout << "Derived::toString()" << std::endl;
		}
	};
}

namespace Lesson156
{
	class Parent {};

	class Child : public Parent {};

	class GrandChild final : public Child {};

	class Base
	{
	public:
		virtual ~Base() {};

		virtual void toString() const final
		{
			std::cout << "Base::toString()" << std::endl;
		}
	};

	class Derived : public Base
	{
	public:
		virtual ~Derived() {};

		//virtual void toString() const override
		//{
		//	std::cout << "Derived::toString()" << std::endl;
		//}
	};

	class Base2
	{
	public:
		virtual ~Base2() {};

		virtual void toString() const final;
	};

	class Derived2 : public Base2
	{
	public:
		virtual ~Derived2() {};

		//virtual void toString() const override;
	};

	void Base2::toString() const
	{
		std::cout << "Base2::toString()" << std::endl;
	}

	//void Derived2::toString() const
	//{
	//	std::cout << "Derived2::toString()" << std::endl;
	//}

}

namespace Lesson157
{
	class Entity
	{
	public:
		void toString() { std::cout << "Entity::toString" << std::endl; }

	protected:
		Entity() {}
	private:
	};

	class Abstract
	{
	public:
		// pure virtual function declaration
		virtual void toString() const = 0;
		virtual ~Abstract() { std::cout << "Abstract::Destructor" << std::endl; }
		void hello() { std::cout << "Hello!" << std::endl; }
	};

	class Concrete : public Abstract
	{
	public:
		virtual void toString() const override
		{
			std::cout << "Concrete::toString()" << std::endl;
		}

		virtual ~Concrete() { std::cout << "Concrete::Destructor" << std::endl; }
	};
}

namespace Lesson158
{
	class ISpawnable
	{
	public:
		virtual void spawn() const = 0;
		virtual ~ISpawnable() {}
	};

	class GameLevel
	{
	public:
		void spawn(ISpawnable* toSpawnP) const
		{
			toSpawnP->spawn();
		}

		//void spawnPlayer();
		//void spawnChair();
		//void spawnAsteroid();
		//void spawnAlien();
	};

	class PlayerCharacter : public ISpawnable
	{
	public:
		virtual void spawn() const override
		{
			std::cout << "Player Spawned!" << std::endl;
		}
	};

	class Alien : public ISpawnable
	{
	public:
		virtual void spawn() const override
		{
			std::cout << "Alien Spawned!" << std::endl;
		}
	};

	class Chair : public ISpawnable
	{
	public:
		virtual void spawn() const override
		{
			std::cout << "Chair Spawned!" << std::endl;
		}
	};
}

namespace Lesson158v2
{
	class PlayerCharacter {};

	std::ostream& operator<<(std::ostream& output, const PlayerCharacter& player)
	{
		output << "Human player joined the game!";
		return output;
	}

	class Alien {};

	std::ostream& operator<<(std::ostream& output, const Alien& alien)
	{
		output << "Alien AI joined the game!";
		return output;
	}
}

namespace Lesson158v3
{
	class IPrintable
	{
		//friend std::ostream& operator<<(std::ostream& output, const IPrintable& rho);
	public:
		virtual void toString(std::ostream& output) const = 0;
		virtual ~IPrintable() {}
	};

	std::ostream& operator<<(std::ostream& output, const IPrintable& rho)
	{
		rho.toString(output);
		return output;
	}

	class PlayerCharacter : public IPrintable
	{
	public:
		virtual void toString(std::ostream& output) const override
		{
			output << "Human player joined the game!";
		}

		virtual ~PlayerCharacter() {}
	};

	class Alien : public IPrintable
	{
	public:
		virtual void toString(std::ostream& output) const override
		{
			output << "Alien AI joined the game!";
		}

		virtual ~Alien() {}
	};

	class Chair : public IPrintable
	{
	public:
		virtual void toString(std::ostream& output) const override
		{
			output << "A chair has spawned in the game!";
		}

		virtual ~Chair() {}
	};
}

namespace Lesson159
{
	class Entity
	{
	public:
		// Use compiler generated no-args constuctor
		Entity() = default;

		// One-argument Constructor (whith no default argument)
		Entity(int xP) { member = xP; }
		// Entity(int xP = 0) { member = xP; } // если в аргументах передаваемых есть значение по умолчанию то в конструктор можно и не передавать значение

		// Entity(const Entity& other) { member = other.member; }

		// Use compiler generated copy constructor
		Entity(const Entity& other) = default;

		void setMember(int memberP) { member = memberP; }

		void toString() { std::cout << member << std::endl; }

	private:
		int member{44};
	};

	class Derived : public Entity
	{
	public:

	};
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
		//using namespace Lesson152v2;

		////Derived* derived = new Derived(33, 55);
		////Base* base = (Base*)derived; //upcast from derived to base
		////base->toString();

		////
		////Base* base = new Derived(33, 55); //upcast implicitly from derived to base
		////base->toString();

		////Derived* derived = (Derived*)base;
		////derived->toString();

		////
		//Base* base = new Base(33); 
		//base->toString();

		//Derived* derived = (Derived*)base; //downcast 
		//derived->toString(); 
	}


	// 153. Virtual Member Functions
	{
		using namespace Lesson153;

		//Base* basePtr = new Derived;
		//basePtr->toString();

		//Derived* derivedPtr = new Derived;
		//derivedPtr->toString();
		//derivedPtr->Base::toString();

		//delete derivedPtr;
		//delete basePtr;

		//
		//GrandChild* grandChilPtr = new GrandChild;

		//grandChilPtr->toString();
		//grandChilPtr->Child::toString();
		//grandChilPtr->Parent::toString();

		//delete grandChilPtr;

		//
		//int a = 1;
		//int* aP = &a;
		//std::cout << sizeof(aP) << std::endl;

		//std::cout << sizeof(VirtualEntity) << std::endl;

		//NonVirtualEntity entity;
		//std::cout << sizeof(entity) << std::endl;

		//
		//VirtualEntity* entityPtr = new VirtualEntity;

		//VirtualEntity& entityRef = *entityPtr;

		//std::cout << sizeof(entityPtr) << std::endl;

		//std::cout << sizeof(entityRef) << std::endl;

		//delete entityPtr;

	}


	// 154. Virtual Destructors
	{
		//using namespace Lesson154;

		//Base* basePtr = new Base;
		//Base* basePtr2 = new Derived;

		//delete basePtr;
		//delete basePtr2;
	}


	// 155. The override Keyword
	{
		//using namespace Lesson155;

		//Base* basePtr = new Derived();

		//basePtr->toString();

		//delete basePtr;
	}


	// 156. The final Keyword
	{
		//using namespace Lesson156;

		//Base* basePtr = new Derived();

		//basePtr->toString();

		//delete basePtr;
	}


	// 157. Abstract and Concrete Classes
	{
		//using namespace Lesson157;

		// Entity entity; // не будет работать - запрещено инстанцировать ибо конструктор приватный или защищённый. но обычно так не делают
		// Abstract a; // не будет работать - запрещено инстанцировать ибо pure function

		//
		//Concrete c;
		//c.toString();

		//
		//Abstract* abstractPtr = new Concrete;
		//abstractPtr->toString();
		//abstractPtr->hello();
		//delete abstractPtr;
	}


	// 158. Interface Classes
	{
		//using namespace Lesson158;

		//GameLevel level1;

		//PlayerCharacter player;
		//Alien alien;
		//Chair chair;

		//level1.spawn(&player);
		//level1.spawn(&alien);
		//level1.spawn(&chair);
	}

	{
		//using namespace Lesson158v2;

		//PlayerCharacter player;
		//Alien alien;

		//std::cout << player << std::endl;
		//std::cout << alien << std::endl;
	}

	{
		//using namespace Lesson158v3;

		//PlayerCharacter player;
		//Alien alien;
		//Chair chair;

		//std::cout << player << std::endl;
		//std::cout << alien << std::endl;
		//std::cout << chair << std::endl;
	}


	// 159. Explicitly Defaulted Functions
	{
		//using namespace Lesson159;

		//Entity entity1;
		//entity1.setMember(150);
		//entity1.toString();


		//Entity entity2{ entity1 };
		//entity2.toString();
	}



	std::cout << "\nEND" << std::endl;
	return 0;
}
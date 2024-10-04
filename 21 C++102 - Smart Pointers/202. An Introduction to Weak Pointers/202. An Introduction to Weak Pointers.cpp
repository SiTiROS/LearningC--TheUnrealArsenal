// 202. An Introduction to Weak Pointers

#include <iostream>
#include <memory>

class Entity
{
public:
	Entity(int memberP = 0) { member = memberP; }
	~Entity() { std::cout << "Entity Destructor Invoked. Memory was: " << member << std::endl; }
	void toString()const { std::cout << member << std::endl; }
	void setMember(int memberP) { member = memberP; }

private:
	int member;
};


namespace E2
{
	class Entity
	{
	public:
		Entity() { std::cout << "Entity Constructor Invoked." << std::endl; }
		~Entity() { std::cout << "Entity Destructor Invoked." << std::endl; }
		void setMember(const std::shared_ptr<Entity>& sp_MemberP) { sp_Member = sp_MemberP; }

	private:
		std::shared_ptr<Entity> sp_Member;
	};
}

namespace E3
{
	class Entity
	{
	public:
		Entity() { std::cout << "Entity Constructor Invoked." << std::endl; }
		~Entity() { std::cout << "Entity Destructor Invoked." << std::endl; }
		void setMember(const std::shared_ptr<Entity>& sp_MemberP) { wp_Member = sp_MemberP; }

	private:
		std::weak_ptr<Entity> wp_Member;
	};
}

namespace E4
{
	class EntityA;
	class EntityB;

	class EntityA
	{
	public:
		EntityA() { std::cout << "EntityA Constructor Invoked." << std::endl; }
		~EntityA() { std::cout << "EntityA Destructor Invoked." << std::endl; }
		void setMember(const std::shared_ptr<EntityB>& sp_MemberP) { sp_Member = sp_MemberP; }

	private:
		std::shared_ptr<EntityB> sp_Member;
	};

	class EntityB
	{
	public:
		EntityB() { std::cout << "EntityB Constructor Invoked." << std::endl; }
		~EntityB() { std::cout << "EntityB Destructor Invoked." << std::endl; }
		void setMember(const std::shared_ptr<EntityA>& sp_MemberP) { sp_Member = sp_MemberP; }

	private:
		std::shared_ptr<EntityA> sp_Member;
	};
}

namespace E5
{
	class EntityA;
	class EntityB;

	class EntityA
	{
	public:
		EntityA() { std::cout << "EntityA Constructor Invoked." << std::endl; }
		~EntityA() { std::cout << "EntityA Destructor Invoked." << std::endl; }
		void setMember(const std::shared_ptr<EntityB>& sp_MemberP) { sp_Member = sp_MemberP; }

	private:
		std::shared_ptr<EntityB> sp_Member;
	};

	class EntityB
	{
	public:
		EntityB() { std::cout << "EntityB Constructor Invoked." << std::endl; }
		~EntityB() { std::cout << "EntityB Destructor Invoked." << std::endl; }
		void setMember(const std::shared_ptr<EntityA>& sp_MemberP) { wp_Member = sp_MemberP; }

	private:
		std::weak_ptr<EntityA> wp_Member;
	};
}

namespace E6
{
	class Employee; //forward declaration

	class Buisness
	{
	public:
		Buisness() { std::cout << "Buisness Constructor Invoked." << std::endl; }
		~Buisness() { std::cout << "Buisness Destructor Invoked." << std::endl; }
		void setMember(const std::shared_ptr<Employee>& sp_MemberP) { sp_Member = sp_MemberP; }

	private:
		std::shared_ptr<Employee> sp_Member;
	};

	class Employee
	{
	public:
		Employee() { std::cout << "Employee Constructor Invoked." << std::endl; }
		~Employee() { std::cout << "Employee Destructor Invoked." << std::endl; }
		void setMember(const std::shared_ptr<Buisness>& sp_MemberP) { wp_Member = sp_MemberP; }

	private:
		std::weak_ptr<Buisness> wp_Member;
	};
}


int main()
{
#if 0
	{
		std::shared_ptr<Entity> smartPtr;
		{
			std::shared_ptr<Entity> sp_Entity = std::make_shared<Entity>();
			smartPtr = sp_Entity;
			std::cout << "Inner use_count: " << sp_Entity.use_count() << std::endl;
		}
		std::cout << "Outer use_count: " << smartPtr.use_count() << std::endl;
	}
#endif

#if 0
	{
		std::weak_ptr<Entity> smartPtr;
		{
			std::shared_ptr<Entity> sp_Entity = std::make_shared<Entity>();
			smartPtr = sp_Entity;
			//smartPtr->toString(); // не будет работать!
			std::cout << "Inner use_count: " << sp_Entity.use_count() << std::endl;
		}
		std::cout << "Outer use_count: " << smartPtr.use_count() << std::endl;
	}
#endif

#if 0
	{
		std::weak_ptr<int> smartPtr;
		{
			std::shared_ptr<int> sp_Entity = std::make_shared<int>(55);
			smartPtr = sp_Entity;
			// std::cout << *smartPtr << std::endl; // не будет работать!
			std::cout << "Inner use_count: " << sp_Entity.use_count() << std::endl;
		}
		std::cout << "Outer use_count: " << smartPtr.use_count() << std::endl;
	}
#endif

#if 0
	{
		std::weak_ptr<int> smartPtr;
		{
			std::shared_ptr<int> sp_Entity = std::make_shared<int>(55);
			smartPtr = sp_Entity;
			std::cout << *(smartPtr.lock()) << std::endl; // lock() - вернёт shared_ptr указатель

			std::cout << "Inner use_count: " << sp_Entity.use_count() << std::endl;
		}
		std::cout << "Outer use_count: " << smartPtr.use_count() << std::endl;
	}
#endif

#if 0
	{
		std::weak_ptr<Entity> smartPtr;
		{
			std::shared_ptr<Entity> sp_Entity = std::make_shared<Entity>(55);
			smartPtr = sp_Entity;
			smartPtr.lock()->toString();
			std::shared_ptr<Entity> sp_Entity2 = smartPtr.lock();

			std::cout << "Inner use_count: " << sp_Entity.use_count() << std::endl;
		}
		std::cout << "Outer use_count: " << smartPtr.use_count() << std::endl;
	}
#endif

#if 0
	{
		std::weak_ptr<Entity> smartPtr;
		{
			std::shared_ptr<Entity> sp_Entity = std::make_shared<Entity>(55);
			smartPtr = sp_Entity;
			smartPtr.reset(); // reset для weak_ptr освобождает ссылку на объект в куче, но не удаляет этот объект
			std::shared_ptr<Entity> sp_Entity2 = smartPtr.lock();

			std::cout << "Inner use_count: " << sp_Entity.use_count() << std::endl;
		}
		std::cout << std::boolalpha;
		std::cout << "Weak pointer expired? " << smartPtr.expired() << std::endl; // истина если объект в куче был удалён
		std::cout << "Outer use_count: " << smartPtr.use_count() << std::endl;
	}
#endif

#if 0
	{
		std::shared_ptr<Entity> sp_Entity = std::make_shared<Entity>(55);
		{
			std::weak_ptr<Entity> smartPtr;
			smartPtr = sp_Entity;
			std::cout << "Inner use_count: " << sp_Entity.use_count() << std::endl;
			// std::cout << smartPtr.get() << std::endl; // для слабых указателей нет функции get
		}
		std::cout << "Outer use_count: " << sp_Entity.use_count() << std::endl;
	}
#endif


	// Part 2
#if 0
	std::shared_ptr<E2::Entity> sp_entityA = std::make_shared<E2::Entity>();
	std::shared_ptr<E2::Entity> sp_entityB = std::make_shared<E2::Entity>();

	std::cout << "Outer use_count: " << sp_entityA.use_count() << std::endl;
	std::cout << "Outer use_count: " << sp_entityB.use_count() << std::endl;

	sp_entityA->setMember(sp_entityB);
	sp_entityB->setMember(sp_entityA);

	std::cout << "Outer use_count: " << sp_entityA.use_count() << std::endl;
	std::cout << "Outer use_count: " << sp_entityB.use_count() << std::endl;

	//memory leak!
#endif

#if 0
	std::shared_ptr<E3::Entity> sp_entityA = std::make_shared<E3::Entity>();
	std::shared_ptr<E3::Entity> sp_entityB = std::make_shared<E3::Entity>();

	std::cout << "Outer use_count: " << sp_entityA.use_count() << std::endl;
	std::cout << "Outer use_count: " << sp_entityB.use_count() << std::endl;

	sp_entityA->setMember(sp_entityB);
	sp_entityB->setMember(sp_entityA);

	std::cout << "Outer use_count: " << sp_entityA.use_count() << std::endl;
	std::cout << "Outer use_count: " << sp_entityB.use_count() << std::endl;

	//memory don't leak!
#endif

#if 0
	std::shared_ptr<E4::EntityA> sp_entityA = std::make_shared<E4::EntityA>();
	std::shared_ptr<E4::EntityB> sp_entityB = std::make_shared<E4::EntityB>();

	std::cout << "Outer use_count: " << sp_entityA.use_count() << std::endl;
	std::cout << "Outer use_count: " << sp_entityB.use_count() << std::endl;

	sp_entityA->setMember(sp_entityB);
	sp_entityB->setMember(sp_entityA);

	std::cout << "Outer use_count: " << sp_entityA.use_count() << std::endl;
	std::cout << "Outer use_count: " << sp_entityB.use_count() << std::endl;

	//memory leak!
#endif

#if 0
	std::shared_ptr<E5::EntityA> sp_entityA = std::make_shared<E5::EntityA>();
	std::shared_ptr<E5::EntityB> sp_entityB = std::make_shared<E5::EntityB>();

	std::cout << "Outer use_count: " << sp_entityA.use_count() << std::endl;
	std::cout << "Outer use_count: " << sp_entityB.use_count() << std::endl;

	sp_entityA->setMember(sp_entityB);
	sp_entityB->setMember(sp_entityA);

	std::cout << "Outer use_count: " << sp_entityA.use_count() << std::endl;
	std::cout << "Outer use_count: " << sp_entityB.use_count() << std::endl;

	//memory don't leak!
#endif

#if 1
	std::shared_ptr<E6::Buisness> sp_entityA = std::make_shared<E6::Buisness>();
	std::shared_ptr<E6::Employee> sp_entityB = std::make_shared<E6::Employee>();

	std::cout << "Outer use_count: " << sp_entityA.use_count() << std::endl;
	std::cout << "Outer use_count: " << sp_entityB.use_count() << std::endl;

	sp_entityA->setMember(sp_entityB);
	sp_entityB->setMember(sp_entityA);

	std::cout << "Outer use_count: " << sp_entityA.use_count() << std::endl;
	std::cout << "Outer use_count: " << sp_entityB.use_count() << std::endl;

	//memory don't leak!
#endif


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
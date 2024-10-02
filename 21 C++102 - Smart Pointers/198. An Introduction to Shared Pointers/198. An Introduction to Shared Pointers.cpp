// 198. An Introduction to Shared Pointers

#include <iostream>
#include <memory>

class Entity
{
public:
	Entity(int memberP = 0) { member = memberP; }
	~Entity() { std::cout << "Entity Destuctor Invoked. Memory was: " << member << std::endl; }
	void toString()const { std::cout << member << std::endl; }
	void setMember(int memberP) { member = memberP; }

private:
	int member;
};


int main()
{
#if 0
	std::shared_ptr<Entity> sPtr1{ new Entity{ 55 } };
	std::shared_ptr<Entity> sPtr2{ sPtr1 }; // copy constructor available

	sPtr1->toString();
	std::cout << "sPtr1 use_count: " << sPtr1.use_count() << std::endl; // use_count = счётчик указателей
	std::cout << "sPtr2 use_count: " << sPtr2.use_count() << std::endl;
#endif

#if 0
	std::shared_ptr<Entity> sPtr1{ new Entity{ 55 } };
	sPtr1->toString();
	std::cout << "sPtr1 use_count: " << sPtr1.use_count() << std::endl;

	{
		std::shared_ptr<Entity> sPtr2{ sPtr1 }; // copy constructor available
		sPtr2->toString();
		std::cout << "sPtr2 use_count: " << sPtr2.use_count() << std::endl;
	}

	std::cout << "sPtr1 use_count: " << sPtr1.use_count() << std::endl;
#endif

#if 0
	std::shared_ptr<Entity> sPtr1;
	std::cout << "sPtr1 use_count: " << sPtr1.use_count() << std::endl;

	{
		std::shared_ptr<Entity> sPtr2{ new Entity{ 55 } };
		sPtr2->toString();
		sPtr1 = sPtr2; // assighment operator
		std::cout << "sPtr2 use_count: " << sPtr2.use_count() << std::endl;
	}

	std::cout << "sPtr1 use_count: " << sPtr1.use_count() << std::endl;
#endif

#if 0
	std::shared_ptr<Entity> sPtr1;

	{
		std::shared_ptr<Entity> sPtr2{ new Entity{ 55 } };
		sPtr1 = sPtr2; // assighment operator
		sPtr1->toString();

		std::cout << "sPtr1 use_count: " << sPtr1.use_count() << std::endl;

		//sPtr2.reset();
		//sPtr2 = nullptr;
		//sPtr1 = nullptr;
		sPtr2.reset(new Entity{ 155 });

		if (sPtr2 == nullptr)
			std::cout << "nullptr!" << std::endl;

		std::cout << "sPtr1 use_count: " << sPtr1.use_count() << std::endl;
		std::cout << "sPtr2 use_count: " << sPtr2.use_count() << std::endl;
	}

#endif

#if 0
	Entity* rawPtr = new Entity{ 55 };

	std::shared_ptr<Entity> sPtr1(rawPtr);

	std::cout << sPtr1.use_count() << std::endl;

	// delete rawPtr; // так нельзя!
#endif

#if 0
	std::shared_ptr<Entity> sPtr1(new Entity{ 55 });

	std::cout << std::boolalpha;
	std::cout << "sPtr1 managed a heap object: " << (sPtr1.get() != 0) << std::endl;
#endif

#if 1
	auto sPtr1 = std::shared_ptr<Entity>(new Entity{ 55 });
	auto sPtr2 = std::make_shared<Entity>(111); // более безопасно
	sPtr1->toString();
	sPtr2->toString();
#endif


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
// 190. Unique Pointers

#include <iostream>
#include <memory>

//example2
namespace E2
{
	struct Entity
	{
		~Entity() { std::cout << "Entity Destructor invoked." << std::endl; }

		int member{};
	};
}


//example8
namespace E8
{
	struct Entity
	{
		~Entity() { std::cout << "Entity Destructor invoked." << std::endl; }

		void toString() const { std::cout << member << std::endl; }

		int member{};
	};

	void display(const Entity& entityP)
	{
		entityP.toString();
	}
}


int main()
{

#if 0
	//example1
	{
		std::unique_ptr<int> sPtr{ new int{ 55 } };
		std::cout << sPtr << std::endl;  //адресс объекта в куче который хранится в указателе
		std::cout << &sPtr << std::endl; //адресс самого указателя
		std::cout << *sPtr << std::endl; //значения переменной на которую указывает указатель

		*sPtr = 150;
		std::cout << *sPtr << std::endl;

	} //sPtr destructor called which deallocates heap object.
#endif


#if 0
	//example2
	{
		using namespace E2;

		std::unique_ptr<Entity> sPtrEntity{ new Entity{ 55 } };
		std::cout << sPtrEntity->member << std::endl;

		sPtrEntity->member = 150;
		std::cout << sPtrEntity->member << std::endl;

	} //sPtrEntity destructor called which deallocates Entity heap object.
#endif

#if 0
	//example3
	{
		using namespace E2;

		Entity entity1{ 55 };
		std::cout << entity1.member << std::endl;
	}
#endif

#if 0
	//example4
	{
		using namespace E2;
		Entity* PtrEntity = new Entity{ 55 };
		std::cout << PtrEntity->member << std::endl;

		delete PtrEntity; // remember to deallocate!
	}
#endif

#if 0
	//example5
	{
		using namespace E2;

		std::unique_ptr<Entity> sPtrEntity{ new Entity{ 55 } };
		//std::unique_ptr<Entity> sPtrEntity = new Entity{ 55 }; //не будет работать! так как под капотом explicit - предотвращает неявные преобразования
		//sPtrEntity = new Entity{ 55 }; // так работать не будет!

		std::cout << sPtrEntity->member << std::endl;

		//Reset used for deallocation and/or allocation of new heap object
		//sPtrEntity.reset(); //удаляет управляемый объект и вызывает деструктор!
		sPtrEntity.reset(new Entity{ 222 }); //удаляет старый объект, добавляет новый и вызывает деструктор!


		if (sPtrEntity)
		{
			std::cout << sPtrEntity->member << std::endl;

			sPtrEntity->member = 150;

			std::cout << sPtrEntity->member << std::endl;
		}
	}
#endif

#if 0
	//example6
	using namespace E2;

	std::unique_ptr<Entity> sPtrEntity1{ new Entity{ 55 } };
	//std::unique_ptr<Entity> sPtrEntity2{ sPtrEntity1 }; // нельзя! так как только 1 unique_ptr управляет только 1 объектом

	std::unique_ptr<Entity> sPtrEntity2;
	//sPtrEntity2 = sPtrEntity1; //нельзя!

	//sPtrEntity1.reset();
	sPtrEntity1 = nullptr; // или так

	sPtrEntity2 = std::move(sPtrEntity1); // передаёт управление объектом
	// std::unique_ptr<Entity> sPtrEntity3{ std::move(sPtrEntity1) }; // или так 

	if (sPtrEntity2 == nullptr)
	{
		std::cout << "sPtrEntity2 == nullptr" << std::endl;
	}
	else
	{
		std::cout << sPtrEntity2->member << std::endl;
	}

	if (!sPtrEntity1)
	{
		std::cout << "sPtrEntity1 == nullptr" << std::endl;
	}
#endif

#if 0
	//example7
	using namespace E2;

	std::unique_ptr<Entity> entityPtr{ new Entity{ 55 } };

	Entity* rawEntityPtr = entityPtr.get(); //возвращает указатель на управляемый объект

	std::cout << rawEntityPtr->member << std::endl;

#endif

#if 1
	//example8
	using namespace E8;

	std::unique_ptr<Entity> entityPtr{ new Entity{ 55 } };

	//entityPtr->toString();
	display(*entityPtr);

#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
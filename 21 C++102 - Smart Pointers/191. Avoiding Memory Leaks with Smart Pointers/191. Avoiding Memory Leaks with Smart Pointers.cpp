// 191. Avoiding Memory Leaks with Smart Pointers

#include <iostream>
#include <memory>

struct Entity
{
	~Entity() { std::cout << "Entity Destructor invoked." << std::endl; }

	int member{};
	int member2{};
};

int main()
{
#if 0
	std::unique_ptr<Entity> entityPtr{ new Entity{ 55 }};

	//release() - return address of heap object and set managet to nullptr
	Entity* ptr = entityPtr.release(); //возвращает указатель на управляемый объект, но освобождает старый указатель 
	std::cout << ptr->member << std::endl;

	if (entityPtr == nullptr)
	{
		std::cout << "entityPtr == nullptr" << std::endl;
	}
	else
	{
		std::cout << entityPtr->member << std::endl;
	}

	delete ptr;
#endif

#if 0
	std::unique_ptr<Entity> entityPtr{ new Entity{ 55 }};

	Entity* ptr = entityPtr.get();
	std::cout << ptr->member << std::endl;

	if (entityPtr == nullptr)
		std::cout << "entityPtr == nullptr" << std::endl;
	else
		std::cout << entityPtr->member << std::endl;

	delete ptr;

	// будет краш, так как указатель ptr удалён 
	// и потом ещё раз удаляется умным указателем entityPtr при выходе их стекового кадра
#endif

#if 0
	Entity* ptr = new Entity{ 55 };

	std::unique_ptr<Entity> uEntityPtr{ ptr };

	delete ptr;

	// будет краш, так как указатель ptr удалён 
	// и потом ещё раз удаляется умным указателем uEntityPtr при выходе их стекового кадра
#endif

#if 1
	Entity* ptr = new Entity{ 55 };

	std::unique_ptr<Entity> uEntityPtr1{ ptr };
	std::unique_ptr<Entity> uEntityPtr2{ ptr };

	// будет краш, так как при выходе их стекового кадра удаляет uEntityPtr1 и потом uEntityPtr2
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
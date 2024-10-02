// 189. An Introduction to Smart Pointers

#include <iostream>

//example1
namespace e1
{
	template<typename T>
	class PointerManager
	{
	public:
		//Constructor
		PointerManager()
		{
			member = new(std::nothrow) T{}; //std::nothrow заставляет new возвращать nullptr в случае неудачи
		}

		//Destructor
		~PointerManager()
		{
			std::cout << "Destructor invoked!" << std::endl;
			delete member;
			member = nullptr;
		}

	private:
		T* member;
	};
}


//example2
namespace e2
{
	struct Entity
	{
		~Entity() { std::cout << "Entity Destructor invoked!" << std::endl; }
		int member{};
	};

	template<typename T>
	class PointerManager
	{
	public:
		//Explicit Constructor to avoid implicit conversations
		explicit PointerManager(T* ptrP = nullptr) { m_Ptr = ptrP; } // explicit предотвращает неявные преобразования

		//Copy constructor
		PointerManager(const PointerManager&) = delete; // удаляем

		~PointerManager() { delete m_Ptr; }

		//Deleted assignement operator
		PointerManager& operator=(const PointerManager&) = delete; // удаляем

		//Overload dereference operator
		T& operator*() { return *m_Ptr; }

		//Overload arrow operator
		T* operator->() { return m_Ptr; }

	private:
		T* m_Ptr;
	};
}

int main()
{
	//example1
#if 0 
	{
		using namespace e1;

		PointerManager<int> pointer1;
	}
#endif


	//example2
#if 0 
	{
		using namespace e2;

		int* ptr = new int{ 5 }; // так делать не надо, могут быть утечки памяти
		PointerManager<int> ptr1{ptr};
		std::cout << *ptr1 << std::endl;

		PointerManager<int> ptr2{ new int{ 55 } };
		std::cout << *ptr2 << std::endl;

		PointerManager<Entity> ptr3{ new Entity{ 34 } };
		std::cout << ptr3->member << std::endl;

		PointerManager<Entity> ptr4{ ptr3 }; // не работает так как в классе удалил конструктор копирования

		PointerManager<Entity> ptr5;
		ptr5 = ptr3; // не работает так как в классе удалил оператор =
	}
#endif



#if 0
#endif
	std::cout << "END" << std::endl;
	return 0;
}
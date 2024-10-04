// 205. Custom Deleters for Smart Pointers

#include <iostream>
#include <memory>
#include <functional>

// test
class LegacyEntityEntity
{
public:

	LegacyEntityEntity() // Конструктор, создающий другой объект LegacyEntity на куче

	{
		memberPtr = new LegacyEntityEntity(false); // Используем флаг, чтобы остановить рекурсию
	}

	LegacyEntityEntity(bool createMember) // Конструктор, который не создает новый объект (используется для внутреннего объекта)

	{
		if (createMember)
		{
			memberPtr = new LegacyEntityEntity(false); // Создаем объект только в основном конструкторе
		}
		else
		{
			memberPtr = nullptr; // Не создаем новый объект
		}
	}

	~LegacyEntityEntity() { std::cout << "LegacyEntity Destructor Invoked" << std::endl; }

	void release()
	{
		std::cout << "Managed heap object of LegacyEntity deallocated." << std::endl;
		std::cout << "Managed heap object was: " << memberPtr << std::endl;

		delete memberPtr;
	}

private:
	LegacyEntityEntity* memberPtr;
};


class LegacyEntity
{
public:
	LegacyEntity(int p = 1) { memberPtr = new int(p); }

	~LegacyEntity() { std::cout << "LegacyEntity Destructor Invoked" << std::endl; }

	void release()
	{
		std::cout << "Managed heap object of LegacyEntity deallocated." << std::endl;
		std::cout << "Managed heap object was: " << *memberPtr << std::endl;

		delete memberPtr;
	}

private:
	int* memberPtr;
};

void deleter(LegacyEntity* leP)
{
	std::cout << "Deleter Invoked" << std::endl;
	leP->release();
	delete leP;
}

template <typename T>
void deleterT(T* leP)
{
	std::cout << "Deleter Invoked" << std::endl;
	leP->release();
	delete leP;
}

struct Deleter_Functor
{
	void operator()(LegacyEntity* leP)
	{
		std::cout << "Deleter_Functor Invoked" << std::endl;
		leP->release();
		delete leP;
	}
};

typedef std::unique_ptr<LegacyEntity, std::function<void(LegacyEntity*)>> dup_LegacyEntity; //алиас dup_LegacyEntity
using dup_LegacyEntity2 = std::unique_ptr<LegacyEntity, std::function<void(LegacyEntity*)>>;

template<typename T>
using dup_LegacyEntityT = std::unique_ptr<T, std::function<void(T*)>>;


//Part2
namespace E2
{
	void deleter(int* p) { delete p; }

	struct Deleter_Functor
	{
		void operator()(int* p) { delete p; }
	};

	struct Deleter_Functor2
	{
		void operator()(int* p) { delete p; }
		double memory1;
		double memory2;
	};
}

int main()
{
#if 0
	LegacyEntity entity(55);
	entity.release();
#endif

#if 0
	LegacyEntityEntity* entityPtr = new LegacyEntityEntity();
	entityPtr->release();

	delete entityPtr;
#endif

#if 0
	LegacyEntity* entityPtr = new LegacyEntity(2);
	entityPtr->release();

	delete entityPtr;
#endif

#if 0
	std::shared_ptr<LegacyEntity> sp{ new LegacyEntity(33), & deleter };
	// std::shared_ptr<LegacyEntity> sp{ new LegacyEntity(33), deleter }; //или так
#endif

#if 0
	std::shared_ptr<LegacyEntity> sp{ new LegacyEntity(33),
		[](LegacyEntity* leP)
		{
			std::cout << "Deleter Invoked" << std::endl;
			leP->release();
			delete leP;
		}
	};
#endif

#if 0
	std::unique_ptr<LegacyEntity, void(*)(LegacyEntity*)> up{ new LegacyEntity(44), deleter };
#endif

#if 0
	std::unique_ptr<LegacyEntity, Deleter_Functor> up{ new LegacyEntity(44), Deleter_Functor() };
#endif

#if 0
	std::unique_ptr<LegacyEntity, std::function<void(LegacyEntity*)>> up
	{ new LegacyEntity(44), Deleter_Functor() };
#endif

#if 0
	std::unique_ptr<LegacyEntity, std::function<void(LegacyEntity*)>> up
	{ new LegacyEntity(44), deleter };
#endif

#if 0
	dup_LegacyEntity up{ new LegacyEntity(44), deleter }; //алиас
	dup_LegacyEntity2 up2{ new LegacyEntity(22), deleter }; //алиас
#endif

#if 0
	dup_LegacyEntityT<LegacyEntity> up{ new LegacyEntity(44), deleter }; //шаблонный алиас
#endif

#if 0
	dup_LegacyEntityT<LegacyEntity> up{ new LegacyEntity(44), deleterT<LegacyEntity> }; //шаблонный алиас и шаблонная функция
#endif

#if 0
	dup_LegacyEntityT<LegacyEntityEntity> up{ new LegacyEntityEntity(44), deleterT<LegacyEntityEntity> }; //шаблонный алиас и шаблонная функция
#endif


	//Part2
#if 1
	std::cout << sizeof(std::unique_ptr<int, std::function<void(int*)>>) << std::endl;

	std::cout << sizeof(std::unique_ptr<int, void(*)(int*)>) << std::endl;

	std::cout << sizeof(std::unique_ptr<int, E2::Deleter_Functor>) << std::endl;

	std::cout << sizeof(std::unique_ptr<int, E2::Deleter_Functor2>) << std::endl;

	auto lambda = [](double* p) { delete p; };
	std::cout << sizeof(std::unique_ptr<int, decltype(lambda)>) << std::endl; // decltype определить тип

	std::cout << sizeof(std::unique_ptr<int, decltype(&deleter)>) << std::endl; // тут обязателен &

	std::cout << sizeof(std::unique_ptr<int>) << std::endl; //using default deleter

#endif




#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
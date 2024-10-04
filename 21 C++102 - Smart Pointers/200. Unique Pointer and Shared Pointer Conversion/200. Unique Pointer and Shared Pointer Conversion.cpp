// 200. Unique Pointer and Shared Pointer Conversion

#include <iostream>
#include <memory>

using namespace std;

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

std::unique_ptr<Entity> unique_prtEntityFactory(int iniP = 0) //лучше делать возврат уник указателей
{
	return make_unique<Entity>(iniP);
}

std::shared_ptr<Entity> shared_prtEntityFactory(int iniP = 0)
{
	return make_shared<Entity>(iniP);
}


int main()
{
#if 0
	unique_ptr<Entity> up_Entity{ new Entity{ 55 } };

	// shared_ptr<Entity> sp_Entity{ up_Entity }; // так нельзя 
	// sp_Entity = up_Entity; // так нельзя 

	// shared_ptr<Entity> sp_Entity = move(up_Entity);

	if (!up_Entity)
	{
		std::cout << "Unique Pointer is nullptr" << std::endl;
	}

	if (sp_Entity)
	{
		std::cout << "Shared Pointer is: ";
		sp_Entity->toString();
	}
#endif

#if 0
	unique_ptr<Entity> up_Entity{ new Entity{ 55 } };

	shared_ptr<Entity> sp_Entity{ up_Entity.release()};

	if (!up_Entity)
	{
		std::cout << "Unique Pointer is nullptr" << std::endl;
	}

	if (sp_Entity)
	{
		std::cout << "Shared Pointer is: ";
		sp_Entity->toString();
	}
#endif

#if 0
	unique_ptr<Entity> up_Entity{ new Entity{ 55 } };

	shared_ptr<Entity> sp_Entity;
	sp_Entity = move(up_Entity);

	if (!up_Entity)
	{
		std::cout << "Unique Pointer is nullptr" << std::endl;
	}

	if (sp_Entity)
	{
		std::cout << "Shared Pointer is: ";
		sp_Entity->toString();
	}
#endif

#if 0
	shared_ptr<Entity> sp_Entity{ new Entity{ 55 } };
	//unique_ptr<Entity> up_Entity;

	// unique_ptr<Entity> up_Entity{ sp_Entity }; //так нельзя
	// up_Entity = sp_Entity; //так нельзя
	// unique_ptr<Entity> up_Entity{ move(sp_Entity) }; //так нельзя
	unique_ptr<Entity> up_Entity{ sp_Entity.get() }; // так крашнется, нельзя!

	if (!up_Entity)
	{
		std::cout << "Unique Pointer is nullptr" << std::endl;
	}
	else
	{
		std::cout << "Unique Pointer is: ";
		up_Entity->toString();
	}
#endif

#if 0
	shared_ptr<Entity> sp_Entity = unique_prtEntityFactory(1);
	sp_Entity = unique_prtEntityFactory(2);

	if (!sp_Entity)
	{
		std::cout << "Shared Pointer is nullptr" << std::endl;
	}
	else
	{
		std::cout << "Shared Pointer is: ";
		sp_Entity->toString();
	}
#endif

#if 0
	unique_ptr<Entity> up_Entity = unique_prtEntityFactory(1);
	up_Entity = unique_prtEntityFactory(2);

	if (!up_Entity)
	{
		std::cout << "Unique Pointer is nullptr" << std::endl;
	}
	else
	{
		std::cout << "Unique Pointer is: ";
		up_Entity->toString();
	}
#endif

#if 1
	//unique_ptr<Entity> up_Entity = shared_prtEntityFactory(1); // не будет работать
	//up_Entity = shared_prtEntityFactory(2); // не будет работать

	shared_ptr<Entity> sp_Entity = shared_prtEntityFactory(1);
	sp_Entity = shared_prtEntityFactory(2);

	if (!sp_Entity)
	{
		std::cout << "Shared Pointer is nullptr" << std::endl;
	}
	else
	{
		std::cout << "Shared Pointer is: ";
		sp_Entity->toString();
	}
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
	}
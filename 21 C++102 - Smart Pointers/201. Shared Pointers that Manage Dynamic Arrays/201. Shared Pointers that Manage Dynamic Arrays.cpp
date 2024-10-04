// 201. Shared Pointers that Manage Dynamic Arrays

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

int main()
{
#if 0
	shared_ptr<int[]> sp_IntArray{ new int[2] {1, 2} };
	cout << sp_IntArray[0] << endl; //индексный оператор для shared_ptr появился в С++17, а именно упарвление массивами, хотя в студии всё работает и на С++14
#endif

#if 0
	shared_ptr<Entity[]> sp_EntityArray{ new Entity[2]{ Entity(55) } };
	sp_EntityArray[0].toString(); // возвращает объект Entity, поэтому используется точка 
	sp_EntityArray->toString(); // так нельзя!

	Entity* ptr = new Entity[2]{};
	ptr->toString(); //ptr — это указатель на первый элемент массива, поэтому можно использовать стрелку
	ptr[1].toString(); //ptr[1] — это объект Entity, поэтому используется точка

#endif

#if 1
	const int SIZE = 2;

	shared_ptr<Entity[]> sp_EntityArray = make_shared<Entity[]>(SIZE); // такой синтаксис не поддерживается до c++20
	sp_EntityArray[0].setMember(44);

	for (int i = 0; i < SIZE; i++)
	{
		sp_EntityArray[i].toString();
	}

#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
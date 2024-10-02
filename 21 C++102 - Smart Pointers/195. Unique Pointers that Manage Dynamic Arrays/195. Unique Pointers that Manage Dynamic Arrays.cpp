// 195. Unique Pointers that Manage Dynamic Arrays

#include <iostream>
#include <memory>

class Entity
{
public:
	Entity(int memberP = 44) { member = memberP; }
	~Entity() { std::cout << "Entity Destructor invoked. Member was: " << member << std::endl; }
	void toString() const { std::cout << member << std::endl; };
	void setMember(int memberP) { member = memberP; };
	int getMember() { return member; };

private:
	int member;
};

int main()
{
#if 0
	//Stack allocated Array

	const int SIZE = 3;

	Entity arr[SIZE]{ Entity(1), Entity(2), Entity(3) };

	for (int i = 0; i < SIZE; i++)
	{
		arr[i].toString();
	}
#endif

#if 0
	//Heap allocated Array

	const int SIZE = 3;
	Entity* p_arr = new Entity[SIZE]{ Entity(4), Entity(5), Entity(6) };

	for (int i = 0; i < SIZE; i++)
	{
		p_arr[i].toString();
	}

	delete[] p_arr;
#endif

#if 0
	//Heap allocated Array whith unique_ptr

	const int SIZE = 3;

	//std::unique_ptr<Entity[]> up_EntityArray = std::unique_ptr<Entity[]>(new Entity[SIZE]{ Entity(4), Entity(5), Entity(6) });
	auto up_EntityArray = std::unique_ptr<Entity[]>(new Entity[SIZE]{ Entity(4), Entity(5), Entity(6) });

	for (int i = 0; i < SIZE; i++)
	{
		up_EntityArray[i].toString();
	}

#endif

#if 0
	//Heap allocated Array whith unique_ptr

	const int SIZE = 3;

	auto up_EntityArray = std::make_unique<Entity[]>(SIZE);

	//initialize
	for (int i = 0; i < SIZE; i++)
	{
		up_EntityArray[i].setMember(i);
	}

	for (int i = 0; i < SIZE; i++)
	{
		up_EntityArray[i].toString();
	}

#endif

#if 1
	//Heap allocated Array whith unique_ptr

	const int SIZE = 3;

	// auto up_EntityArray{ new Entity[SIZE] };
	std::unique_ptr<Entity[]> up_EntityArray{ new Entity[SIZE] }; // тут вместо auto лучше явно указать тип

	//initialize
	for (int i = 0; i < SIZE; i++)
	{
		up_EntityArray[i].setMember(i);
	}

	for (int i = 0; i < SIZE; i++)
	{
		up_EntityArray[i].toString();
	}

#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
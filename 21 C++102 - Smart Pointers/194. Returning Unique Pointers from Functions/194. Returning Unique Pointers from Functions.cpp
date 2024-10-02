// 194. Returning Unique Pointers from Functions

#include <iostream>
#include <memory>

class Entity
{
public:
	Entity(int memberP = 44) { member = memberP; }
	~Entity() { std::cout << "Entity Destructor invoked." << std::endl; }
	void toString() const { std::cout << member << std::endl; };
	void setMember(int memberP) { member = memberP; };

private:
	int member;
};

void print(std::unique_ptr<Entity>&& uPtrP)
{
	if (uPtrP != nullptr)
		uPtrP->toString();
	else
		std::cout << "nullptr" << std::endl;
}

std::unique_ptr<Entity> uPtrEntityFactory(int p)
{
	std::unique_ptr<Entity> uPtr{ new Entity{ p } };

	return uPtr;
}

namespace E2
{
	std::unique_ptr<Entity> uPtrEntityFactory(int p)
	{
		// Implicit move operation
		return std::make_unique<Entity>(p);
	}
}


int main()
{
#if 0
	print(uPtrEntityFactory(55));

	uPtrEntityFactory(22)->toString();//временный объект
#endif

#if 0
	std::unique_ptr<Entity> up_Entity{ uPtrEntityFactory(22) };
	// std::unique_ptr<Entity> up_Entity = uPtrEntityFactory(22); // или так

	up_Entity->toString();

	std::cout << "Assignment..." << std::endl;
	up_Entity = uPtrEntityFactory(33);
	std::cout << "...following assignment" << std::endl;

	up_Entity->toString();
#endif

#if 1
	std::unique_ptr<Entity> up_Entity = E2::uPtrEntityFactory(22);

	up_Entity->toString();

	std::cout << "Assignment..." << std::endl;
	up_Entity = E2::uPtrEntityFactory(33); //move assignment operator
	std::cout << "...following assignment" << std::endl;

	up_Entity->toString();
#endif



#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
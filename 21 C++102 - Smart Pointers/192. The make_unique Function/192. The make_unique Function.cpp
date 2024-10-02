// 192. The make_unique Function

#include <iostream>
#include <memory>

template<typename T>
class Entity
{
public:
	Entity(T memberP = 44) { member = memberP; }
	~Entity() { std::cout << "Entity Destructor invoked." << std::endl; }
	void toString() const { std::cout << member << std::endl; };

private:
	T member;
};


int main()
{
	std::unique_ptr<Entity<int>> uEntityPtr1{ new Entity<int>{ 55 } };

	std::unique_ptr<Entity<int>> uEntityPtr2 = std::make_unique<Entity<int>>(22);
	uEntityPtr2->toString();

	auto uEntityPtr3 = std::make_unique<Entity<int>>(11);
	uEntityPtr3->toString();


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
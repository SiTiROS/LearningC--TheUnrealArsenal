// 203. Shared Pointer Implementation Technicalities

#include <iostream>
#include <memory>

struct Entity
{
	int a;
	int b;
	int c;

	Entity(int aP, int bP, int cP) : a(aP), b(bP), c(cP) {}
};

int main()
{
	std::unique_ptr<int> uPtr = std::make_unique<int>(33);
	std::shared_ptr<int> sPtr = std::make_shared<int>(33);
	std::weak_ptr<int> wPtr = sPtr;
	int* aPtr = new int(33);

	std::cout << sizeof(uPtr) << std::endl;
	std::cout << sizeof(sPtr) << std::endl;
	std::cout << sizeof(wPtr) << std::endl;
	std::cout << sizeof(aPtr) << std::endl;

	std::cout << std::endl;

	std::unique_ptr<Entity> uPtr1 = std::make_unique<Entity>(2, 2, 2);
	std::cout << sizeof(uPtr1) << std::endl;

	std::shared_ptr<Entity> sPtr1 = std::make_shared<Entity>(2, 2, 2);
	std::cout << sizeof(sPtr1) << std::endl;

	std::weak_ptr<Entity> wPtr1 = sPtr1;
	std::cout << sizeof(sPtr1) << std::endl;

	Entity* aPtr1 = new Entity(1, 2, 3);
	std::cout << sizeof(aPtr1) << std::endl;

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
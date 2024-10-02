// 196. Unique Pointers as Class Members

#include <iostream>
#include <memory>

class PointerManager
{
public:
	//Constructor
	PointerManager(int memberIni = 0) : member(new int(memberIni)) {}

	//Destructor
	~PointerManager() { delete member; }

	void toString()const { std::cout << *member << std::endl; }

private:
	int* member;
};

class PointerManagerS
{
public:
	//Constructor
	PointerManagerS(int memberIni = 0) : member(std::make_unique<int>(memberIni)) {}

	//Destructor
	~PointerManagerS() { std::cout << "Destructor invoked" << std::endl; }

	void toString()const { std::cout << *member << std::endl; }

private:
	std::unique_ptr<int> member;
};

int main()
{
#if 0
	PointerManager p(5);
	p.toString();
	//destructor 
#endif

#if 1
	PointerManagerS p;
	p.toString();
#endif


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
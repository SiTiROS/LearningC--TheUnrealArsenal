// 204. Useless Entity Exercise

#include <iostream>

class UselessEntity
{
public:
	UselessEntity(int memberP = 0) : member(memberP) 
	{
		delete this;
	}

	~UselessEntity()
	{
		std::cout << "UselessEntity Destructor Invoked. Member was: " << member << std::endl;
	}

private:
	int member;
};


int main()
{
	UselessEntity* ptr = new UselessEntity(44);
	ptr = nullptr;

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
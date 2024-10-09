// 226. Get a Pointer to the Character Array Managed by a Standard String

#include <iostream>

int main()
{
#if 0
	std::string str{ "Hello, human!" };

	const char* ptr = str.c_str();
	char* ptr2 = str.data(); // worked whitout const only in c++17

	ptr2[0] = '2';

	std::cout << ptr << std::endl;
#endif

#if 1
	std::string str1{ "Hello, human!" };
	std::string str2{ str1 };

	char* ptr1 = str1.data();
	char* ptr2 = str2.data();

	std::cout << "The adress in ptr1: " << &str1[0] << std::endl;
	std::cout << "The adress in ptr2: " << &str2[0] << std::endl;

	std::cout << "The adress in ptr1: " << (int*)str1.c_str() << std::endl;
	std::cout << "The adress in ptr2: " << (int*)str2.data() << std::endl;

	std::cout << "The adress in ptr1: " << (int*)ptr1 << std::endl;
	std::cout << "The adress in ptr2: " << (int*)ptr2 << std::endl;
#endif


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
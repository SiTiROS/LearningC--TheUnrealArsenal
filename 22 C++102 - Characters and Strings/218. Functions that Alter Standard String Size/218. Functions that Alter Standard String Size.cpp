// 218. Functions that Alter Standard String Size

#include <iostream>
#include <string>

int main()
{
#if 0
	std::string str1{ "Bob" };

	std::cout << "str1 is: " << str1 << std::endl;
	std::cout << "str1 size: " << str1.size() << std::endl;

	str1.clear();
	std::cout << "\nstr1 following clear(): " << str1 << std::endl;
	std::cout << "str1 size following clear(): " << str1.size() << std::endl;

	std::cout << "\nstr1 capacity: " << str1.capacity() << std::endl;
#endif

#if 0
	std::string str1{ "Bob" };

	std::cout << "str1 is: " << str1 << std::endl;
	std::cout << "str1 size: " << str1.size() << std::endl;
	std::cout << "str1 capacity: " << str1.capacity() << std::endl;

	str1.resize(25);
	std::cout << "\nstr1 following resize(): " << str1 << std::endl;
	std::cout << "str1 size following resize(): " << str1.size() << std::endl;
	std::cout << "str1 capacity following resize(): " << str1.capacity() << std::endl;
#endif

#if 0
	//std::string str1{ "Hello Human!" };
	std::string str1{ "1234567890" };

	std::cout << "str1 is: " << str1 << std::endl;
	std::cout << "str1 size: " << str1.size() << std::endl;
	std::cout << "str1 capacity: " << str1.capacity() << std::endl;

	//str1.erase(5, str1.size() - 6);
	//str1.erase(0, 5);
	str1.erase(5);
	std::cout << "\nstr1 following erase(): " << str1 << std::endl;
	std::cout << "str1 size following erase(): " << str1.size() << std::endl;
	std::cout << "str1 capacity following erase(): " << str1.capacity() << std::endl;
#endif

#if 1
	std::string str1{ "Hello Human" };

	std::cout << "str1 is: " << str1 << std::endl;
	std::cout << "str1 size: " << str1.size() << std::endl;
	std::cout << "str1 capacity: " << str1.capacity() << std::endl;

	//append argument character
	str1.push_back('!');
	std::cout << "\nstr1 following push_back(): " << str1 << std::endl;
	std::cout << "str1 size following push_back(): " << str1.size() << std::endl;
	std::cout << "str1 capacity following push_back(): " << str1.capacity() << std::endl;

	//remove final character
	str1.pop_back();
	std::cout << "\nstr1 following push_back(): " << str1 << std::endl;
	std::cout << "str1 size following push_back(): " << str1.size() << std::endl;
	std::cout << "str1 capacity following push_back(): " << str1.capacity() << std::endl;
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
// 219. Standard String Comparisons

#include <iostream>
#include <string>

int main()
{
#if 0
	std::string str1{ "Bob " };
	std::string str2{ "Bob" };

	std::cout << std::boolalpha;
	std::cout << str1 << " == " << str2 << " : " << (str1 == str2) << std::endl;
	std::cout << str1 << " != " << str2 << " : " << (str1 != str2) << std::endl;
	std::cout << str1 << " > " << str2 << " : " << (str1 > str2) << std::endl;
	std::cout << str1 << " >= " << str2 << " : " << (str1 >= str2) << std::endl;
	std::cout << str1 << " < " << str2 << " : " << (str1 < str2) << std::endl;
	std::cout << str1 << " <= " << str2 << " : " << (str1 <= str2) << std::endl;
#endif

#if 0
	std::string str1{ "Bob" };

	char cstr[]{ 'B', 'o', 'b', 0 };

	std::cout << std::boolalpha;
	std::cout << str1 << " == " << cstr << " : " << (str1 == cstr) << std::endl;
#endif

#if 0
	std::string str1{ "Bob" };
	std::string str2{ "Bob2" };

	char cstr[]{ 'B', 'o', 'b', 0 };

	std::cout << "str1.compare(cstr): " << str1.compare(cstr) << std::endl;

	if (str1.compare(cstr) == 0)
	{
		std::cout << str1 << " and " << cstr << " are equal " << std::endl;
	}
	else
	{
		std::cout << str1 << " and " << cstr << " are not equal " << std::endl;
	}
#endif

#if 1
	std::string str1{ "Hello" };
	std::string str2{ "Hello Human!" };

	std::cout << "str2.compare(0, 5, str1): " << str2.compare(0, 5, str1) << std::endl;

	if (str2.compare(0, 5, str1) == 0)
	{
		std::cout << "equal " << std::endl;
	}
	else
	{
		std::cout << "not equal " << std::endl;
	}
#endif
#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
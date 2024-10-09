// 223. Raw String Literals

#include <iostream>
#include <string>


int main()
{
#if 0
	std::string str1{ "Test text, \nTest text, \nTest text, \nTest text, \nTest text, \nTest text, \nTest text. " };
	std::string str2{ R"_(
---
Test text, 
Test text, 
Test text, 
Test text, 
Test text, 
Test text, 
(Test text), )_" };

	char cstr[]{ R"(
---
Test text, 
Test text, 
Test text, 
Test text, 
Test text, 
Test text, 
Test text, )" };

	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	std::cout << cstr << std::endl;
#endif

#if 1
	std::string str1{ "C:\\Users\\Bob\\Documents\\TODO.txt" };
	std::string str2{ R"(C:\Users\Bob\Documents\TODO.txt)" };

	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
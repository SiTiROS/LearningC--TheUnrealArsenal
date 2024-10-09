// 221. Operating on Standard String Substrings

#include <iostream>
#include <string>

int main()
{
#if 0
	std::string str1{ "Hello Human!" };
	std::cout << "str1: " << str1 << std::endl;

	// Return a string object initialized to a substring of this object.
	// Argument 1: index/position of first character
	// Argument 2: Number of characters to copy from *this to create new substring
	std::cout << "Substring of str1: " << str1.substr(6, 5) << std::endl;

	std::cout << "str1 size: " << str1.size() << std::endl;
	std::cout << "str1 capacity: " << str1.capacity() << std::endl;
#endif

#if 0
	std::string str1{ "Bob" };

	str1.insert(3, 1, '!'); //add 1 symbol ! 
	//str1.insert(3, 11, '!'); //add 11 symbol !
	std::cout << str1 << std::endl;
#endif

#if 0
	std::string str1{ "Hello !" };
	std::string str2{ "Humans" };

	std::cout << "str1 size: " << str1.size() << std::endl;

	//str1.insert(6, str2);
	str1.insert(6, str2, 2, 3);

	std::cout << "str1: " << str1 << std::endl;

	std::cout << "str1 size following insert(): " << str1.size() << std::endl;
#endif

#if 0
	std::string str1{ "Hello !" };
	char cstr[]{ "Humans" };

	std::cout << "str1 size: " << str1.size() << std::endl;

	str1.insert(6, cstr, 6);
	std::cout << "str1: " << str1 << std::endl;

	std::cout << "str1 size following insert(): " << str1.size() << std::endl;
#endif

#if 0
	std::string str1{ "Wait, Bob!" };
	std::string str2{ "Halt!" };
	char cstr[]{ "Halt" };

	std::cout << str1 << std::endl;
	//str1.replace(0, 4, str2);
	str1.replace(0, 4, str2, 0, 5);

	std::cout << "str1 following replace(): " << str1 << std::endl;
#endif

#if 1
	std::string str1{ "Halt, Bob!" };
	char cstr[15]{};

	// Copy substring from *this std::string instance, to a C-String.
	// Arguments: C-String, number of characters, index.
	//str1.copy(cstr, 11, 0);
	//str1.copy(cstr, 4, 6);
	std::size_t cstr_lenght = str1.copy(cstr, 4, 6); // return finish index

	cstr[cstr_lenght] = 0; //finish symbol

	std::cout << cstr << std::endl;
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
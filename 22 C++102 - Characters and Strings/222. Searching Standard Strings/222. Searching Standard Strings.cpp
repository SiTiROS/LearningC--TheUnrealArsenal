// 222. Searching Standard Strings

#include <iostream>
#include <string>

int main()
{
#if 0
	std::string str{ "Where is Bob!\?" };
	std::string strToFind{ "is" };
	char cstr[]{ "is" };

	std::cout << cstr << std::endl;

	//Return starting index of substring in *this
	std::cout << str.find("is") << std::endl;

	for (size_t i = 0; i < str.length(); i++)
	{
		std::cout << i << " " << str[i] << std::endl;
	}
#endif

#if 0
	std::string str{ "Where is Bob!\?" };
	std::string strToFind{ "is" };
	char cstr[]{ "is" };

	std::cout << cstr << std::endl;

	//Return starting index of substring in *this
	std::cout << str.find("dsfd") << std::endl;

	size_t t{ size_t(-1) };
	std::cout << "std::string::npos is : " << std::string::npos << std::endl;
	std::cout << "t is : " << t << std::endl;
#endif

#if 0
	std::string str{ "Where is Bob!\?" };
	std::string strToFind{ "is" };
	char cstr[]{ "is" };

	std::cout << str << std::endl;

	size_t position = str.find("is");

	if (position != std::string::npos)
	{
		std::cout << position << std::endl;
	}
	else
	{
		std::cout << "not found" << std::endl;
	}
#endif

#if 1
	std::string str{ "Day one. Day one. Day one. Day four..." };
	std::string strToFind{ "one" };

	std::cout << str << std::endl;

	//size_t position = str.find(strToFind); // find first string
	//size_t position = str.rfind(strToFind); // find last string
	size_t position = str.find(strToFind, 20); // find string for index

	if (position != std::string::npos)
	{
		str.replace(position, strToFind.length(), "three");
	}

	position = str.rfind(strToFind);

	if (position != std::string::npos)
	{
		str.replace(position, strToFind.length(), "two");
	}

	std::cout << str << std::endl;
#endif


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
// 216. Accessing Characters in the Standard String

#include <iostream>
#include <string>

int main()
{
#if 0
	std::string s1{ "Bob" };
	s1 = "Hello";

	s1[0] = 'M';
	//s1.at(0) = 'M';

	for (size_t i = 0; i < s1.size(); i++)
	{
		//std::cout << s1[i] << std::endl;
		std::cout << s1.at(i) << std::endl;
	}

	for (char c : s1)
	{
		std::cout << c << " ";
	}
#endif

#if 1
	std::string s1{ "Bob" };

	//s1.front() = 'M';

	char& c = s1.front();
	c = 'M';

	std::cout << s1.front() << std::endl; // first symbol
	std::cout << s1.back() << std::endl; // end symbol
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
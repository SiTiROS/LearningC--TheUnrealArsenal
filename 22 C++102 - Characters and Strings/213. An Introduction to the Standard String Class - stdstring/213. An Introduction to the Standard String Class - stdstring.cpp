// 213. An Introduction to the Standard String Class - stdstring

#include <iostream>
#include <string>

int main()
{
	std::string s1{ "Hello Human!" };
	std::string s2{ "Hello Human!", 5 };
	std::string s3(3, 'X');  // XXX
	std::string s4{ s1, 0, 5 }; // Hello
	std::string s5 = s1;

	std::string s6{"Bob"};
	s6 = s1;
	s6 = "Hello Human!";

	std::cout << s6 << std::endl;

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
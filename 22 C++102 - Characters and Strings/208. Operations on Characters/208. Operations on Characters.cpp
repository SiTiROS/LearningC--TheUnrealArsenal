// 208. Operations on Characters

#include <iostream>
#include <cctype>

int main()
{
	char myChar{ '!' };
	myChar = toupper(myChar);

	if (isalpha(myChar))
		std::cout << myChar << " is alphabetic." << std::endl;

	if (isupper(myChar))
		std::cout << myChar << " is a uppercase letter." << std::endl;

	if (islower(myChar))
		std::cout << myChar << " is a lowercase letter." << std::endl;

	if (ispunct(myChar))
		std::cout << myChar << " is a punctuation character." << std::endl;

	if (isdigit(myChar))
		std::cout << myChar << " is a digit." << std::endl;



#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
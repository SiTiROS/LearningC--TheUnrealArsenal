// 207. The char Type and ASCII Codes

#include <iostream>

int main()
{
	char myChar{ 'X' };
	std::cout << "myChar is: " << myChar << std::endl;
	
	myChar = 'Y';
	std::cout << "myChar is: " << myChar << std::endl;

	myChar = 120; //ASCII code
	std::cout << "myChar is: " << myChar << std::endl;
	
	myChar = 89; //ASCII code
	std::cout << "myChar is: " << myChar << std::endl;

	std::cout << "Code in myChar is: " << static_cast<int>(myChar) << std::endl;


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
// 209. An Introduction to C-Strings

#include <iostream>

int main()
{
#if 0
	char arr[]{ 'x', 'y', 'z' };

	for (int i = 0; i < 3; i++)
	{
		std::cout << arr[i] << std::endl;
	}
#endif

#if 0
	//char arr[]{ 'x', 'y', 'z' };
	char arr[]{ 'x', 'y', 'z', 0 };
	std::cout << arr << std::endl;
#endif

#if 0
	char arr[]{ 'x', 'y', 'z'};

	char C_String[]{ 'x', 'y', 'z', '\0' };

	std::cout << C_String << std::endl;
#endif

#if 0
	char C_String[4]{ 'x', 'y', 'z' };

	std::cout << C_String << std::endl;

#endif

#if 1
	char C_String[]{ "Hello" };

	std::cout << C_String << std::endl;

#endif


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
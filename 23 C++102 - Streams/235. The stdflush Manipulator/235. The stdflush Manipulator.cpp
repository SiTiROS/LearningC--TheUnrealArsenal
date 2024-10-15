// 235. The stdflush Manipulator

#include <iostream>

int main()
{
#if 1
	int x{};

	std::cout << "Enter your favorite number: " << std::flush;
	//std::cout.flush();
	std::cin >> x;

	std::cout << std::showpos;
	std::cout << "Your favorite number is: " << x << std::endl;
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
// 215. Swapping Standard Strings

#include <iostream>
#include <string>

int main()
{
	std::string player1{ "Bob" };
	std::string player2{ "Car1" };

	std::cout << "Player one: " << player1 << std::endl;
	std::cout << "Player two: " << player2 << std::endl;

	player1.swap(player2);
	std::cout << "\nAfter swapping the players:" << std::endl;

	std::cout << "Player one: " << player1 << std::endl;
	std::cout << "Player two: " << player2 << std::endl;
#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
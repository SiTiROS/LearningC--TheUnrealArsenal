// 184. The Lambda Expression Capture Clause
#include <iostream>

int main()
{
#if 0
	int x{ 3 }, y{ 5 };

	auto increment = [=, &y]() mutable
	{
		y++;
		x++;
		std::cout << x << '\t' << y << std::endl;
		std::cout << &x << '\t' << &y << std::endl;
	};

	increment();

	std::cout << x << '\t' << y << std::endl;
	std::cout << &x << '\t' << &y << std::endl;

#endif

#if 1
	int x{ 3 }, y{ 5 };

	auto increment = [&, x]() mutable
	{
		y++;
		x++;
		std::cout << x << '\t' << y << std::endl;
};

	increment();

	std::cout << x << '\t' << y << std::endl;
#endif

#if 0
#endif
	std::cout << "END" << std::endl;
	return 0;
}
// 182. Predefined Function Objects

#include <iostream>
#include <functional>  // https://en.cppreference.com/w/cpp/utility/functional

namespace Example
{
	class Square_Functor
	{
	public:
		int operator()(int p) const { return (p * p); }
	};

	class Addition_Functor
	{
	public:
		int operator()(int lho, int rho) const { return (lho + rho); }
	};
}

int main()
{
	std::plus<int> addition;
	std::minus<int> substraction;
	std::greater<int> greaterThan;
	std::less<int> lessThan;

	std::cout << "5 + 3: " << addition(5, 3) << std::endl;
	std::cout << "5 - 3: " << substraction(5, 3) << std::endl;
	
	
	std::cout << std::boolalpha;
	std::cout << "5 > 3: " << greaterThan(5, 3) << std::endl;
	std::cout << "5 < 3: " << lessThan(5, 3) << std::endl;

#if 0
#endif
	std::cout << "END\n";
	return 0;
}
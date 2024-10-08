// 214. Concatenation with the Standard String

#include <iostream>
#include <string>

int main()
{
#if 0
	std::string s1{ "Hello" };
	std::string s2{ "Human" };
	std::string s3 = s1 + " " + s2;
	std::string s4{ s1 + '\n' + s2 };
	//std::string s5 {"Hello" + "Human!"}; // не будет работать! надо хотя бы 1 массив преобразовать 
	std::string s5{ std::string("Hello") + "Human!" }; // С style cast
	std::string s6{ static_cast<std::string>("Hello") + "Human!" };
	std::string s7{ std::string{"Hello"} + "Human!" }; // временая инициализация

	std::cout << s5 << std::endl;
	std::cout << s6 << std::endl;
	std::cout << s7 << std::endl;
#endif

#if 0
	std::string s1{ "Hello" };
	std::string s2{ "Human" };
	std::string s3{ std::string("Hello") };

	char cString[]{ " Human!" };

	//std::cout << s3.append(" Human!") << std::endl;
	std::cout << s3.append(cString) << std::endl;
#endif

#if 0
	std::string s1{ "Hello" };
	std::string s2{ "Human" };
	std::string s3{ };

	s3.append("Hello Human!", 5);
	//s3.append(s1);
	s3.append(" ");
	s3.append(s2, 2, 4); // со 2ого символа скопировать 4 символа - man!

	std::cout << s3 << std::endl;
#endif

#if 0
	using namespace std::string_literals;
	std::cout << "Hello"s + " Human!" << std::endl;
#endif

#if 1
	std::string s1{ "Hello " };
	std::cout << s1 + std::to_string(16.5f) << std::endl;

#endif


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
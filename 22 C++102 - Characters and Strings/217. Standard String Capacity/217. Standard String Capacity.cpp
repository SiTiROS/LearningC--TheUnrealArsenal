// 217. Standard String Capacity

#include <iostream>
#include <string>


int main()
{
	std::string str1{ "Bob" };

	if (!str1.empty())
	{
		std::cout << "str1 is: " << str1 << std::endl;

		// return the string size/lenght of the string in bytes
		std::cout << "str1 size: " << str1.size() << std::endl;
		std::cout << "str1 length: " << str1.length() << std::endl;

		// return the currently allocated size for the string in bytes
		std::cout << "str1 capacity: " << str1.capacity() << std::endl;
	}

	// automatically reallocate and expand the capacity
	str1 = "Hello Humans! Don't run, we are your friends!";
	std::cout << "\nstr1 is: " << str1 << std::endl;
	std::cout << "str1 capacity: " << str1.capacity() << std::endl;
	std::cout << "str1 size: " << str1.size() << std::endl;

	// request a change in capacity
	str1.reserve(80);
	std::cout << "\nstr1 capacity following reserve(80): " << str1.capacity() << std::endl;

	// request the reduction of capacity to fit the size
	str1.shrink_to_fit();
	std::cout << "\nstr1 capacity following shrink_to_fit(): " << str1.capacity() << std::endl;
	
	// return maximum size/lenght of managed string
	std::cout << "\nstr1 max_size(): " << str1.max_size() << std::endl;


#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
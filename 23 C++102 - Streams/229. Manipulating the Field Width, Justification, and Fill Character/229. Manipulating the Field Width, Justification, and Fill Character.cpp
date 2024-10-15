// 229. Manipulating the Field Width, Justification, and Fill Character

#include <iostream>
#include <iomanip>

int main()
{
#if 0
	char gradeMaths = 'A';
	char gradePhysics = 'B';
	char gradeEnglish = 'C';

	std::cout << "SUBJECT\t\t" << "GRADE" << std::endl;

	std::cout << "Maths:\t\t" << gradeMaths << std::endl;
	std::cout << "Physics:\t" << gradePhysics << std::endl;
	std::cout << "English:\t" << gradeEnglish << std::endl;
#endif

#if 0
	char gradeMaths = 'A';
	char gradePhysics = 'B';
	char gradeEnglish = 'C';

	std::cout << "SUBJECT\t\t" << "GRADE" << std::endl;

	std::cout.width(8);
	std::cout.fill('-');
	std::cout << std::right << "Math:" << gradeMaths << std::endl;
	std::cout << "Physics:" << gradePhysics << std::endl;
	std::cout << "English:" << gradeEnglish << std::endl;
#endif

#if 0
	char gradeMaths = 'A';
	char gradePhysics = 'B';
	char gradeEnglish = 'C';

	std::cout << std::setw(8) << "SUBJECT" << std::setw(8) << "GRADE" << std::endl;

	std::cout << std::setw(8) << "Math:" << std::setw(8) << gradeMaths << std::endl;
	std::cout << std::setw(8) << "Physics:" << std::setw(8) << gradePhysics << std::endl;
	std::cout << std::setw(8) << "English:" << std::setw(8) << gradeEnglish << std::endl;
#endif

#if 0
	char gradeMaths = 'A';
	char gradePhysics = 'B';
	char gradeEnglish = 'C';

	unsigned int width{ 8 };

	std::cout << std::right;
	std::cout << std::setw(width) << "SUBJECT" << std::setw(width) << "GRADE" << std::endl;

	std::cout << std::setw(width) << "Math:" << std::setw(width) << gradeMaths << std::endl;
	std::cout << std::setw(width) << "Physics:" << std::setw(width) << gradePhysics << std::endl;
	std::cout << std::setw(width) << "English:" << std::setw(width) << gradeEnglish << std::endl;
#endif

#if 1
	unsigned int fieldWidth{ 12 };

	std::cout << std::right;
	std::cout.fill('-');

	std::cout << std::setw(fieldWidth) << "First Name:" << std::setw(fieldWidth) << "Last Name:"
		<< std::setw(fieldWidth) << "Age:" << std::endl;
	std::cout << std::setw(fieldWidth) << "Avril" << std::setw(fieldWidth) << "Lavigne"
		<< std::setw(fieldWidth) << "37" << std::endl;
	std::cout << std::setw(fieldWidth) << "Bob" << std::setw(fieldWidth) << "Adams"
		<< std::setw(fieldWidth) << "97" << std::endl;
	std::cout << std::setw(fieldWidth) << "David" << std::setw(fieldWidth) << "Smith"
		<< std::setw(fieldWidth) << "45" << std::endl;
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
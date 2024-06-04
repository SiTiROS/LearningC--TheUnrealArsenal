#include <iostream>
using namespace std;

struct Vector2D
{
	float x{};
	float y{};

	Vector2D operator-() const;
};

Vector2D Vector2D::operator-() const
{
	Vector2D temp;
	temp.x = -x;
	temp.y = -y;

	return temp;
}
// тест

int main()
{
	// int x{5}, y{55};
	// ++x;
	// x = x + y;
	// cout << x << endl;
	// cout << y << endl;

	// Vector2D vec1, vec2{ 15.0f, 5.0f };
	// cout << vec1.x << " " << vec1.y << endl;
	// cout << vec2.x << " " << vec2.y << endl;

	// vec1++;
	// vec1 = vec1 + vec2;
	// cout << vec1 << endl;

	// cout.operator<<(vec2.y);

	// int x{}, y{ 5 };
	// x = -y;
	// cout << x << endl;
	// cout << y << endl;

	Vector2D vec1, vec2{ 15.0f, 5.0f };

	vec1 = -vec2;
	cout << vec1.x << endl;
	cout << vec2.y << endl;

	cout << endl;
	return 0;
}

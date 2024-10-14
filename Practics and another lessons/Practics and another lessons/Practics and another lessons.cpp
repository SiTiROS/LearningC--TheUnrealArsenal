// Practics and another lessons

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <string>
#include <random>
//#include <iterator>

struct People
{
	std::string name, surname;
	int age, money;

	bool operator<(const People& other) const
	{
		std::cout << "age: " << age << std::endl;
		std::cout << "other.age: " << other.age << std::endl;

		return age < other.age;
	}

	People& operator+=(const People& other)
	{
		age += other.age;
		return *this;
	}

	bool operator==(const People& other) const
	{
		return name == other.name && surname == other.surname && age == other.age && money == other.money;
	}
};

bool operator>(const People& left, People& right)
{
	std::cout << "left.age: " << left.age << std::endl;
	std::cout << "right.age: " << right.age << std::endl;

	return left.age > right.age;
}

bool greaterComporator(const People& left, People& right)
{
	return left.age > right.age;
}

// istream = in stream
std::istream& operator>>(std::istream& in, People& b)
{
	in >> b.name >> b.surname >> b.age >> b.money;
	return in;
}

// ostream = out stream
std::ostream& operator<<(std::ostream& in, People& b)
{
	in << b.name << b.surname << b.age << b.money;
	return in;
}

template<class T, class C>
std::istream& operator>>(std::istream& in, std::pair<T, C>& p)
{
	in >> p.first >> p.second;
	return in;
}


struct Line
{
	int a;
	int b;

	Line(int x, int y) : a(x), b(y)
	{}

	int operator()(int x) const
	{
		return a * x + b;
	}

	int operator[](int x) const
	{
		return a * x + b;
	}

	int calc(int x) const
	{
		return a * x + b;
	}

	Line operator*(int x)
	{
		/*return Line // c++20
		{
			.a = a * x,
			.b = b
		};*/
		return Line
		{
			a = a * x,
			b
		};
	}

	Line operator*(Line& other)
	{
		return Line
		{
			a = a * other.a,
			b
		};
	}

	//operator int() const
	//{
	//	return 12;
	//}
};


struct MyStruct
{
	int z, x, c, v, b, n, m;

	MyStruct(int z, int x, int c, int v, int b, int n, int m) : z(z), x(x), c(c), v(v), b(b), n(n), m(m)
	{
	}

	MyStruct(int aP, int bP)
	{
		z = aP, x = bP;
		c = v = b = n = m = 0;
	}
};

struct Struct2
{
	Struct2(int n) : sum(n), vec(n, 1)
	{}

	void add(int x)
	{
		vec.push_back(x);
		sum += x;
	}

	int sum;
	std::vector<int> vec;
};

void print(std::vector<int>& vecP)
{
	for (auto& item : vecP)
	{
		std::cout << item << ' ';
	}
	std::cout << std::endl;
}

std::string dash_fold(std::string a, int b)
{
	return a + '-' + std::to_string(b);
}

int main()
{
#if 0
	//std::vector<std::pair<std::string, int>> peoples(2);
	std::vector<std::pair<std::string, int>> peoples(5, { "unknown", 0 });

	//peoples.resize(2);

	/*for (auto &item : peoples)
	{
		std::cin >> item.first >> item.second;
	}*/

	for (auto item : peoples)
	{
		std::cout << item.first << " " << item.second << std::endl;
	}
#endif

#if 0
	std::vector<std::pair<std::pair< std::string, std::string>, int>> peoples;

	for (auto& item : peoples)
	{
		std::cin >> item.first.first >> item.first.second >> item.second;
	}

	for (auto item : peoples)
	{
		std::cout << item.first.first << " " << item.first.second << " " << item.second << std::endl;
	}
#endif

#if 0
	std::vector<People> peps{ {} };
	for (auto& item : peps)
	{
		std::cin >> item.name >> item.surname >> item.age >> item.money;
	}

	for (auto& item : peps)
	{
		std::cout << item.name << item.surname << item.age << item.money << std::endl;
	}

	for (auto& [name, surname, age, money] : peps) // c++17
	{
		std::cout << "name: " << name << std::endl;
		std::cout << "surname: " << surname << std::endl;
		std::cout << "age: " << age << std::endl;
		std::cout << "money: " << money << std::endl;
	}
#endif

#if 0
	People bab{ "Anna", "ASD", 88, 3333 };
	auto [name, surname, age, money] = bab;

	std::cout << "name: " << name << std::endl;
	std::cout << "surname: " << surname << std::endl;
	std::cout << "age: " << age << std::endl;
	std::cout << "money: " << money << std::endl;

#endif

#if 0
	std::pair<int, int> pair{ 1,2 };
	auto [x, y] = pair;

	std::cout << y << x;
#endif

#if 0
	std::vector<People> peoples{ 1 };
	for (auto& pep : peoples)
	{
		std::cin >> pep;
	}

	for (auto& pep : peoples)
	{
		std::cout << pep;
	}

	std::pair<int, int> p;
	std::cin >> p;
#endif

#if 0
	People b
	{
		.name = "A",
		.surname = "B",
		.age = 85,
		.money = 10753
	}; // C++20
#endif

#if 0
	std::vector<People> pep
	{
		{ "A", "B", 80, 1},
		{ "C", "D", 70, 2}
	};

	std::cout << std::boolalpha;
	std::cout << pep[0].operator<(pep[1]);
	std::cout << std::endl;

	std::cout << pep[0] << std::endl;
	std::cout << pep[1] << std::endl;
	std::cout << std::endl;

	std::cout << (*pep.begin() < pep.back());
	std::cout << std::endl;

	std::cout << pep.begin()->age << std::endl;
	std::cout << pep.back().age << std::endl;
	std::cout << std::endl;

	std::cout << *pep.begin() << std::endl;
	std::cout << pep.back() << std::endl;
	std::cout << std::endl;

	std::cout << "sort: " << std::endl;
	std::sort(pep.begin(), pep.end());
	std::cout << std::endl;

	std::cout << *pep.begin() << std::endl;
	std::cout << pep.back() << std::endl;
	std::cout << std::endl;
#endif

#if 0
	std::vector<People> pep
	{
		{ "A", "B", 80, 1},
		{ "C", "D", 70, 2}
	};

	std::cout << pep[0].age << std::endl;
	std::cout << pep[1].age << std::endl;
	std::cout << std::endl;

	pep[0] += pep[1];

	std::cout << pep[0].age << std::endl;
	std::cout << pep[1].age << std::endl;
	std::cout << std::endl;
#endif

#if 0
	std::vector<People> pep
	{
		{ "A", "B", 80, 1},
		{ "A", "B", 80, 1},
		{ "C", "D", 70, 2}
	};

	std::cout << (pep[0] == pep[1]);
#endif

#if 0
	std::vector<People> pep
	{
		{ "A", "B", 80, 1},
		{ "C", "D", 70, 2}
	};

	std::cout << std::boolalpha;
	std::cout << (pep[0] > pep[1]);

	std::cout << std::endl;

	std::cout << (*pep.begin() > pep.back());
	std::cout << std::endl;
#endif

#if 0
	std::vector<People> pep
	{
		{ "A", "B", 11, 1},
		{ "A", "B", 43, 1},
		{ "A", "B", 23, 1},
		{ "C", "D", 70, 2}
	};

	for (auto& item : pep)
	{
		std::cout << item.age << std::endl;
	}

	std::cout << std::endl;

	std::cout << "sort whith functor: " << std::endl;
	std::sort(pep.begin(), pep.end(), greaterComporator);

	std::cout << std::endl;

	for (auto& item : pep)
	{
		std::cout << item.age << std::endl;
	}

	std::cout << std::endl;

	std::cout << "sort whith lambda: " << std::endl;
	std::sort(pep.begin(), pep.end(), [](const People& left, People& right) {return left.age < right.age; });

	std::cout << std::endl;

	for (auto& item : pep)
	{
		std::cout << item.age << std::endl;
	}
#endif

#if 0
	Line l{ 5, 2 };
	std::cout << l.calc(1) << std::endl;
	std::cout << l(1) << std::endl;
	std::cout << l[1] << std::endl;

	Line a{ 2, 2 };
	Line b{ 2, 2 };
	std::cout << (a * 2).a << std::endl;
	std::cout << (a * b).a << std::endl;

	std::cout << int(a) << std::endl;
	std::cout << static_cast<int>(a) << std::endl;
#endif

#if 0
	//	z, x, c, v, b, n, m; 
	MyStruct ms{ 1, 2, 3, 4, 5, 6, 7 };
	MyStruct ms2{ 1, 2 };

	std::vector<Line> v;
	v.push_back({ 1, 2 });
	v.emplace_back(2, 3);

	std::cout << v[0].a << ' ' << v[0].b << std::endl;
	std::cout << v[1].a << ' ' << v[1].b << std::endl;


	std::set<Line> l;
	l.insert(Line{ 5, 4 });
#endif

#if 0
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	std::vector<int> vec2{ 1, 2, 3, 4, 5 };

	auto it = vec.begin();
	std::vector<int>::iterator it2 = vec2.begin();

	std::cout << *it << std::endl; // значение вектора который хранит итератор
	std::cout << *it2 << std::endl; // значение вектора который хранит итератор

	std::cout << &it << std::endl; // адресс итератора
	std::cout << &it2 << std::endl; // адресс итератора

	std::cout << &(*it) << std::endl; // адресс 1 элемента в векторе
	std::cout << &(*it2) << std::endl; // адресс 1 элемента в векторе

	std::cout << &vec << std::endl; // адресс всего вектора
	std::cout << &vec2 << std::endl; // адресс всего вектора

	std::cout << &vec[0] << std::endl; // адресс 1 элемента в векторе
	std::cout << &vec2[0] << std::endl; // адресс 1 элемента в векторе

	for (it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	for (auto& i : vec)
	{
		std::cout << i << std::endl;
	}

	std::cout << std::endl;
	std::cout << *it2 << std::endl;

	++it2;
	std::cout << *it2 << std::endl;
#endif

#if 0
	std::vector<int> vec = { 1, 2, 3, 4, 5 };

	std::vector<int>::iterator it = std::max_element(vec.begin(), vec.end());
	std::cout << *it << std::endl;

	std::cout << (it - vec.begin()) << std::endl;
	std::cout << *it << std::endl;

	std::cout << std::distance(vec.begin(), it) << std::endl;
	std::cout << *it << std::endl;

	std::cout << std::endl;
	std::cout << *vec.rbegin() << std::endl; // указывает на последний
	std::cout << vec.back() << std::endl; //вернёт значение последнего элемента
	//std::cout << *vec.rend() << std::endl; // указывает на перед первым
	//std::cout << *vec.end() << std::endl; // указывает на после последнего
	std::cout << std::endl;

	//vec.back() == vec[vec.size() - 1];
	//vec.front() == vec[0];

	std::sort(vec.begin(), vec.end());
	std::sort(vec.begin() + 1, vec.end() - 1);
	std::sort(vec.begin() + 1, vec.begin() + 1);
	std::sort(vec.begin() + 1, vec.begin() + 2);

	std::reverse(vec.begin(), vec.end());
	std::sort(vec.rbegin(), vec.rend());

	for (auto& i : vec)
	{
		std::cout << i << std::endl;
	}
#endif

#if 0
	std::set<int> s = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	auto it = s.begin();
	std::set<int>::iterator it2 = ++s.begin();

	std::cout << "*it: " << *it << std::endl;
	std::cout << "*it2: " << *it2 << std::endl;

	++it;
	std::cout << "*it: " << *it << std::endl;

	--it;
	std::cout << "*it: " << *it << std::endl;

	//it+=5; //нельзя
	std::advance(it, 5); // equal it+=5
	std::cout << "*it: " << *it << std::endl;

	std::cout << std::endl;

	//it2 - it; //нельзя
	std::cout << "distance(): " << std::distance(it2, it) << std::endl;

	std::cout << std::endl;
	std::cout << "*s.begin(): " << *s.begin() << std::endl; // get first element 

	std::cout << "std::next(s.begin(), 1): " << *std::next(s.begin(), 1) << std::endl; // get second element 
	std::cout << "std::next(s.begin(), 5): " << *std::next(s.begin(), 5) << std::endl; // get 6 element 

	std::cout << "std::prev(s.end(), 1): " << *std::prev(s.end(), 1) << std::endl; // get 9 element 
#endif

#if 0
	int n;

	std::cout << "Enter n vector: ";
	std::cin >> n;
	std::vector<int> vec;

	vec.reserve(n); // так будет быстрее работать, так как память будет выделена заранее и не будет реалокаций

	for (size_t i = 0; i < n; i++)
	{
		int x;
		std::cout << "Add x in vector: ";
		std::cin >> x;
		vec.push_back(x);
	}

	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
#endif

#if 0
	std::vector<int> vec;

	for (size_t i = 0; i < 34; i++)
	{
		std::cout << "vec.size: " << vec.size() << " vec.capacity: " << vec.capacity() << std::endl;
		vec.push_back(i);
	}
#endif

#if 0
	std::vector<int> vec{ 1, 2 };

	vec.resize(6); // Изменяет размер вектора без выделений памяти, но если надо выделит с реалокацией
	//vec.resize(6, 0); // Изменяет размер вектора, и элементы 0 заполняет

	vec[2] = 3;
	vec[3] = 4;

	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
#endif

#if 0
	std::vector<int> vec;
	for (size_t i = 0; i < 300; i++)
	{
		vec.push_back(i);
	}

	std::cout << "Capacity before shrink_to_fit() is: " << vec.capacity() << std::endl;

	vec.shrink_to_fit();
	std::cout << "Capacity after shrink_to_fit() is: " << vec.capacity() << std::endl;

	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
#endif

#if 0
	std::vector<int> vec;

	vec.push_back(1);//добавляем в конец + реалоцируем память если надо
	vec.push_back(2);

	vec.pop_back(); //удаляем с конца
	vec.pop_back();

	vec.emplace_back(3);
	vec.emplace_back(1);
	vec.emplace_back(2);

	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
#endif

#if 0
	std::vector<Struct2> vec;

	Struct2 value(3);     //создаём объект структуры
	vec.push_back(value); // копируем обект в вектор

	vec.emplace_back(3); //вызовет конструктор у структуры и поместит объект в вектор


	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i].sum << std::endl;

		for (size_t j = 0; j < vec[i].vec.size(); j++)
		{
			std::cout << vec[i].vec[j] << std::endl;
		}
		std::cout << std::endl;
	}
#endif

#if 0
	//Доступ по индексу	O(1)
	//Добавление в конец	O(1) (амортизированная)
	//Удаление с конца	O(1)
	//Вставка / удаление в середине	O(n)
	//Вставка нескольких элементов	O(n + m)
	//Изменение размера	O(n)
	//Резервирование памяти	O(n)

	std::vector<int> vec{ 1, 2, 3, 4, 5, 6 };
	int pos = 2;

	vec.insert(vec.begin() + pos, 5); //вставить элемент - передаём итератор и число которое вставляем,  O(n)

	vec.erase(vec.begin() + pos + 1); //удалить элемент - передаём итератор,  O(n)

	std::cout << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
#endif

#if 0
	std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8 };

	vec.assign(5, 2); // Полностью заменяет содержимое вектора новыми элементами
	// заменит элементы вектора на 5 элементов с числами 2, 
	// посути почти то же самое что и vec = std::vector<int>(5, 2)
	// но работает быстрее так как память уже выделеную задействует

	std::cout << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}

	std::vector<int> vec2 = { 1, 2, 3 };
	vec2.resize(5, 10); // Теперь вектор содержит {1, 2, 3, 10, 10}
	vec2.resize(2);     // Теперь вектор содержит {1, 2}

	std::vector<int> vec3 = { 1, 2, 3 };
	vec3.assign(5, 10); // Теперь вектор содержит {10, 10, 10, 10, 10}


	std::vector<int> vec4 = { 1, 2, 3 };

	vec4.resize(5, 7); // {1, 2, 3, 7, 7}
	std::cout << "After resize: ";
	for (int i : vec4) std::cout << i << " ";
	std::cout << std::endl;

	vec4.assign(4, 9); // {9, 9, 9, 9}
	std::cout << "After assign: ";
	for (int i : vec4) std::cout << i << " ";
	std::cout << std::endl;

	vec4.assign({ 1, 2, 3, 4, 5, 6 });
	std::cout << "After assign{}: ";
	for (int i : vec4) std::cout << i << " ";
	std::cout << std::endl;
#endif

#if 0
	//stack - O(1)
	//LIFO 
	std::stack<int> st;

	st.push(0);					// добавить в конец ,O(1)
	st.push(2);
	st.push(1);
	st.push(7);
	st.push(4);
	st.pop();					// удалить конец, O(1)

	std::cout << st.top();		// посмотреть конец, O(1)

	std::cout << std::endl;
	std::cout << st.empty();	// проверяет не пуст ли контейнер

	std::cout << std::endl;
	std::cout << st.size();		// вернёт размер стека

	//for (int i : vec) std::cout << i << " ";
	std::cout << std::endl;
#endif

#if 0
	//queue - O(1)
	// FIFO
	std::queue<int> q;

	q.push(0);					// добавить в конец ,O(1)
	q.pop();					// удалить конец, O(1)

	q.push(0);					// back pushes 0
	q.push(1);					// q = 0 1
	q.push(2);					// q = 0 1 2
	q.push(3);					// q = 0 1 2 3
	// 0 1 2 3
	//       |

	q.pop();					// removes the front element, 0

	std::cout << q.front();		// access the first element
	std::cout << std::endl;
	std::cout << q.back();		// access the end element

	std::cout << '\n' << "q: ";
	for (; !q.empty(); q.pop())
	{
		std::cout << q.front() << ' ';
	}
#endif

#if 0
	//deque - O(1)
	//Доступ по индексу	O(1)
	//Вставка/удаление с конца (push_back, pop_back)	O(1)
	//Вставка/удаление с начала (push_front, pop_front)	O(1)
	//Вставка/удаление в середине	O(n)
	//Размер (size)	O(1)
	//Очистка (clear)	O(n)

	std::deque<int> dq;

	dq.push_back(0);				// добавить в конец ,O(1)
	dq.pop_back();					// удалить конец, O(1)

	dq.push_back(0);				// back pushes 0
	dq.push_front(1);				// q = 0 1
	dq.push_front(2);				// q = 0 1 2
	dq.push_back(3);				// q = 0 1 2 3
	// 2 1 0 3
	//       |

	std::cout << dq.front();		// access the first element
	std::cout << std::endl;
	std::cout << dq.back();			// access the end element

	std::cout << '\n' << dq.size() << std::endl;

	std::cout << '\n' << "dq: ";
	for (int n : dq)
	{
		std::cout << n << ' ';
	}
	dq.pop_front();					// удалить начало, O(1)
	std::cout << std::endl;

	for (size_t i = 0; i < dq.size(); i++)
	{
		std::cout << dq[i] << ' ';
	}
#endif

#if 0
	// set - O(log(n))
	// Вставка элемента (insert)	O(log n)
	// Удаление элемента (erase)	O(log n)
	// Поиск элемента (find)	O(log n)
	// Минимальный/максимальный элемент	O(1)
	// Размер (size)	O(1)
	// Поиск диапазона (lower_bound, upper_bound)	O(log n)

	// Отсортирован по порядку, элементы не повторяются 

	std::set<int> st;

	for (int i = 0; i < 10; ++i)
	{
		st.insert(rand() % 10);
	}

	std::cout << "size: " << st.size() << std::endl;

	for (auto& i : st)
	{
		std::cout << i << std::endl;
	}
	std::cout << std::endl;

	st.insert(0);
	st.erase(0);
	//std::cout << *st.find(2); // вернёт итератор на 2, если есть, иначе вернёт st.end()
	std::cout << (st.find(2) == st.end());
	std::cout << std::endl << std::endl;

	auto res = st.insert(2);
	bool inserted = res.second;

	if (st.insert(3).second)
	{
		std::cout << "insert" << std::endl;
	}
	else
	{
		std::cout << "didn't insert" << std::endl;
	}

	if (st.erase(3))
	{
		std::cout << "erase" << std::endl;
	}
	else
	{
		std::cout << "didn't erase" << std::endl;
	}


	auto it = st.find(1);
	it = st.erase(it); // удалит и передвинет итератор на следующий элемент

	auto it2 = st.lower_bound(1);
	auto it2 = st.upper_bound(1);
#endif

#if 0
	//Вставка элемента (insert)	O(log n)
	//Доступ по ключу (operator[], at())	O(log n)
	//Удаление элемента (erase)	O(log n)
	//Поиск элемента (find)	O(log n)
	//Итерация по элементам	O(n)
	//Размер контейнера (size())	O(1)
	//lower_bound() и upper_bound() O(log n)

	std::vector<int> vec = { 2, 4, 15, 12332, -123, 4, -123 };

	std::map<int, int> mp;

	for (int x : vec)
	{
		++mp[x]; //mp[x] обращается к элементу с ключом x в карте mp. Если ключ не существует, он автоматически добавляется в карту с нулевым значением. ++mp[x] увеличивает значение по этому ключу на 1.
	}
	// [-123] = 2; [2] = 1; [4] = 2; [15] = 1; [12332] = 1;

	for (const auto& [key, value] : mp) // c++ 17
	{
		std::cout << '[' << key << "] = " << value << "; ";
	}

	// C++11 alternative:
	//for (const auto& n : mp)
	//{
	//	std::cout << n.first << " = " << n.second << "; ";
	//}
	//
	// C++98 alternative:
	//for (std::map<std::string, int>::const_iterator it = mp.begin(); it != mp.end(); ++it)
	//{
	//	std::cout << it->first << " = " << it->second << "; ";
	//}

	mp[3] = 1000;
	mp.erase(3);
	std::cout << std::endl;

	std::cout << "mp.size(): " << mp.size() << std::endl;

	std::cout << "mp.count(4): " << mp.count(4) << std::endl; //возвращает количество элементов, соответствующих определенному ключу
	std::cout << std::endl;

	auto it = mp.find(4);
	if (it != mp.end())
	{
		std::cout << "it->first: " << it->first << std::endl;
		std::cout << "it->second: " << it->second << std::endl;
	}

	// C++11 alternative:
	for (const auto& n : mp)
	{
		std::cout << n.first << " = " << n.second << "; ";
	}

	// *mp.begin(); //min element
	// *mp.begin(); // ==  *(--mp.end()) == *prev(mp.end()) // max element
#endif

#if 0
	//std::multiset хранит упорядоченные элементы и позволяет дубликаты
	//Вставка элемента (insert())	O(log n)
	//Поиск элемента (find())	O(log n)
	//Удаление элемента (erase())	O(log n)
	//Доступ к элементам (итерация)	O(n)
	//Количество экземпляров элемента (count())	O(log n)
	//Размер контейнера (size())	O(1)

	std::multiset<int> mst;

	mst.insert(1);
	mst.insert(5);
	mst.insert(1);
	mst.insert(2);
	mst.insert(3);
	mst.insert(3);

	mst.erase(1); // delete all 1

	for (const auto& elem : mst)
	{
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	mst.erase(mst.find(5)); // delete single 1

	for (const auto& elem : mst)
	{
		std::cout << elem << " ";
	}
#endif

#if 0
	// unordered_set это ассоциативный контейнер, который хранит неупорядоченные уникальные элементы
	//Вставка элемента (insert())	O(1) (в среднем)
	//Поиск элемента (find())	O(1) (в среднем)
	//Удаление элемента (erase())	O(1) (в среднем)
	//Проверка на наличие элемента (count())	O(1) (в среднем)
	//Размер контейнера (size())	O(1)	

	std::unordered_set<int> uset;

	// Вставка элементов
	uset.insert(1);
	uset.insert(5);
	uset.insert(3);
	uset.insert(5); // дубликат не будет добавлен
	uset.insert(7);

	// Итерация по элементам
	std::cout << "Elements in unordered_set: ";
	for (const auto& elem : uset)
	{
		std::cout << elem << " "; // порядок может отличаться
	}
	std::cout << std::endl;

	// Поиск элемента
	auto it = uset.find(3);
	if (it != uset.end())
	{
		std::cout << "Element 3 found." << std::endl;
	}

	// Удаление элемента
	uset.erase(5); // удаляет 5

	// Проверка на наличие элемента
	std::cout << "Count of 5 after erase: " << uset.count(5) << std::endl; // 0

	it = uset.begin(); // возвращает итератор в начало
	std::cout << *it << std::endl;
#endif

#if 0
	//unordered_map это ассоциативный контейнер, который хранит неупорядоченные пары "ключ-значение"
	//Вставка элемента (insert())	O(1) (в среднем)
	//Доступ по ключу (operator[], at())	O(1) (в среднем)
	//Удаление элемента (erase())	O(1) (в среднем)
	//Проверка на наличие элемента (count())	O(1) (в среднем)
	//Размер контейнера (size())	O(1)

	std::unordered_map<int, std::string> umap;

	// Вставка элементов
	umap.insert({ 1, "One" });
	umap[2] = "Two"; // добавление пары "ключ-значение"
	umap[3] = "Three";

	// Итерация по элементам
	std::cout << "Elements in unordered_map:\n";
	for (const auto& pair : umap)
	{
		std::cout << "Key: " << pair.first << ", Value: " << pair.second << "\n"; // порядок может отличаться
	}

	// Поиск элемента
	auto it = umap.find(2);
	if (it != umap.end())
	{
		std::cout << "Key 2 found with value: " << it->second << std::endl;
	}

	// Удаление элемента
	umap.erase(1); // удаляет элемент с ключом 1

	// Проверка на наличие ключа
	std::cout << "Count of key 1 after erase: " << umap.count(1) << std::endl; // 0
#endif

#if 0
	//priority_queue контейнер, который хранит элементы в определённом порядке, позволяя быстро извлекать элемент с наивысшим приоритетом
	//Вставка элемента (push())	O(log n)
	//Извлечение элемента с наивысшим приоритетом (top(), pop())	O(log n)
	//Проверка на пустоту (empty())	O(1)
	//Размер контейнера (size())	O(1)

	std::priority_queue<int> pq;

	// Вставка элементов
	pq.push(10);
	pq.push(5);
	pq.push(20);

	std::cout << "pq.top(): " << pq.top() << std::endl; // макс элемент

	// Итерация по элементам (нельзя, так как priority_queue не поддерживает итерацию)
	// Но можно извлекать элементы по приоритету
	std::cout << "Elements in priority queue (in order of priority): ";
	while (!pq.empty())
	{
		std::cout << pq.top() << " "; // вывод: 20 10 5
		pq.pop(); // удалить элемент
	}
	std::cout << std::endl;

#endif

#if 0
	// min/max element
	// O(n)
	std::cout << "min/max element" << std::endl;
	std::vector<int> a{ 2, 3, 1, 4, 6, 1, 5, 8, }, b;
	// index 			0, 1, 2, 3, 4, 5, 6, 7

	b = a;
	auto it = std::min_element(a.begin(), a.end()); // 2 позиция индекса

	std::cout << *it << std::endl; // значение 1 по индекску 2

	std::cout << "index: " << std::min_element(a.begin(), a.end()) - a.begin() << std::endl;
	std::cout << "index: " << std::distance(a.begin(), it) << std::endl;

	std::cout << "value: " << *std::min_element(a.begin(), a.end()) << std::endl;
#endif

#if 0
	// rotate
	// O(n)
	std::cout << "rotate" << std::endl;

	std::vector<int> a{ 2, 3, 1, 4, 6, 1, 5, 8, }, b;
	print(a);

	//std::rotate(a.begin(), a.begin() + 1, a.end());
	//print(a);

	std::rotate(a.begin(), a.begin() + 5, a.end());
	print(a);

	auto itFirst = a.begin() + 2, itMiddle = a.begin() + 3, itLast = a.begin() + 6;
	std::rotate(itFirst, itMiddle, itLast);
	print(a);
#endif

#if 0
	// unique
	// O(n)
	// нужен сортированный массив
	std::vector<int> a{ 2, 3, 1, 4, 6, 1, 5, 8, 10, 21, 10, 21, 21 }, b;
	print(a);

	std::sort(a.begin(), a.end());
	print(a);

	auto it = unique(a.begin(), a.end());
	print(a);
	std::cout << it - a.begin() << std::endl;
	std::cout << *it << std::endl;


	a.resize(it - a.begin()); //режем вектор до 9, it - a.begin()  получение у итератора индекса
	print(a);
#endif

#if 0
	// count
	// O(n)
	// ищет в массиве значение
	std::vector<int> a{ 2, 3, 1, 4, 6, 1 }, b;

	std::cout << std::count(a.begin(), a.end(), 1) << std::endl;
	std::cout << std::count(a.begin(), a.end(), 3) << std::endl;
	std::cout << std::count(a.begin(), a.end(), 100) << std::endl;
#endif

#if 0
	// reverse
	// O(n)
	std::vector<int> a{ 2, 3, 1, 4, 6, 1, 3, 4 }, b;
	print(a);

	std::reverse(a.begin(), a.end());
	print(a);

	std::reverse(a.begin() + 1, a.begin() + 5);
	print(a);
#endif

#if 0
	// iota
	// ++value
	std::vector<int> a(10);
	print(a);

	std::iota(a.begin(), a.end(), 0);
	print(a);

	std::iota(a.begin(), a.end(), -100);
	print(a);
#endif

#if 0
	// partial sum
	// O(n)
	// sum value - a[i] = a[i - 1] + a[i]
	std::vector<int> a = { 1 ,2, 3 ,4 ,5 };
	print(a);

	std::partial_sum(a.begin(), a.end(), a.begin());
	print(a);

	std::partial_sum(a.begin(), a.end(), a.begin(), std::multiplies<int>());
	print(a);
#endif

#if 0
	// accumulate
	std::vector<int> a{ 1, 2, 3, 4 };

	int sum = std::accumulate(a.begin(), a.end(), 10); // 10 это начальное число перед массивом т.е 10 + 1 + 2 + 3 + 4
	std::cout << sum << std::endl;

	int product = std::accumulate(a.begin(), a.end(), 2, std::multiplies<int>()); // 2 это начальное число перед массивом т.е 2 * 1 * 2 * 3 * 4
	std::cout << product << std::endl;

	std::string str = accumulate(a.begin() + 1, a.end(), std::to_string(a[0]), *dash_fold); // для ф-ции dash_fold ожидается, что первый аргумент — накопленное значение (текущий результат). Второй аргументу — текущий элемент контейнера (то есть элемент из диапазона, по которому идёт итерация).

	std::cout << str << std::endl;
#endif

#if 1
	//shuffle
	std::vector<int> a{ 1, 2, 3, 4};
	print(a);

	std::mt19937 rnd(413);

	std::shuffle(a.begin(), a.end(), rnd); // рандомит
	print(a);


#endif

#if 0
#endif

#if 0
	std::vector<std::string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	std::vector<std::string>::iterator myIterator;
	std::vector<std::string>::const_iterator const_myIterator;

	std::cout << "Your items: " << std::endl;

	for (const_myIterator = inventory.begin(); const_myIterator != inventory.end(); ++const_myIterator)
	{
		std::cout << *const_myIterator << std::endl;
	}

	myIterator = inventory.begin();
	*myIterator = "battle axe";

	for (const_myIterator = inventory.begin(); const_myIterator != inventory.end(); ++const_myIterator)
	{
		std::cout << *const_myIterator << std::endl;
	}

	std::cout << (*myIterator).size() << std::endl;
	std::cout << myIterator->size() << std::endl;

	inventory.insert(inventory.begin(), "crossbow");

	for (const_myIterator = inventory.begin(); const_myIterator != inventory.end(); ++const_myIterator)
	{
		std::cout << *const_myIterator << std::endl;
	}

	inventory.erase((inventory.begin() + 2));

	for (const_myIterator = inventory.begin(); const_myIterator != inventory.end(); ++const_myIterator)
	{
		std::cout << *const_myIterator << std::endl;
	}
#endif

#if 0
#endif
	std::cout << "\n--- End of Program ---" << std::endl;
	return 0;
}
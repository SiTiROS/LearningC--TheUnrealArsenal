#include <iostream>

using namespace std;

// #define END cout << "\n--- End of Program ---" << endl;
// #define THREE 3
// #define SQUARE(x) x * x
// #define MULTIPLY(x, y) (x) * (y)

// class GameStats
// {
// public:
// 	int getCurrentLevel() { return currentLevel; }
// 	void setCurrentLevel(int newLevel) { currentLevel = newLevel; }
//
// private:
// 	int currentLevel = 7;
// }game;

// class Entity
// {
// public:
// 	Entity()
// 	{
// 		member = new int(15);
// 	}
//
// 	~Entity()
// 	{
// 		cout << "Destructor invoked!" << endl;
// 		delete member;
// 		member = nullptr;
// 	}
//
// private:
// 	int* member;
// };

// struct Vector2D
// {
// 	Vector2D()
// 	{
// 		x = 0;
// 		y = 0;
// 	}
//
// 	Vector2D(float xP, float yP)
// 	{
// 		x = xP;
// 		y = yP;
// 	}
//
// 	~Vector2D()
// 	{
// 		cout << "Vector2D Object Destroyed!" << endl;
// 	}
//
// 	float x;
// 	float y;
// };

// class PlayerStats
// {
// public:
// 	PlayerStats()
// 	{
// 		health = 100;
// 		location = new Vector2D(5.4f, 3.3f);
// 	}
//
// 	~PlayerStats()
// 	{
// 		delete location;
// 		location = nullptr;
// 		cout << "PlayerStats Object Destroyed!" << endl;
// 	}
//
// 	void setLocation(float xP, float yP)
// 	{
// 		location->x = xP;
// 		location->y = yP;
// 	}
//
// 	Vector2D getLocation()
// 	{
// 		if (location)
// 			return *location;
// 		else
// 			return Vector2D();
// 	} // так как функция возвращает как бы временный объект Vector2D а не указатель, то будет вызван ещё 1 раз деструктор Vector2D, после вызова функции 
//
// private:
// 	float health;
// 	Vector2D* location;
// };

// class GameStats
// {
// public:
// 	GameStats();
// 	GameStats(int x); // constructor
//
// 	int getCurrentLevel();
// 	void setCurrentLevel(int level);
//
// private:
// 	int currentLevel;
// };

// GameStats::GameStats()
// {
// 	currentLevel = 1;
// }
//
// GameStats::GameStats(int x)
// {
// 	currentLevel = x;
// }
//
// int GameStats::getCurrentLevel()
// {
// 	return currentLevel;
// }
//
// void GameStats::setCurrentLevel(int level)
// {
// 	currentLevel = level;
// }

// static int s_Var = 5;
//
// static void demoFunction()
// {
// 	cout << "Hello from main.cpp" << endl;
// }

// extern void demoFunction();
// extern int var;

// struct Entity
// {
// 	// int member;
// 	static int s_Member;
// 	inline static int s_Member2 = 5;
//
// 	static void ToString()
// 	{
// 		cout << s_Member << endl;
// 		cout << s_Member2 << endl;
// 	}
// };
//
// int Entity::s_Member = 555;

// struct Entity
// {
// 	int member = 0;
//
// 	void setMember(int member)
// 	{
// 		this->member = member;
// 		// (*this).member = member;
// 	}
//
// };

// struct Entity
// {
// 	int member = 0;
//
// 	void compare(const Entity &other)
// 	{
// 		if (this == &other)
// 		{
// 			cout << "The object compared are identical" << endl;
// 			cout << "this: " << this <<endl;
// 			cout << "&other: " << &other <<endl;
// 		}
// 		else
// 		{
// 			cout << "The object compared are not identical" << endl;
// 		}
//
// 	}
// };

// class GameStats
// {
// public:
// 	GameStats();
//
// 	GameStats& setCurrentLevel(int levelP);
// 	GameStats& setCurrentRoom(int roomP);
//
// 	void ToString();
//
// private:
// 	int m_Level;
// 	int m_Room;
// };
//
// GameStats::GameStats() : m_Level(1), m_Room(1)
// {
// 	cout << "Default constructor invoked." << endl;
// }
//
// GameStats& GameStats::setCurrentLevel(int levelP)
// {
// 	m_Level = levelP;
// 	return *(&(*this));
// }
//
// GameStats& GameStats::setCurrentRoom(int roomP)
// {
// 	m_Room = roomP;
// 	return *this;
// }
//
// void GameStats::ToString()
// {
// 	cout << "---------" << endl;
// 	cout << "Current Level:\t" << m_Level << endl;
// 	cout << "Current Room:\t" << m_Room << endl;
// 	cout << "---------" << endl;
// }

// class GameStats
// {
// public:
// 	GameStats();
// 	GameStats(int levelP);
//
// 	int getCurrentLevel();
// 	void setCurrentLevel(int level);
//
// private:
// 	int currentLevel = 1;
// };
//
// GameStats::GameStats() : currentLevel(1)
// {
//
// }
//
// GameStats::GameStats(int levelP)
// 	:currentLevel(levelP)
// {
//
// }
//
// int GameStats::getCurrentLevel()
// {
// 	return currentLevel;
// }
//
// void GameStats::setCurrentLevel(int level)
// {
// 	currentLevel = level;
// }

// struct Vector2D
// {
// 	Vector2D()
// 		:x(0), y(0)
// 	{
// 		cout << "Vector Initialized." << endl;
// 	}
//
// 	Vector2D(float xP, float yP)
// 	{
// 		x = xP;
// 		y = yP;
//
// 		cout << "Vector Initialized. x: " << x << " and y: " << y << endl;
// 	}
//
// 	float x;
// 	float y;
// };
//
// class PlayerStats
// {
// public:
// 	PlayerStats()
// 		//:health(100), location(Vector2D(15.3f, 4.3f))
// 		:health(100), location(15.3f, 4.3f) // так короче
// 	{
//
// 	}
//
// 	void setLocation(float xP, float yP)
// 	{
// 		location.x = xP;
// 		location.y = yP;
// 	}
//
// 	Vector2D getLocation()
// 	{
// 		return location;
// 	}
//
// private:
// 	float health;
// 	Vector2D location;
// };

// class GameStats
// {
// public:
// 	GameStats();
// 	GameStats(int levelP, int roomP);
//
// 	int getCurrentLevel();
// 	void setCurrentLevel(int levelP);
//
// private:
// 	int mLevel;
// 	int mRoom;
// };
//
// GameStats::GameStats()
// 	: GameStats(1, 1) // нельзя к делегирующему конструкотору добавить другой!
// {
// 	cout << "Default constructor invoked." << endl;
// }
//
// GameStats::GameStats(int levelP, int roomP)
// 	:mLevel(levelP), mRoom(roomP)
// {
// 	cout << "Overload two-args constructor invoked." << endl;
// }
//
// int GameStats::getCurrentLevel()
// {
// 	return mLevel;
// }
//
// void GameStats::setCurrentLevel(int levelP)
// {
// 	 mLevel = levelP;
// }
//
// class Entity
// {
// public:
// 	Entity() : Entity(2, 3) {} //бесконечный цикл
// 	Entity(int memberVar1P, int memberVar2P) : Entity() {} //бесконечный цикл
//
// private:
// 	int memberVar1;
// 	int memberVar2;
// };

// class GameStats
// {
// public:
// 	// GameStats() {} // будет ошибка как как уже есть конструктор со стандартными аргументами
// 	GameStats(int levelP = 1, int roomP = 1); // constructor with default arguments
//
// 	void ToString();
//
// private:
// 	int m_Level;
// 	int m_Room;
// };
//
// GameStats::GameStats(int levelP, int roomP)
// 	: m_Level(levelP), m_Room(roomP)
// {
// }
//
// void GameStats::ToString()
// {
// 	cout << "-----" << endl;
// 	cout << "Current Level:\t" << m_Level << endl;
// 	cout << "Current Room:\t" << m_Room << endl;
// 	cout << "-----" << endl;
// }

// class Entity
// {
// public:
// 	int getMember() const;
// 	void setMember(int memberP);
//
// private:
// 	mutable int member = 15;
// };
//
// int Entity::getMember() const
// {
// 	member = 2;
//  	return member;
// }
//
// void Entity::setMember(int memberP)
// {
// 	member = memberP;
// }
//
// void print(const Entity& entityP)
// {
// 	cout << entityP.getMember() << endl;
// }

// inline int greatestInt(int x, int y)
// {
// 	return x > y ? x : y;
// }
//
// class Entity
// {
// public:
// 	//inline int getMember();
// 	int getMember();
//
// private:
// 	int member = 15;
// };
//
// inline int Entity::getMember()
// {
// 	return member;
// }

// //enum EDifficulty { Easy, Normal, Hard };
//
// enum EGameDifficulty
// {
// 	Easy = 1,
// 	Normal = 3,
// 	Hard = 5
// };
//
// enum class ETerrainDifficulty
// {
// 	Easy,
// 	Normal,
// 	Hard
// };
//
// EGameDifficulty pointsCollected(int points)
// {
// 	if (points == 1)
// 	{
// 		return EGameDifficulty::Easy;
// 	}
// 	else if (points == 3)
// 	{
// 		return Normal;
// 	}
// 	else if (points == 5)
// 	{
// 		return Hard;
// 	}
// 	else
// 	{
// 		return Easy;
// 	}
// }
//
// enum class EMyEnum : int { a, b, c };

// const int x = 55;
//

struct Vector2D
{
	Vector2D(float xP = 0, float yP = 0)
		: x(xP), y(yP)
	{
	}

	~Vector2D()
	{
	}

	float x;
	float y;
};

class PlayerStats
{
public:
	PlayerStats(int healthP = 100, Vector2D locationP = Vector2D{ 33.15f, 47.5f })
		: health(healthP), location(locationP.x, locationP.y)
	{}

	~PlayerStats() {};

	int getHealth() const
	{
		return health;
	}

	Vector2D getPos() const
	{
		return location;
	}

private:
	int health;
	Vector2D location;
};


int main()
{
	// GameStats* newDynamicWorld = new GameStats;
	// GameStats* gamePtr = &game;
	//
	// cout << game.getCurrentLevel() << endl;
	// game.setCurrentLevel(3);
	// cout << game.getCurrentLevel() << endl;
	//
	// gamePtr->setCurrentLevel(1);
	// cout <<gamePtr->getCurrentLevel() << endl;
	//
	// cout << newDynamicWorld->getCurrentLevel() << endl;
	// newDynamicWorld->setCurrentLevel(13);
	// cout << newDynamicWorld->getCurrentLevel() << endl;
	//
	// delete newDynamicWorld;
	// newDynamicWorld = nullptr;


	// GameStats game;
	// game.setCurrentLevel(15);
	// cout << game.getCurrentLevel() << endl;


	//GameStats game(2);
	// GameStats game, game2(4);
	// cout << game.getCurrentLevel() << endl;
	// cout << game2.getCurrentLevel() << endl;


	// {
	// 	Entity entity1, entity2;
	// }
	//
	// Entity* entity3 = new Entity;
	// delete entity3;
	// entity3 = nullptr;


	// PlayerStats player1;
	//
	// cout << player1.getLocation().x << endl;
	// cout << endl;
	// Vector2D playerLocation = player1.getLocation();
	// cout << playerLocation.x << endl;
	// cout << playerLocation.y << endl;


	// //cout << s_Var;
	// // demoFunction();
	//
	// // Entity entity1{ 5 }; // списковая инициализация
	//
	// // Entity entity1, entity2;
	//
	// // entity1.s_Member = 5;
	// // entity2.s_Member = 55;
	//
	// // entity1.ToString();
	// // entity2.ToString();
	//
	// Entity::s_Member = 66;
	// Entity::s_Member2 = 466;
	//
	// Entity::ToString();


	// Entity entity1;
	// entity1.setMember(400);
	// cout << entity1.member << endl;
	// cout << endl;
	//
	// Entity entity1, entity2;
	// entity1.compare(entity1);
	//
	// GameStats game;
	// game.ToString();
	// game.setCurrentLevel(5).setCurrentRoom(9);
	// game.ToString();
	//
	// int demoVar = 12;
	// int* demoPtr = &demoVar;
	// cout << *demoPtr << endl;
	// cout << demoPtr << endl;


	// // GameStats game, game2(5);
	// //
	// // cout << game.getCurrentLevel() << endl;
	// // cout << game2.getCurrentLevel() << endl;
	//
	// PlayerStats player1;


	// GameStats game, game2(5, 4);
	//
	// cout << game.getCurrentLevel() << endl;
	// cout << game2.getCurrentLevel() << endl;
	// 
	// cout << endl;


	// GameStats game;
	// game.ToString();


	// Entity entity1;
	// //cout << entity1.getMember() << endl;
	// //print(entity1);
	//
	// const Entity ENTITY_2;
	// //ENTITY_2.setMember(5); // не будет работать ибо сам объект const
	// cout << ENTITY_2.getMember() << endl;


	// // Example inline expansion
	// // int demoInt{};
	// // {
	// // 	int x = 5;
	// // 	int y = 10;
	// // 	demoInt = x > y ? x : y;
	// // }
	// // cout << demoInt << endl;
	//
	// // int demoInt{}; // может быть пустым - само 0 ставит
	// // int demoInt2(0); // не может быть пустым, ругнётся при компиляции
	// // cout << demoInt << endl;
	// // cout << demoInt2 << endl;
	//
	// // int demoInt{};
	// // demoInt = greatestInt(5, 10);
	// // cout << demoInt << endl;
	//
	// Entity entity1;
	// cout << entity1.getMember() << endl;


	// int* intPtr = NULL;
	// cout << THREE << endl;
	// END
	// cout << SQUARE(4 + 2) << endl;
	// END
	// cout << MULTIPLY(2,2) <<endl;
	// cout << MULTIPLY(2.2,2.2) <<endl;


	// // EDifficulty difficulty = EDifficulty::Normal;
	// // EDifficulty difficulty = Easy;
	// //
	// // cout << difficulty << endl;
	// // cout << Normal << endl;
	// //
	// // switch (difficulty)
	// // {
	// // case Easy:
	// // 	cout << "Easy" << endl;
	// // 	break;
	// // case Normal:
	// // 	cout << "Normal" << endl;
	// // 	break;
	// // case Hard:
	// // 	cout << "Hard" << endl;
	// // 	break;
	// // default:
	// // 	cout << "Illegal choice!" << endl;
	// // 	break;
	// // }
	//
	// // EGameDifficulty gameDifficulty = Normal;
	// //
	// // cout << Easy << endl;
	// // cout << Normal << endl;
	// // cout << Hard << endl;
	// //
	// // if (gameDifficulty == Normal)
	// // {
	// // 	cout << (Normal - Easy) << endl;
	// // }
	//
	// // EGameDifficulty gameDifficulty = pointsCollected(4);
	// //
	// // cout << gameDifficulty << endl;
	//
	// EGameDifficulty gameDifficulty = EGameDifficulty::Normal;
	// ETerrainDifficulty terrainDifficulty = ETerrainDifficulty::Normal;
	//
	// // if (terrainDifficulty == ETerrainDifficulty::Normal)
	// // {
	// // 	cout << "Normal" << endl;
	// // }
	//
	// int x = 2;
	// x = Normal; // так будет работать
	// // x = ETerrainDifficulty::Normal; // так не будет работать
	// x = (int)ETerrainDifficulty::Normal; // так будет работать
	// cout << x << endl;
	//
	// EMyEnum myEnum = EMyEnum::a;
	// cout << (int)myEnum << endl;
	//
	// gameDifficulty = (EGameDifficulty)2;
	// terrainDifficulty = (ETerrainDifficulty)2;
	// cout << gameDifficulty << endl;
	// cout << (int)terrainDifficulty << endl;


	// int x = 2;
	// cout << ::x << endl;


	// int x = (3, 5, 7);
	// cout << x << endl;


	// PlayerStats playerOne{};
	// cout << playerOne.getHealth() << endl;
	// cout << playerOne.getPos().x << endl;
	// cout << playerOne.getPos().y << endl;
	// cout << endl;
	//
	// PlayerStats playerTwo{ 75, Vector2D{55.50f, 66.68f}};
	// // prefered
	// // Vector2D playerTwoLocation{55.50f, 66.68f};
	// // PlayerStats playerTwo {75, playerTwoLocation};
	// cout << playerTwo.getHealth() << endl;
	// cout << playerTwo.getPos().x << endl;
	// cout << playerTwo.getPos().y << endl;

	// int j{ 3 }, k{ 5 }, l{ 7 };
	// cout << j << k << l << endl;
	//
	// int m = (j = k, l);
	// cout << j << k << l << endl;
	// cout << m << endl;


	cout << endl;
	return 0;
}

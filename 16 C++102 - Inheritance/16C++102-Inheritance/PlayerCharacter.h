#pragma once
#include "Character.h"
#include "Vector.h"

//class Vector; // forward declaration для указателей

class PlayerCharacter : public Character 
{
public:
	PlayerCharacter();
	~PlayerCharacter();

private:
	// class Vector* vec; // forward declaration и так можно
	//Vector* vec; // с указателем можно forward declaration
	Vector vec;
};
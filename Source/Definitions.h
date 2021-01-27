#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <cmath>
#include <memory>
#include <map>
#include <string>
#include <vector>
#include <iostream>
//TODO:: const correctness. Check to see if consts can be put on pointer parameters and class methods.
//TODO:: clear out #includes. Make sure every #include is needed in ever file! Cleared out all includes and have put them
//in definitions
//TODO:: Move initialization to the constructor and stopping/finishing to the destructor.
//TODO:: Move default initialization of member variables to .h file using {} for ALL classes!
//Basic Types


typedef unsigned int	Uint32;
typedef float			eFloat;
typedef Uint32			eInt;

struct Vector2D
{

	eFloat x;
	eFloat y;
	friend Vector2D operator+ (const Vector2D& src1, const Vector2D& src2)
	{
		return { src1.x + src2.x, src1.y + src2.y };
	}
	friend Vector2D& operator+=(Vector2D& src1, const Vector2D& src2)
	{
		src1.x += src2.x;
		src1.y += src2.y;
		return src1;
	}
	friend Vector2D operator% (const Vector2D& src1, const Vector2D& src2)
	{
		return {
			fmod(fmod(src1.x, src2.x) + src2.x, src2.x),
			fmod(fmod(src1.y, src2.y) + src2.y, src2.y) };
	}
	friend Vector2D operator- (const Vector2D& src1, const Vector2D& src2)
	{
		return { src1.x - src2.x, src1.y - src2.y };
	}
	friend bool operator> (const Vector2D& src1, int src2)
	{
		if (src1.x > src2 && src1.y > src2)
		{
			return true;
		}
		return false;
	}
	friend bool operator< (const Vector2D& src1, int src2)
	{
		if (src1.x < src2 && src1.y < src2)
		{
			return true;
		}
		return false;
	}
	friend bool operator== (const Vector2D& src1, const Vector2D& src2)
	{
		if (src1.x == src2.x && src1.y == src2.y)
		{
			return true;
		}
		return false;
	}
	friend Vector2D abs(Vector2D& src)
	{
		return { std::abs((float)src.x),std::abs((float)src.y) };
	}

};


struct RGBA
{
	eInt R{ 255 };
	eInt G{ 255 };
	eInt B{ 255 };
	eInt A{ 255 };

	void set(Uint32 C) {
		R = floor( C / 16777216 );
		C %= 16777216;
		G = floor( C / 65536 );
		C %= 65536;
		B = floor( C / 256 );
		A = C % 256;
	}
};

struct Weapon
{
	
	int slashAttack;
	int TrustAttack;
	int bluntAttack;
	int magicAttack;
	int fireAttack;
	int lightningAttack;
	int forstAttack;
	int abssAttack;
	int holyAttack;
	int durability;

	int strRrq;
	int dexRrq;
	int intRrq;
	int faithRrq;
};

struct Armor
{
	
	int slashDef;
	int trustDef;
	int bluntDef;
	int magicDef;
	int fireDef;
	int lightningDef;
	int forstDef;
	int abssDef;
	int holyDef;
	int durability;
	int maxDurabilty;
};

//Constants
const eFloat PI = 3.14159f;
const eFloat PI_TO_DEG = PI / 180.0f;
const eFloat RAD_TO_DEG = 180.0f / PI;
const int windowWidth = 800;
const int windowHeight = 800;
#endif
#pragma once
#include <string>

class int2
{
public:
	static const int2 Left;
	static const int2 Right;
	static const int2 Up;
	static const int2 Down;
	static const int2 Zero;

public:
	int x = 0;
	int y = 0;

	int2();
	int2(int _x);
	int2(int _x, int _y);
	~int2();

	bool IsZero() const
	{
		return x == 0 && y == 0;
	}

	int2 operator+(const int2& _Other) const
	{
		int2 Copy = int2();
		Copy.x = this->x + _Other.x;
		Copy.y = this->y + _Other.y;
		return Copy;
	}

	int2 operator-(const int2& _Other) const
	{
		int2 Copy = int2();
		Copy.x = this->x - _Other.x;
		Copy.y = this->y - _Other.y;
		return Copy;
	}

	int2 operator*(const int _Value) const
	{
		int2 Copy = int2();
		Copy.x = this->x * _Value;
		Copy.y = this->y * _Value;
		return Copy;
	}

	int2 operator*(const float _Value) const
	{
		int2 Copy = int2();
		Copy.x = static_cast<int>(this->x * _Value);
		Copy.y = static_cast<int>(this->y * _Value);
		return Copy;
	}

	int2& operator+=(const int2& _Other)
	{
		this->x += _Other.x;
		this->y += _Other.y;
		return *this;
	}

	int2& operator-=(const int2& _Other)
	{
		this->x -= _Other.x;
		this->y -= _Other.y;
		return *this;
	}

	int2& operator*=(const int _Value)
	{
		this->x *= _Value;
		this->y *= _Value;
		return *this;
	}

	int2& operator*=(const float _Value)
	{
		this->x = static_cast<int>(this->x * _Value);
		this->y = static_cast<int>(this->y * _Value);
		return *this;
	}

	std::string ToString()
	{
		char ArrReturn[256];

		sprintf_s(ArrReturn, "x: %d, y: %d", x, y);

		return std::string(ArrReturn);
	}

protected:

private:

};
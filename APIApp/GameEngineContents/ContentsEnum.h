#pragma once

enum class RenderOrder
{
	BackGround,		 // 0
	Tilemap,
	Monster,		 // 1
	Player,			 // 2

	Fade,
};

enum class CollisionOrder
{
	Player,          // 0
};

enum class GroundType
{
	Grass,
	Rock,
	Water,
	Temp0, // Todo : ���� Ÿ������ �𸣰��� �� �� �˾Ƴ� ����
	Temp1,
	Temp2,
	Temp3,
	Temp4,
	Temp5
};
#pragma once

enum class RenderOrder
{
	//Field
	BackGround,		 // 0
	Tilemap,
	Monster,		 // 1
	Player,			 // 2
	DebugUI,
	Field_Dialog,
	Field_Dialog_Text,
	Particle,

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
	Water
};
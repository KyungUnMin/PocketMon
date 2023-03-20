#pragma once

enum class RenderOrder
{
	//Field
	BackGround,		 // 0
	Tilemap,
	BattleGround,
	Monster,		 // 1
	Player,			 // 2
	Particle,

	DebugUI,
	DebugText,
	Field_Dialog,
	Field_Dialog_Text,

	Fade,
};

enum class CollisionOrder
{
	Player,          // 0
};

enum class GroundType
{
	Grass = 0, // c0f890 [r] 192 [g] 248 [b] 144
	Rock,      // c8c058 [r] 200 [g] 192 [b] 88
	Water,     // 70b8f0 [r] 112 [g] 184 [b] 240
	Blue,      // c8e0e8 [r] 200 [g] 224 [b] 232
	Grey,      // e8e8f0 [r] 232 [g] 232 [b] 240
	Gold,      // e8e0c0 [r] 232 [g] 224 [b] 192
	Purple,    // d8b8e8 [r] 216 [g] 184 [b] 232
	Cyan,      // b8e0d0 [r] 184 [g] 224 [b] 208
	Beige,     // e8e8e8 [r] 232 [g] 232 [b] 232
	Unknown    //
};
#pragma once

enum class RenderOrder
{
	//Field
	BackGround,		 // 0
	Tilemap,
	FieldBack,
	Monster,		 // 1
	Player,			 // 2
	FieldFront,
	Particle,

	Field_MainMenu,
	DebugUI,
	DebugText,
	Shop_MainMenu,
	Shop_MainMenu_Arrow,
	Field_Dialog,
	Field_Dialog_Text,

	Shop_Text,
	Shop_CountItemMenu,
	Shop_Dialog,
	Shop_Dialog_Text,

	// Battle
	Battle_UI,
	Battle_Text,
	Battle_Cursor,

	EndingBack,
	EndingMiddle,
	EndingFront,

	Fade,
	EndingLastText,
};

enum class BattleRenderOrder
{
	BackGround,
	Ground,

	Effect0,
	Effect1,
	Effect2,

	Monster0,
	Monster1,
	Monster2,

	Player0,
	Player1,
	Player2,

	CreateEffect,

	SkillEffect,
	Particle0,
	Particle1,
	
	//이 사이에 UI 넣어주세요
	Battle_UI,
	Battle_Text,
	Battle_Cursor,
	//

	Fade,
};

enum class PlayerDir
{
	Up,
	Down,
	Left,
	Right
};

enum class CollisionOrder
{
	Player,          // 0
	NPC,
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

enum class UpdateOrder
{
	Default,
	Battle_Actors,

};


enum class ItemCode
{
	Potion,			// 0. 상처약
	Repel,			// 1. 벌레퇴치스프레이
	Revive,			// 2. 기력의 조각
	RareCandy,		// 3. 이상한사탕
	Ether,			// 4. PP에이드
	WiseGlasses,	// 5. 박식안경	(특공 상승)
	MuscleBand,		// 6. 힘의 띠 (물공 상승)
	ChoiceBand,		// 7. 머리띠 (방어 상승)
	ChoiceScarf,	// 8. 스카프 (특방 상승)
	Bike,			// 9. 자전거
	MonsterBall,	// 10. 몬스터볼 
	MasterBall,		// 11. 마스터볼 
	Cancel			// 12. 취소
};

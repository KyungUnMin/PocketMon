#include "FieldmapBattleZone.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "Fieldmap.h"
#include "Player.h"
#include "BattleZoneBushParticle.h"
#include "BattleLevel.h"
#include "BattleFadeCtrl.h"
#include "InputControll.h"

FieldmapBattleZone::FieldmapBattleZone()
{
}

FieldmapBattleZone::~FieldmapBattleZone()
{
}

void FieldmapBattleZone::InitBattleZone(const std::string_view& _CityName, const int2& _Start, const int2& _Size, size_t _MinLevel, size_t _MaxLevel)
{
	CityName = _CityName;

	StartIndex = _Start;
	ZoneSize = _Size;

	MinLevel = _MinLevel;
	MaxLevel = _MaxLevel;

	PokeNumbers.reserve(16);

	int2 ZoneIndex = StartIndex;

	for (size_t y = 0; y < ZoneSize.y; y++)
	{
		for (size_t x = 0; x < ZoneSize.x; x++)
		{
			Fieldmap::AddStartEvent(CityName, ZoneIndex, {.Name = "Battle",
				.Order = 10,
				.VaildFunc = []() {return true;},
				.EventFunc = std::bind(&FieldmapBattleZone::BattleStart, this),
				.Loop = true});

			ZoneIndex.x++;
		}

		ZoneIndex.y++;
		ZoneIndex.x = StartIndex.x;
	}
}

void FieldmapBattleZone::AddPokemon(PokeNumber _Number)
{
	PokeNumbers.push_back(_Number);
}

void FieldmapBattleZone::BattleStart()
{
	BattleZoneBushParticle* Particle = GetLevel()->CreateActor<BattleZoneBushParticle>();
	Particle->SetPos(Fieldmap::GetPos(Fieldmap::GetIndex(Player::MainPlayer->GetPos())));

	if (0 < GameEngineRandom::MainRandom.RandomInt(0, 10))
	{
		return;
	}

	GameEngineRandom& MianRand = GameEngineRandom::MainRandom;

	int RandomIndex = MianRand.RandomInt(0, static_cast<int>(PokeNumbers.size() - 1));
	int PokeNumber = static_cast<int>(PokeNumbers[RandomIndex]);
	int RandomLevel = MianRand.RandomInt(static_cast<int>(MinLevel), static_cast<int>(MaxLevel));

	//BattleFieldType _Type;

	//BattleLevel::BattleLevelPtr->Init();

	InputControllHandle = InputControll::UseControll();

	BattleFadeCtrl* Fade = GetLevel()->CreateActor<BattleFadeCtrl>();
	Fade->Init(BattleFadeCtrl::FadeType::BlackOut, std::bind(
		[](FieldmapBattleZone* _this)
		{
			_this->InputControllHandle = InputControll::ResetControll(_this->InputControllHandle);
			DebugMsgBox("��Ʋ ����");
		},
		this));
	Fade->On();
	//Fade->SetDuration(1.0f);
}

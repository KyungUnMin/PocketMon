#include "FieldmapBattleZone.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "Fieldmap.h"
#include "Player.h"
#include "BattleZoneBushParticle.h"
#include "BattleLevel.h"
#include "BattleFade.h"
#include "InputControll.h"
#include "BgmPlayer.h"

bool FieldmapBattleZone::NoBattleDebugOn = false;

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
	if (true == NoBattleDebugOn)
	{
		return;
	}

	float4 PlayerPos = Player::MainPlayer->GetPos();
	int2 PlayerIndex = Fieldmap::GetIndex(PlayerPos);

	BattleZoneBushParticle* Particle = GetLevel()->CreateActor<BattleZoneBushParticle>();
	Particle->SetPos(PlayerPos);

	if (5 < GameEngineRandom::MainRandom.RandomInt(0, 100))
	{
		return;
	}

	GameEngineRandom& MianRand = GameEngineRandom::MainRandom;

	int RandomIndex = MianRand.RandomInt(0, static_cast<int>(PokeNumbers.size() - 1));
	int RandomLevel = MianRand.RandomInt(static_cast<int>(MinLevel), static_cast<int>(MaxLevel));

	GroundType MyGroundType = Fieldmap::GetGroundType(PlayerIndex);

	std::vector<PokeDataBase> PoekDatas;
	PoekDatas.push_back(PokeDataBase::PokeCreate(PokeNumbers[RandomIndex], RandomLevel));

	BattleLevel::BattleLevelPtr->Init(PoekDatas, MyGroundType);

	InputControllHandle = InputControll::UseControll();

	BattleFade* Fade = BattleFade::GetFieldmapBattleFade();
	Fade->PlayBattleFade(3, 5.0f, std::bind(
		[](FieldmapBattleZone* _this)
		{
			_this->InputControllHandle = InputControll::ResetControll(_this->InputControllHandle);
			GameEngineCore::GetInst()->ChangeLevel("BattleLevel");
		},
		this));
}

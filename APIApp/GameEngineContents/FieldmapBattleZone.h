#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <string>
#include <vector>
#include "int2.h"
#include "PokeDataBase.h"

class FieldmapBattleZone : public GameEngineActor
{
public:
	static bool NoBattleDebugOn;
public:
	FieldmapBattleZone();
	~FieldmapBattleZone();

	FieldmapBattleZone(const FieldmapBattleZone& _Other) = delete;
	FieldmapBattleZone(FieldmapBattleZone&& _Other) noexcept = delete;
	FieldmapBattleZone& operator=(const FieldmapBattleZone& _Other) = delete;
	FieldmapBattleZone& operator=(FieldmapBattleZone&& _Other) noexcept = delete;

	void InitBattleZone(const std::string_view& _CityName, const int2& _Start, const int2& _Size, size_t _MinLevel, size_t _MaxLevel);
	void AddPokemon(PokeNumber _Number);

protected:

private:
	std::string CityName = "";

	int2 StartIndex = int2::Zero;
	int2 ZoneSize = int2::Zero;

	size_t MinLevel = 1;
	size_t MaxLevel = 1;

	std::vector<PokeNumber> PokeNumbers;

	int InputControllHandle = -1;

	void BattleStart();
};
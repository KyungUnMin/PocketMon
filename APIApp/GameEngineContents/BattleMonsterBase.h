#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "PokeDataBase.h"

class PokeDataBase;
enum class PokeNumber;
enum class PokeSkill;
class GameEngineRender;
class BattleSkillBase;
class Battle_HpUIHandlerBase;

enum class BattleMonsterType
{
	PlayerMon,
	WildMon,
	NPCMon,
};

class BattleMonsterBase : public GameEngineActor
{
public:
	BattleMonsterBase();
	virtual ~BattleMonsterBase() = 0;

	BattleMonsterBase(const BattleMonsterBase& _Other) = delete;
	BattleMonsterBase(BattleMonsterBase&& _Other) noexcept = delete;
	BattleMonsterBase& operator=(const BattleMonsterBase& _Other) = delete;
	BattleMonsterBase& operator=(const BattleMonsterBase&& _Other) noexcept = delete;

	inline PokeDataBase* GetDB()
	{
		return &DbPtr;
	}

	virtual class GameEngineRender* GetRender() = 0;

	virtual Battle_HpUIHandlerBase* GetHpUI() = 0;

	virtual void CreateHpUI() = 0;

	virtual void DamageOnIU(int _Value) = 0;

protected:
	void Init(PokeNumber _MonsterType, int _Level = 1);

private:
	bool IsInit = false;
	static const std::vector<std::string_view> NameEnumToString;
	static const std::vector<std::string_view> SkiilEnumToString;

	PokeDataBase DbPtr;
};


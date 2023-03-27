#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "PokeDataBase.h"

class PokeDataBase;
enum class PokeNumber;
enum class PokeSkill;
class GameEngineRender;
class BattleSkillBase;

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



protected:
	void Init(PokeNumber _MonsterType);
	BattleSkillBase* CreateSkill(PokeSkill _SkillType, BattleMonsterBase* _Owner);

private:
	static const std::vector<std::string_view> NameEnumToString;
	static const std::vector<std::string_view> SkiilEnumToString;

	PokeDataBase DbPtr;;
};


#pragma once
#include <GameEngineCore/GameEngineActor.h>

class PokeDataBase;
enum class PokeNumber;
enum class PokeSkill;
class GameEngineRender;

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
		return DbPtr;
	}



protected:
	void Init(PokeNumber _MonsterType);
	GameEngineRender* DamageBySkill(PokeSkill _SkillType);

private:
	static const std::vector<std::string_view> NameEnumToString;
	static const std::vector<std::string_view> SkiilEnumToString;
	//static const std::vector<int> SkiilAniFrame;


	PokeDataBase* DbPtr = nullptr;

	GameEngineRender* CreateSkiilEffect(PokeSkill _SkillType);
};


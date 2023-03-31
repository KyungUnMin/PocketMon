#pragma once
#include <vector>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentsEnum.h"

class GameEngineRender;
class TestScript;
class Battle_Select;
class BattleFSM;
class BackTextActor;
enum class PokeNumber;
enum class ItemCode;
class PokeDataBase;

enum class BattleFieldType
{
	Indoor,
	Forest,	
	Gym,
};

enum class BattleNpcType
{
	None,
	Rival,
	Woong

};


class BattleLevel : public GameEngineLevel
{
public:
	static BattleLevel* BattleLevelPtr;
	static const std::string_view  BattleKeyName;

	static const std::string_view BattleBgmName;
	static const std::string_view VictoryBgmName;

	BattleLevel();
	~BattleLevel() override;

	BattleLevel(const BattleLevel& _Other) = delete;
	BattleLevel(BattleLevel&& _Other) noexcept = delete;
	BattleLevel& operator=(const BattleLevel& _Other) = delete;
	BattleLevel& operator=(const BattleLevel&& _Other) noexcept = delete;

	//맵 레벨에서 배틀레벨로 전환될때 호출해주시면 됩니다.
	void Init(
		const std::vector<PokeDataBase>& _EnemyMonsters,
		GroundType _FieldType,
		BattleNpcType _NpcType = BattleNpcType::None);

	inline BattleFSM* GetBattleFSM()
	{
		return BattleFsmPtr;
	}

	void PassPlayerTurn();

	void UseMonsterBall(ItemCode _MonsterBallType);

	void ChangePlayerMonster(PokeNumber _NextMonster);

	void LockWildPocketMon();

	void ChangeFieldLevel(bool _FadeColorBlack = true, float _FadeDuration = 1.5f);

	void ChangeBGM(const std::string_view& _BgmName);

	bool IsWildBattle()
	{
		return (BattleNpcType::None == BattleType);
	}

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel);
	void LevelChangeStart(GameEngineLevel* _PrevLevel);

private:
	static const char BattleKey;

	GameEngineRender* FadeDownRender = nullptr;
	GameEngineRender* FadeUpRender = nullptr;

	BattleFSM* BattleFsmPtr = nullptr;
	BattleNpcType BattleType = BattleNpcType::None;


	GameEngineSoundPlayer BgmCtrl;
	const float WorldBgmVolumn = 1.0f;

	void InitActors(BattleFieldType _FieldType, BattleNpcType _NpcType, const std::vector<PokeDataBase>& _EnemyMonsters);

	bool TestKeyUpdate();

	void Init_Level(
		const std::vector<PokeDataBase>& _EnemyMonsters,
		BattleFieldType _FieldType,
		BattleNpcType _NpcType = BattleNpcType::None);

	BattleFieldType FieldConvertor(GroundType _FieldType);




	void CreateBGM(BattleNpcType _BattleType);


	void Clear();
};


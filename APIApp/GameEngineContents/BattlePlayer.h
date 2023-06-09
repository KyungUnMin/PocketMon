#pragma once
#include "BattleTrainerBase.h"
#include <string_view>

class GameEngineRender;
class BattleMonsterPlayer;

class BattlePlayerFSM;
class PokeDataBase;
enum class PokeSkill;
enum class BattleNpcType;
enum class BattleFieldType;
enum class BattlePlayer_StateType;

class BattlePlayer : public BattleTrainerBase
{
public:
	static BattlePlayer* PlayerPtr;

	BattlePlayer();
	~BattlePlayer() override;

	BattlePlayer(const BattlePlayer& _Other) = delete;
	BattlePlayer(BattlePlayer&& _Other) noexcept = delete;
	BattlePlayer& operator=(const BattlePlayer& _Other) = delete;
	BattlePlayer& operator=(const BattlePlayer&& _Other) noexcept = delete;

	void Init(BattleFieldType _FieldType, BattleNpcType _NpcType);


	PokeSkill GetSlotSkillType(size_t _Index);

	inline BattleMonsterPlayer* GetMonster()
	{
		return Monster;
	}

	PokeDataBase* GetMonsterDB() override;

	inline GameEngineRender* GetTrainerRender() override
	{
		return PlayerRenderPtr;
	}

	BattlePlayer_StateType GetNowState();

	inline BattlePlayerFSM* GetFSM()
	{
		return FsmPtr;
	}

	void ThrowBallToCreate();
	void ThrowBallToCatch(bool _IsMasterBall);
	void CreateMontser();

	void ChangeNextMonster();
	
protected:

	void Update(float _DeltaTime) override;

private:
	GameEngineRender* PlayerRenderPtr = nullptr;
	BattleMonsterPlayer* Monster = nullptr;
	BattlePlayerFSM* FsmPtr = nullptr;
	
	void CreateGround(BattleFieldType _FieldType);
};
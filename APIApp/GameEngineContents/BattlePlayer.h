#pragma once
#include "BattleTrainerBase.h"

class GameEngineRender;
class BattleMonsterPlayer;
enum class PokeSkill;
//enum class PokeD

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

	void Init(BattleFieldType _FieldType);
	void CreateMontser();

	PokeSkill GetSlotSkillType(size_t _Index);

	inline BattleMonsterPlayer* GetMonster()
	{
		return Monster;
	}



protected:
	void Update(float _DeltaTime) override;

private:
	static const std::string_view IdleAniName;
	static const std::string_view ThrowAniName;

	enum class State
	{
		Move,
		Idle,
		Throw
	};

	GameEngineRender* PlayerRenderPtr = nullptr;
	BattleMonsterPlayer* Monster = nullptr;
	const float4 PlayerRenderScale = float4{ 256.f, 196.f };
	const float4 PlayerRenderOffset = float4{ 0.f, -65.f };

	State CurState = State::Move;
	float4 MoveStartPos = float4::Zero;
	float4 MoveEndPos = float4::Zero;
	const float4 ThrowMoveDest = float4{ -400.f, -65.f };
	const float ThrowDuration = 0.5f;
	float4 MonsterSpawnPos = float4::Zero;

	
	void CreateGround(BattleFieldType _FieldType);
	void CreatePlayerRender();

	void Update_Move();
	void Update_Throw();
};
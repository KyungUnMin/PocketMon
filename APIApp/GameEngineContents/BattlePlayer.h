#pragma once
#include "BattleTrainerBase.h"

class GameEngineRender;
class BattleMonsterPlayer;

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
	void CreateMontser() override;



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

	State CurState = State::Move;
	float4 MoveStartPos = float4::Zero;
	float4 MoveEndPos = float4::Zero;
	const float ThrowDuration = 0.5f;
	const float ThrowMoveLen = 300.f;

	
	void CreateGround(BattleFieldType _FieldType);
	void CreatePlayerRender();

	void Update_Move();
	void Update_Throw();
};


#pragma once
#include <GameEngineCore/GameEngineActor.h>

class BattleMonsterBase;
class GameEngineActor;

class Battle_HpUIHandlerBase : public GameEngineActor
{
public:
	Battle_HpUIHandlerBase();
	~Battle_HpUIHandlerBase() override;

	Battle_HpUIHandlerBase(const Battle_HpUIHandlerBase& _Other) = delete;
	Battle_HpUIHandlerBase(Battle_HpUIHandlerBase&& _Other) noexcept = delete;
	Battle_HpUIHandlerBase& operator=(const Battle_HpUIHandlerBase& _Other) = delete;
	Battle_HpUIHandlerBase& operator=(const Battle_HpUIHandlerBase&& _Other) noexcept = delete;

	virtual void OnDamage(int _Value) = 0;

	void ExpCheck();

	virtual bool IsLevelUp() { return false; }

	virtual void SetPrevExp(int _Exp);

protected:
	inline void SetOwner(BattleMonsterBase* _Owner)
	{
		Owner = _Owner;
	}

	inline void SetUI(GameEngineActor* _UI)
	{
		UI = _UI;
	}

	virtual void Start() = 0;
	void Update(float _DeltaTime) final;

	inline void SetMovePoints(const float4& _StartPos, const float4& _DestPos)
	{
		StartPos = _StartPos;
		DestPos = _DestPos;
	}

	inline void SetOffset(const float4& _Offset)
	{
		Offset = _Offset;
	}

private:
	bool IsArrive = false;
	BattleMonsterBase* Owner = nullptr;
	GameEngineActor* UI = nullptr;

	float4 StartPos = float4::Zero;
	float4 DestPos = float4::Zero;
	float4 Offset = float4::Zero;
	const float Duration = 0.5f;
};


#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineLevel;
class GameEngineRender;
class PokeDataBase;
enum class PokeNumber;

enum class BattleMonsterType
{
	PlayerMon,
	WildMon,
	NPCMon,
};

class BattleMonsterBase : public GameEngineActor
{
public:
	static BattleMonsterBase* CreateMonster(
		GameEngineLevel* _Level, 
		PokeNumber _MonType,
		BattleMonsterType _OwnerType);

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
	void Update(float _DeltaTime) override;

	inline GameEngineRender* SetShadow(GameEngineRender* _ShadowRender)
	{
		AppearRender = _ShadowRender;
	}

	

private:
	BattleMonsterType OwnerType = BattleMonsterType::WildMon;
	PokeDataBase* DbPtr = nullptr;

	GameEngineRender* AppearRender = nullptr;
	const float4 StartAlpha = float4{ 100.f, 0.f };

	enum class State
	{
		Move,
		Appear,
		Ready
	};

	State CurState = State::Appear;
	float AppearTime = 0.f;

	void RenderCreate();
	void Update_Move();
	void Update_Appear();
};


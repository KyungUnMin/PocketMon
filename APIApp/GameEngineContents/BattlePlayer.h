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
	void CreatePlayerMonster();

protected:
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* PlayerRenderPtr = nullptr;
	BattleMonsterPlayer* Monster = nullptr;

	bool IsMonsterAppear = false;
	float MoveStartTime = 0.f;

	void CreateGround(BattleFieldType _FieldType);
	void CreatePlayerRender();
};


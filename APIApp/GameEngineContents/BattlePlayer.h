#pragma once
#include "BattleTrainerBase.h"

class GameEngineRender;

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

protected:

private:
	GameEngineRender* PlayerRenderPtr = nullptr;

	void CreateGround(BattleFieldType _FieldType);
	void CreatePlayer();
};


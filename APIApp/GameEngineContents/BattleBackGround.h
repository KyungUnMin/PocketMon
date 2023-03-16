#pragma once
#include <GameEngineCore/GameEngineActor.h>

class BattleBackGround : public GameEngineActor
{
public:
	BattleBackGround();
	~BattleBackGround();

	BattleBackGround(const BattleBackGround& _Other) = delete;
	BattleBackGround(BattleBackGround&& _Other) noexcept = delete;
	BattleBackGround& operator=(const BattleBackGround& _Other) = delete;
	BattleBackGround& operator=(const BattleBackGround&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	
private:

};


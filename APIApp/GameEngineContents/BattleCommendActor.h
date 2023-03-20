#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BattleCommendActor : public GameEngineActor
{
public:
	// constrcuter destructer
	BattleCommendActor();
	~BattleCommendActor();

	// delete Function
	BattleCommendActor(const BattleCommendActor& _Other) = delete;
	BattleCommendActor(BattleCommendActor&& _Other) noexcept = delete;
	BattleCommendActor& operator=(const BattleCommendActor& _Other) = delete;
	BattleCommendActor& operator=(BattleCommendActor&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void B_ArrowNumberCheck();
	void B_ArrowInput(int _Number);

	GameEngineRender* BattleArrowRender= nullptr;

private:

	int B_ArrowCheckNum = 0;

};


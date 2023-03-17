#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Battle_Select : public GameEngineActor
{
public:
	// constrcuter destructer
	Battle_Select();
	~Battle_Select();

	// delete Function
	Battle_Select(const Battle_Select& _Other) = delete;
	Battle_Select(Battle_Select&& _Other) noexcept = delete;
	Battle_Select& operator=(const Battle_Select& _Other) = delete;
	Battle_Select& operator=(Battle_Select&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
//	void CollisionCheck(float _DeltaTime);
	

private:

	GameEngineCollision* ArrowCol = nullptr;

};


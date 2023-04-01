#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class JumpEffect : public GameEngineActor
{
public:
	// constrcuter destructer
	JumpEffect();
	~JumpEffect();

	// delete Function
	JumpEffect(const JumpEffect& _Other) = delete;
	JumpEffect(JumpEffect&& _Other) noexcept = delete;
	JumpEffect& operator=(const JumpEffect& _Other) = delete;
	JumpEffect& operator=(JumpEffect&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	GameEngineRender* Effect = nullptr;

};

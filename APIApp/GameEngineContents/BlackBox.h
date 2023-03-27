#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BlackBox : public GameEngineActor
{
public:
	// constrcuter destructer
	BlackBox();
	~BlackBox();

	// delete Function
	BlackBox(const BlackBox& _Other) = delete;
	BlackBox(BlackBox&& _Other) noexcept = delete;
	BlackBox& operator=(const BlackBox& _Other) = delete;
	BlackBox& operator=(BlackBox&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:

};


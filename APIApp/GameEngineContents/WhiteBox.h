#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class WhiteBox : public GameEngineActor
{
public:
	// constrcuter destructer
	WhiteBox();
	~WhiteBox();

	// delete Function
	WhiteBox(const WhiteBox& _Other) = delete;
	WhiteBox(WhiteBox&& _Other) noexcept = delete;
	WhiteBox& operator=(const WhiteBox& _Other) = delete;
	WhiteBox& operator=(WhiteBox&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:

};


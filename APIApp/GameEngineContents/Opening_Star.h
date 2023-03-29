#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Opening_Star : public GameEngineActor
{
public:
	// constrcuter destructer
	Opening_Star();
	~Opening_Star();

	// delete Function
	Opening_Star(const Opening_Star& _Other) = delete;
	Opening_Star(Opening_Star&& _Other) noexcept = delete;
	Opening_Star& operator=(const Opening_Star& _Other) = delete;
	Opening_Star& operator=(Opening_Star&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

};


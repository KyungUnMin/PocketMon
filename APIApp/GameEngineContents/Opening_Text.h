#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Opening_Text : public GameEngineActor
{
public:
	// constrcuter destructer
	Opening_Text();
	~Opening_Text();

	// delete Function
	Opening_Text(const Opening_Text& _Other) = delete;
	Opening_Text(Opening_Text&& _Other) noexcept = delete;
	Opening_Text& operator=(const Opening_Text& _Other) = delete;
	Opening_Text& operator=(Opening_Text&& _Other) noexcept = delete;

	void AlphaControl(float _Deltatime);

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

	int Alphavalue = 255;

	float AlphaTime = 0.0f;

};


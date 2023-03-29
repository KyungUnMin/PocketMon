#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Logo_PressStart : public GameEngineActor
{
public:
	// constrcuter destructer
	Logo_PressStart();
	~Logo_PressStart();

	// delete Function
	Logo_PressStart(const Logo_PressStart& _Other) = delete;
	Logo_PressStart(Logo_PressStart&& _Other) noexcept = delete;
	Logo_PressStart& operator=(const Logo_PressStart& _Other) = delete;
	Logo_PressStart& operator=(Logo_PressStart&& _Other) noexcept = delete;

	void BlinkStart()
	{
		IsBlinkStart = true;
	}

	void BlinkEnd();

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

	bool IsBlinkStart = false;
	bool RenderOff = false;
	float BlinkTime = 0.0f;

	void Blink(float _Deltatime);
};


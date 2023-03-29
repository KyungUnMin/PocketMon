#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Logo_Fireredversion_White : public GameEngineActor
{
public:
	static Logo_Fireredversion_White* FireWhitePtr;
	static bool FireBlink;

	// constrcuter destructer
	Logo_Fireredversion_White();
	~Logo_Fireredversion_White();

	// delete Function
	Logo_Fireredversion_White(const Logo_Fireredversion_White& _Other) = delete;
	Logo_Fireredversion_White(Logo_Fireredversion_White&& _Other) noexcept = delete;
	Logo_Fireredversion_White& operator=(const Logo_Fireredversion_White& _Other) = delete;
	Logo_Fireredversion_White& operator=(Logo_Fireredversion_White&& _Other) noexcept = delete;

	void BlinkStart()
	{
		IsBlink = true;
	}

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

	int BlinkValue = 0;
	float BlinkTime = 0.0f;

	bool IsBlink = false;
	bool BlinkUp = false;
	bool BlinkDown = true;


	void BlinkAnimation(float _Deltatime);
};


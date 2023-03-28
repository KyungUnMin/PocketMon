#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Logo_Charizard_White : public GameEngineActor
{
public:
	static Logo_Charizard_White* ZardWhitePtr;
	static bool OriginBlink;
	static int OffCount1;

	// constrcuter destructer
	Logo_Charizard_White();
	~Logo_Charizard_White();

	// delete Function
	Logo_Charizard_White(const Logo_Charizard_White& _Other) = delete;
	Logo_Charizard_White(Logo_Charizard_White&& _Other) noexcept = delete;
	Logo_Charizard_White& operator=(const Logo_Charizard_White& _Other) = delete;
	Logo_Charizard_White& operator=(Logo_Charizard_White&& _Other) noexcept = delete;

	void BlinkStart()
	{
		BlinkDown = false;
	}

	void OriginBlinkStart()
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
	void OriginBlinkAnimation(float _Deltatime);
};


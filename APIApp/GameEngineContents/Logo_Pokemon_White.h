#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Logo_Pokemon_White : public GameEngineActor
{
public:
	static Logo_Pokemon_White* PokeWhitePtr;
	static bool PokeBlink;

	// constrcuter destructer
	Logo_Pokemon_White();
	~Logo_Pokemon_White();

	// delete Function
	Logo_Pokemon_White(const Logo_Pokemon_White& _Other) = delete;
	Logo_Pokemon_White(Logo_Pokemon_White&& _Other) noexcept = delete;
	Logo_Pokemon_White& operator=(const Logo_Pokemon_White& _Other) = delete;
	Logo_Pokemon_White& operator=(Logo_Pokemon_White&& _Other) noexcept = delete;

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


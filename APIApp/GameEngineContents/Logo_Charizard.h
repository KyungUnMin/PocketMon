#pragma once

#include <GameEngineCore/GameEngineActor.h>

enum class ZardColor
{
	Gray,
	Origin,
};

// Ό³Έν :
class Logo_Charizard : public GameEngineActor
{
public:
	// constrcuter destructer
	Logo_Charizard();
	~Logo_Charizard();

	// delete Function
	Logo_Charizard(const Logo_Charizard& _Other) = delete;
	Logo_Charizard(Logo_Charizard&& _Other) noexcept = delete;
	Logo_Charizard& operator=(const Logo_Charizard& _Other) = delete;
	Logo_Charizard& operator=(Logo_Charizard&& _Other) noexcept = delete;

	void GrayAnimationStart()
	{
		IsGrayStart = true;
	}

	void ColorGray()
	{

	}

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;
	ZardColor ColorSelect = ZardColor::Gray;

	float GrayTime = 0.0f;

	bool IsGrayStart = false;

	void ChangeColor(ZardColor _Color);
	void GaryAnimaion(float _Deltatime);

};


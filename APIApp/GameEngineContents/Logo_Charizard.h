#pragma once

#include <GameEngineCore/GameEngineActor.h>

enum class ZardColor
{
	Gray,
	Origin,
};

// ���� :
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

	void ColorGray()
	{

	}

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;
	ZardColor ColorSelect = ZardColor::Gray;

	void ColorChange();

};


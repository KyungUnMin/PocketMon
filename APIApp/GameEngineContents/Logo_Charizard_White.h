#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Logo_Charizard_White : public GameEngineActor
{
public:
	// constrcuter destructer
	Logo_Charizard_White();
	~Logo_Charizard_White();

	// delete Function
	Logo_Charizard_White(const Logo_Charizard_White& _Other) = delete;
	Logo_Charizard_White(Logo_Charizard_White&& _Other) noexcept = delete;
	Logo_Charizard_White& operator=(const Logo_Charizard_White& _Other) = delete;
	Logo_Charizard_White& operator=(Logo_Charizard_White&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

};


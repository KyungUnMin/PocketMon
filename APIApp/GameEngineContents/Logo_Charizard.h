#pragma once

#include <GameEngineCore/GameEngineActor.h>

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

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:

};


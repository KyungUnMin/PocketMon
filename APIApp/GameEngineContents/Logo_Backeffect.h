#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Logo_Backeffect : public GameEngineActor
{
public:
	// constrcuter destructer
	Logo_Backeffect();
	~Logo_Backeffect();

	// delete Function
	Logo_Backeffect(const Logo_Backeffect& _Other) = delete;
	Logo_Backeffect(Logo_Backeffect&& _Other) noexcept = delete;
	Logo_Backeffect& operator=(const Logo_Backeffect& _Other) = delete;
	Logo_Backeffect& operator=(Logo_Backeffect&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:

};


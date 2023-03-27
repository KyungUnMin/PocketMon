#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Logo_Pokemon : public GameEngineActor
{
public:
	// constrcuter destructer
	Logo_Pokemon();
	~Logo_Pokemon();

	// delete Function
	Logo_Pokemon(const Logo_Pokemon& _Other) = delete;
	Logo_Pokemon(Logo_Pokemon&& _Other) noexcept = delete;
	Logo_Pokemon& operator=(const Logo_Pokemon& _Other) = delete;
	Logo_Pokemon& operator=(Logo_Pokemon&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:

};


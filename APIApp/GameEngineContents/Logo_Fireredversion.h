#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Logo_Fireredversion : public GameEngineActor
{
public:
	// constrcuter destructer
	Logo_Fireredversion();
	~Logo_Fireredversion();

	// delete Function
	Logo_Fireredversion(const Logo_Fireredversion& _Other) = delete;
	Logo_Fireredversion(Logo_Fireredversion&& _Other) noexcept = delete;
	Logo_Fireredversion& operator=(const Logo_Fireredversion& _Other) = delete;
	Logo_Fireredversion& operator=(Logo_Fireredversion&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:

};


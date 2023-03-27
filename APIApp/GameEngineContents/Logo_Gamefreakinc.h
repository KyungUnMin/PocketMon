#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Logo_Gamefreakinc : public GameEngineActor
{
public:
	// constrcuter destructer
	Logo_Gamefreakinc();
	~Logo_Gamefreakinc();

	// delete Function
	Logo_Gamefreakinc(const Logo_Gamefreakinc& _Other) = delete;
	Logo_Gamefreakinc(Logo_Gamefreakinc&& _Other) noexcept = delete;
	Logo_Gamefreakinc& operator=(const Logo_Gamefreakinc& _Other) = delete;
	Logo_Gamefreakinc& operator=(Logo_Gamefreakinc&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:

};


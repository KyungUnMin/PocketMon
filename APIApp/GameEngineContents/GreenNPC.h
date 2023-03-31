#pragma once
#include "StaticNPC.h"

class GreenNPC : public StaticNPC
{
public:
	GreenNPC();
	~GreenNPC();

	GreenNPC(const GreenNPC& _Other) = delete;
	GreenNPC(GreenNPC&& _Other) noexcept = delete;
	GreenNPC& operator=(const GreenNPC& _Other) = delete;
	GreenNPC& operator=(GreenNPC&& _Other) noexcept = delete;

	bool BattleEventCheck();
	void BattleStart();

protected:
	
	void IdleUpdate(float _DeltaTime) override;
	
	void InteractionEnd() override;
private:
	bool IsSelectMove = false;
	bool IsBlockMove = false;
	bool IsBattleEnd = false;
};


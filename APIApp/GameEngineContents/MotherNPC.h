#pragma once
#include "StaticNPC.h"

class MotherNPC : public StaticNPC
{
public:
	MotherNPC();
	~MotherNPC();

	MotherNPC(const MotherNPC& _Other) = delete;
	MotherNPC(MotherNPC&& _Other) noexcept = delete;
	MotherNPC& operator=(const MotherNPC& _Other) = delete;
	MotherNPC& operator=(MotherNPC&& _Other) noexcept = delete;

protected:

	void IdleUpdate(float _DeltaTime) override;
	void InteractionEnd() override;

private:


};


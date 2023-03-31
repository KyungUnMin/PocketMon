#pragma once
#include "StaticNPC.h"

class OakNPC : public StaticNPC
{
public:
	OakNPC();
	~OakNPC();

	OakNPC(const OakNPC& _Other) = delete;
	OakNPC(OakNPC&& _Other) noexcept = delete;
	OakNPC& operator=(const OakNPC& _Other) = delete;
	OakNPC& operator=(OakNPC&& _Other) noexcept = delete;

protected:	
	void IdleUpdate(float _DeltaTime) override;
private:


};


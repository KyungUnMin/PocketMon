#pragma once
#include "BaseNPC.h"

class StopOakNPC : public BaseNPC
{
public:
	StopOakNPC();
	~StopOakNPC();

	StopOakNPC(const StopOakNPC& _Other) = delete;
	StopOakNPC(StopOakNPC&& _Other) noexcept = delete;
	StopOakNPC& operator=(const StopOakNPC& _Other) = delete;
	StopOakNPC& operator=(StopOakNPC&& _Other) noexcept = delete;

protected:
	void Start() override;
	void IdleUpdate(float _DeltaTime) override;

	void MoveStart() override;
	void MoveEnd() override;

	void InteractionStart() override;
	void InteractionUpdate(float _DeltaTime) override;
	void InteractionEnd() override;


private:
	bool FirstEventEnd = false;
	bool SecondEventEnd = false;
	int InputHandle = -1;
};


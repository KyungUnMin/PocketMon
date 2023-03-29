#pragma once
#include "BaseNPC.h"

enum class LookDir;
class TurnNPC : public BaseNPC
{
public:
	enum class TurnDir
	{
		Left,
		Right
	};
public:
	// constrcuter destructer
	TurnNPC();
	~TurnNPC();

	// delete Function
	TurnNPC(const TurnNPC& _Other) = delete;
	TurnNPC(TurnNPC&& _Other) noexcept = delete;
	TurnNPC& operator=(const TurnNPC& _Other) = delete;
	TurnNPC& operator=(TurnNPC&& _Other) noexcept = delete;

	inline void SetTurnTime(float _Time)
	{
		TurnTime = _Time;
	}

	inline void SetTurnDir(TurnDir _TurnDir)
	{
		TurnDirEnum = _TurnDir;
	}

protected:
	void IdleUpdate(float _DeltaTime) override;

private:
	TurnDir TurnDirEnum = TurnDir::Right;

	float TurnTime = 1.0f;
	float TurnProgress = 0.0f;
};


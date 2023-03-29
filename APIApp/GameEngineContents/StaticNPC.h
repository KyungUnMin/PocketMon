#pragma once
#include "BaseNPC.h"

// ���� :
enum class LookDir;
class StaticNPC : public BaseNPC
{
public:
	// constrcuter destructer
	StaticNPC();
	~StaticNPC();

	// delete Function
	StaticNPC(const StaticNPC& _Other) = delete;
	StaticNPC(StaticNPC&& _Other) noexcept = delete;
	StaticNPC& operator=(const StaticNPC& _Other) = delete;
	StaticNPC& operator=(StaticNPC&& _Other) noexcept = delete;

	inline void SetBaseDir(LookDir _Dir)
	{
		BaseDir = _Dir;
	}

protected:
	void MoveEnd() override;
	void InteractionEnd() override;

private:
	LookDir BaseDir;
};


#pragma once
#include "BaseNPC.h"

// Ό³Έν :
class StaticNPC : BaseNPC
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

protected:

private:

};


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

protected:
	
private:


};


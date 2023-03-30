#pragma once
#include "StaticNPC.h"

class MarketNPC : public StaticNPC
{
public:
	MarketNPC();
	~MarketNPC();

	MarketNPC(const MarketNPC& _Other) = delete;
	MarketNPC(MarketNPC&& _Other) noexcept = delete;
	MarketNPC& operator=(const MarketNPC& _Other) = delete;
	MarketNPC& operator=(MarketNPC&& _Other) noexcept = delete;

protected:
	
private:


};


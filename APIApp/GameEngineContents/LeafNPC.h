#pragma once
#include "StaticNPC.h"

class LeafNPC : public StaticNPC
{
public:
	LeafNPC();
	~LeafNPC();

	LeafNPC(const LeafNPC& _Other) = delete;
	LeafNPC(LeafNPC&& _Other) noexcept = delete;
	LeafNPC& operator=(const LeafNPC& _Other) = delete;
	LeafNPC& operator=(LeafNPC&& _Other) noexcept = delete;

protected:

	void InteractionStart() override;
	void InteractionEnd() override;

private:

};
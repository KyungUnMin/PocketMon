#pragma once
#include "DoorActorBase.h"

class GameEngineRender;
class FieldmapDoubleDoor : public DoorActorBase
{
public:
	FieldmapDoubleDoor();
	~FieldmapDoubleDoor();

	FieldmapDoubleDoor(const FieldmapDoubleDoor& _Other) = delete;
	FieldmapDoubleDoor(FieldmapDoubleDoor&& _Other) noexcept = delete;
	FieldmapDoubleDoor& operator=(const FieldmapDoubleDoor& _Other) = delete;
	FieldmapDoubleDoor& operator=(FieldmapDoubleDoor&& _Other) noexcept = delete;

protected:
	void RenderInit() override;

	void PlayOpenSound() override;

private:
};
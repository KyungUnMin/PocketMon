#pragma once
#include "DoorActorBase.h"

class FieldmapWoodDoor : public DoorActorBase
{
public:
	FieldmapWoodDoor();
	~FieldmapWoodDoor();

	FieldmapWoodDoor(const FieldmapWoodDoor& _Other) = delete;
	FieldmapWoodDoor(FieldmapWoodDoor&& _Other) noexcept = delete;
	FieldmapWoodDoor& operator=(const FieldmapWoodDoor& _Other) = delete;
	FieldmapWoodDoor& operator=(FieldmapWoodDoor&& _Other) noexcept = delete;

protected:
	void RenderInit() override;

private:

};
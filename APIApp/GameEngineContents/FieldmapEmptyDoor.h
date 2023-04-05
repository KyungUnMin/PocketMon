#pragma once
#include "DoorActorBase.h"

class FieldmapEmptyDoor : public DoorActorBase
{
public:
	FieldmapEmptyDoor();
	~FieldmapEmptyDoor();

	FieldmapEmptyDoor(const FieldmapEmptyDoor& _Other) = delete;
	FieldmapEmptyDoor(FieldmapEmptyDoor&& _Other) noexcept = delete;
	FieldmapEmptyDoor& operator=(const FieldmapEmptyDoor& _Other) = delete;
	FieldmapEmptyDoor& operator=(FieldmapEmptyDoor&& _Other) noexcept = delete;

	void UseDoor() override;

protected:
	void RenderInit() override;
private:

};
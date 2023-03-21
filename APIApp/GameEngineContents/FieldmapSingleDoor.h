#pragma once
#include "DoorActorBase.h"

class FieldmapSingleDoor : public DoorActorBase
{
public:
	FieldmapSingleDoor();
	~FieldmapSingleDoor();

	FieldmapSingleDoor(const FieldmapSingleDoor& _Other) = delete;
	FieldmapSingleDoor(FieldmapSingleDoor&& _Other) noexcept = delete;
	FieldmapSingleDoor& operator=(const FieldmapSingleDoor& _Other) = delete;
	FieldmapSingleDoor& operator=(FieldmapSingleDoor&& _Other) noexcept = delete;

protected:
	void RenderInit() override;
private:

};
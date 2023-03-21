#pragma once
#include <GameEngineBase/GameEngineTimeEvent.h>
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include "int2.h"

class DoorActorBase : public GameEngineActor
{
public:
	DoorActorBase();
	~DoorActorBase();

	DoorActorBase(const DoorActorBase& _Other) = delete;
	DoorActorBase(DoorActorBase&& _Other) noexcept = delete;
	DoorActorBase& operator=(const DoorActorBase& _Other) = delete;
	DoorActorBase& operator=(DoorActorBase&& _Other) noexcept = delete;
	
	inline void SetDoorName(const std::string_view& _DoorName)
	{
		DoorName = _DoorName;
	}

	inline void SetDoorCity(const std::string_view& _CityName)
	{
		DoorCity = _CityName;
	}

	inline void SetDoorIndex(const int2& _Index)
	{
		DoorIndex = _Index;
	}

	void SetLinkDoor(DoorActorBase* _LinkDoor);

	bool VaildDoor() const
	{
		return true;
	}

	void UseDoor();

protected:
	GameEngineRender* DoorRender = nullptr;

	static const std::string DoorIdleAnimName;
	static const std::string DoorOpenAnimName;
	static const std::string DoorCloseAnimName;

	// �ش� �ִϸ��̼��� �ݵ�� ���� Idle, Open, Close static onst std::string�� ����� ������ ������ ��
	virtual void RenderInit() = 0;
private:
	GameEngineTimeEvent DoorEvent;

	std::string DoorName;
	std::string DoorCity;
	int2 DoorIndex;

	DoorActorBase* LinkDoor = nullptr;

	bool IsUse = false;

	void Start() override;
	void Update(float _DeltaTime) override;

	void DoorOpenAndClose();
	void DoorOpen();
	void DoorClose();
	void PlayerMove();
};
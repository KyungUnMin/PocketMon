#pragma once
#include <GameEngineCore/GameEngineActor.h>

class FieldmapFlower : public GameEngineActor
{
public:
	FieldmapFlower();
	~FieldmapFlower();

	FieldmapFlower(const FieldmapFlower& _Other) = delete;
	FieldmapFlower(FieldmapFlower&& _Other) noexcept = delete;
	FieldmapFlower& operator=(const FieldmapFlower& _Other) = delete;
	FieldmapFlower& operator=(FieldmapFlower&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};
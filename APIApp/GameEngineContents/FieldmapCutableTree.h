#pragma once
#include <GameEngineCore/GameEngineActor.h>

class FieldmapCutableTree : public GameEngineActor
{
public:
	FieldmapCutableTree();
	~FieldmapCutableTree();

	FieldmapCutableTree(const FieldmapCutableTree& _Other) = delete;
	FieldmapCutableTree(FieldmapCutableTree&& _Other) noexcept = delete;
	FieldmapCutableTree& operator=(const FieldmapCutableTree& _Other) = delete;
	FieldmapCutableTree& operator=(FieldmapCutableTree&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};
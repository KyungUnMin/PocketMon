#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class FieldmapLevel : public GameEngineLevel
{
public:
	FieldmapLevel();
	~FieldmapLevel();

	FieldmapLevel(const FieldmapLevel& _Other) = delete;
	FieldmapLevel(FieldmapLevel&& _Other) noexcept = delete;
	FieldmapLevel& operator=(const FieldmapLevel& _Other) = delete;
	FieldmapLevel& operator=(FieldmapLevel&& _Other) noexcept = delete;

protected:

private:

};
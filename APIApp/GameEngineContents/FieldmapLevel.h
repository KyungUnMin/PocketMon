#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class FieldmapRender;
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
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {}
private:
	FieldmapRender* MainFieldRender = nullptr;

	float4 FreeCameraPos = float4::Zero;

	bool IsCameraDebug = false;
};
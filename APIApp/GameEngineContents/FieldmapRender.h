#pragma once
#include <vector>
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;
class FieldmapRender : public GameEngineActor
{
public:
	FieldmapRender();
	~FieldmapRender();

	FieldmapRender(const FieldmapRender& _Other) = delete;
	FieldmapRender(FieldmapRender&& _Other) noexcept = delete;
	FieldmapRender& operator=(const FieldmapRender& _Other) = delete;
	FieldmapRender& operator=(FieldmapRender&& _Other) noexcept = delete;

	void RenderPosUpdate(const float4& _Pos);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	std::vector<std::vector<GameEngineRender*>> TileRenders;
	std::vector<std::vector<GameEngineRender*>> DebugRenders;
	float4 CurPos = float4::Zero;

	const int RenderSizeX = 3;
	const int RenderSizeY = 3;

	int FieldSize = 0;
	int FieldSizeHalf = 0;

	bool IsDebugRender = false;
};
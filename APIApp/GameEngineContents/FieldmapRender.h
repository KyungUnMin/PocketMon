#pragma once
#include <vector>
#include <GameEngineCore/GameEngineActor.h>
#include "TileDebugRender.h"

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
	void RenderTypeSwitch(TileDebugRender::RenderType _DebugRenderType);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	std::vector<std::vector<TileDebugRender*>> TileDebugRenders;

	float4 RendersSizeHalf = float4::Zero;
	float4 CurPos = float4::Zero;

	const int RenderSizeX = 3;
	const int RenderSizeY = 3;

	float4 FieldSizeHalfFloat4 = float4::Zero;
	int FieldSize = 0;
	int FieldSizeHalf = 0;
};
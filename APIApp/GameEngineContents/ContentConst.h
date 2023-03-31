#pragma once
#include <GameEngineBase/GameEngineMath.h>

class ContentConst
{
public:
	static const float4 NpcSize;
	static const float4 NpcRenderPos;

protected:

private:
	ContentConst();
	~ContentConst();

	ContentConst(const ContentConst& _Other) = delete;
	ContentConst(ContentConst&& _Other) noexcept = delete;
	ContentConst& operator=(const ContentConst& _Other) = delete;
	ContentConst& operator=(ContentConst&& _Other) noexcept = delete;

};
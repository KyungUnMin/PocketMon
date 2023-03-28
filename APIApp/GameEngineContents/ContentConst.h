#pragma once
#include <GameEngineBase/GameEngineMath.h>

class ContentConst
{
public:
	static const float4 NpcSize;

protected:

private:
	ContentConst();
	~ContentConst();

	ContentConst(const ContentConst& _Other) = delete;
	ContentConst(ContentConst&& _Other) noexcept = delete;
	ContentConst& operator=(const ContentConst& _Other) = delete;
	ContentConst& operator=(ContentConst&& _Other) noexcept = delete;

};
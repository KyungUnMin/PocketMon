#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "int2.h"

class GameEngineRender;
class TileDebugRender : public GameEngineActor
{
public:
	enum class RenderType
	{
		Walkable,
		GroundType,
		Event
	};
public:
	TileDebugRender();
	~TileDebugRender();

	TileDebugRender(const TileDebugRender& _Other) = delete;
	TileDebugRender(TileDebugRender&& _Other) noexcept = delete;
	TileDebugRender& operator=(const TileDebugRender& _Other) = delete;
	TileDebugRender& operator=(TileDebugRender&& _Other) noexcept = delete;
	
	inline void SetIndex(const int2& _Index)
	{
		Index = _Index;
	}

	void SetDebugType(RenderType _DebugType);

	inline RenderType GetDebugType() const
	{
		return DebugType;
	}

protected:
	void Start();
	void Update(float _DeltaTime);

private:
	RenderType DebugType = RenderType::Walkable;

	int2 Index = int2::Zero;

	GameEngineRender* TileRender = nullptr;
	GameEngineRender* TextRender = nullptr;
};
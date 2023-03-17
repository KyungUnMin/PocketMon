#pragma once
#include <vector>
#include <map>
#include <string>
#include <GameEngineBase/GameEngineMath.h>
#include "int2.h"

class FieldData;
class Fieldmap
{
public:
	static const float TileSize;
	static const float TileSizeHalf;

	static float4 GetPos(const int _x, const int _y)
	{
		return GetPos(int2(_x, _y));
	}

	static float4 GetPos(const int2& _Index)
	{
		return float4(_Index.x * TileSize, _Index.y * TileSize);
	}

	static void CalRenderStartPos(float4& _Pos)
	{
		_Pos.x = TileSize * static_cast<int>(_Pos.x / TileSize);
		_Pos.y = TileSize * static_cast<int>(_Pos.y / TileSize);
	}

	static int2 GetIndex(const float _x, const float _y)
	{
		return GetIndex(float4(_x, _y));
	}

	static int2 GetIndex(const float4& _Pos);

	static bool Walkable(const float4& _Pos)
	{
		return Walkable(GetIndex(_Pos));
	}

	static int GetRenderFrame(const float4& _Pos)
	{
		return GetRenderFrame(GetIndex(_Pos));
	}

	static int GetRenderFrame(const int2& _Index);

	static bool Walkable(const int2& _Index);
	static bool AddFieldData(std::string _FieldName, std::string _FileName);
	static bool ChangeField(std::string _FieldName);

private:
	static FieldData* CurFieldData;
	static std::map<std::string, FieldData*> FieldList;

	// 소멸자 호출용 삭제 오브젝트
	static Fieldmap DeleteObject;

public:


protected:

private:	
	Fieldmap();
	~Fieldmap();

	Fieldmap(const Fieldmap& _Other) = delete;
	Fieldmap(Fieldmap&& _Other) noexcept = delete;
	Fieldmap& operator=(const Fieldmap& _Other) = delete;
	Fieldmap& operator=(Fieldmap&& _Other) noexcept = delete;
};
#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class Player;
class FieldDialog;
class FieldmapRender;
class FieldmapLevel : public GameEngineLevel
{
public:
	static float4 GetPlayerPos()
	{
		return PlayerPos;
	}
private:
	static float4 PlayerPos;
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
	Player* MainPlayer = nullptr;
	FieldDialog* MainFieldDialog = nullptr;
	FieldmapRender* MainFieldRender = nullptr;
	bool IsCameraDebug = false;

	void ImageLoad();
	
	// ImageName���� .bmp�� ���� �Է�
	void CreateFieldmapCity(const std::string_view& _CityName, const std::string_view& _ImageName, const float4& _Pos);

	bool VaileTest() const
	{
		int b = 0;

		return true;
	}

	void EventTest() const
	{
		int a = 0;
	}
};
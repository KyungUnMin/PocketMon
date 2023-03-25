#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "int2.h"

class EndingPlayerAnimActor;
class GameEngineRender;
class TextActor;
class EndingFade;
class EndingPlayActor : public GameEngineActor
{
public:
	static EndingPlayActor* MainEndingPlayActor;
	static bool IsEndingPlay;
public:
	EndingPlayActor();
	~EndingPlayActor();

	EndingPlayActor(const EndingPlayActor& _Other) = delete;
	EndingPlayActor(EndingPlayActor&& _Other) noexcept = delete;
	EndingPlayActor& operator=(const EndingPlayActor& _Other) = delete;
	EndingPlayActor& operator=(EndingPlayActor&& _Other) noexcept = delete;
public:
	void PlayEnding();

	void SetText(const std::string_view& _MainText, const std::string_view _SubText);
	void AddCameraMoveEvent(const std::string_view& _CityName, const int2& _CityIndex, const float4& _MoveDir = float4::Down);

	inline void SetCameraDir(const float4& _Dir)
	{
		CameraMoveDir = _Dir;
	}
		
	inline void SetFakeTextAlpha(float _Alpha)
	{
		FakeFontAlpha = _Alpha;
		UpdateAlpha();
	}

	inline void SetFakeTextAlphaDiff(float _Diff)
	{
		FakeFontAlphaDiff = _Diff;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	EndingPlayerAnimActor* PlayerAnim = nullptr;
	GameEngineRender* BackgroundRender = nullptr;
	EndingFade* Fade = nullptr;

	TextActor* MainTextActor = nullptr;
	TextActor* SubTextActor = nullptr;

	TextActor* MainFakeTextActor = nullptr;
	TextActor* SubFakeTextActor = nullptr;

	float4 CameraMoveDir = float4::Down;
	float CameraSpeed = 1.0f;

	float FakeFontAlpha = 0.0f;
	float FakeFontAlphaDiff = 0.0f;

	float4 BackgroundScaleStart = float4::Zero;
	float4 BackgroundScaleDest = float4::Zero;

	float BackgroundLerpScale = 0.0f;
	float BackgroundLerpSpeed = 1.0f;

	void UpdateAlpha();
};
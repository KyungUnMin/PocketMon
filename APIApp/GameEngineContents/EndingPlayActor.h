#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "int2.h"

class EndingPlayerAnimActor;
class GameEngineRender;
class TextActor;
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
	void AddCameraMoveEvent(const std::string_view& _CityName, const int2& _CityIndex);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	EndingPlayerAnimActor* PlayerAnim = nullptr;
	GameEngineRender* BackgroundRender = nullptr;

	TextActor* MainTextActor = nullptr;
	TextActor* SubTextActor = nullptr;

	TextActor* MainFakeTextActor = nullptr;
	TextActor* SubFakeTextActor = nullptr;

	float4 CameraMoveDir = float4::Down;
	float CameraSpeed = 1.0f;
};
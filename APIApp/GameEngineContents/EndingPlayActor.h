#pragma once
#include <GameEngineCore/GameEngineActor.h>

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

protected:
	void Start() override;

private:
	EndingPlayerAnimActor* PlayerAnim = nullptr;
	GameEngineRender* BackgroundRender = nullptr;
	TextActor* MainTextActor = nullptr;
	TextActor* SubTextActor = nullptr;

	float4 CameraStartPos = float4::Zero;
	float4 CameraDestPos = float4::Zero;

};
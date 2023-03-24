#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;
class EndingPlayerAnimActor : public GameEngineActor
{
public:
	EndingPlayerAnimActor();
	~EndingPlayerAnimActor();

	EndingPlayerAnimActor(const EndingPlayerAnimActor& _Other) = delete;
	EndingPlayerAnimActor(EndingPlayerAnimActor&& _Other) noexcept = delete;
	EndingPlayerAnimActor& operator=(const EndingPlayerAnimActor& _Other) = delete;
	EndingPlayerAnimActor& operator=(EndingPlayerAnimActor&& _Other) noexcept = delete;

protected:
	void Start() override;

private:
	GameEngineRender* AnimRender = nullptr;
};
#pragma once
#include <GameEngineCore/GameEngineActor.h>

class EndingEndLogo : public GameEngineActor
{
public:
	EndingEndLogo();
	~EndingEndLogo();

	EndingEndLogo(const EndingEndLogo& _Other) = delete;
	EndingEndLogo(EndingEndLogo&& _Other) noexcept = delete;
	EndingEndLogo& operator=(const EndingEndLogo& _Other) = delete;
	EndingEndLogo& operator=(EndingEndLogo&& _Other) noexcept = delete;

protected:

private:

};
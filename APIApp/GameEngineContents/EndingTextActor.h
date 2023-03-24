#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;
class EndingTextActor : public GameEngineActor
{
public:
	EndingTextActor();
	~EndingTextActor();

	EndingTextActor(const EndingTextActor& _Other) = delete;
	EndingTextActor(EndingTextActor&& _Other) noexcept = delete;
	EndingTextActor& operator=(const EndingTextActor& _Other) = delete;
	EndingTextActor& operator=(EndingTextActor&& _Other) noexcept = delete;

protected:
	void Start() override;
private:

	GameEngineRender* PokemonRender = nullptr;
};
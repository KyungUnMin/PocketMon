#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class PokeNumber;
class GameEngineRender;
class StartingPokeball : public GameEngineActor
{
public:
	StartingPokeball();
	~StartingPokeball();

	StartingPokeball(const StartingPokeball& _Other) = delete;
	StartingPokeball(StartingPokeball&& _Other) noexcept = delete;
	StartingPokeball& operator=(const StartingPokeball& _Other) = delete;
	StartingPokeball& operator=(StartingPokeball&& _Other) noexcept = delete;

	void Init(PokeNumber _Number);

	bool EventCheck();
	
	void EventFunc();
	void SelectEvent();

protected:
	void Start() override;

private:
	PokeNumber _MyNumber;
	GameEngineRender* PokeballRender = nullptr;
};


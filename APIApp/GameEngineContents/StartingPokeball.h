#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "int2.h"

enum class PokeNumber;
class GameEngineRender;
class StartingPokeball : public GameEngineActor
{
public:
	static int2 StaticRivalMovelIndex;
	static StartingPokeball* StaticRivalPokeball;

public:
	StartingPokeball();
	~StartingPokeball();

	StartingPokeball(const StartingPokeball& _Other) = delete;
	StartingPokeball(StartingPokeball&& _Other) noexcept = delete;
	StartingPokeball& operator=(const StartingPokeball& _Other) = delete;
	StartingPokeball& operator=(StartingPokeball&& _Other) noexcept = delete;

	void Init(PokeNumber _Number, int2 _RivalIndex, StartingPokeball* _RivalPokeball);

	bool EventCheck();
	
	void EventFunc();
	void SelectEvent();

	void RenderOff();

	inline PokeNumber GetPokeNumber() const
	{
		return PokemonNumber;
	}

protected:
	void Start() override;

private:
	PokeNumber PokemonNumber;

	StartingPokeball* RivalPokeball = nullptr;
	int2 RivalBallIndex = int2::Zero;

	GameEngineRender* PokeballRender = nullptr;
};


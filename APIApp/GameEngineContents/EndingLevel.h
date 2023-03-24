#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "EndingPokeballBackground.h"

class EndingPokemonRender;
class EndingFade;
class EndingTextActor;
class EndingLevel : public GameEngineLevel
{
public:
	EndingLevel();
	~EndingLevel();

	EndingLevel(const EndingLevel& _Other) = delete;
	EndingLevel(EndingLevel&& _Other) noexcept = delete;
	EndingLevel& operator=(const EndingLevel& _Other) = delete;
	EndingLevel& operator=(EndingLevel&& _Other) noexcept = delete;

	static EndingPokeballBackground::PokeColor PokeballColor;
	static std::string PokemonRenderImageName;

	static bool LastEffect;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override {}
		
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void LevelChangeEnd(GameEngineLevel* _PrevLevel) override;

private:	
	EndingPokeballBackground* PokeBackActor = nullptr;
	EndingPokemonRender* PokemonRender = nullptr;
	EndingFade* Fade = nullptr;
	EndingTextActor* LastLogo = nullptr;
};
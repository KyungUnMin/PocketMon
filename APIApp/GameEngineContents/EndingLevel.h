#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <vector>
#include <functional>
#include "EndingPokeballBackground.h"


class EndingPokemonRender;
class EndingFade;
class EndingTextActor;
class EndingLevel : public GameEngineLevel
{
private:
	static EndingPokeballBackground::PokeColor PokeballColor;
	static std::string PokemonRenderImageName;

	static bool LastEffect;
	static std::vector<std::function<void()>> EndCallFunctions;
public:
	EndingLevel();
	~EndingLevel();

	EndingLevel(const EndingLevel& _Other) = delete;
	EndingLevel(EndingLevel&& _Other) noexcept = delete;
	EndingLevel& operator=(const EndingLevel& _Other) = delete;
	EndingLevel& operator=(EndingLevel&& _Other) noexcept = delete;

	static void AddEndEvent(std::function<void()> _Event)
	{
		EndCallFunctions.push_back(_Event);
	}

	static void SetPokeballColor(EndingPokeballBackground::PokeColor _Color)
	{
		PokeballColor = _Color;
	}

	static void SetPokemonImageName(const std::string_view& _ImageName)
	{
		PokemonRenderImageName = _ImageName;
	}

	static void PlayLastEffect()
	{
		LastEffect = true;
	}

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
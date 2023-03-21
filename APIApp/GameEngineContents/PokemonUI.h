#pragma once
#include <vector>
#include <GameEngineCore/GameEngineActor.h>
#include "TextActor.h"
// Ό³Έν :
class GameEngineRender;
class PokemonUI : public GameEngineActor
{
public:
	// constrcuter destructer
	PokemonUI();
	~PokemonUI();

	// delete Function
	PokemonUI(const PokemonUI& _Other) = delete;
	PokemonUI(PokemonUI&& _Other) noexcept = delete;
	PokemonUI& operator=(const PokemonUI& _Other) = delete;
	PokemonUI& operator=(PokemonUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _PrevLevel) override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
private:
	GameEngineRender* MainPokemonBack = nullptr;
	GameEngineRender* MainPokemonRender = nullptr;
	TextActor* MainPokemonNameText = nullptr;
	TextActor* MainPokemonHPText = nullptr;
	TextActor* MainPokemonLevelText = nullptr;
	GameEngineRender* CancelButtonRender = nullptr;
	GameEngineRender* TextBarRender = nullptr;
	std::vector<GameEngineRender*> SubPokemonBack = std::vector<GameEngineRender*>(5);
	std::vector<GameEngineRender*> SubPokemonRender = std::vector<GameEngineRender*>(5);
	std::vector<TextActor*> SubPokemonNameText = std::vector<TextActor*>(5);
	std::vector<TextActor*> SubPokemonHPText = std::vector<TextActor*>(5);
	std::vector<TextActor*> SubPokemonLevelText = std::vector<TextActor*>(5);
};


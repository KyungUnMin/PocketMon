#pragma once
#include <vector>
#include <GameEngineCore/GameEngineActor.h>
#include "TextActor.h"

enum class PokemonUIState
{
	Normal,
	Potion,
	Give,
	Switch,
	Select
};

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
	GameEngineLevel* PrevLevel = nullptr;
	GameEngineRender* MainPokemonBack = nullptr;
	GameEngineRender* MainPokemonRender = nullptr;
	GameEngineRender* CancelButtonRender = nullptr;
	GameEngineRender* TextBarRender = nullptr;
	GameEngineRender* SelectRender = nullptr;
	GameEngineRender* SelectCursorRender = nullptr;
	std::vector<GameEngineRender*> SubPokemonBack = std::vector<GameEngineRender*>(5);
	std::vector<GameEngineRender*> SubPokemonRender = std::vector<GameEngineRender*>(5);
	std::vector<GameEngineRender*> CursorRender = std::vector<GameEngineRender*>(7);
	TextActor* MainPokemonNameText = nullptr;
	TextActor* MainPokemonHPText = nullptr;
	TextActor* MainPokemonMaxHPText = nullptr;
	TextActor* MainPokemonLevelText = nullptr;
	TextActor* SelectText = nullptr;
	std::vector<TextActor*> SubPokemonNameText = std::vector<TextActor*>(5);
	std::vector<TextActor*> SubPokemonHPText = std::vector<TextActor*>(5);
	std::vector<TextActor*> SubPokemonMaxHPText = std::vector<TextActor*>(5);
	std::vector<TextActor*> SubPokemonLevelText = std::vector<TextActor*>(5);
	bool IsSelect = false;
	int CurrentCursor = 0;
	int CurrentSelectCursor = 0;
	int SelectSize = 0;

	void CursorUp();
	void CursorDown();
	void CursorMove();

	void SelectOn();
	void SelectOff();
};


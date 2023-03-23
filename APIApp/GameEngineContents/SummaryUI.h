#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <vector>

enum class SummaryPage
{
	Info,
	Skills,
	Moves,
	MovesSwitch
};

// Ό³Έν :
class GameEngineRender;
class TextActor;
class PokeDataBase;
class SummaryUI : public GameEngineActor
{
	friend class PlayerBag;
public:
	// constrcuter destructer
	SummaryUI();
	~SummaryUI();

	// delete Function
	SummaryUI(const SummaryUI& _Other) = delete;
	SummaryUI(SummaryUI&& _Other) noexcept = delete;
	SummaryUI& operator=(const SummaryUI& _Other) = delete;
	SummaryUI& operator=(SummaryUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	GameEngineLevel* CurrentLevel = nullptr;
	GameEngineRender* InfoBack = nullptr;
	GameEngineRender* PokemonRender = nullptr;

	SummaryPage CurrentPage = SummaryPage::Info;
	std::vector<PokeDataBase*> Pokemons;
	int CurrentPokemon = 0;

	void NextPage();
	void PrevPage();
	void MovePage();

	void NextPokemon();
	void PrevPokemon();
	void MovePokemon();
};


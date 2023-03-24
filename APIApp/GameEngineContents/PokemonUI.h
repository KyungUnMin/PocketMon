#pragma once
#include <vector>
#include <functional>
#include <GameEngineCore/GameEngineActor.h>
#include "TextActor.h"
#include "Item.h"
enum class PokemonUIState
{
	Normal,		// �ʵ忡�� ��������
	Switch,		// (�ʵ�) ��ġ ��ȯ
	Shift,		// ���� �� ��ü
	Potion,		// ���濡�� ������ ���
	Give,		// ���濡�� ���ѹ��� ����
};

// ���� :
class GameEngineRender;
class PokeDataBase;
class PokemonUI : public GameEngineActor
{
public:
	// constrcuter destructer
	PokemonUI();
	~PokemonUI();

	static PokemonUI* MainPokemon;

	void ItemUse(ItemCode _ItemCode);

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
	GameEngineLevel* CurrentLevel = nullptr;
	std::vector<PokeDataBase*> Pokemons;

	std::vector<GameEngineRender*> PokemonBack = std::vector<GameEngineRender*>(6);
	std::vector<GameEngineRender*> PokemonRender = std::vector<GameEngineRender*>(6);
	std::vector<GameEngineRender*> CursorRender;
	GameEngineRender* CancelButtonRender = nullptr;

	GameEngineRender* TextBarRender = nullptr;
	GameEngineRender* SelectRender = nullptr;
	GameEngineRender* SelectCursorRender = nullptr;

	TextActor* SelectText = nullptr;
	std::vector<TextActor*> PokemonNameText = std::vector<TextActor*>(6);
	std::vector<TextActor*> PokemonCurrentHPText = std::vector<TextActor*>(6);
	std::vector<TextActor*> PokemonMaxHPText = std::vector<TextActor*>(6);
	std::vector<TextActor*> PokemonLevelText = std::vector<TextActor*>(6);
	std::vector<std::function<void()>> SelectFunctions = std::vector<std::function<void()>>(5);

	PokemonUIState StateValue = PokemonUIState::Normal;
	int CurrentCursor = 0;
	int SwitchCursor = 0;
	int CurrentSelectCursor = 0;
	int SelectSize = 0;
	bool IsSelect = false;

	void PokeDataSetting();

	void CursorUp();
	void CursorDown();
	void CursorMove();

	void SelectOn();
	void SelectOff();
	void SelectMenu();
	void SelectUp();
	void SelectDown();
	void SelectMove();

	void Summary();
	void Switch();
	void SwitchCancel();
	void SwitchSelect();
	void Item();
	void Shift();

	void PotionUse();
};


#pragma once
#include <vector>
#include <functional>
#include <GameEngineBase/GameEngineTimeEvent.h>
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineResources.h>
#include "Item.h"
enum class PokemonUIState
{
	Normal,		// 필드에서 열었을때
	Switch,		// (필드) 위치 교환
	Shift,		// 전투 중 교체
	Potion,		// 가방에서 아이템 사용
	Give,		// 가방에서 지닌물건 선택
};

// 설명 :
class GameEngineRender;
class PokeDataBase;
class TextActor;
class PokemonHPBar;
class PokemonUI : public GameEngineActor
{
	friend class SummaryUI;
public:
	// constrcuter destructer
	PokemonUI();
	~PokemonUI();

	static PokemonUI* MainPokemon;

	void SetState_ItemUse(ItemCode _ItemCode);
	void SetState_ItemGive(ItemCode _ItemCode);
	void SetState_Shift();
	void SetCursor(int _Cursor);
	// 포션을 사용했는가
	bool GetIsPotion();
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
	GameEngineSoundPlayer MenuSound;
	std::vector<PokeDataBase> Pokemons;

	std::vector<GameEngineRender*> PokemonBack = std::vector<GameEngineRender*>(6);
	std::vector<GameEngineRender*> PokemonRender = std::vector<GameEngineRender*>(6);
	std::vector<GameEngineRender*> PokemonItem = std::vector<GameEngineRender*>(6);
	std::vector <PokemonHPBar*> PokemonHPBars = std::vector<PokemonHPBar*>(6);

	std::vector<GameEngineRender*> CursorRender;
	GameEngineRender* CancelButtonRender = nullptr;

	GameEngineRender* TextBarRender = nullptr;
	GameEngineRender* SelectRender = nullptr;
	GameEngineRender* SelectCursorRender = nullptr;

	TextActor* BarText = nullptr;
	TextActor* SelectText = nullptr;
	std::vector<TextActor*> PokemonNameText = std::vector<TextActor*>(6);
	std::vector<TextActor*> PokemonCurrentHPText = std::vector<TextActor*>(6);
	std::vector<TextActor*> PokemonMaxHPText = std::vector<TextActor*>(6);
	std::vector<TextActor*> PokemonLevelText = std::vector<TextActor*>(6);
	std::vector<std::function<void()>> SelectFunctions = std::vector<std::function<void()>>(5);
	
	GameEngineTimeEvent TimeEvent;
	PokemonUIState StateValue = PokemonUIState::Normal;
	int CurrentCursor = 0;
	int SwitchCursor = 0;
	int CurrentSelectCursor = 0;
	int SelectSize = 0;
	bool IsSelect = false;
	bool IsBattle = false;
	bool IsPotion = false;
	int BeforeHP = 0;
	int CurrentHP = 0;
	float Timer = 0;
	ItemCode CurrentItemCode = ItemCode::Cancel;

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

	void SetBarText();
	void GiveItem();
	void PotionUse();

	void AnimUpdate(float _DeltaTime);
	float AnimTimer = 0;
	const float AnimSpeed = 13.5f;
	bool IsStop = false;
};


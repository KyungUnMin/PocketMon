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
	void LevelChangeStart(GameEngineLevel* _Prev) override;
private:

	GameEngineLevel* CurrentLevel = nullptr;
	
	std::vector<PokeDataBase> Pokemons;
	GameEngineRender* PokemonRender = nullptr;
	GameEngineRender* CurrentSkillSelect = nullptr;
	GameEngineRender* SkillSelect = nullptr;
	TextActor* PokemonName = nullptr;
	TextActor* PokemonLevel = nullptr;

	SummaryPage CurrentPage = SummaryPage::Info;

	std::vector<GameEngineObject*> Info_Objects;
	GameEngineRender* Info_Back = nullptr;
	GameEngineRender* Info_Type = nullptr;
	TextActor* Info_Number = nullptr;
	TextActor* Info_Name = nullptr;
	TextActor* Info_Item = nullptr;
	TextActor* Info_Memo = nullptr;
	
	std::vector<GameEngineObject*> Skill_Objects;
	GameEngineRender* Skill_Back = nullptr;
	TextActor* Skill_HP = nullptr;
	TextActor* Skill_ATK = nullptr;
	TextActor* Skill_DEF = nullptr;
	TextActor* Skill_SPATK = nullptr;
	TextActor* Skill_SPDEF = nullptr;
	TextActor* Skill_Speed = nullptr;
	TextActor* Skill_EXP = nullptr;
	TextActor* Skill_NextEXP = nullptr;

	std::vector<GameEngineObject*> Move_Objects;
	GameEngineRender* Move_Back = nullptr;
	struct Move
	{
		GameEngineRender* Type;
		TextActor* Name;
		TextActor* PP;
		/*std::string_view Power;
		std::string_view Accuracy;
		std::string_view Effect;*/
	};
	std::vector<Move> Move_Moves;
	TextActor* Move_Power = nullptr;
	TextActor* Move_Accuracy = nullptr;
	TextActor* Move_Effect = nullptr;

	int CurrentPokemon = 0;
	int CurrentSkillCursor = 0;
	int SelectSkillCursor = -1;
	int SkillSize = 0;

	bool IsStop = false;
	void NextPage();
	void PrevPage();
	void MovePage();
	void PageOn();
	void PageOff();

	void Select();
	void Cancel();

	void NextPokemon();
	void PrevPokemon();
	void MovePokemon();

	void SetPokemonData();

	void MovesSwitchOn();
	void MovesSwitchOff();
	void MovesSwitchUp();
	void MovesSwitchDown();
	void MovesSwitchSelect();
	void MovesSwitchCancle();
};


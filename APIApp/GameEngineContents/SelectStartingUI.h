#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "PokeDataBase.h"

enum class MenuState
{
	Null = -1,
	Yes,
	No
};

class FieldDialog;
class GameEngineRender;
class SelectStartingUI : public GameEngineActor
{
public:
	// construtor destructor
	SelectStartingUI();
	~SelectStartingUI();

	// delete Function
	SelectStartingUI(const SelectStartingUI& _Other) = delete;
	SelectStartingUI(SelectStartingUI&& _Other) noexcept = delete;
	SelectStartingUI& operator=(const SelectStartingUI& _Other) = delete;
	SelectStartingUI& operator=(SelectStartingUI&& _Other) noexcept = delete;

	void SelectMonster(PokeNumber _Pokemon);
	void TestSelectMonster();

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	FieldDialog* AcFieldDialog = nullptr;
	PokeNumber Select = PokeNumber::Bulbasaur;

	MenuState State = MenuState::Null;

	std::vector<GameEngineRender*> MenuRenders = std::vector<GameEngineRender*>();
	float4 MenuRenderPos = { 764,352 };

	std::list<std::string> BulbasaurScript = std::list<std::string>();
	std::list<std::string> CharmanderScript = std::list<std::string>();
	std::list<std::string> SquirtleScript = std::list<std::string>();
	std::list<std::string> SelectScript = std::list<std::string>();

	void UpdateStart(PokeNumber _Pokemon);

	void StateToRender();
	void ChangeState();
};


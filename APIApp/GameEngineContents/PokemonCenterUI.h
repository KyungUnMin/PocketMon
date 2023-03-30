#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class CenterProcess
{
	Welcome,
	Heal,
	Goodbye
};

enum class PokemonMenuState
{
	Null = -1,
	Yes,
	No
};

class GameEngineRender;
class FieldDialog;
class PokemonCenterUI : public GameEngineActor
{
public:
	// construtor destructor
	PokemonCenterUI();
	~PokemonCenterUI();

	// delete Function
	PokemonCenterUI(const PokemonCenterUI& _Other) = delete;
	PokemonCenterUI(PokemonCenterUI&& _Other) noexcept = delete;
	PokemonCenterUI& operator=(const PokemonCenterUI& _Other) = delete;
	PokemonCenterUI& operator=(PokemonCenterUI&& _Other) noexcept = delete;

	void CenterStart();
	

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	CenterProcess Process = CenterProcess::Welcome;

	FieldDialog* AcFieldDialog = nullptr;
	std::list<std::string> WelcomeScript = std::list<std::string>();
	std::list<std::string> HealScript = std::list<std::string>();
	std::list<std::string> GoodbyeScript1 = std::list<std::string>();

	std::vector<GameEngineRender*> MenuRenders = std::vector<GameEngineRender*>();
	float4 MenuRenderPos = { 764,352 };
	PokemonMenuState State = PokemonMenuState::Null;

	void StateToRender();
	void ChangeState();
};


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
	std::list<std::string> GoodbyeScript2 = std::list<std::string>();

	std::vector<GameEngineRender*> MenuRenders = std::vector<GameEngineRender*>();
	float4 MenuRenderPos = { 764,352 };
	PokemonMenuState State = PokemonMenuState::Null;

	int HealMonsterCount = 6;
	
	GameEngineRender* PutBallAnimation = nullptr;
	float4 PutBallAnimationPos = { 380,160 };

	std::vector<std::vector<GameEngineRender*>> TwinkleBallAnimation = std::vector<std::vector<GameEngineRender*>>();
	float4 TwinkleBallAnimationStartPos = { 368,144 };

	GameEngineRender* MonitorAnimation = nullptr;

	float AnimationTime = 0.0f;

	void StateToRender();
	void ChangeState();

	void AllAnimationOff();
	void StartAnimationAndChangeProcess(float _DeltaTime);

	bool IsAnyTwinkleBallAnimationUpdate();
	void CountAndTwinkleBallAnimationOn(int _Count);
	void CountAndTwinkleBallAnimationOff(int _Count);

};


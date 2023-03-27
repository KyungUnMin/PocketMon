#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnum.h"

enum class MainMenuState
{
	Pokemon,
	Bag,
	Red,
	Save,
	Option,
	Exit
};

class GameEngineRender;
class FieldMainMenu : public GameEngineActor
{
public:
	// construtor destructor
	FieldMainMenu();
	~FieldMainMenu();

	// delete Function
	FieldMainMenu(const FieldMainMenu& _Other) = delete;
	FieldMainMenu(FieldMainMenu&& _Other) noexcept = delete;
	FieldMainMenu& operator=(const FieldMainMenu& _Other) = delete;
	FieldMainMenu& operator=(FieldMainMenu&& _Other) noexcept = delete;

	static FieldMainMenu* GetFieldMainMenu()
	{
		return MainFieldMainMenu;
	}

	void On() override;
	void Off() override;
	void OnOffSwtich() override;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	static FieldMainMenu* MainFieldMainMenu;

	std::vector<GameEngineRender*> FieldMainMenuRender = std::vector<GameEngineRender*>();
	MainMenuState State = MainMenuState::Pokemon;
	float4 ActorPos = {480, 320};

	int InputControlHandle = -1;

	void UpdateStart();
	void UpdateEnd();
	void MenuStateToRender();
	void ChangeStatePrev();
	void ChangeStateNext();
};


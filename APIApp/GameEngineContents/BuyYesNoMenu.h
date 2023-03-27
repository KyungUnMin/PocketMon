#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnum.h"

enum class MenuState
{
	Yes,
	No
};

class GameEngineRender;
class BuyYesNoMenu : public GameEngineActor
{
public:
	// construtor destructor
	BuyYesNoMenu();
	~BuyYesNoMenu();

	// delete Function
	BuyYesNoMenu(const BuyYesNoMenu& _Other) = delete;
	BuyYesNoMenu(BuyYesNoMenu&& _Other) noexcept = delete;
	BuyYesNoMenu& operator=(const BuyYesNoMenu& _Other) = delete;
	BuyYesNoMenu& operator=(BuyYesNoMenu&& _Other) noexcept = delete;

	void On() override;
	void Off() override;

	static BuyYesNoMenu* GetBuyYesNoMenu()
	{
		return AcBuyYesNoMenu;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	static BuyYesNoMenu* AcBuyYesNoMenu;

	float4 ActorPos = { 480,320 };
	std::vector<GameEngineRender*> MenuRenders = std::vector<GameEngineRender*>();

	MenuState State = MenuState::Yes;

	void UpdateStart();
	void UpdateEnd();

	void StateToRender();
	void ChangeState();

};


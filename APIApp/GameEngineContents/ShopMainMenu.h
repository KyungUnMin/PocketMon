#pragma once
#include <GameEngineCore/GameEngineActor.h>	
#include "ShopUIManager.h"
#include "ContentsEnum.h"

enum class ShopMianMenuState
{
	Buy,
	Sell,
	SeeYa
};

class GameEngineRender;
class ShopMainMenu : public GameEngineActor
{
public:
	// construtor destructor
	ShopMainMenu();
	~ShopMainMenu();

	// delete Function
	ShopMainMenu(const ShopMainMenu& _Other) = delete;
	ShopMainMenu(ShopMainMenu&& _Other) noexcept = delete;
	ShopMainMenu& operator=(const ShopMainMenu& _Other) = delete;
	ShopMainMenu& operator=(ShopMainMenu&& _Other) noexcept = delete;

	void On() override;
	void Off() override;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	static ShopMainMenu* AcShopMainMenu;

	ShopUIManager* AcParent = nullptr;

	float4 ActorPos = { 236, 128 };

	ShopMianMenuState State = ShopMianMenuState::Buy;

	GameEngineRender* ShopMainMenuRender = nullptr;
	GameEngineRender* MenuArrowRender = nullptr;

	float4 FirstArrowRenderPos = {-176, -60}; // 32 44  //12, 20
	float4 SecondArrowRenderPos = {-176, 4}; // 32 44  //12, 20
	float4 ThirdArrowRenderPos = {-176, 68}; // 32 44  //12, 20

	void UpdateStart();
	void UpdateEnd();
	void MenuStateToRender();

	void ChangeStatePrev();
	void ChangeStateNext();
	void ChangeState();
};


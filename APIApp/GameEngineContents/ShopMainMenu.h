#pragma once
#include <GameEngineCore/GameEngineActor.h>	

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

protected:


private:
	GameEngineRender* ShopMainMenuRender = nullptr;

};


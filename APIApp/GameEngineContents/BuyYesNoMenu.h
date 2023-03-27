#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnum.h"

enum class MenuState
{
	Yes,
	No
};

class GameEngineRender;
class Item;
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
	
	void SetItemAndCount(Item& _Item, int _Count)
	{
		SetItem(_Item);
		SetCount(_Count);
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	static BuyYesNoMenu* AcBuyYesNoMenu;

	float4 ActorPos = { 764,352 };
	std::vector<GameEngineRender*> MenuRenders = std::vector<GameEngineRender*>();

	MenuState State = MenuState::Yes;

	std::list<std::string> Script = std::list<std::string>();

	Item* SelectItem = nullptr;
	int Count = 0;

	void UpdateStart();
	void UpdateEnd();

	void StateToRender();
	void ChangeState();
	
	void SetItem(Item& _Item)
	{
		SelectItem = &_Item;
	}
	
	void SetCount(int _Count)
	{
		Count = _Count;
	}

	void BuyItem();
};


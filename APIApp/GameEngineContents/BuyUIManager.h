#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnum.h"

class BuyLevel;
class BuyLevelDialog;
class CountItemMenu;
class Item;
class BuyUIManager : public GameEngineActor
{
public:
	// construtor destructor
	BuyUIManager();
	~BuyUIManager();

	// delete Function
	BuyUIManager(const BuyUIManager& _Other) = delete;
	BuyUIManager(BuyUIManager&& _Other) noexcept = delete;
	BuyUIManager& operator=(const BuyUIManager& _Other) = delete;
	BuyUIManager& operator=(BuyUIManager&& _Other) noexcept = delete;

	void On(Item& _Item);
	void Off() override;

	static BuyUIManager* GetBuyUIManager()
	{
		return AcBuyUIManager;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	static BuyUIManager* AcBuyUIManager;

	BuyLevel* Parent = nullptr;
	BuyLevelDialog* AcBuyLevelDialog = nullptr;
	CountItemMenu* AcCountItemMenu = nullptr;

	std::string Script = std::string();
	std::list<std::string> Scripts = std::list<std::string>();

	Item* SelectItem = nullptr;

	int InputControllHandle = -1;

	void UpdateStart(Item& _Item);
	void UpdateEnd();

};


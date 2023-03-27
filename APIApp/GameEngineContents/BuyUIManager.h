#pragma once
#include <GameEngineCore/GameEngineActor.h>

class BuyLevel;
class BuyLevelDialog;
class CountItemMenu;
struct TestItem;
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

	void On(TestItem& _Item);
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

	std::list<std::string> CountMenuScript = std::list<std::string>();

	TestItem* Item = nullptr;

	void UpdateStart(TestItem& _Item);
	void UpdateEnd();

};


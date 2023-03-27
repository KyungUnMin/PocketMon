#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class BuyWindow;
class BuyYesNoMenu;
class BuyLevelDialog;
class BuyUIManager;
class BuyLevel : public GameEngineLevel
{
public:
	// construtor destructor
	BuyLevel();
	~BuyLevel();

	// delete Function
	BuyLevel(const BuyLevel& _Other) = delete;
	BuyLevel(BuyLevel&& _Other) noexcept = delete;
	BuyLevel& operator=(const BuyLevel& _Other) = delete;
	BuyLevel& operator=(BuyLevel&& _Other) noexcept = delete;



	//CountItemMenu* GetCountItemMenu()
	//{
	//	return AcCountItemMenu;
	//}

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel);
	void LevelChangeStart(GameEngineLevel* _PrevLevel);

private:
	BuyWindow* AcBuyWindow = nullptr;
	BuyYesNoMenu* AcBuyYesNoMenu = nullptr;
	BuyLevelDialog* AcBuyLevelDialog = nullptr;
	BuyUIManager* AcBuyUIManager = nullptr;

	void ImageLoad();

};


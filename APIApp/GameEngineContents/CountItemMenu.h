#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/NumberRenderObject.h>
#include "ContentsEnum.h"

class GameEngineRender;
class Item;
class BuyLevelDialog;
class BuyUIManager;
class CountItemMenu : public GameEngineActor
{
public:
	// construtor destructor
	CountItemMenu();
	~CountItemMenu();

	// delete Function
	CountItemMenu(const CountItemMenu& _Other) = delete;
	CountItemMenu(CountItemMenu&& _Other) noexcept = delete;
	CountItemMenu& operator=(const CountItemMenu& _Other) = delete;
	CountItemMenu& operator=(CountItemMenu&& _Other) noexcept = delete;

	void Off() override;

	void CountStart(Item& _Item);

	//static CountItemMenu* GetCountItemMenu()
	//{
	//	return AcCountItemMenu;
	//}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	//static CountItemMenu* AcCountItemMenu;

	BuyUIManager* AcParent = nullptr;

	float4 ActorPos = { 736, 352 }; // 129 65 (516, 260) 220 92
	GameEngineRender* CountItemMenuRender = nullptr;
	int Count = 0;
	NumberRenderObject CountNum = NumberRenderObject();
	float4 CountNumRenderPos = { -144, 8 }; // 17 21 // 68 84
	
	int Price = 0;
	NumberRenderObject PriceNum = NumberRenderObject();
	float4 PriceNumRenderPos = { 144, 8 }; // 17 21 // 68 84

	float4 NumRenderScale = { 20,32 };

	GameEngineRender* Up_ArrowRender = nullptr;
	float4 Up_Pos = { -130, -70 }; // -92 + 22
	GameEngineRender* Down_ArrowRender = nullptr;
	float4 Down_Pos = { -130, 70 };
	float4 ArrowRenderScale = {56,44};

	GameEngineRender* MoneySignRender = nullptr;
	float4 MoneySignRenderScale = { 20,32 };

	Item* SelectItem = nullptr;

	std::string Script = std::string();
	std::list<std::string> Scripts = std::list<std::string>();

	int InputControllHandle = -1;
	GameEngineSoundPlayer MenuBeepSound = GameEngineSoundPlayer();
	void MenuBeepSoundPlay();

	void UpdateStart(Item& _Item);
	void UpdateEnd();

	void AddCount();
	void AddCount10();
	void SubCount();
	void SubCount10();

	void SetCount(int _ItemCount);
	void SetPrice(int _ItemPrice);
};


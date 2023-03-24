#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>
#include "TextActor.h"
#include "ContentsEnum.h"

struct TestItem
{
	std::string Name = "abcd";
	int Price = 100;
	std::string Explain = "ASDLASJDLdsadasdasda";
};

class BuyLevel;
class GameEngineRender;
class BuyWindow : public GameEngineActor
{
public:
	// construtor destructor
	BuyWindow();
	~BuyWindow();

	// delete Function
	BuyWindow(const BuyWindow& _Other) = delete;
	BuyWindow(BuyWindow&& _Other) noexcept = delete;
	BuyWindow& operator=(const BuyWindow& _Other) = delete;
	BuyWindow& operator=(BuyWindow&& _Other) noexcept = delete;

	void ChangeState(int _State);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	BuyLevel* ParentLevel = nullptr;
	
	float4 ActorPos = { 480, 320 };

	GameEngineRender* Background = nullptr;
	std::vector<TextActor*> ItemNameRenders = std::vector<TextActor*>();
	float4 NameRenderFirstPos = { 400,72 };
	
	//NumberRenderObject ItemPriceRender = NumberRenderObject();
	//std::vector<NumberRenderObject> ItemPriceRenders = std::vector<NumberRenderObject>();
	NumberRenderObject ItemPriceRenders[5] = {};
	float4 ItemPriceRenderScale = { 20,32 };
	float4 FirstItemPriceRenderPos = { 392,-248 };

	GameEngineRender* ArrowRender = nullptr;
	float4 FirstArrowRenderPos = { -108,-252 };

	float4 LineInterval = { 0, 64 };

	int State = 0;

	void StateToRender();
	void ChangeStatePrev();
	void ChangeStateNext();

	void Cancle();

	std::list<TestItem> ItemList = std::list<TestItem>();

	void ItemPushBack();
};


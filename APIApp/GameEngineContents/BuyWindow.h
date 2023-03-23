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

protected:
	void Start() override;

private:
	BuyLevel* ParentLevel = nullptr;
	
	float4 ActorPos = { 480, 320 };

	GameEngineRender* Background = nullptr;
	std::vector<TextActor*> ItemNameRenders = std::vector<TextActor*>();
	float4 NameRenderFirstPos = { 400,72 };
	
	//NumberRenderObject ItemPriceRender = NumberRenderObject();
	//std::vector<NumberRenderObject> ItemPriceRenders = std::vector<NumberRenderObject>();
	NumberRenderObject ItemPriceRenders[6] = {};
	float4 ItemPriceRenderScale = { 20,32 };
	float4 FirstItemPriceRenderPos = { 392,-248 };

};


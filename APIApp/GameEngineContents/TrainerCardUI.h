#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>
#include "ContentsEnum.h"

class GameEngineRender;
class PlayTime;
class TrainerCardUI : public GameEngineActor
{
public:
	// construtor destructor
	TrainerCardUI();
	~TrainerCardUI();

	// delete Function
	TrainerCardUI(const TrainerCardUI& _Other) = delete;
	TrainerCardUI(TrainerCardUI&& _Other) noexcept = delete;
	TrainerCardUI& operator=(const TrainerCardUI& _Other) = delete;
	TrainerCardUI& operator=(TrainerCardUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float4 ActorPos = {480,320};

	GameEngineRender* CardBackground = nullptr;

	float4 NumberRenderScale = { 24, 48 };
	int Money = 0;
	NumberRenderObject MoneyRender = NumberRenderObject();
	float4 MoneyRenderPos = { 88,-36 };

	GameEngineRender* MoneySignRender = nullptr;
	float4 MoneySignRenderPos = {};
	float4 MoneySignRenderScale = {};

	PlayTime* MainPlayTime = nullptr;
	NumberRenderObject GamePlayTimeRender_Hour = NumberRenderObject();
	NumberRenderObject GamePlayTimeRender_Minute = NumberRenderObject();
	float4 HourRenderPos = { 20, 92 };
	float4 MinuteRenderPos = { 88, 92 };

	GameEngineRender* ColonsAnimation = nullptr;
	float4 ColonsAnimationPos = { 40, 92 };
	float4 ColonsAnimationScale = { 20, 48 };

	GameEngineRender* BadgeIconRender = nullptr;
	float4 BadgeIconRenderPos = { -320,224 }; // -320 + 224
	float4 BadgeIconRenderScale = { 56,56 };
};


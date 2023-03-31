#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>
#include "ContentsEnum.h"

class GameEngineRender;
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

	int Money = 0;
	NumberRenderObject MoneyRender = NumberRenderObject();


};


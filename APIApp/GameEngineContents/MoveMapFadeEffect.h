#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnum.h"

class GameEngineRender;
class MoveMapFadeEffect : public GameEngineActor
{
public:
	static MoveMapFadeEffect* MainMoveMapFadeEffect;

public:
	MoveMapFadeEffect();
	~MoveMapFadeEffect();

	// delete Function
	MoveMapFadeEffect(const MoveMapFadeEffect& _Other) = delete;
	MoveMapFadeEffect(MoveMapFadeEffect&& _Other) noexcept = delete;
	MoveMapFadeEffect& operator=(const MoveMapFadeEffect& _Other) = delete;
	MoveMapFadeEffect& operator=(MoveMapFadeEffect&& _Other) noexcept = delete;


	void On() override;
	void Off() override;

	void OnOffSwtich() override;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;


private:
	float4 ActorPos = { 480,320 };

	GameEngineRender* FadeAlphaRender = nullptr;
	float4 AlphaStartValue = {};
	float4 AlphaEndValue = {255};
	
	GameEngineRender* FadeDoorRender1 = nullptr;
	float4 FadeDoorRender1StartPos = {-240,0};
	float4 FadeDoorRender1EndPos = {-720,0};


	GameEngineRender* FadeDoorRender2 = nullptr;
	float4 FadeDoorRender2StartPos = { 240,0 };
	float4 FadeDoorRender2EndPos = { 720,0 };
	float Time = 0.0f;
	float FadeSpeed = 0.5f;
	int LoopCount = 0;

	void UpdateStart();
	void UpdateEnd();
};


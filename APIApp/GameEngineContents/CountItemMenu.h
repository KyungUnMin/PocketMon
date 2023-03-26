#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>
#include "ContentsEnum.h"

class GameEngineRender;
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

	void On() override;
	void Off() override;

	void OnOffSwtich() override;

	//static CountItemMenu* GetCountItemMenu()
	//{
	//	return AcCountItemMenu;
	//}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	//static CountItemMenu* AcCountItemMenu;

	float4 ActorPos = { 736, 352 }; // 129 65 (516, 260) 220 92
	GameEngineRender* CountItemMenuRender = nullptr;

	int Count = 0;
	NumberRenderObject CountNum = NumberRenderObject();
	float4 CountNumRenderScale = { 20,32 };
	float4 CountNumRenderPos = { -144, 8 }; // 17 21 // 68 84

	GameEngineRender* Up_ArrowRender = nullptr;
	float4 Up_Pos = { -130, -70 }; // -92 + 22
	GameEngineRender* Down_ArrowRender = nullptr;
	float4 Down_Pos = { -130, 70 };
	float4 ArrowRenderScale = {56,44};

	void UpdateStart();
	void UpdateEnd();

	void AddCount();
	void AddCount10();
	void SubCount();
	void SubCount10();
};


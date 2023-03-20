#include "BattleCommendActor.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnum.h"
BattleCommendActor::BattleCommendActor()
{
}

BattleCommendActor::~BattleCommendActor()
{

}
void BattleCommendActor::Start()
{
	SetPos({ 480,540 });
	GameEngineRender* RenderPtr = CreateRender("BattleCommend.bmp", RenderOrder::BackGround);
	RenderPtr->SetScale((RenderPtr->GetImage()->GetImageScale()));

	BattleArrowRender = CreateRender("Battle_Arrow.bmp", RenderOrder::Player);
	BattleArrowRender->SetScale((BattleArrowRender->GetImage()->GetImageScale()));

	BattleArrowRender->SetPosition({ -430,-25 }); // y값은 -25 40 고정 
}

void BattleCommendActor::Update(float _DeltaTime)
{
	B_ArrowNumberCheck();

	if (B_ArrowCheckNum == 0) {
		BattleArrowRender->SetPosition({ -430,-25 });
	}
	if (B_ArrowCheckNum == 1) {
		BattleArrowRender->SetPosition({ -170,-25 });
	}
	if (B_ArrowCheckNum == 2) {
		BattleArrowRender->SetPosition({ -430,40 });
	}
	if (B_ArrowCheckNum == 3) {
		BattleArrowRender->SetPosition({ -170,40 });
	}
}


void BattleCommendActor::B_ArrowNumberCheck()
{
	if (B_ArrowCheckNum == 1 || B_ArrowCheckNum == 3) {
		if (true == GameEngineInput::IsDown("LeftMove")) {
			B_ArrowCheckNum -= 1;
		}
	}
	if (B_ArrowCheckNum == 0 || B_ArrowCheckNum == 2) {
		if (true == GameEngineInput::IsDown("RightMove")) {
			B_ArrowCheckNum += 1;
		}
	}
	if (B_ArrowCheckNum == 2 || B_ArrowCheckNum == 3) {
		if (true == GameEngineInput::IsDown("UpMove")) {
			B_ArrowCheckNum -= 2;
		}
	}
	if (B_ArrowCheckNum == 0 || B_ArrowCheckNum == 1) {
		if (true == GameEngineInput::IsDown("DownMove")) {
			B_ArrowCheckNum += 2;
		}
	}
}

void BattleCommendActor::B_ArrowInput(int _Number)
{
	if (true == GameEngineInput::IsDown("InsertMove1") && _Number == 0) {

		// 대사가 나오며 전투쪽으로 무슨 값 전달하기
	}
	if (true == GameEngineInput::IsDown("InsertMove1") && _Number == 1) {

		// 대사가 나오며 전투쪽으로 무슨 값 전달하기

	}
	if (true == GameEngineInput::IsDown("InsertMove1") && _Number == 2) {

		// 대사가 나오며 전투쪽으로 무슨 값 전달하기

	}
	if (true == GameEngineInput::IsDown("InsertMove1") && _Number == 3) {

		// 대사가 나오며 전투쪽으로 무슨 값 전달하기

	}
}


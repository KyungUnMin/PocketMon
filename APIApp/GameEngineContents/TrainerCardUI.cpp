#include "TrainerCardUI.h"
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>

TrainerCardUI::TrainerCardUI()
{

}

TrainerCardUI::~TrainerCardUI()
{

}

void TrainerCardUI::Start()
{
	SetPos(ActorPos);
	CardBackground = CreateRender("TrainerCard.bmp",RenderOrder::BackGround);
	CardBackground->SetScale({960,640});
	CardBackground->EffectCameraOff();

	MoneyRender.SetOwner(this);
	MoneyRender.SetImage("Num.bmp", { 24,48 }, static_cast<int>(RenderOrder::FieldFront), RGB(255, 0, 255));
	MoneyRender.SetAlign(Align::Right);
	MoneyRender.SetValue(1231);
	MoneyRender.SetCameraEffect(false);
	MoneyRender.SetRenderPos(MoneyRenderPos);
}

void TrainerCardUI::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("B"))
	{
		GameEngineCore::GetInst()->ChangeLevel("FieldmapLevel");
	}
}

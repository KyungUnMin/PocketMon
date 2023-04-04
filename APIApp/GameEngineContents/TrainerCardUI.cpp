#include "TrainerCardUI.h"
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "PlayTime.h"
#include "PlayerBag.h"
#include "Player.h"

TrainerCardUI::TrainerCardUI()
{

}

TrainerCardUI::~TrainerCardUI()
{

}

void TrainerCardUI::Start()
{
	MainPlayTime = PlayTime::MianPlayTime;

	SetPos(ActorPos);
	CardBackground = CreateRender("TrainerCard.bmp",RenderOrder::BackGround);
	CardBackground->SetScale({960,640});
	CardBackground->EffectCameraOff();

	MoneyRender.SetOwner(this);
	MoneyRender.SetImage("Num.bmp", NumberRenderScale, static_cast<int>(RenderOrder::FieldFront), RGB(255, 0, 255));
	MoneyRender.SetAlign(Align::Right);
	MoneyRender.SetValue(1231);
	MoneyRender.SetCameraEffect(false);
	MoneyRender.SetRenderPos(MoneyRenderPos);

	MoneySignRender = CreateRender("BigMoneysign.bmp", RenderOrder::FieldFront);
	MoneySignRender->SetScale(NumberRenderScale);
	MoneySignRender->EffectCameraOff();

	GamePlayTimeRender_Hour.SetOwner(this);
	GamePlayTimeRender_Hour.SetImage("Num.bmp", NumberRenderScale, static_cast<int>(RenderOrder::FieldFront), RGB(255, 0, 255));
	GamePlayTimeRender_Hour.SetAlign(Align::Right);
	GamePlayTimeRender_Hour.SetValue(MainPlayTime->Hour);
	GamePlayTimeRender_Hour.SetCameraEffect(false);
	GamePlayTimeRender_Hour.SetRenderPos(HourRenderPos);
	
	GamePlayTimeRender_Minute.SetOwner(this);
	GamePlayTimeRender_Minute.SetImage("Num.bmp", NumberRenderScale, static_cast<int>(RenderOrder::FieldFront), RGB(255, 0, 255));
	GamePlayTimeRender_Minute.SetAlign(Align::Right);
	GamePlayTimeRender_Minute.SetNumOfDigits(2);
	GamePlayTimeRender_Minute.SetValue(MainPlayTime->Minute);
	GamePlayTimeRender_Minute.SetCameraEffect(false);
	GamePlayTimeRender_Minute.SetRenderPos(MinuteRenderPos);

	ColonsAnimation = CreateRender(RenderOrder::FieldFront);
	ColonsAnimation->SetPosition(ColonsAnimationPos);
	ColonsAnimation->SetScale(ColonsAnimationScale);
	ColonsAnimation->EffectCameraOff();
	ColonsAnimation->CreateAnimation({.AnimationName = "1", .ImageName = "ColonsAnimation.bmp", .Start = 0, .End = 1, .InterTime = 0.5});
	ColonsAnimation->ChangeAnimation("1");

	BadgeIconRender = CreateRender("FirstBadge.bmp", RenderOrder::FieldFront);
	BadgeIconRender->SetPosition(BadgeIconRenderPos);
	BadgeIconRender->SetScale(BadgeIconRenderScale);
	BadgeIconRender->EffectCameraOff();
}

void TrainerCardUI::Update(float _DeltaTime)
{
	MoneySignRender->SetPosition(MoneyRenderPos + float4::Left * NumberRenderScale * static_cast<float>(GameEngineMath::GetLenth(Money)) + float4{ -8,0 });

	if (GameEngineInput::IsDown("B"))
	{
		GameEngineCore::GetInst()->ChangeLevel("FieldmapLevel");
	}
	GamePlayTimeRender_Hour.SetValue((int)MainPlayTime->Hour);
	GamePlayTimeRender_Minute.SetValue((int)MainPlayTime->Minute);

	if (Money != PlayerBag::MainBag->GetMoney())
	{
		Money = PlayerBag::MainBag->GetMoney();
		MoneyRender.SetValue(Money);
	}

	if (Player::MainPlayer->GymClear)
	{
		BadgeIconRender->On();
	}
	else
	{
		BadgeIconRender->Off();
	}
}

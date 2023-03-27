#include "BattleFadeCtrl.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

BattleFadeCtrl::BattleFadeCtrl()
{

}

BattleFadeCtrl::~BattleFadeCtrl()
{

}

void BattleFadeCtrl::Init(FadeType _FadeType, const std::function<void()>& _Event)
{
	if (FadeType::UNKNOWN == _FadeType)
	{
		MsgAssert("UNKNOWN���δ� �ʱ�ȭ�� �� �����ϴ�");
		return;
	}

	Event = _Event;
	Type = _FadeType;
	SetPos(GameEngineWindow::GetScreenSize().half());

	std::string ImageName = "BattleFadeBlack.bmp";
	if (FadeType::WhiteIn == _FadeType || FadeType::WhiteOut == _FadeType)
	{
		ImageName = "BattleFadeWhite.bmp";
	}

	FadeRender = CreateRender(ImageName, BattleRenderOrder::Fade);
	FadeRender->SetScaleToImage();
	FadeRender->EffectCameraOff();
}

void BattleFadeCtrl::Update(float _DeltaTime)
{
	if (FadeType::UNKNOWN == Type)
	{
		MsgAssert("FadeCtrl�� �ʱ�ȭ ������ �ʾҽ��ϴ�. Init�Լ��� ȣ���ϼ���");
		return;
	}

	float LiveTime = GetLiveTime();
	if (Duration < LiveTime)
	{
		if (nullptr != Event)
		{
			Event();
		}

		Death();
		return;
	}

	float Ratio = (LiveTime / Duration);
	float NowAlpha = 0.f;
	if (FadeType::BlackIn == Type || FadeType::WhiteIn == Type)
	{
		NowAlpha = 255.f  - (255.f * Ratio);
	}
	else
	{
		NowAlpha = (255.f * Ratio);
	}

	if (NowAlpha < 0.f)
	{
		NowAlpha = 0.f;
	}
	else if (255.f < NowAlpha)
	{
		NowAlpha = 255.f;
	}

	FadeRender->SetAlpha(static_cast<int>(NowAlpha));
}



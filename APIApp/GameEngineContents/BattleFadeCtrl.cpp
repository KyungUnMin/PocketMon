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
		MsgAssert("UNKNOWN으로는 초기화할 수 없습니다");
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
}

void BattleFadeCtrl::Update(float _DeltaTime)
{
	if (FadeType::UNKNOWN == Type)
	{
		MsgAssert("FadeCtrl을 초기화 해주지 않았습니다. Init함수를 호출하세요");
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



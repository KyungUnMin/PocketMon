#include "EndingPlayActor.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "EndingPlayerAnimActor.h"
#include "TextActor.h"

EndingPlayActor* EndingPlayActor::MainEndingPlayActor = nullptr;
bool EndingPlayActor::IsEndingPlay = false;

EndingPlayActor::EndingPlayActor()
{
}

EndingPlayActor::~EndingPlayActor()
{
}

void EndingPlayActor::PlayEnding()
{
	if (true == IsEndingPlay)
	{
		return;
	}

	PlayerAnim->On();
	BackgroundRender->On();
	IsEndingPlay = true;

	MainTextActor->SetText(
		"GGGG DDDDDDDD",
		"Font_Dialog_White.bmp",
		static_cast<int>(RenderOrder::EndingFront),
		false);

	MainTextActor->On();

	SubTextActor->SetLine(5);
	SubTextActor->SetText(
		"GGGG DDDDDDDD\nSDFLJ SDLFKJDSF\nSDFKLJSDFL SDLKFJDSF\n\nSDFLKJ SDFLKJ",
		"Font_Dialog_White.bmp",
		static_cast<int>(RenderOrder::EndingFront),
		false);

	SubTextActor->On();
}

void EndingPlayActor::Start()
{
	if (nullptr != MainEndingPlayActor)
	{
		MsgAssert("엔딩 호출을 관리하는 액터가 중복 생성되었습니다");
		return;
	}


	MainEndingPlayActor = this; 
	float4 ScreenSize = GameEngineWindow::GetScreenSize();
	float4 ScreenSizeHalf = ScreenSize.half();

	SetPos(ScreenSizeHalf);

	PlayerAnim = GetLevel()->CreateActor<EndingPlayerAnimActor>();
	PlayerAnim->SetPos(float4(ScreenSize.x, ScreenSizeHalf.y) + float4(-140, 20));
	PlayerAnim->Off();

	BackgroundRender = CreateRender("Background.bmp", RenderOrder::EndingBack);
	BackgroundRender->SetPosition(float4::Zero);
	BackgroundRender->SetScale(float4{ ScreenSize.x, 400});
	BackgroundRender->SetAlpha(128);
	BackgroundRender->EffectCameraOff();
	BackgroundRender->Off();

	MainTextActor = GetLevel()->CreateActor<TextActor>();
	MainTextActor->SetPos(float4(35, 170));
	MainTextActor->Off();

	SubTextActor = GetLevel()->CreateActor<TextActor>();
	SubTextActor->SetPos(float4(150, 230));
	SubTextActor->Off();
}

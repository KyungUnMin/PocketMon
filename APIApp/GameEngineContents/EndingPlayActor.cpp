#include "EndingPlayActor.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCore.h>
#include "ContentsEnum.h"
#include "EndingPlayerAnimActor.h"
#include "TextActor.h"
#include "EndingLevel.h"
#include "EndingPokeballBackground.h"
#include "Fieldmap.h"
#include "EndingFade.h"
#include "Player.h"

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

	Player::MainPlayer->Off();
	On();

	PlayerAnim->On();
	BackgroundRender->On();
	IsEndingPlay = true;

	CameraMoveDir = float4::Zero;
	CameraSpeed = 128.0f;

	MainTextActor->SetLine(1);
	SubTextActor->SetLine(7);

	Fade->Off();
	PlayerAnim->Off();

	AddCameraMoveEvent("PewterCity", int2(10, 12), float4::Zero);

	GameEngineLevel* Level = GetLevel();
	GameEngineTimeEvent& LevelTimeEvent = Level->LevelEvent;

	LevelTimeEvent.AddEvent(1.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			float4 AnimPos = _This->PlayerAnim->GetPos();
			_This->PlayerAnim->MovePos(AnimPos + float4(200, 0), AnimPos, 1.0f);
			_This->PlayerAnim->SetPos(AnimPos + float4(200, 0));
			_This->PlayerAnim->On();
		}, this), false);

	LevelTimeEvent.AddEvent(2.0f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);
			_This->SetText("Game Design", "UTG");
			_This->MainTextActor->On();
			_This->MainFakeTextActor->On();
			_This->SubTextActor->On();
			_This->SubFakeTextActor->On();

			_This->SetCameraDir(float4(1, 1).NormalizeReturn());
		}, this), false);

	LevelTimeEvent.AddEvent(7.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
		},this), false);

	LevelTimeEvent.AddEvent(8.0f, std::bind(
		[](EndingPlayActor* _This)
		{
			EndingLevel::SetPokemonImageName("EndingPokemon001.bmp");
			EndingLevel::SetPokeballColor(EndingPokeballBackground::PokeColor::Red);

			EndingLevel::AddEndEvent(std::bind(&EndingPlayActor::SetText, _This, "Player Design", "YDM"));
			EndingLevel::AddEndEvent(std::bind(&EndingPlayActor::AddCameraMoveEvent, _This, "ViridianForest", int2(32, 55), float4::Left));

			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");
			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);

		}, this), false); // 회색 시티


	LevelTimeEvent.AddEvent(12.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
		}, this), false);

	LevelTimeEvent.AddEvent(13.0f, std::bind(
		[](EndingPlayActor* _This) 
		{
			EndingLevel::SetPokemonImageName("EndingPokemon002.bmp");
			EndingLevel::SetPokeballColor(EndingPokeballBackground::PokeColor::Green);

			EndingLevel::AddEndEvent(std::bind(&EndingPlayActor::SetText, _This, "Map Design", "KKS"));
			EndingLevel::AddEndEvent(std::bind(&EndingPlayActor::AddCameraMoveEvent, _This, "ViridianCity", int2(18, 10), float4::Down));

			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");

			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);

		}, this), false); // 상록 숲


	LevelTimeEvent.AddEvent(17.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
		}, this), false);

	LevelTimeEvent.AddEvent(18.0f, std::bind(
		[](EndingPlayActor* _This) // this call
		{
			EndingLevel::SetPokemonImageName("EndingPokemon003.bmp");
			EndingLevel::SetPokeballColor(EndingPokeballBackground::PokeColor::Blue);

			EndingLevel::AddEndEvent(std::bind(&EndingPlayActor::SetText, _This, "UI Design", "KKH\nHSM\nKMS"));
			EndingLevel::AddEndEvent(std::bind(&EndingPlayActor::AddCameraMoveEvent, _This, "Route1", int2(14, 14), float4::Down));

			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");

			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);

		}, this), false); // 상록 시티


	LevelTimeEvent.AddEvent(22.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
		}, this), false);

	LevelTimeEvent.AddEvent(23.0f, std::bind(
		[](EndingPlayActor* _This) 
		{
			EndingLevel::SetPokemonImageName("EndingPokemon004.bmp");
			EndingLevel::SetPokeballColor(EndingPokeballBackground::PokeColor::Yellow);

			EndingLevel::AddEndEvent(std::bind(&EndingPlayActor::SetText, _This, "Battle Design", "MKU"));
			EndingLevel::AddEndEvent(std::bind(&EndingPlayActor::AddCameraMoveEvent, _This, "PalletTown", int2(8, 3), float4::Left));

			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");

			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);

		}, this), false); // 1번 도로

	LevelTimeEvent.AddEvent(25.0f, std::bind(
		[](EndingPlayActor* _This)
		{
			EndingPlayerAnimActor* AnimPtr = _This->PlayerAnim;

			float4 StartPos = AnimPtr->GetPos();
			float4 DestPos = float4{ GameEngineWindow::GetScreenSize().half().x,StartPos.y };

			AnimPtr->MovePos(StartPos, DestPos, 0.4f);
			_This->SetCameraDir(float4::Zero);
		}, this), false);

	LevelTimeEvent.AddEvent(26.0f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->Fade->On();
		}, this), false);

	LevelTimeEvent.AddEvent(27.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->Fade->On();
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
		}, this), false);

	LevelTimeEvent.AddEvent(28.0f, std::bind(
		[](EndingPlayActor* _This) 
		{
			EndingLevel::PlayLastEffect();
			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");
		}, this), false); // 태초마을 카메라
}

void EndingPlayActor::SetText(const std::string_view& _MainText, const std::string_view _SubText)
{
	MainTextActor->SetText(
		_MainText,
		"Font_Dialog_White.bmp",
		static_cast<int>(RenderOrder::EndingMiddle),
		false);

	MainFakeTextActor->SetText(_MainText,
		"Font_Dialog_Black.bmp",
		static_cast<int>(RenderOrder::EndingFront),
		false);
	MainFakeTextActor->SetAlpha(255);

	SubTextActor->SetText(
		_SubText,
		"Font_Dialog_White.bmp",
		static_cast<int>(RenderOrder::EndingMiddle),
		false);

	SubFakeTextActor->SetText(
		_SubText,
		"Font_Dialog_Black.bmp",
		static_cast<int>(RenderOrder::EndingFront),
		false);
	SubFakeTextActor->SetAlpha(255);
}

void EndingPlayActor::AddCameraMoveEvent(const std::string_view& _CityName, const int2& _CityIndex, const float4& _MoveDir)
{
	GetLevel()->LevelEvent.AddEvent(
		0.0f, std::bind(
		[=](EndingPlayActor* _This) 
		{
			Fieldmap::ChangeCity(_CityName);
			_This->GetLevel()->SetCameraPos(Fieldmap::GetPos(_CityIndex));
			_This->SetCameraDir(_MoveDir);
		}, this), false); // 상록 시티
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

	Fade = GetLevel()->CreateActor<EndingFade>();
	Fade->SetProgress(0.0f);
	Fade->SetSpeed(1.0f);
	Fade->SetPos(ScreenSizeHalf);
	Fade->Off();

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

	MainFakeTextActor = GetLevel()->CreateActor<TextActor>();
	MainFakeTextActor->SetPos(float4(35, 170));
	MainFakeTextActor->Off();
	
	SubFakeTextActor = GetLevel()->CreateActor<TextActor>();
	SubFakeTextActor->SetPos(float4(150, 230));
	SubFakeTextActor->Off();

	BackgroundScaleStart = float4{ ScreenSize.x, 0 };
	BackgroundScaleDest = float4{ ScreenSize.x, 400 };
	BackgroundLerpSpeed = 0.9f;
}

void EndingPlayActor::Update(float _DeltaTime)
{
	GetLevel()->SetCameraMove(CameraMoveDir * _DeltaTime * CameraSpeed);
	FakeFontAlpha += FakeFontAlphaDiff * _DeltaTime;
	UpdateAlpha();

	BackgroundLerpScale += _DeltaTime * BackgroundLerpSpeed;
	BackgroundRender->SetScale(float4::LerpClamp(BackgroundScaleStart, BackgroundScaleDest, BackgroundLerpScale));
}

void EndingPlayActor::UpdateAlpha()
{
	int IntAlpha = static_cast<int>(FakeFontAlpha);

	if (0 > IntAlpha)
	{
		IntAlpha = 0;
	}

	if (255 < IntAlpha)
	{
		IntAlpha = 255;
	}

	MainFakeTextActor->SetAlpha(IntAlpha);
	SubFakeTextActor->SetAlpha(IntAlpha);
}

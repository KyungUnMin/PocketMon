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
	CameraSpeed = 100.0f;

	MainTextActor->SetLine(1);
	MainFakeTextActor->SetLine(1);
	SubTextActor->SetLine(7);
	SubFakeTextActor->SetLine(7);

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
			_This->SetText("Game Design", "Um Taegun");
			_This->MainTextActor->On();
			_This->MainFakeTextActor->On();
			_This->SubTextActor->On();
			_This->SubFakeTextActor->On();
	
			_This->SetCameraDir(float4(1, 1).NormalizeReturn());
		}, this), false);
	
	LevelTimeEvent.AddEvent(6.0f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
		},this), false);
	
	LevelTimeEvent.AddEvent(6.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);
			_This->SetText("Consultation", "Cho Haegeun");
			_This->MainTextActor->On();
			_This->MainFakeTextActor->On();
			_This->SubTextActor->On();
			_This->SubFakeTextActor->On();
	
			_This->SetCameraDir(float4(0, 1).NormalizeReturn());
		}, this), false);
	
	LevelTimeEvent.AddEvent(10.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
		}, this), false);
	
	LevelTimeEvent.AddEvent(11.0f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);
			_This->SetText("Opening Desing", "Um Taegun");
			_This->MainTextActor->On();
			_This->MainFakeTextActor->On();
			_This->SubTextActor->On();
			_This->SubFakeTextActor->On();
	
			_This->SetCameraDir(float4(-0.5, 1).NormalizeReturn());
		}, this), false);
	
	LevelTimeEvent.AddEvent(15.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
		}, this), false);
	
	LevelTimeEvent.AddEvent(16.0f, std::bind(
		[](EndingPlayActor* _This)
		{
			EndingLevel::SetPokemonImageName("EndingPokemon001.bmp");
			EndingLevel::SetPokeballColor(EndingPokeballBackground::PokeColor::Red);
	
			EndingLevel::AddEndEvent(std::bind(&EndingPlayActor::SetText, _This, "Player Design", "Yoo Dongmin"));
			EndingLevel::AddEndEvent(std::bind(&EndingPlayActor::AddCameraMoveEvent, _This, "ViridianForest", int2(32, 35), float4::Down));
	
			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");
			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);
	
		}, this), false);
	
	LevelTimeEvent.AddEvent(20.0f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
		}, this), false);
	
	LevelTimeEvent.AddEvent(20.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);
			_This->SetText("Map Desing", "Kim Kyeongsik\nUm Taegun");
			_This->MainTextActor->On();
			_This->MainFakeTextActor->On();
			_This->SubTextActor->On();
			_This->SubFakeTextActor->On();
	
			_This->SetCameraDir(float4(-1, 1).NormalizeReturn());
		}, this), false);
	
	LevelTimeEvent.AddEvent(24.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
		}, this), false);
	
	LevelTimeEvent.AddEvent(25.0f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);
			_This->SetText("NPC Desing", "Kim Kyeongsik\nYoo Dongmin");
			_This->MainTextActor->On();
			_This->MainFakeTextActor->On();
			_This->SubTextActor->On();
			_This->SubFakeTextActor->On();
	
			_This->SetCameraDir(float4(0, 1).NormalizeReturn());
		}, this), false);
	
	LevelTimeEvent.AddEvent(29.0f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
		}, this), false);
	
	LevelTimeEvent.AddEvent(29.5f, std::bind(
		[](EndingPlayActor* _This) 
		{
			EndingLevel::SetPokemonImageName("EndingPokemon002.bmp");
			EndingLevel::SetPokeballColor(EndingPokeballBackground::PokeColor::Green);
	
			EndingLevel::AddEndEvent(std::bind(&EndingPlayActor::SetText, _This, "Event Desing", "Kim Kyeongsik"));
			EndingLevel::AddEndEvent(std::bind(&EndingPlayActor::AddCameraMoveEvent, _This, "ViridianCity", int2(18, 10), float4::Down));
	
			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");
	
			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);
	
		}, this), false);
	
	LevelTimeEvent.AddEvent(33.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);
			_This->SetText("Ending Desing", "Kim Kyeongsik");
			_This->MainTextActor->On();
			_This->MainFakeTextActor->On();
			_This->SubTextActor->On();
			_This->SubFakeTextActor->On();
	
			_This->SetCameraDir(float4(-1, 1).NormalizeReturn());
		}, this), false);
	
	LevelTimeEvent.AddEvent(37.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
		}, this), false);
	
	LevelTimeEvent.AddEvent(38.0f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);
			_This->SetText("Field UI Desing", "Hwang Seungmin");
			_This->MainTextActor->On();
			_This->MainFakeTextActor->On();
			_This->SubTextActor->On();
			_This->SubFakeTextActor->On();
	
			_This->SetCameraDir(float4(0, 1).NormalizeReturn());
		}, this), false);
	
	LevelTimeEvent.AddEvent(42.0f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
		}, this), false);
	
	LevelTimeEvent.AddEvent(42.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			EndingLevel::SetPokemonImageName("EndingPokemon003.bmp");
			EndingLevel::SetPokeballColor(EndingPokeballBackground::PokeColor::Blue);
	
			EndingLevel::AddEndEvent(std::bind(&EndingPlayActor::SetText, _This, "Battle UI Desing", "Kim Minseok\nMin Kyungwoon\nKim Kyunghak"));
			EndingLevel::AddEndEvent(std::bind(&EndingPlayActor::AddCameraMoveEvent, _This, "Route1", int2(14, 14), float4::Down));
	
			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");
	
			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);
	
		}, this), false);
	
	LevelTimeEvent.AddEvent(46.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
		}, this), false);
	
	LevelTimeEvent.AddEvent(47.0f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);
			_This->SetText("Inventory UI Desing", "Kim Kyunghak");
			_This->MainTextActor->On();
			_This->MainFakeTextActor->On();
			_This->SubTextActor->On();
			_This->SubFakeTextActor->On();
	
			_This->SetCameraDir(float4(-1, 1).NormalizeReturn());
		}, this), false);
	
	LevelTimeEvent.AddEvent(51.0f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
		}, this), false);
	
	LevelTimeEvent.AddEvent(51.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);
			_This->SetText("Battle Desing", "Min Kyungwoon\nKim Kyunghak\nUm Taegun\nKim Minseok");
			_This->MainTextActor->On();
			_This->MainFakeTextActor->On();
			_This->SubTextActor->On();
			_This->SubFakeTextActor->On();
	
			_This->SetCameraDir(float4(0, 1).NormalizeReturn());
		}, this), false);
	
	LevelTimeEvent.AddEvent(55.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
		}, this), false);

	LevelTimeEvent.AddEvent(56.0f, std::bind(
		[](EndingPlayActor* _This) 
		{
			EndingLevel::SetPokemonImageName("EndingPokemon004.bmp");
			EndingLevel::SetPokeballColor(EndingPokeballBackground::PokeColor::Yellow);

			EndingLevel::AddEndEvent(std::bind(&EndingPlayActor::SetText, _This, "Tanks For Watching", " "));
			EndingLevel::AddEndEvent(std::bind(&EndingPlayActor::AddCameraMoveEvent, _This, "PalletTown", int2(12, 2), float4::Left));

			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");

			_This->SetFakeTextAlpha(255);
			_This->SetFakeTextAlphaDiff(-510.0f);

		}, this), false);

	LevelTimeEvent.AddEvent(60.0f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->SetFakeTextAlpha(0);
			_This->SetFakeTextAlphaDiff(510.0f);
			_This->SetCameraDir(float4::Zero);
		}, this), false);	
	
	LevelTimeEvent.AddEvent(60.5f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->MainTextActor->Off();
			_This->MainFakeTextActor->Off();
			_This->SubTextActor->Off();
			_This->SubFakeTextActor->Off();

			float4 Start = _This->PlayerAnim->GetPos();
			float4 Dest = GameEngineWindow::GetScreenSize().half();
			Dest.y = Start.y;

			_This->PlayerAnim->MovePos(Start, Dest, 0.5f);
		}, this), false);

	LevelTimeEvent.AddEvent(61.3f, std::bind(
		[](EndingPlayActor* _This)
		{
			_This->Fade->On();
		}, this), false);

	LevelTimeEvent.AddEvent(63.0f, std::bind(
		[](EndingPlayActor* _This) 
		{
			EndingLevel::PlayLastEffect();
			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");
		}, this), false);
}

void EndingPlayActor::SetText(const std::string_view& _MainText, const std::string_view _SubText)
{
	MainTextActor->SetText(
		_MainText,
		"Font_Dialog_Orange.bmp",
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
			Fieldmap::ChangeCity(_CityName, false);
			_This->GetLevel()->SetCameraPos(Fieldmap::GetPos(_CityIndex));
			_This->SetCameraDir(_MoveDir);
		}, this), false); // ��� ��Ƽ
}

void EndingPlayActor::Start()
{
	if (nullptr != MainEndingPlayActor)
	{
		MsgAssert("���� ȣ���� �����ϴ� ���Ͱ� �ߺ� �����Ǿ����ϴ�");
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

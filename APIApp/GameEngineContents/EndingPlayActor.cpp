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
		"Game Design",
		"Font_Dialog_White.bmp",
		static_cast<int>(RenderOrder::EndingMiddle),
		false);

	SubTextActor->SetLine(1);
	SubTextActor->SetText(
		"UTG",
		"Font_Dialog_White.bmp",
		static_cast<int>(RenderOrder::EndingMiddle),
		false);

	MainTextActor->On();
	SubTextActor->On();

	CameraMoveDir = float4::Down;
	CameraSpeed = 128.0f;

	AddCameraMoveEvent("PewterCity", int2(15, 10));

	GetLevel()->LevelEvent.AddEvent(5.0f, std::bind(
		[](EndingPlayActor* _This){
			_This->MainTextActor->SetText(
				"Player Design",
				"Font_Dialog_White.bmp",
				static_cast<int>(RenderOrder::EndingMiddle),
				false);

			_This->SubTextActor->SetLine(1);
			_This->SubTextActor->SetText(
				"YDM",
				"Font_Dialog_White.bmp",
				static_cast<int>(RenderOrder::EndingMiddle),
				false);

			EndingLevel::PokemonRenderImageName = "EndingPokemon001.bmp";
			EndingLevel::PokeballColor = EndingPokeballBackground::PokeColor::Red;

			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");

			_This->AddCameraMoveEvent("ViridianForest", int2(10, 5));

		}, this), false); // 회색 시티
	GetLevel()->LevelEvent.AddEvent(10.0f, std::bind(
		[](EndingPlayActor* _This) {
			_This->MainTextActor->SetText(
				"Map Design",
				"Font_Dialog_White.bmp",
				static_cast<int>(RenderOrder::EndingMiddle),
				false);

			_This->SubTextActor->SetLine(1);
			_This->SubTextActor->SetText(
				"KKS",
				"Font_Dialog_White.bmp",
				static_cast<int>(RenderOrder::EndingMiddle),
				false);

			EndingLevel::PokemonRenderImageName = "EndingPokemon002.bmp";
			EndingLevel::PokeballColor = EndingPokeballBackground::PokeColor::Green;

			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");

			_This->AddCameraMoveEvent("ViridianCity", int2(10, 5));

		}, this), false); // 상록 숲
	GetLevel()->LevelEvent.AddEvent(15.0f, std::bind(
		[](EndingPlayActor* _This) {
			_This->MainTextActor->SetText(
				"UI Design",
				"Font_Dialog_White.bmp",
				static_cast<int>(RenderOrder::EndingMiddle),
				false);

			_This->SubTextActor->SetLine(3);
			_This->SubTextActor->SetText(
				"KKH\nHSM\nKMS",
				"Font_Dialog_White.bmp",
				static_cast<int>(RenderOrder::EndingMiddle),
				false);

			EndingLevel::PokemonRenderImageName = "EndingPokemon003.bmp";
			EndingLevel::PokeballColor = EndingPokeballBackground::PokeColor::Blue;

			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");

			_This->AddCameraMoveEvent("Route1", int2(10, 5));

		}, this), false); // 상록 시티
	GetLevel()->LevelEvent.AddEvent(20.0f, std::bind(
		[](EndingPlayActor* _This) {
			_This->MainTextActor->SetText(
				"Battle Design",
				"Font_Dialog_White.bmp",
				static_cast<int>(RenderOrder::EndingMiddle),
				false);

			_This->SubTextActor->SetLine(1);
			_This->SubTextActor->SetText(
				"MKU",
				"Font_Dialog_White.bmp",
				static_cast<int>(RenderOrder::EndingMiddle),
				false);

			EndingLevel::PokemonRenderImageName = "EndingPokemon004.bmp";
			EndingLevel::PokeballColor = EndingPokeballBackground::PokeColor::Yellow;

			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");

			_This->AddCameraMoveEvent("PalletTown", int2(10, 5));
		}, this), false); // 1번 도로
	GetLevel()->LevelEvent.AddEvent(25.0f, std::bind(
		[](EndingPlayActor* _This) {
			EndingLevel::LastEffect = true;
			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");
		}, this), false); // 태초마을 카메라
}

void EndingPlayActor::AddCameraMoveEvent(const std::string_view& _CityName, const int2& _CityIndex)
{
	GetLevel()->LevelEvent.AddEvent(0.0f, std::bind(
		[=](EndingPlayActor* _This) {
			Fieldmap::ChangeCity(_CityName);
			_This->GetLevel()->SetCameraPos(Fieldmap::GetPos(_CityIndex));
			_This->CameraMoveDir = float4::Down;
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

	//MainFakeTextActor = GetLevel()->CreateActor<TextActor>();
	//MainFakeTextActor->SetPos(float4(35, 170));
	//MainFakeTextActor->Off();
	//
	//SubFakeTextActor = GetLevel()->CreateActor<TextActor>();
	//SubFakeTextActor->SetPos(float4(150, 230));
	//SubFakeTextActor->Off();
}

void EndingPlayActor::Update(float _DeltaTime)
{
	GetLevel()->SetCameraMove(CameraMoveDir * _DeltaTime * CameraSpeed);
}

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
		static_cast<int>(RenderOrder::EndingFront),
		false);

	SubTextActor->SetLine(1);
	SubTextActor->SetText(
		"UTG",
		"Font_Dialog_White.bmp",
		static_cast<int>(RenderOrder::EndingFront),
		false);

	MainTextActor->On();
	SubTextActor->On();

	GetLevel()->LevelEvent.AddEvent(3.0f, std::bind(
		[](EndingPlayActor* _This){
			_This->MainTextActor->SetText(
				"Player Design",
				"Font_Dialog_White.bmp",
				static_cast<int>(RenderOrder::EndingFront),
				false);

			_This->SubTextActor->SetLine(1);
			_This->SubTextActor->SetText(
				"YDM",
				"Font_Dialog_White.bmp",
				static_cast<int>(RenderOrder::EndingFront),
				false);

			EndingLevel::PokemonRenderImageName = "EndingPokemon001.bmp";
			EndingLevel::PokeballColor = EndingPokeballBackground::PokeColor::Red;

			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");

			Fieldmap::ChangeCity("PalletTown");
		}, this), false); // ȸ�� ��Ƽ
	GetLevel()->LevelEvent.AddEvent(6.0f, std::bind(
		[](EndingPlayActor* _This) {
			_This->MainTextActor->SetText(
				"Map Design",
				"Font_Dialog_White.bmp",
				static_cast<int>(RenderOrder::EndingFront),
				false);

			_This->SubTextActor->SetLine(1);
			_This->SubTextActor->SetText(
				"KKS",
				"Font_Dialog_White.bmp",
				static_cast<int>(RenderOrder::EndingFront),
				false);

			EndingLevel::PokemonRenderImageName = "EndingPokemon002.bmp";
			EndingLevel::PokeballColor = EndingPokeballBackground::PokeColor::Green;

			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");

			Fieldmap::ChangeCity("PalletTown");
		}, this), false); // ��� ��
	GetLevel()->LevelEvent.AddEvent(9.0f, std::bind(
		[](EndingPlayActor* _This) {
			_This->MainTextActor->SetText(
				"UI Design",
				"Font_Dialog_White.bmp",
				static_cast<int>(RenderOrder::EndingFront),
				false);

			_This->SubTextActor->SetLine(3);
			_This->SubTextActor->SetText(
				"KKH\nHSM\nKMS",
				"Font_Dialog_White.bmp",
				static_cast<int>(RenderOrder::EndingFront),
				false);

			EndingLevel::PokemonRenderImageName = "EndingPokemon003.bmp";
			EndingLevel::PokeballColor = EndingPokeballBackground::PokeColor::Blue;

			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");

			Fieldmap::ChangeCity("PalletTown");
		}, this), false); // ��� ��Ƽ
	GetLevel()->LevelEvent.AddEvent(12.0f, std::bind(
		[](EndingPlayActor* _This) {
			_This->MainTextActor->SetText(
				"Battle Design",
				"Font_Dialog_White.bmp",
				static_cast<int>(RenderOrder::EndingFront),
				false);

			_This->SubTextActor->SetLine(1);
			_This->SubTextActor->SetText(
				"MKU",
				"Font_Dialog_White.bmp",
				static_cast<int>(RenderOrder::EndingFront),
				false);

			EndingLevel::PokemonRenderImageName = "EndingPokemon004.bmp";
			EndingLevel::PokeballColor = EndingPokeballBackground::PokeColor::Yellow;

			GameEngineCore::GetInst()->ChangeLevel("EndingLevel");

			Fieldmap::ChangeCity("PalletTown");
		}, this), false); // 1�� ����
	GetLevel()->LevelEvent.AddEvent(15.0f, std::bind(
		[](EndingPlayActor* _This) {
			// ���� �� �ؽ�Ʈ...
		}, this), false); // ���ʸ��� ī�޶�
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

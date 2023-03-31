#include "PokemonCenterUI.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include "FieldDialog.h"
#include "Player.h"

PokemonCenterUI* PokemonCenterUI::MainPokemonCenterUI = nullptr;

PokemonCenterUI::PokemonCenterUI()
{
	MainPokemonCenterUI = this;
}

PokemonCenterUI::~PokemonCenterUI()
{

}

void PokemonCenterUI::CenterStart()
{
	Process = CenterProcess::Welcome;
	AcFieldDialog->ConversationStart(&WelcomeScript);
	On();
	AllAnimationOff();
}

void PokemonCenterUI::Start()
{
	AcFieldDialog = FieldDialog::GetFieldDialog();
	if (AcFieldDialog == nullptr)
	{
		MsgAssert("FieldDialog가 nullptr입니다.")
	}
	WelcomeScript.emplace_back("Welcome to our POK@MON CENTER!");
	WelcomeScript.emplace_back("Would you like me to heal your\nPOK@MON back to perfect health?");
	HealScript.emplace_back("Okay, I`ll take your POK@MON for a few seconds.");
	GoodbyeScript1.emplace_back("We hope to see you again!");
	GoodbyeScript2.emplace_back("Thank you for waiting. We`ve restored your POK@MON to full health.");
	GoodbyeScript2.emplace_back("We hope to see you again!");

	MenuRenders.reserve(2);
	MenuRenders.emplace_back(CreateRender("Shop_Yes.bmp", RenderOrder::YesNoMenu));
	MenuRenders.emplace_back(CreateRender("Shop_No.bmp", RenderOrder::YesNoMenu));

	for (size_t i = 0; i < MenuRenders.size(); i++)
	{
		MenuRenders[i]->SetPosition(MenuRenderPos);
		MenuRenders[i]->SetScaleToImage();
		MenuRenders[i]->EffectCameraOff();
		MenuRenders[i]->Off();
	}

	PutBallAnimation = CreateRender(RenderOrder::YesNoMenu);
	PutBallAnimation->SetScale({ 56,56 });
	PutBallAnimation->EffectCameraOff();
	PutBallAnimation->CreateAnimation({.AnimationName = "1", .ImageName = "PokemonCenterBallAnimation.bmp", .Start = 0, .End = 0, .InterTime = 0.4f, .Loop = false});
	PutBallAnimation->CreateAnimation({.AnimationName = "2", .ImageName = "PokemonCenterBallAnimation.bmp", .Start = 0, .End = 1, .InterTime = 0.4f, .Loop = false});
	PutBallAnimation->CreateAnimation({.AnimationName = "3", .ImageName = "PokemonCenterBallAnimation.bmp", .Start = 0, .End = 2, .InterTime = 0.4f, .Loop = false});
	PutBallAnimation->CreateAnimation({.AnimationName = "4", .ImageName = "PokemonCenterBallAnimation.bmp", .Start = 0, .End = 3, .InterTime = 0.4f, .Loop = false});
	PutBallAnimation->CreateAnimation({.AnimationName = "5", .ImageName = "PokemonCenterBallAnimation.bmp", .Start = 0, .End = 4, .InterTime = 0.4f, .Loop = false});
	PutBallAnimation->CreateAnimation({.AnimationName = "6", .ImageName = "PokemonCenterBallAnimation.bmp", .Start = 0, .End = 5, .InterTime = 0.4f, .Loop = false});
	PutBallAnimation->SetPosition(PutBallAnimationPos);
	PutBallAnimation->ChangeAnimation("1");

	TwinkleBallAnimation.resize(3);
	for (size_t y = 0; y < TwinkleBallAnimation.size(); y++)
	{
		TwinkleBallAnimation[y].resize(2);
	}

	for (size_t y = 0; y < TwinkleBallAnimation.size(); y++)
	{
		for (size_t x = 0; x < TwinkleBallAnimation[y].size(); x++)
		{
			TwinkleBallAnimation[y][x] = CreateRender(RenderOrder::YesNoMenu_Arrow);
			TwinkleBallAnimation[y][x]->SetScale({ 24,24 });
			TwinkleBallAnimation[y][x]->EffectCameraOff();
			TwinkleBallAnimation[y][x]->CreateAnimation({ .AnimationName = "Start", .ImageName = "PokemonCenterBallAnimation2.bmp", .Start = 0, .End = 3, .InterTime = 0.1f });
			TwinkleBallAnimation[y][x]->SetPosition(TwinkleBallAnimationStartPos + float4{ static_cast<float>(x),static_cast<float>(y) } *float4{24,16});
			TwinkleBallAnimation[y][x]->ChangeAnimation("Start");
		}
	}

	MonitorAnimation = CreateRender(RenderOrder::YesNoMenu_Arrow);
	MonitorAnimation->SetScale({ 96,60 });
	MonitorAnimation->EffectCameraOff();
	MonitorAnimation->CreateAnimation({ .AnimationName = "Monitor", .ImageName = "PokemonCenterTVAnimation.bmp", .Start = 0, .End = 7, .InterTime = 0.05f });
	MonitorAnimation->SetPosition({ 504,98 }); // 24 262 
	MonitorAnimation->ChangeAnimation("Monitor");

	Off();
}

void PokemonCenterUI::Update(float _DeltaTime)
{
	switch (Process)
	{
	case CenterProcess::Welcome:
		if (AcFieldDialog->IsAllScriptPrintEnd() && State == PokemonMenuState::Null)
		{
			State = PokemonMenuState::Yes;
			StateToRender();
		}
		else if (AcFieldDialog->IsAllScriptPrintEnd() && State != PokemonMenuState::Null)
		{
			AcFieldDialog->IsValid = false;
			if (GameEngineInput::IsDown("Menu_Up") || GameEngineInput::IsDown("Menu_Down"))
			{
				ChangeState();
			}

			if (GameEngineInput::IsDown("A"))
			{
				switch (State)
				{
				case PokemonMenuState::Yes:
					Process = CenterProcess::Heal;
					AcFieldDialog->ConversationStart(&HealScript);
					AcFieldDialog->IsValid = false;
					State = PokemonMenuState::Null;
					StateToRender();
					HealMonsterCount = static_cast<int>(Player::MainPlayer->GetPlayerPokemon()->GetPokemonCount());
					Player::MainPlayer->GetPlayerPokemon()->AllRecovery();
					break;
				case PokemonMenuState::No:
					AcFieldDialog->ConversationStart(&GoodbyeScript1);
					State = PokemonMenuState::Null;
					StateToRender();
					Off();
					break;
				default:
					break;
				}
			}
		}
		break;
	case CenterProcess::Heal:
		if (AcFieldDialog->IsAllScriptPrintEnd())
		{
			StartAnimationAndChangeProcess(_DeltaTime);
		}
		break;
	case CenterProcess::Goodbye:
		if (!AcFieldDialog->IsUpdate())
		{
			Off();
		}
		break;
	default:
		break;
	}
}

void PokemonCenterUI::StateToRender()
{
	switch (State)
	{
	case PokemonMenuState::Null:
		MenuRenders[0]->Off();
		MenuRenders[1]->Off();
		break;
	case PokemonMenuState::Yes:
		MenuRenders[0]->On();
		MenuRenders[1]->Off();
		break;
	case PokemonMenuState::No:
		MenuRenders[0]->Off();
		MenuRenders[1]->On();
		break;
	default:
		break;
	}
}

void PokemonCenterUI::ChangeState()
{
	if (State == PokemonMenuState::Yes)
	{
		State = PokemonMenuState::No;
	}
	else if (State == PokemonMenuState::No)
	{
		State = PokemonMenuState::Yes;
	}
	StateToRender();
}

void PokemonCenterUI::AllAnimationOff()
{
	PutBallAnimation->Off();
	for (size_t y = 0; y < TwinkleBallAnimation.size(); y++)
	{
		for (size_t x = 0; x < TwinkleBallAnimation[y].size(); x++)
		{
			TwinkleBallAnimation[y][x]->Off();
		}
	}
	MonitorAnimation->Off();
}

void PokemonCenterUI::StartAnimationAndChangeProcess(float _DeltaTime)
{
	if (!PutBallAnimation->IsUpdate())
	{
		PutBallAnimation->ChangeAnimation(std::to_string(HealMonsterCount), true);
		PutBallAnimation->On();
	}
	
	if (PutBallAnimation->IsAnimationEnd())
	{
		AnimationTime += _DeltaTime;
		if (AnimationTime >= 0.4f && !IsAnyTwinkleBallAnimationUpdate())
		{
			CountAndTwinkleBallAnimationOn(HealMonsterCount);
			MonitorAnimation->On();
		}
		else if (AnimationTime >= 2.0f)
		{
			AllAnimationOff();
			Process = CenterProcess::Goodbye;
			AcFieldDialog->ConversationStart(&GoodbyeScript2);
			AnimationTime = 0;
		}
	}
}

bool PokemonCenterUI::IsAnyTwinkleBallAnimationUpdate()
{
	for (size_t y = 0; y < TwinkleBallAnimation.size(); y++)
	{
		for (size_t x = 0; x < TwinkleBallAnimation[y].size(); x++)
		{
			if (TwinkleBallAnimation[y][x]->IsUpdate())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

void PokemonCenterUI::CountAndTwinkleBallAnimationOn(int _Count)
{
	switch (_Count)
	{
	case 6:
		TwinkleBallAnimation[2][1]->On();
	case 5:
		TwinkleBallAnimation[2][0]->On();
	case 4:
		TwinkleBallAnimation[1][1]->On();
	case 3:
		TwinkleBallAnimation[1][0]->On();
	case 2:
		TwinkleBallAnimation[0][1]->On();
	case 1:
		TwinkleBallAnimation[0][0]->On();
		break;
	default:
		break;
	}
}
void PokemonCenterUI::CountAndTwinkleBallAnimationOff(int _Count)
{
	switch (_Count)
	{
	case 6:
		TwinkleBallAnimation[2][1]->Off();
	case 5:
		TwinkleBallAnimation[2][0]->Off();
	case 4:
		TwinkleBallAnimation[1][1]->Off();
	case 3:
		TwinkleBallAnimation[1][0]->Off();
	case 2:
		TwinkleBallAnimation[0][1]->Off();
	case 1:
		TwinkleBallAnimation[0][0]->Off();
		break;
	default:
		break;
	}
}



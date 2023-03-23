#include "SummaryUI.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "PocketMonCore.h"
#include "PokeDataBase.h"
#include "TextActor.h"
SummaryUI::SummaryUI() 
{
}

SummaryUI::~SummaryUI() 
{
}

void SummaryUI::Start()
{
	CurrentLevel = GetLevel();

	//_______테스트용 포켓몬 생성
	Pokemons.resize(5);
	Pokemons[0] = PokeDataBase::PokeCreate(1, 5);
	Pokemons[1] = PokeDataBase::PokeCreate(4, 5);
	Pokemons[2] = PokeDataBase::PokeCreate(7, 5);
	Pokemons[3] = PokeDataBase::PokeCreate(10, 2);
	Pokemons[4] = PokeDataBase::PokeCreate(11, 3);

	// 포켓몬 기본 정보
	PokemonRender = CreateRender("BattleBulbasaurFront.bmp", 1);
	PokemonRender->SetScaleToImage();
	PokemonRender->SetPosition({230, 278});

	PokemonName = CurrentLevel->CreateActor<TextActor>();
	PokemonName->SetPos({ 132, 104 });
	PokemonName->SetText("BULBASAUR", "Font_Dialog_White.bmp", false);

	PokemonLevel = CurrentLevel->CreateActor<TextActor>();
	PokemonLevel->SetPos({ 72, 100 });
	PokemonLevel->SetText("5", "Font_Dialog_White.bmp", false);

	// 포켓몬 정보 창
	{
		Info_Back = CreateRender("PokemonInfo.bmp", 0);
		Info_Back->SetScaleToImage();
		Info_Back->SetPosition(Info_Back->GetScale().half());

		Info_Type = CreateRender("Types.bmp", 1);
		Info_Type->SetScale({ 128, 48 });;
		Info_Type->SetPosition({ 733, 228 });
		Info_Type->SetFrame(11);

		Info_Number = CurrentLevel->CreateActor<TextActor>();
		Info_Number->SetPos({ 684, 110 });
		Info_Number->SetText("001", false);

		Info_Name = CurrentLevel->CreateActor<TextActor>();
		Info_Name->SetPos({ 684, 174 });
		Info_Name->SetText("BULBASAUR", false);

		Info_Item = CurrentLevel->CreateActor<TextActor>();
		Info_Item->SetPos({ 684, 412 });
		Info_Item->SetText("NONE", false);

		Info_Memo = CurrentLevel->CreateActor<TextActor>();
		Info_Memo->SetPos({ 48, 484 });
		Info_Memo->SetText("ABCDefewrASDJASDLqiwejskljASDJFaslkfashfljewfheaaaaaaaaaasssssssawifufasfasj", false);

		Info_Objects.reserve(6);
		Info_Objects.push_back(Info_Back);
		Info_Objects.push_back(Info_Type);
		Info_Objects.push_back(Info_Number);
		Info_Objects.push_back(Info_Name);
		Info_Objects.push_back(Info_Item);
		Info_Objects.push_back(Info_Memo);
	}
	// 포켓몬 스텟 창
	{
		Skill_Back = CreateRender("PokemonSkills.bmp", 0);
		Skill_Back->SetScaleToImage();
		Skill_Back->SetPosition(Info_Back->GetScale().half());

		Skill_HP = CurrentLevel->CreateActor<TextActor>();
		Skill_HP->SetAligned(true);
		Skill_HP->SetPos({927,108});
		Skill_HP->SetText("123/320", false);

		Skill_ATK = CurrentLevel->CreateActor<TextActor>();
		Skill_ATK->SetAligned(true);
		Skill_ATK->SetPos({927, 180});
		Skill_ATK->SetText("55");

		Skill_DEF = CurrentLevel->CreateActor<TextActor>();
		Skill_DEF->SetAligned(true);
		Skill_DEF->SetPos({ 927, 232 });
		Skill_DEF->SetText("123");

		Skill_SPATK = CurrentLevel->CreateActor<TextActor>();
		Skill_SPATK->SetAligned(true);
		Skill_SPATK->SetPos({ 927, 284 });
		Skill_SPATK->SetText("123");

		Skill_SPDEF = CurrentLevel->CreateActor<TextActor>();
		Skill_SPDEF->SetAligned(true);
		Skill_SPDEF->SetPos({ 927, 336 });
		Skill_SPDEF->SetText("123");

		Skill_Speed = CurrentLevel->CreateActor<TextActor>();
		Skill_Speed->SetAligned(true);
		Skill_Speed->SetPos({ 927, 388 });
		Skill_Speed->SetText("123");

		Skill_EXP = CurrentLevel->CreateActor<TextActor>();
		Skill_EXP->SetAligned(true);
		Skill_EXP->SetPos({ 927, 440 });
		Skill_EXP->SetText("123");

		Skill_NextEXP = CurrentLevel->CreateActor<TextActor>();
		Skill_NextEXP->SetAligned(true);
		Skill_NextEXP->SetPos({ 927, 492 });
		Skill_NextEXP->SetText("123");

		Skill_Objects.reserve(9);
		Skill_Objects.push_back(Skill_Back);
		Skill_Objects.push_back(Skill_HP);
		Skill_Objects.push_back(Skill_ATK);
		Skill_Objects.push_back(Skill_DEF);
		Skill_Objects.push_back(Skill_SPATK);
		Skill_Objects.push_back(Skill_SPDEF);
		Skill_Objects.push_back(Skill_Speed);
		Skill_Objects.push_back(Skill_EXP);
		Skill_Objects.push_back(Skill_NextEXP);
		for (size_t i = 0; i < Skill_Objects.size(); i++)
		{
			Skill_Objects[i]->Off();
		}
	}

	// 포켓몬 기술 창
	{
		Move_Objects.reserve(20);

		Move_Back = CreateRender("PokemonMoves.bmp", 0);
		Move_Back->SetScaleToImage();
		Move_Back->SetPosition(Move_Back->GetScale().half());

		Move_Moves.reserve(4);
		for (int i = 0; i < 4; i++)
		{
			Move NewMove = Move();
			NewMove.Type = CreateRender("Types.bmp", 1);
			NewMove.Type->SetScale({ 128, 48 });;
			NewMove.Type->SetPosition({ 564, 112.0f + 112 * i});
			NewMove.Type->SetFrame(11);

			NewMove.Name = CurrentLevel->CreateActor<TextActor>();
			NewMove.Name->SetPos({ 664, 112.0f + 112 * i });
			NewMove.Name->SetText("Attack1");

			NewMove.PP = CurrentLevel->CreateActor<TextActor>();
			NewMove.PP->SetAligned(true);
			NewMove.PP->SetPos({ 932, 156.0f + 112 * i });
			NewMove.PP->SetText("20/20");

			Move_Objects.push_back(NewMove.Type);
			Move_Objects.push_back(NewMove.Name);
			Move_Objects.push_back(NewMove.PP);
		}


		Move_Objects.push_back(Move_Back);


		for (size_t i = 0; i < Move_Objects.size(); i++)
		{
			Move_Objects[i]->Off();
		}
	}
}

void SummaryUI::Update(float _DeltaTime)
{

	if (CurrentPage == SummaryPage::MovesSwitch)
	{

	}
	if (GameEngineInput::IsDown("LeftMove"))
	{
		PrevPage();
		return;
	}
	if (GameEngineInput::IsDown("RightMove"))
	{
		NextPage();
		return;
	}
	
	if (GameEngineInput::IsDown("A"))
	{
		Select();
		return;
	}
	if (GameEngineInput::IsDown("B"))
	{
		Cancel();
		return;
	}
	
}

void SummaryUI::NextPage()
{
	switch (CurrentPage)
	{
	case SummaryPage::Info:
		PageOff();
		CurrentPage = SummaryPage::Skills;
		break;
	case SummaryPage::Skills:
		PageOff();
		CurrentPage = SummaryPage::Moves;
		break;
	case SummaryPage::Moves:
	case SummaryPage::MovesSwitch:
	default:
		return;
	}
	MovePage();
}

void SummaryUI::PrevPage()
{
	switch (CurrentPage)
	{
	case SummaryPage::Skills:
		PageOff();
		CurrentPage = SummaryPage::Info;
		break;
	case SummaryPage::Moves:
		PageOff();
		CurrentPage = SummaryPage::Skills;
		break;
	case SummaryPage::Info:
	case SummaryPage::MovesSwitch:
	default:
		return;
	}
	MovePage();
}

void SummaryUI::MovePage()
{
	PageOn();
}

void SummaryUI::PageOn()
{
	std::vector<GameEngineObject*> Objects;
	switch (CurrentPage)
	{
	case SummaryPage::Info:
		Objects = Info_Objects;
		break;
	case SummaryPage::Skills:
		Objects = Skill_Objects;
		break;
	case SummaryPage::Moves:
	case SummaryPage::MovesSwitch:
		Objects = Move_Objects;
		break;
	default:
		return;
	}

	for (size_t i = 0; i < Objects.size(); i++)
	{
		Objects[i]->On();
	}
}

void SummaryUI::PageOff()
{
	std::vector<GameEngineObject*> Objects;
	switch (CurrentPage)
	{
	case SummaryPage::Info:
		Objects = Info_Objects;
		break;
	case SummaryPage::Skills:
		Objects = Skill_Objects;
		break;
	case SummaryPage::Moves:
	case SummaryPage::MovesSwitch:
		Objects = Move_Objects;
		break;
	default:
		return;
	}

	for (size_t i = 0; i < Objects.size(); i++)
	{
		Objects[i]->Off();
	}
}

void SummaryUI::Select()
{
	switch (CurrentPage)
	{
	case SummaryPage::Info:
		PocketMonCore::GetInst().ChangeLevel("PokemonLevel");
		break;
	case SummaryPage::Skills:
		break;
	case SummaryPage::Moves:
		CurrentPage = SummaryPage::MovesSwitch;
		break;
	case SummaryPage::MovesSwitch:
		break;
	default:
		break;
	}
}

void SummaryUI::Cancel()
{
	switch (CurrentPage)
	{
	case SummaryPage::Info:
	case SummaryPage::Skills:
	case SummaryPage::Moves:
		PocketMonCore::GetInst().ChangeLevel("PokemonLevel");
		break;
	case SummaryPage::MovesSwitch:
		break;
	default:
		break;
	}
}

void SummaryUI::NextPokemon()
{
}

void SummaryUI::PrevPokemon()
{
}

void SummaryUI::MovePokemon()
{
}


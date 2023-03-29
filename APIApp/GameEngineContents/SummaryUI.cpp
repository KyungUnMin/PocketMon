#include "SummaryUI.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "LevelChangeFade.h"
#include "PokeDataBase.h"
#include "TextActor.h"
#include "PokemonUI.h"
#include "ContentsEnum.h"
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

	PokemonLevel = CurrentLevel->CreateActor<TextActor>();
	PokemonLevel->SetPos({ 72, 100 });

	CurrentSkillSelect = CreateRender("MoveSelect.bmp", 6);
	CurrentSkillSelect->SetScale({ 480, 116 });
	CurrentSkillSelect->SetPosition({ 720, 132 });
	CurrentSkillSelect->Off();

	SkillSelect = CreateRender("MoveSelect.bmp", 5);
	SkillSelect->SetScale({ 480, 116 });
	SkillSelect->SetPosition({ 720, 132 });
	SkillSelect->Off();

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

		Info_Name = CurrentLevel->CreateActor<TextActor>();
		Info_Name->SetPos({ 684, 174 });

		Info_Item = CurrentLevel->CreateActor<TextActor>();
		Info_Item->SetPos({ 684, 412 });

		Info_Memo = CurrentLevel->CreateActor<TextActor>();
		Info_Memo->SetPos({ 48, 484 });

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

		Skill_ATK = CurrentLevel->CreateActor<TextActor>();
		Skill_ATK->SetAligned(true);
		Skill_ATK->SetPos({927, 180});

		Skill_DEF = CurrentLevel->CreateActor<TextActor>();
		Skill_DEF->SetAligned(true);
		Skill_DEF->SetPos({ 927, 232 });

		Skill_SPATK = CurrentLevel->CreateActor<TextActor>();
		Skill_SPATK->SetAligned(true);
		Skill_SPATK->SetPos({ 927, 284 });

		Skill_SPDEF = CurrentLevel->CreateActor<TextActor>();
		Skill_SPDEF->SetAligned(true);
		Skill_SPDEF->SetPos({ 927, 336 });

		Skill_Speed = CurrentLevel->CreateActor<TextActor>();
		Skill_Speed->SetAligned(true);
		Skill_Speed->SetPos({ 927, 388 });

		Skill_EXP = CurrentLevel->CreateActor<TextActor>();
		Skill_EXP->SetAligned(true);
		Skill_EXP->SetPos({ 927, 440 });

		Skill_NextEXP = CurrentLevel->CreateActor<TextActor>();
		Skill_NextEXP->SetAligned(true);
		Skill_NextEXP->SetPos({ 927, 492 });

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

			NewMove.PP = CurrentLevel->CreateActor<TextActor>();
			NewMove.PP->SetAligned(true);
			NewMove.PP->SetPos({ 932, 156.0f + 112 * i });

			Move_Objects.push_back(NewMove.Type);
			Move_Objects.push_back(NewMove.Name);
			Move_Objects.push_back(NewMove.PP);
			Move_Moves.push_back(NewMove);
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
	if (GameEngineInput::IsDown("UpMove"))
	{
		PrevPokemon();
		return;
	}
	if (GameEngineInput::IsDown("DownMove"))
	{
		NextPokemon();
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

void SummaryUI::LevelChangeStart(GameEngineLevel* _Prev)
{
	CurrentPokemon = PokemonUI::MainPokemon->CurrentCursor;
	SetPokemonData();

	PageOff();
	CurrentPage = SummaryPage::Info;
	PageOn();
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
		PokemonUI::MainPokemon->SetCursor(CurrentPokemon);
		LevelChangeFade::MainLevelFade->LevelChangeFadeOut("PokemonLevel");
		break;
	case SummaryPage::Skills:
		break;
	case SummaryPage::Moves:
		MovesSwitchOn();
		break;
	case SummaryPage::MovesSwitch:
		MovesSwitchSelect();
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
		PokemonUI::MainPokemon->SetCursor(CurrentPokemon);
		LevelChangeFade::MainLevelFade->LevelChangeFadeOut("PokemonLevel");
		break;
	case SummaryPage::MovesSwitch:
		MovesSwitchCancle();
		break;
	default:
		break;
	}
}

void SummaryUI::NextPokemon()
{
	switch (CurrentPage)
	{
	case SummaryPage::Info:
	case SummaryPage::Skills:
	case SummaryPage::Moves:
	{
		if (CurrentPokemon == Pokemons.size() - 1)
		{
			return;
		}
		CurrentPokemon++;
		SetPokemonData();
	}
		break;
	case SummaryPage::MovesSwitch:
		MovesSwitchDown();
		break;
	default:
		break;
	}
}

void SummaryUI::PrevPokemon()
{
	switch (CurrentPage)
	{
	case SummaryPage::Info:
	case SummaryPage::Skills:
	case SummaryPage::Moves:
	{
		if (CurrentPokemon == 0)
		{
			return;
		}
		CurrentPokemon--;
		SetPokemonData();
	}
	break;
	case SummaryPage::MovesSwitch:
		MovesSwitchUp();
		break;
	default:
		break;
	}
}

void SummaryUI::MovePokemon()
{
}

void SummaryUI::SetPokemonData()
{
	PokeDataBase Pokemon = Pokemons[CurrentPokemon];
	PokemonRender->SetImage("Battle" + Pokemon.ForUI_GetMonsterName() + "Front.bmp");
	PokemonName->SetText(Pokemon.ForUI_GetMonsterName(), "Font_Dialog_White.bmp",  false);
	PokemonLevel->SetText(Pokemon.ForUI_GetMonsterLevel(), "Font_Dialog_White.bmp", false);
	Info_Number->SetText(Pokemon.ForUI_GetMonsterNumberName(), "Font_Dialog_Black2.bmp", false);
	Info_Name->SetText(Pokemon.ForUI_GetMonsterName(), "Font_Dialog_Black2.bmp", false);
	Info_Type->SetFrame(static_cast<int>(Pokemon.GetMonsterType()));
	ItemCode Pokemon_ItemCode = Pokemon.GetPossession();
	if (ItemCode::Potion <= Pokemon_ItemCode && ItemCode::Cancel >= Pokemon_ItemCode)
	{
		Info_Item->SetText(Item::GetItem(Pokemon_ItemCode).GetItemName(), "Font_Dialog_Black2.bmp", false);
	}
	else
	{
		Info_Item->SetText("NONE", "Font_Dialog_Black2.bmp", false);
	}
	Info_Memo->SetText(Pokemon.ForUI_GetPokeDexText(), "Font_Dialog_Black2.bmp", false);

	Skill_HP->SetText(Pokemon.ForUI_GetMonsterCurrentHP() + "/" + Pokemon.ForUI_GetMonsterMaxHP(), "Font_Dialog_Black2.bmp", false);
	Skill_ATK->SetText(std::to_string(Pokemon.GetMonsterAttackPower_int()), "Font_Dialog_Black2.bmp", false);
	Skill_DEF->SetText(std::to_string(Pokemon.GetMonsterDefense_int()), "Font_Dialog_Black2.bmp", false);
	Skill_SPATK->SetText(std::to_string(Pokemon.GetMonsterSpecialAttackPower_int()), "Font_Dialog_Black2.bmp", false);
	Skill_SPDEF->SetText(std::to_string(Pokemon.GetMonsterSpecialDefense_int()), "Font_Dialog_Black2.bmp", false);
	Skill_Speed->SetText(std::to_string(Pokemon.GetMonsterAgility()), "Font_Dialog_Black2.bmp", false);
	Skill_EXP->SetText(Pokemon.ForUI_GetMonsterExperience(), "Font_Dialog_Black2.bmp", false);
	Skill_NextEXP->SetText(std::to_string(100 - Pokemon.GetMonsterExperience()), "Font_Dialog_Black2.bmp", false);

	SkillSize = 0;
	for (int i = 0; i < 4; i++)
	{
		PokeSkillBase Skill = Pokemon.GetMonsterSkillList(i+1);
		if (Skill.GetSkill() == PokeSkill::Unknown)
		{
			Move_Moves[i].Type->SetFrame(17);
			Move_Moves[i].Name->SetText(" ");
			Move_Moves[i].PP->SetText("-  ", "Font_Dialog_Black2.bmp", false);
			continue;
		}
		SkillSize++;
		Move_Moves[i].Type->SetFrame(static_cast<int>(Skill.GetSkillType()));
		Move_Moves[i].Name->SetText(Skill.ForUI_GetSkillName(), "Font_Dialog_Black2.bmp", false);
		Move_Moves[i].PP->SetText(Skill.ForUI_GetCurrentSkillPowerPoint() + "/" + Skill.ForUI_GetMaxSkillPowerPoint(), "Font_Dialog_Black2.bmp", false);
	}
}

void SummaryUI::MovesSwitchOn()
{
	CurrentSkillCursor = 0;
	SelectSkillCursor = -1;
	CurrentSkillSelect->SetPosition({ 720, 132.0f + 108 * CurrentSkillCursor });
	CurrentSkillSelect->On();
	SkillSelect->Off();
	CurrentPage = SummaryPage::MovesSwitch;
}

void SummaryUI::MovesSwitchOff()
{
	CurrentSkillSelect->Off();
	SkillSelect->SetFrame(0);
	SkillSelect->Off();
	CurrentPage = SummaryPage::Moves;
}

void SummaryUI::MovesSwitchUp()
{
	if (CurrentSkillCursor == 0)
	{
		return;
	}
	CurrentSkillCursor--;
	CurrentSkillSelect->SetPosition({ 720, 132.0f + 108 * CurrentSkillCursor });
}

void SummaryUI::MovesSwitchDown()
{
	if (CurrentSkillCursor == SkillSize - 1)
	{
		return;
	}
	CurrentSkillCursor++;
	CurrentSkillSelect->SetPosition({ 720, 132.0f + 108 * CurrentSkillCursor });
}

void SummaryUI::MovesSwitchSelect()
{
	if (SelectSkillCursor == -1)
	{
		SelectSkillCursor = CurrentSkillCursor;
		SkillSelect->SetFrame(1);
		SkillSelect->On();
		SkillSelect->SetPosition({ 720, 132.0f + 108 * SelectSkillCursor });
		return;
	}

	if (SelectSkillCursor == CurrentSkillCursor)
	{
		return;
	}

	PokeSkill Select = Pokemons[CurrentPokemon].GetMonsterSkillList(SelectSkillCursor+1).GetSkill();
	Pokemons[CurrentPokemon].ChangeMonsterSkill(SelectSkillCursor+1, Pokemons[CurrentPokemon].GetMonsterSkillList(CurrentSkillCursor+1).GetSkill());
	Pokemons[CurrentPokemon].ChangeMonsterSkill(CurrentSkillCursor+1, Select);
	SetPokemonData();
	MovesSwitchCancle();
}

void SummaryUI::MovesSwitchCancle()
{
	if (SelectSkillCursor == -1)
	{
		MovesSwitchOff();
		return;
	}
	SelectSkillCursor = -1;
	SkillSelect->Off();
}


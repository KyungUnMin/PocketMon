#include <Windows.h>
#include <GameEngineContents/PocketMonCore.h>

#include <vector>
#include <iostream>

#include <GameEngineContents/PokeDataBase.h>
#include <GameEngineContents/PokeBattleSystem.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	PokeDataBase* NewP1 = PokeDataBase::PokeCreate(1, 15);
	PokeDataBase* NewP2 = PokeDataBase::PokeCreate(4, 8);

	std::string AAAA = NewP1->ForUI_GetMonsterName();

	std::string A = NewP1->GetMonsterSkillList(1)->ForUI_GetSkillName();
	std::string B = NewP1->GetMonsterSkillList(2)->ForUI_GetSkillName();
	std::string C = NewP1->GetMonsterSkillList(3)->ForUI_GetSkillName();
	int CCC = NewP1->GetMonsterSkillList(3)->GetSkillDamage();
	std::string D = NewP1->GetMonsterSkillList(4)->ForUI_GetSkillName();

	NewP1->ChangeMonsterSkill(3, PokeSkill::SolarBeam);

	A = NewP1->GetMonsterSkillList(1)->ForUI_GetSkillName();
	B = NewP1->GetMonsterSkillList(2)->ForUI_GetSkillName();
	C = NewP1->GetMonsterSkillList(3)->ForUI_GetSkillName();
	CCC = NewP1->GetMonsterSkillList(3)->GetSkillDamage();
	D = NewP1->GetMonsterSkillList(4)->ForUI_GetSkillName();

	int a = NewP2->GetMonsterMaxHP_int();
	int b = NewP1->GetMonsterMaxHP_int();
	int bb = NewP1->GetMonsterCurrentHP();

	BattleScript aa = PokeBattleSystem::Battle(NewP2, 1, NewP1);

	int bbc = NewP1->GetMonsterCurrentHP();

	int aaaa1212 = NewP1->GetMonsterLevel_int();

	PokeDataBase::PokeExperienceGain(NewP1, NewP2);
	PokeDataBase::PokeExperienceGain(NewP1, NewP2);
	PokeDataBase::PokeExperienceGain(NewP1, NewP2);
	PokeDataBase::PokeExperienceGain(NewP1, NewP2);
	PokeDataBase::PokeExperienceGain(NewP1, NewP2);

	int aaaa = NewP1->GetMonsterLevel_int();

	PocketMonCore::GetInst().CoreStart(hInstance);
	return 1;
}
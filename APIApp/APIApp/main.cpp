#include <Windows.h>
#include <GameEngineContents/PocketMonCore.h>

#include <vector>
#include <string>
#include <iostream>

#include <GameEngineContents/PokeDataBase.h>
#include <GameEngineContents/PokeBattleSystem.h>
#include <GameEngineContents/ItemDataBase.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	PokeDataBase NewP1 = PokeDataBase::PokeCreate(4, 15);
	PokeDataBase NewP2 = PokeDataBase::PokeCreate(1, 20);

	PokeDataBase NewP3 = PokeDataBase::PokeCreate(PokeNumber::Bulbasaur, 20);

	std::string AAAA = NewP1.ForUI_GetMonsterName();

	std::string A = NewP1.GetMonsterSkillList(1).ForUI_GetSkillName();
	std::string B = NewP1.GetMonsterSkillList(2).ForUI_GetSkillName();
	std::string C = NewP1.GetMonsterSkillList(3).ForUI_GetSkillName();
	std::string D = NewP1.GetMonsterSkillList(4).ForUI_GetSkillName();

	int aa = NewP1.GetMonsterMaxHP_int();
	int bb = NewP1.GetMonsterCurrentHP();

	std::string AA = NewP2.GetMonsterSkillList(1).ForUI_GetSkillName();
	std::string BB = NewP2.GetMonsterSkillList(2).ForUI_GetSkillName();
	std::string CC = NewP2.GetMonsterSkillList(3).ForUI_GetSkillName();
	std::string DD = NewP2.GetMonsterSkillList(4).ForUI_GetSkillName();

	int aaa = NewP2.GetMonsterMaxHP_int();
	int bbb = NewP2.GetMonsterCurrentHP();

	PokeBattleSystem::Battle(NewP1, 1, NewP2);
	int AAAAasdfasdfasdf = PokeBattleSystem::GetDamage();

	PokeBattleSystem::Battle(NewP1, 3, NewP2);

	AAAAasdfasdfasdf = PokeBattleSystem::GetDamage();
	PokeBattleSystem::Battle(NewP1, 1, NewP2);
	AAAAasdfasdfasdf = PokeBattleSystem::GetDamage();
	PokeBattleSystem::Battle(NewP2, 1, NewP1);
	AAAAasdfasdfasdf = PokeBattleSystem::GetDamage();

	aa = NewP1.GetMonsterMaxHP_int();
	bb = NewP1.GetMonsterCurrentHP();

	aaa = NewP2.GetMonsterMaxHP_int();
	bbb = NewP2.GetMonsterCurrentHP();

	int a12121212 = NewP1.GetMonsterLevel_int();
	int a1212121212 = NewP1.GetMonsterExperience();

	PokeDataBase::PokeExperienceGain(NewP1, NewP2);
	PokeDataBase::PokeExperienceGain(NewP1, NewP2);

	a12121212 = NewP1.GetMonsterLevel_int();
	a1212121212 = NewP1.GetMonsterExperience();

	PokeDataBase PPP = PokeDataBase::SpecialPokeCreate(SpecialPokeEnum::CatchRattata, 6);
	
	PokeNumber pasdf = PPP.GetPokeNumber_enum();
	

	PocketMonCore::GetInst().CoreStart(hInstance);
	return 1;
}
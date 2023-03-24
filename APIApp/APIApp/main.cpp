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
	PokeDataBase* NewP1 = PokeDataBase::PokeCreate(4, 15);
	PokeDataBase* NewP2 = PokeDataBase::PokeCreate(1, 20);

	std::string AAAA = NewP1->ForUI_GetMonsterName();

	std::string A = NewP1->GetMonsterSkillList(1)->ForUI_GetSkillName();
	std::string B = NewP1->GetMonsterSkillList(2)->ForUI_GetSkillName();
	std::string C = NewP1->GetMonsterSkillList(3)->ForUI_GetSkillName();
	std::string D = NewP1->GetMonsterSkillList(4)->ForUI_GetSkillName();

	PokeBattleSystem::Battle(NewP1, 4, NewP2);
	PokeBattleSystem::Battle(NewP1, 4, NewP2);
	PokeBattleSystem::Battle(NewP1, 4, NewP2);
	PokeBattleSystem::Battle(NewP2, 1, NewP1);

	PokeDataBase::PokeExperienceGain(NewP1, NewP2);
	PokeDataBase::PokeExperienceGain(NewP1, NewP2);
	
	PocketMonCore::GetInst().CoreStart(hInstance);
	return 1;
}
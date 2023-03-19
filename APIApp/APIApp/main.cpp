#include <Windows.h>
#include <GameEngineContents/PocketMonCore.h>

#include <vector>
#include <iostream>

#include <GameEngineContents/PokeDataBase.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	//PokeDataBase* NewPoke2 = PokeDataBase::PokeCreate(4, 1);
	//PokeDataBase* NewPoke3 = PokeDataBase::PokeCreate(7, 1);
	//PokeDataBase* NewPoke4 = PokeDataBase::PokeCreate(9, 1);
	//PokeDataBase* NewPoke5 = PokeDataBase::PokeCreate(11, 1);
	
	PokeDataBase* NewPoke = PokeDataBase::PokeCreate(1, 1);
	NewPoke->GetMonsterMaxHP();

	std::string MHPS = "max체력쓰 : ";
	std::string CHPS = "cur체력쓰 : ";
	std::string MOBN = "내이름 : ";
	std::string SKILN = "내스킬이름1 : ";
	std::string SKILN1 = "내스킬이름2 : ";
	std::string SKILN2 = "내스킬이름3 : ";
	std::string SKILN3 = "내스킬이름4 : ";
	std::string MPP = "1번스킬 maxPP : ";
	std::string CPP = "1번스킬 curPP : ";
	std::string MPP1 = "2번스킬 maxPP : ";
	std::string CPP1 = "2번스킬 curPP : ";
	MHPS += NewPoke->ForUI_GetMonsterMaxHP();
	CHPS += NewPoke->ForUI_GetMonsterCurrentHP();
	MOBN += NewPoke->ForUI_GetMonsterName();
	SKILN += NewPoke->GetMonsterSkillList(1)->ForUI_GetSkillName();
	SKILN1 += NewPoke->GetMonsterSkillList(2)->ForUI_GetSkillName();
	SKILN2 += NewPoke->GetMonsterSkillList(3)->ForUI_GetSkillName();
	SKILN3 += NewPoke->GetMonsterSkillList(4)->ForUI_GetSkillName();
	MPP += NewPoke->GetMonsterSkillList(1)->ForUI_GetMaxSkillPowerPoint();
	CPP += NewPoke->GetMonsterSkillList(1)->ForUI_GetCurrentSkillPowerPoint();
	MPP1 += NewPoke->GetMonsterSkillList(1)->ForUI_GetMaxSkillPowerPoint();
	CPP1 += NewPoke->GetMonsterSkillList(1)->ForUI_GetCurrentSkillPowerPoint();

	PocketMonCore::GetInst().CoreStart(hInstance);
	return 1;

}
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

	std::string MHPS = "maxü�¾� : ";
	std::string CHPS = "curü�¾� : ";
	std::string MOBN = "���̸� : ";
	std::string SKILN = "����ų�̸�1 : ";
	std::string SKILN1 = "����ų�̸�2 : ";
	std::string SKILN2 = "����ų�̸�3 : ";
	std::string SKILN3 = "����ų�̸�4 : ";
	std::string MPP = "1����ų maxPP : ";
	std::string CPP = "1����ų curPP : ";
	std::string MPP1 = "2����ų maxPP : ";
	std::string CPP1 = "2����ų curPP : ";
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
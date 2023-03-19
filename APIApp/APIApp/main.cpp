#include <Windows.h>
#include <GameEngineContents/PocketMonCore.h>

#include <vector>

#include <GameEngineContents/PokeDataBase.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	PokeDataBase* NewPoke = PokeDataBase::PokeCreate(1, 1);
	PokeDataBase* NewPoke2 = PokeDataBase::PokeCreate(4, 1);
	PokeDataBase* NewPoke3 = PokeDataBase::PokeCreate(7, 1);
	PokeDataBase* NewPoke4 = PokeDataBase::PokeCreate(9, 1);
	PokeDataBase* NewPoke5 = PokeDataBase::PokeCreate(11, 1);

	int aa = NewPoke->GetMonsterMaxHP();
	int a1 = NewPoke->GetMonsterAgility();
	int a2 = NewPoke->GetMonsterAttackPower();
	PokeSkillBase* aaaa = NewPoke->GetMonsterSkillList(1);
	int d1 = NewPoke->GetMonsterSkillList(1)->GetSkillDamage();
	float d3 = NewPoke->GetMonsterSkillList(1)->GetSkillHitrate();

	PocketMonCore::GetInst().CoreStart(hInstance);
	return 1;

}
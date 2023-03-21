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
	PokeDataBase* NewP1 = PokeDataBase::PokeCreate(1, 10);
	PokeDataBase* NewP2 = PokeDataBase::PokeCreate(4, 8);

	int a = NewP2->GetMonsterMaxHP_int();
	int b = NewP1->GetMonsterMaxHP_int();
	int bb = NewP1->GetMonsterCurrentHP();

	PokeBattleSystem::Battle(NewP2, 3, NewP1);

	int bbc = NewP1->GetMonsterCurrentHP();

	PocketMonCore::GetInst().CoreStart(hInstance);
	return 1;
}
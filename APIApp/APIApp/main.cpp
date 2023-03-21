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
	PokeDataBase* NewP1 = PokeDataBase::PokeCreate(1, 4);
	PokeDataBase* NewP2 = PokeDataBase::PokeCreate(1, 9);

	PokeBattleSystem::Battle(NewP1, 1, NewP2);

	PocketMonCore::GetInst().CoreStart(hInstance);
	return 1;
}
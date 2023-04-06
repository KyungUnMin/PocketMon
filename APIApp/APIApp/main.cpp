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
	PocketMonCore::GetInst().CoreStart(hInstance);
	return 1;
}
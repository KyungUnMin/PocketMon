#include <Windows.h>
#include <GameEngineContents/PocketMonCore.h>

#include <GameEngineContents/PokeDataBase.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	// 1 이상해씨, 4 파이리, 7 꼬부기
	PokeDataBase Po;
	Po.PokeCreate(1, 1);

	PokeDataBase Po1;
	Po1.PokeCreate(4, 3);

	PokeDataBase Po2;
	Po2.PokeCreate(7, 6);

	int a = 0;

	PocketMonCore::GetInst().CoreStart(hInstance);
	return 1;
}
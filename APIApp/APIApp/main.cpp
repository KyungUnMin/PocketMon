#include <Windows.h>
#include <GameEngineContents/PocketMonCore.h>

#include <vector>

#include <GameEngineContents/PokeDataBase.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	// 1 이상해씨, 4 파이리, 7 꼬부기
	std::vector<PokeDataBase*> PlayerPokemons;
	PlayerPokemons.reserve(6);

	PokeDataBase AA;
	AA.PokeCreate(1, 1);
	PlayerPokemons.push_back(&AA);

	PokeDataBase BB;
	BB.PokeCreate(4, 1);
	PlayerPokemons.push_back(&BB);

	PokeDataBase CC;
	CC.PokeCreate(7, 1);
	PlayerPokemons.push_back(&CC);

	PokeDataBase DD;
	DD.PokeCreate(9, 1);
	PlayerPokemons.push_back(&DD);

	PokeDataBase EE;
	EE.PokeCreate(11, 1);
	PlayerPokemons.push_back(&EE);

	PokeDataBase FF;
	FF.PokeCreate(14, 1);
	PlayerPokemons.push_back(&FF);

	int a = 0;

	PocketMonCore::GetInst().CoreStart(hInstance);
	return 1;
}
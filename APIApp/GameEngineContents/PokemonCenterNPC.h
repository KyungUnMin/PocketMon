#pragma once
#include "StaticNPC.h"
#include <GameEngineCore/GameEngineCollision.h>

class GameEngineCollision;
class PokemonCenterUI;
class PokemonCenterNPC : public StaticNPC
{
public:
	PokemonCenterNPC();
	~PokemonCenterNPC();

	PokemonCenterNPC(const PokemonCenterNPC& _Other) = delete;
	PokemonCenterNPC(PokemonCenterNPC&& _Other) noexcept = delete;
	PokemonCenterNPC& operator=(const PokemonCenterNPC& _Other) = delete;
	PokemonCenterNPC& operator=(PokemonCenterNPC&& _Other) noexcept = delete;

	//1은상록 2는회색
	inline void SetCityValue(int _Value)
	{
		if (!(_Value == 1 || _Value == 2))
		{
			MsgAssert("등록할수없는 CityValue입니다");
		}
		CityValue = _Value;
	}
	
protected:
	void Start() override;
	void IdleUpdate(float _DeltaTime) override;
	void Update(float _DeltaTime) override;
private:
	GameEngineCollision* CenterNpc_C = nullptr;
	int2 SavePlayerPos = int2::Zero;
	

	int CityValue = 0;
};


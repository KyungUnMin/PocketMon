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
	int2 GetSavePlayerPos()
	{
		return SavePlayerPos;
	}
protected:
	void Start() override;
	void IdleUpdate(float _DeltaTime) override;
private:
	GameEngineCollision* CenterNpc_C = nullptr;
	int2 SavePlayerPos = int2::Zero;
	
};


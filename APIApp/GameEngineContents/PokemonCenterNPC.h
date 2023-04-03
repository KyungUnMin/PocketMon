#pragma once
#include "StaticNPC.h"


class PokemonCenterNPC : public StaticNPC
{
public:
	PokemonCenterNPC();
	~PokemonCenterNPC();

	PokemonCenterNPC(const PokemonCenterNPC& _Other) = delete;
	PokemonCenterNPC(PokemonCenterNPC&& _Other) noexcept = delete;
	PokemonCenterNPC& operator=(const PokemonCenterNPC& _Other) = delete;
	PokemonCenterNPC& operator=(PokemonCenterNPC&& _Other) noexcept = delete;

protected:
	void Start() override;
	void IdleUpdate(float _DeltaTime) override;
private:


};


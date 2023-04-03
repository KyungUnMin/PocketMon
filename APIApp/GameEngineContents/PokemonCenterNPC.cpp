#include "PokemonCenterNPC.h"
#include "BattleLevel.h"
#include "PokemoncenterUI.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include "Player.h"
#include <string>

PokemonCenterNPC::PokemonCenterNPC()
{
}

PokemonCenterNPC::~PokemonCenterNPC()
{
}

void PokemonCenterNPC::Start()
{
	InitNPC("PoketmonCenterNpc", "Nurse.bmp", BattleNpcType::NPC3);
	AddNPC("PewterCity_PokemonCenter", { 8,4 });
	Look(LookDir::Down);

	CenterNpc_C = CreateCollision(CollisionOrder::NPC);
	CenterNpc_C->SetDebugRenderType(CollisionType::CT_Rect);
	CenterNpc_C->SetScale({ 64, 128 });
	CenterNpc_C->SetPosition({ 0,64 });
}
void PokemonCenterNPC::IdleUpdate(float _DeltaTime)
{
	std::vector<GameEngineCollision*> CheckCollisions;
	CollisionCheckParameter CheckPlayer = { .TargetGroup = static_cast<int>(CollisionOrder::Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == CenterNpc_C->Collision(CheckPlayer, CheckCollisions) &&
		true == GameEngineInput::IsDown("NpcTalk") &&
		Player::MainPlayer->GetPlayerMoveBool())
	{
		PokemonCenterUI::MainPokemonCenterUI->CenterStart();
	}
	CenterProcess Test=PokemonCenterUI::MainPokemonCenterUI->GetProcess();
	if (Test == CenterProcess::Heal)
	{
		Look(LookDir::Left);
	}
	else
	{
		Look(LookDir::Down);
	}
}
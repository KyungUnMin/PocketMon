#include "BattleSkill_PlayerDefenseCurl.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterPlayer.h"
#include <GameEngineCore/GameEngineResources.h>
BattleSkill_PlayerDefenseCurl::BattleSkill_PlayerDefenseCurl() 
{
}

BattleSkill_PlayerDefenseCurl::~BattleSkill_PlayerDefenseCurl() 
{
}

void BattleSkill_PlayerDefenseCurl::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	EffectRender = GetPlayerMonster()->CreateRender("DefenseCurl.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScale({ 128, 128 });
	EffectRender->SetAlpha({ 225 });
	EffectRender->CreateAnimation({ .AnimationName = "Defalut", .ImageName = "DefenseCurl.bmp", .Start = 0, .End = 7, .Loop = false, .FrameTime = {0.15f, 0.15f, 0.08f, 0.1f, 0.06f, 0.04f, 0.02f, 1.0f} });
	EffectRender->ChangeAnimation("Defalut");
	EffectRender->On();

	GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl("DefenseCurl.wav");
	SfxCtrl.LoopCount(1);
	SfxCtrl.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_PlayerDefenseCurl::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, Duration))
		return;

}

void BattleSkill_PlayerDefenseCurl::ExitState()
{
	BattleSkill_PlayerBase::ExitState();
}

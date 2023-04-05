#include "BattleSkill_PlayerIronDefense.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterPlayer.h"
#include "SkillActor_BlackBox.h"
#include "BattleLevel.h"
BattleSkill_PlayerIronDefense::BattleSkill_PlayerIronDefense()
{
}

BattleSkill_PlayerIronDefense::~BattleSkill_PlayerIronDefense()
{
}

void BattleSkill_PlayerIronDefense::EnterState()
{
	BattleSkill_PlayerBase::EnterState();

	EffectRender = GetPlayerMonster()->CreateRender("DefenseCurl.bmp", BattleRenderOrder::SkillEffect);
	EffectRender->SetScale({ 128, 128 });
	EffectRender->SetAlpha({ 225 });
	EffectRender->CreateAnimation({ .AnimationName = "Defalut", .ImageName = "DefenseCurl.bmp", .Start = 0, .End = 7, .Loop = false, .FrameTime = {0.15f, 0.15f, 0.08f, 0.1f, 0.06f, 0.04f, 0.02f, 1.0f} });
	EffectRender->ChangeAnimation("Defalut");
	EffectRender->On();
	Timer = 0;
	BBox = BattleLevel::BattleLevelPtr->CreateActor<SkillActor_BlackBox>();

	GameEngineSoundPlayer SfxCtrl = GameEngineResources::GetInst().SoundPlayToControl("DefenseCurl.wav");
	SfxCtrl.LoopCount(1);
	SfxCtrl.Volume(BattleDefine::WorldVolumn);
	GameEngineSoundPlayer SfxCtrl2 = GameEngineResources::GetInst().SoundPlayToControl("IronDefense.wav");
	SfxCtrl2.LoopCount(1);
	SfxCtrl2.Volume(BattleDefine::WorldVolumn);
}

void BattleSkill_PlayerIronDefense::Update(float _DeltaTime)
{
	if (true == BattleSkill_PlayerBase::Update_CheckTime(_DeltaTime, Duration))
		return;

	Timer += _DeltaTime;
	if (1.2f < Timer)
	{
		BBox->FadeOutStart();
	}
	else if (0 < Timer)
	{
		BBox->FadeInStart();
	}
}

void BattleSkill_PlayerIronDefense::ExitState()
{
	BattleSkill_PlayerBase::ExitState();

	BBox->Death();
	BBox = nullptr;
}

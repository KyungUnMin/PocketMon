#include "BattlePlayerMonster_CreateState.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include "BattlePlayer.h"
#include "BattleMonsterPlayer.h"
#include "ContentsEnum.h"
#include "Battle_MonsterAppearEffect.h"
#include "BattleLevel.h"
#include "BattlePlayerMonsterFSM.h"
#include "BattleDefine.h"

BattlePlayerMonster_CreateState::BattlePlayerMonster_CreateState()
{

}

BattlePlayerMonster_CreateState::~BattlePlayerMonster_CreateState()
{

}

void BattlePlayerMonster_CreateState::EnterState()
{
	static const float OffsetY = 30.f;

	BattlePlayer* Player = BattlePlayer::PlayerPtr;
	Monster = Player->GetMonster();
	Monster->SetPos(Player->GetPos() + float4::Up * OffsetY);

	GameEngineRender* MonsterRender = Monster->GetRender();
	DestScale = MonsterRender->GetScale();
	MonsterRender->Off();

	std::string Name = Monster->GetName();
	std::string ImagePath = "Battle" + Name + "BackLight.bmp";

	EffectRender = Monster->CreateRender(ImagePath, BattleRenderOrder::CreateEffect);
	EffectRender->SetScale(float4::Zero);
	EffectRender->SetAlpha(200);

	BattleLevel::BattleLevelPtr->CreateActor<Battle_MonsterAppearEffect>(UpdateOrder::Battle_Actors);
	Duration = Battle_MonsterAppearEffect::FadeDuration;

	GameEngineSoundPlayer Sfx = GameEngineResources::GetInst().SoundPlayToControl(BattleDefine::SfxName_BallPop);
	Sfx.LoopCount(1);
	Sfx.Volume(BattleDefine::WorldVolumn);
}

void BattlePlayerMonster_CreateState::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Duration < Timer)
	{
		GetFSM()->ChangeState(BattlePlayerMonster_StateType::Idle);
		return;
	}

	float Ratio = (Timer / Duration);
	float4 NowScale = float4::LerpClamp(float4::Zero, DestScale, Ratio);
	EffectRender->SetScale(NowScale);
}

void BattlePlayerMonster_CreateState::ExitState()
{
	Monster->GetRender()->On();
	EffectRender->Off();
}

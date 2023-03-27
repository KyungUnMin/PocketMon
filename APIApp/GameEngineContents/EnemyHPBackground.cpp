#include "EnemyHPBackground.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
EnemyHPBackground* EnemyHPBackground::EnemyPtr = nullptr;

EnemyHPBackground::EnemyHPBackground()
{
	EnemyPtr = this;
}

EnemyHPBackground::~EnemyHPBackground()
{
	if (this == EnemyPtr)
	{
		EnemyPtr = nullptr;
	}
}


void EnemyHPBackground::Start()
{
	GameEngineRender* RenderPtr = CreateRender("EnemyHPBackground.bmp", BattleRenderOrder::Battle_UI);
	RenderPtr->SetScale((RenderPtr->GetImage()->GetImageScale()));
	RenderPtr->SetPosition({ 280,160 });

	EnemyHPRenderPtr = CreateRender("EnemyHPBar.bmp", BattleRenderOrder::Battle_Text);
	float hp = 100.0f;
	//데미지 / 현재 hp
	float hpcur = 20.0f / 100.0f;
	//hp 배율
	float hpcur11 = 100.0f / 20.0f;

	//데미지
	float damege = GameEngineMath::Lerp(192.0f, 0.0f, hpcur);
	EnemyHPRenderPtr->SetScale(float4{ 192, 172 });
	EnemyHPRenderPtr->SetPosition({ 324, 160 });



	for (int i = 10; i >= 0; i--) {
		EnemyDamegeTick.push_back(damege + ((192.0f - damege)) / 10 * i); /*현재 HP - (데미지 / 10 *)1*/
	}

	EnemyPoketMonName_R.resize(PoketMonNameMax);
	EnemyPoketMonLevel_R.resize(PoketMonLevelMax);

	for (size_t x = 0; x < EnemyPoketMonName_R.size(); x++)
	{
		EnemyPoketMonName_R[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		EnemyPoketMonName_R[x]->SetPosition(EnemyPoketMonName_S + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScale));
		EnemyPoketMonName_R[x]->SetScale(TextRenderImageScale);
		EnemyPoketMonName_R[x]->SetFrame(SpaceFrameNum);
		EnemyPoketMonName_R[x]->EffectCameraOff();



		for (size_t x = 0; x < EnemyPoketMonLevel_R.size(); x++)
		{
			EnemyPoketMonLevel_R[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
			EnemyPoketMonLevel_R[x]->SetPosition(EnemyPoketMonLevel_S + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScale));
			EnemyPoketMonLevel_R[x]->SetScale(TextRenderImageScale);
			EnemyPoketMonLevel_R[x]->SetFrame(SpaceFrameNum);
			EnemyPoketMonLevel_R[x]->EffectCameraOff();




		}


	}

}
void EnemyHPBackground::Update(float _DeltaTime)
{
	
	//일단 현제거 받자
	BattleCommendActor::BattleCommendActorPtr->StringToRender(EnemyPoketMonName_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterName());
	BattleCommendActor::BattleCommendActorPtr->StringToRender(EnemyPoketMonLevel_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterLevel());
	//FriendlyHPBackground::FriendlyPtr->	RenderTick(EnemyHPRenderPtr, EnemyDamegeTick, _DeltaTime,192.0f,9 ,float4{ 324,160 });


	NextTickTime_2 += _DeltaTime;
	if (NextTickTime_2 > 0.1f) {
		NextTickTime_2 = 0;
		if (TickNumber_2 != 10) {
			EnemyHPRenderPtr->SetScale(float4{ EnemyDamegeTick[TickNumber_2], 172 });
			EnemyHPRenderPtr->SetPosition({ 324.0f - (192.0f - EnemyDamegeTick[TickNumber_2]) / 2 , 160.0f });
			TickNumber_2++;
		}
	}
}
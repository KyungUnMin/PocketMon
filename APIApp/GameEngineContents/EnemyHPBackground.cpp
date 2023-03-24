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
}
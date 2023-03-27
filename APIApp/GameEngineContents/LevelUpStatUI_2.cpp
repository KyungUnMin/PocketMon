#include "LevelUpStatUI_2.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

LevelUpStatUI_2* LevelUpStatUI_2::LevelUpStatUIPtr_2 = nullptr;

LevelUpStatUI_2::LevelUpStatUI_2()
{
	LevelUpStatUIPtr_2 = this;
}

LevelUpStatUI_2::~LevelUpStatUI_2()
{
	if (this == LevelUpStatUIPtr_2)
	{
		LevelUpStatUIPtr_2 = nullptr;
	}
}


void LevelUpStatUI_2::Start()
{

	GameEngineRender* StatRenderPtr = CreateRender("BattleStatus.bmp", BattleRenderOrder::Battle_UI);
	StatRenderPtr->SetScale((StatRenderPtr->GetImage()->GetImageScale()));
	StatRenderPtr->SetPosition({ 720,360 });

	GameEngineRender* StatRenderPtr1 = CreateRender("BattleStatusTwo.bmp", BattleRenderOrder::Battle_UI);
	StatRenderPtr1->SetScale((StatRenderPtr1->GetImage()->GetImageScale()));
	StatRenderPtr1->SetPosition({ 320,360 });

	LevelUpStat1_R.resize(PoketMonStatMax);
	LevelUpStat2_R.resize(PoketMonStatMax);
	LevelUpStat3_R.resize(PoketMonStatMax);
	LevelUpStat4_R.resize(PoketMonStatMax);
	LevelUpStat5_R.resize(PoketMonStatMax);
	LevelUpStat6_R.resize(PoketMonStatMax);
	for (size_t x = 0; x < LevelUpStat1_R.size(); x++)
	{
		LevelUpStat1_R[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		LevelUpStat1_R[x]->SetPosition(LevelUpStatPos + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScale));
		LevelUpStat1_R[x]->SetScale(TextRenderImageScale);
		LevelUpStat1_R[x]->SetFrame(SpaceFrameNum);
		LevelUpStat1_R[x]->EffectCameraOff();

	}
	for (size_t x = 0; x < LevelUpStat2_R.size(); x++)
	{
		LevelUpStat2_R[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		LevelUpStat2_R[x]->SetPosition(LevelUpStatPos + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScale));
		LevelUpStat2_R[x]->SetScale(TextRenderImageScale);
		LevelUpStat2_R[x]->SetFrame(SpaceFrameNum);
		LevelUpStat2_R[x]->EffectCameraOff();

	}
	for (size_t x = 0; x < LevelUpStat3_R.size(); x++)
	{
		LevelUpStat3_R[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		LevelUpStat3_R[x]->SetPosition(LevelUpStatPos + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScale));
		LevelUpStat3_R[x]->SetScale(TextRenderImageScale);
		LevelUpStat3_R[x]->SetFrame(SpaceFrameNum);
		LevelUpStat3_R[x]->EffectCameraOff();

	}
	for (size_t x = 0; x < LevelUpStat4_R.size(); x++)
	{
		LevelUpStat4_R[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		LevelUpStat4_R[x]->SetPosition(LevelUpStatPos + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScale));
		LevelUpStat4_R[x]->SetScale(TextRenderImageScale);
		LevelUpStat4_R[x]->SetFrame(SpaceFrameNum);
		LevelUpStat4_R[x]->EffectCameraOff();

	}
	for (size_t x = 0; x < LevelUpStat5_R.size(); x++)
	{
		LevelUpStat5_R[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		LevelUpStat5_R[x]->SetPosition(LevelUpStatPos + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScale));
		LevelUpStat5_R[x]->SetScale(TextRenderImageScale);
		LevelUpStat5_R[x]->SetFrame(SpaceFrameNum);
		LevelUpStat5_R[x]->EffectCameraOff();

	}
	for (size_t x = 0; x < LevelUpStat6_R.size(); x++)
	{
		LevelUpStat6_R[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		LevelUpStat6_R[x]->SetPosition(LevelUpStatPos + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScale));
		LevelUpStat6_R[x]->SetScale(TextRenderImageScale);
		LevelUpStat6_R[x]->SetFrame(SpaceFrameNum);
		LevelUpStat6_R[x]->EffectCameraOff();

	}



}
void LevelUpStatUI_2::Update(float _DeltaTime)
{

	BattleCommendActor::BattleCommendActorPtr->StringToRender(LevelUpStat1_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterMaxHP());
	//BattleCommendActor::BattleCommendActorPtr->StringToRender(LevelUpStat2_R, BattlePlayer::PlayerPtr->GetMonsterDB()->
	//BattleCommendActor::BattleCommendActorPtr->StringToRender(LevelUpStat3_R, BattlePlayer::PlayerPtr->GetMonsterDB()->
	//BattleCommendActor::BattleCommendActorPtr->StringToRender(LevelUpStat4_R, BattlePlayer::PlayerPtr->GetMonsterDB()->
	//BattleCommendActor::BattleCommendActorPtr->StringToRender(LevelUpStat5_R, BattlePlayer::PlayerPtr->GetMonsterDB()->
	//BattleCommendActor::BattleCommendActorPtr->StringToRender(LevelUpStat6_R, BattlePlayer::PlayerPtr->GetMonsterDB()->

}
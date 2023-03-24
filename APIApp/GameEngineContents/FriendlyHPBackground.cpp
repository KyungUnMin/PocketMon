#include "FriendlyHPBackground.h"
#include "BattlePlayer.h"
#include "BattleMonsterPlayer.h"
#include "BattleCommendActor.h"

#include "BattlePlayer.h"
#include "BattleMonsterPlayer.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineBase/GameEngineMath.h>

#include "ContentsEnum.h"


FriendlyHPBackground* FriendlyHPBackground::FriendlyPtr = nullptr;

FriendlyHPBackground::FriendlyHPBackground()
{
	FriendlyPtr = this;
}

FriendlyHPBackground::~FriendlyHPBackground()
{
	if (this == FriendlyPtr)
	{
		FriendlyPtr = nullptr;
	}
}

void FriendlyHPBackground::Start()
{
	GameEngineRender* RenderPtr = CreateRender("FriendlyHPBackground.bmp", BattleRenderOrder::Battle_UI);
	RenderPtr->SetScale((RenderPtr->GetImage()->GetImageScale()));
	RenderPtr->SetPosition({ 480,360 });
	//몬스터의 최대체력과 현제체력 
	// START END Ratio (현재/최대) 

	HPRenderPtr = CreateRender("FriendlyHPBar.bmp", BattleRenderOrder::Battle_Text);
	HPRenderPtr->SetScale((HPRenderPtr->GetImage()->GetImageScale()));
	HPRenderPtr->SetPosition({ 560,360 });
	//러프로 hp바 어떻게해야할까
	//float4::Zero;
	//float4 Xpos = float4::LerpClamp(float4{ 0,0 }, float4{ 192,0 }, (20 / 100));
	//HPRenderPtr->SetScale({ Xpos.x ,static_cast<float>(172) });
	
	/*float AA = GameEngineMath::Lerp(192.0f, 0.0f, (20.0f / 40.0f));
	HPRenderPtr->SetScale(float4{ AA, 172 });
	HPRenderPtr->SetPosition({ 560 - AA/2 , 360 });
	*/

	//예시코드
	//현재 hp
	float hp = 100.0f;
	//데미지 / 현재 hp
	float hpcur = 20.0f / 100.0f;
	//hp 배율
	float hpcur11 = 100.0f / 20.0f;

	//데미지
	float damege = GameEngineMath::Lerp(192.0f, 0.0f, hpcur);
	HPRenderPtr->SetScale(float4{ damege, 172 });
	HPRenderPtr->SetPosition({ 560 - (192.0f-damege) / 2, 360 });
	//DamegeTick.resize(4);







	//for (int i = 3; i >= 0; i--) {
	//	DamegeTick.push_back(damege + ((192.0f-damege))/4*i); /*현재 HP - (데미지 / 4 *)1*/
	//}

	
	PoketMonName_R.resize(PoketMonNameMax);
	PoketMonLevel_R.resize(PoketMonLevelMax);
	PoketMonHPCUR_R.resize(PoketMonLevelMax);
	PoketMonHPMAX_R.resize(PoketMonLevelMax);

	for (size_t x = 0; x < PoketMonName_R.size(); x++)
	{
		PoketMonName_R[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		PoketMonName_R[x]->SetPosition(PoketMonName_S + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScale));
		PoketMonName_R[x]->SetScale(TextRenderImageScale);
		PoketMonName_R[x]->SetFrame(SpaceFrameNum);
		PoketMonName_R[x]->EffectCameraOff();

	}

	for (size_t x = 0; x < PoketMonLevel_R.size(); x++)
	{
		PoketMonLevel_R[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		PoketMonLevel_R[x]->SetPosition(PoketMonLevel_S + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScale));
		PoketMonLevel_R[x]->SetScale(TextRenderImageScale);
		PoketMonLevel_R[x]->SetFrame(SpaceFrameNum);
		PoketMonLevel_R[x]->EffectCameraOff();

	}
	for (size_t x = 0; x < PoketMonHPCUR_R.size(); x++)
	{
		PoketMonHPCUR_R[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		PoketMonHPCUR_R[x]->SetPosition(PoketMonHPCUR_S + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScaleHP));
		PoketMonHPCUR_R[x]->SetScale(TextRenderImageScaleHP);
		PoketMonHPCUR_R[x]->SetFrame(SpaceFrameNum);
		PoketMonHPCUR_R[x]->EffectCameraOff();

	}
	for (size_t x = 0; x < PoketMonHPMAX_R.size(); x++)
	{
		PoketMonHPMAX_R[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		PoketMonHPMAX_R[x]->SetPosition(PoketMonHPMAX_S + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScaleHP));
		PoketMonHPMAX_R[x]->SetScale(TextRenderImageScaleHP);
		PoketMonHPMAX_R[x]->SetFrame(SpaceFrameNum);
		PoketMonHPMAX_R[x]->EffectCameraOff();

	}
}

void FriendlyHPBackground::Update(float _DeltaTime)
{
	BattleCommendActor::BattleCommendActorPtr->StringToRender(PoketMonName_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterName());
	BattleCommendActor::BattleCommendActorPtr->StringToRender(PoketMonLevel_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterLevel());
	BattleCommendActor::BattleCommendActorPtr->StringToRender(PoketMonHPCUR_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterCurrentHP());
	BattleCommendActor::BattleCommendActorPtr->StringToRender(PoketMonHPMAX_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterMaxHP());
	//DamegeTicks(HPRenderPtr, DamegeTick);

}

void FriendlyHPBackground::DamegeTicks(GameEngineRender* _Render , std::vector<float> _Tick)
{
	
	for (size_t x = 0; x < _Tick.size(); x++)
	{

		_Render->SetScale(float4{ _Tick[x], 172});
		_Render->SetPosition({ 560 - (_Tick[x] / 2) , 360 });

	}

}

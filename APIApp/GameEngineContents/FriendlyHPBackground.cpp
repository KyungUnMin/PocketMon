#include "FriendlyHPBackground.h"
#include "BattlePlayer.h"
#include "BattleMonsterPlayer.h"
#include "BattleCommendActor.h"

#include "BattlePlayer.h"
#include "BattleMonsterPlayer.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEnginePlatform/GameEngineInput.h>

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

	HPRenderPtr = CreateRender("FriendlyHPBar.bmp", BattleRenderOrder::Battle_Text);
	EXPRenderPtr = CreateRender("FriendlyHPExp.bmp", BattleRenderOrder::Battle_Text);

	
	if (false == GameEngineInput::IsKey("HpDebug111"))
	{

		GameEngineInput::CreateKey("HpDebug111", 'Z');
	}
	//예시코드

	float hpcur = 100.0f / 100.0f;


	//데미지
	float damege = GameEngineMath::Lerp(192.0f, 0.0f, hpcur);
	HPRenderPtr->SetScale(float4{ 192, 172 });
	HPRenderPtr->SetPosition({ 560, 360 });



	float ExpNum = GameEngineMath::Lerp(0.0f, 256.0f, hpcur);

	/*EXPRenderPtr->SetScale(float4{ 256,172 });
	EXPRenderPtr->SetPosition({ 528 , 360 });
*/

	EXPRenderPtr->SetScale(float4{ 0,172 });
	EXPRenderPtr->SetPosition({ 528- (256-ExpNum)/2, 380 });


	//for (int i = 10; i >= 1; i--) {
	//	
	//	DamegeTick.push_back(damege + ((192.0f-damege))/ 10 *i); /*현재 HP - (데미지 / 10 *)1*/
	//	
	//}
	/*if (damege == 0) {
		DamegeTick[9] = damege;
	}*/
	for (int i = 1; i <= 10; i++) {
		EXPTick.push_back((ExpNum / 10) * i);
	}
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
	PokeDataBase* DB = BattlePlayer::PlayerPtr->GetMonsterDB();
	if (nullptr == DB)
		return;

	BattleCommendActor::BattleCommendActorPtr->StringToRender(PoketMonName_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterName());
	BattleCommendActor::BattleCommendActorPtr->StringToRender(PoketMonLevel_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterLevel());
	BattleCommendActor::BattleCommendActorPtr->StringToRender(PoketMonHPCUR_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterCurrentHP());
	BattleCommendActor::BattleCommendActorPtr->StringToRender(PoketMonHPMAX_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterMaxHP());
	//RenderTick(HPRenderPtr, DamegeTick, _DeltaTime, 192.0f, 9, float4{ 560,360 });
//	RenderTick(HPRenderPtr, EXPTick, _DeltaTime, 256.0f, 9, float4{ 528,360 });
	HpUpdate(EnumyMonsterDamage, BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterCurrentHP());
	//	HpUpdate(20.0f, 100.0f);


	if (BattleStartCheck == true) {
		NextTickTime += _DeltaTime;
		if (NextTickTime > 0.1f) {
			NextTickTime = 0;
			if (TickNumber != 10) {
				HPRenderPtr->SetScale(float4{ DamegeTick[TickNumber], 172 });
				HPRenderPtr->SetPosition({ 560.0f - (192.0f - DamegeTick[TickNumber]) / 2 , 360.0f });
				TickNumber++;
			}
		}

		NextTickTime_1 += _DeltaTime;
		if (NextTickTime_1 > 0.1f) {
			NextTickTime_1 = 0;
			if (TickNumber_1 != 10) {
				EXPRenderPtr->SetScale(float4{ EXPTick[TickNumber_1], 172 });
				EXPRenderPtr->SetPosition({ 528.0f - (256.0f - EXPTick[TickNumber_1]) / 2 , 360.0f });
				TickNumber_1++;
			}
		}
		if (TickNumber == 10 && TickNumber_1 == 10) {
			BattleStartCheck = false;
			CurHpRender(HPRenderPtr, DamegeTick);

		}
	}
}


void FriendlyHPBackground::Render(float _DeltaTime)
{
	
}

void FriendlyHPBackground::CurHpRender(GameEngineRender* _Render, std::vector<float> _Tick)
{
	_Render->SetScale(float4{ _Tick[9], 172 });
	_Render->SetPosition({ 560.0f - (192.0f - _Tick[9]) / 2 , 360.0f });
	Clear(DamegeTick);

}

void FriendlyHPBackground::Clear(std::vector<float> _Tick)
{
	_Tick.erase(_Tick.begin(), _Tick.end());
	int a = 0;
}



void FriendlyHPBackground::HpUpdate(float _EnumyMonsterDamage , float _MyCurHp)
{
	float Hpmag = _EnumyMonsterDamage / _MyCurHp;
	float damege = GameEngineMath::Lerp(192.0f, 0.0f, Hpmag);

	for (int i = 10; i >= 1; i--) {

		DamegeTick.push_back(damege + ((192.0f - damege)) / 10 * i); /*현재 HP - (데미지 / 10 *)1*/

	}
	CurMyHP = DamegeTick[9];

}



bool FriendlyHPBackground::IsBattleStartCheck(bool _Value)
{
	BattleStartCheck = _Value;
	return BattleStartCheck;
}

float FriendlyHPBackground::GetMonsterDamage(int _EnumyMonsterDamage)
{
	EnumyMonsterDamage = _EnumyMonsterDamage;
	return EnumyMonsterDamage;
}



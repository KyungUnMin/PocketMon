#include "BattleCommendActor.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnum.h"
BattleCommendActor::BattleCommendActor()
{
}

BattleCommendActor::~BattleCommendActor()
{

}
void BattleCommendActor::Start()
{
	SetPos({ 480,540 });
	GameEngineRender* RenderPtr = CreateRender("BattleCommend.bmp", BattleRenderOrder::Battle_UI);
	RenderPtr->SetScale((RenderPtr->GetImage()->GetImageScale()));

	BattleArrowRender = CreateRender("Battle_Arrow.bmp", RenderOrder::Battle_Cursor);
	BattleArrowRender->SetScale((BattleArrowRender->GetImage()->GetImageScale()));

	BattleArrowRender->SetPosition({ -430,-25 }); // y값은 -25 40 고정 


	PoketMonSkill_R1.resize(SkillLineMax);
	PoketMonSkill_R2.resize(SkillLineMax);
	PoketMonSkill_R3.resize(SkillLineMax);
	PoketMonSkill_R4.resize(SkillLineMax);
	PPCUR_R.resize(PPLineMax);
	PPMAX_R.resize(PPLineMax);
	TYPE_R.resize(TypeLineMax);
	
	//SetAndResize(PoketMonSkill_R1, OneTextRenderPos);
	//SetAndResize(PoketMonSkill_R2, TwoTextRenderPos);
	//SetAndResize(PoketMonSkill_R3, ThreeRenderPos);
	//SetAndResize(PoketMonSkill_R4, FourTextRenderPos);

	//SKILL
	for (size_t x = 0; x < PoketMonSkill_R1.size(); x++)
	{
		PoketMonSkill_R1[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		PoketMonSkill_R1[x]->SetPosition(OneTextRenderPos_S + float4{ static_cast<float>(x) } *(TextRenderInterval + SkillTextRenderImageScale));
		PoketMonSkill_R1[x]->SetScale(SkillTextRenderImageScale);
		PoketMonSkill_R1[x]->SetFrame(SpaceFrameNum);
		PoketMonSkill_R1[x]->EffectCameraOff();
	}

	for (size_t x = 0; x < PoketMonSkill_R2.size(); x++)
	{
		PoketMonSkill_R2[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		PoketMonSkill_R2[x]->SetPosition(TwoTextRenderPos_S + float4{ static_cast<float>(x) } *(TextRenderInterval + SkillTextRenderImageScale));
		PoketMonSkill_R2[x]->SetScale(SkillTextRenderImageScale);
		PoketMonSkill_R2[x]->SetFrame(SpaceFrameNum);
		PoketMonSkill_R2[x]->EffectCameraOff();
	}

	for (size_t x = 0; x < PoketMonSkill_R3.size(); x++)
	{
		PoketMonSkill_R3[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		PoketMonSkill_R3[x]->SetPosition(ThreeRenderPos_S + float4{ static_cast<float>(x) } *(TextRenderInterval + SkillTextRenderImageScale));
		PoketMonSkill_R3[x]->SetScale(SkillTextRenderImageScale);
		PoketMonSkill_R3[x]->SetFrame(SpaceFrameNum);
		PoketMonSkill_R3[x]->EffectCameraOff();
	}

	for (size_t x = 0; x < PoketMonSkill_R4.size(); x++)
	{
		PoketMonSkill_R4[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		PoketMonSkill_R4[x]->SetPosition(FourTextRenderPos_S + float4{ static_cast<float>(x) } *(TextRenderInterval + SkillTextRenderImageScale));
		PoketMonSkill_R4[x]->SetScale(SkillTextRenderImageScale);
		PoketMonSkill_R4[x]->SetFrame(SpaceFrameNum);
		PoketMonSkill_R4[x]->EffectCameraOff();
	}


	//PP
	for (size_t x = 0; x < PPCUR_R.size(); x++)
	{
		PPCUR_R[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		PPCUR_R[x]->SetPosition(PPCurRenderPos_S + float4{ static_cast<float>(x) } *(TextRenderInterval + PPTextRenderImageScale));
		PPCUR_R[x]->SetScale(PPTextRenderImageScale);
		PPCUR_R[x]->SetFrame(SpaceFrameNum);
		PPCUR_R[x]->EffectCameraOff();
	}

	for (size_t x = 0; x < PPMAX_R.size(); x++)
	{
		PPMAX_R [x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		PPMAX_R [x]->SetPosition(PPMaxRenderPos_S + float4{ static_cast<float>(x) } *(TextRenderInterval + PPTextRenderImageScale));
		PPMAX_R [x]->SetScale(PPTextRenderImageScale);
		PPMAX_R [x]->SetFrame(SpaceFrameNum);
		PPMAX_R [x]->EffectCameraOff();
	}
	//TYPE
	for (size_t x = 0; x < TYPE_R.size(); x++)
	{
		TYPE_R[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
		TYPE_R[x]->SetPosition(TypeRenderPos_S + float4{ static_cast<float>(x) } *(TextRenderInterval + PPTextRenderImageScale));
		TYPE_R[x]->SetScale(PPTextRenderImageScale);
		TYPE_R[x]->SetFrame(SpaceFrameNum);
		TYPE_R[x]->EffectCameraOff();
	}

}

void BattleCommendActor::Update(float _DeltaTime)
{
	B_ArrowNumberCheck();

	if (B_ArrowCheckNum == 0) {
		BattleArrowRender->SetPosition({ -430,-25 });
	}
	if (B_ArrowCheckNum == 1) {
		BattleArrowRender->SetPosition({ -170,-25 });
	}
	if (B_ArrowCheckNum == 2) {
		BattleArrowRender->SetPosition({ -430,40 });
	}
	if (B_ArrowCheckNum == 3) {
		BattleArrowRender->SetPosition({ -170,40 });
	}

	//SKILL
	StringToRender(PoketMonSkill_R1);
	StringToRender(PoketMonSkill_R2);
	StringToRender(PoketMonSkill_R3);
	StringToRender(PoketMonSkill_R4);
	//PP
	StringToRender(PPCUR_R);
	StringToRender(PPMAX_R);
	StringToRender(TYPE_R);
}


void BattleCommendActor::B_ArrowNumberCheck()
{
	if (B_ArrowCheckNum == 1 || B_ArrowCheckNum == 3) {
		if (true == GameEngineInput::IsDown("LeftMove")) {
			B_ArrowCheckNum -= 1;
		}
	}
	if (B_ArrowCheckNum == 0 || B_ArrowCheckNum == 2) {
		if (true == GameEngineInput::IsDown("RightMove")) {
			B_ArrowCheckNum += 1;
		}
	}
	if (B_ArrowCheckNum == 2 || B_ArrowCheckNum == 3) {
		if (true == GameEngineInput::IsDown("UpMove")) {
			B_ArrowCheckNum -= 2;
		}
	}
	if (B_ArrowCheckNum == 0 || B_ArrowCheckNum == 1) {
		if (true == GameEngineInput::IsDown("DownMove")) {
			B_ArrowCheckNum += 2;
		}
	}
}

void BattleCommendActor::B_ArrowInput(int _Number)
{
	if (true == GameEngineInput::IsDown("InsertMove1") && _Number == 0) {

		// 대사가 나오며 전투쪽으로 무슨 값 전달하기
	}
	if (true == GameEngineInput::IsDown("InsertMove1") && _Number == 1) {

		// 대사가 나오며 전투쪽으로 무슨 값 전달하기

	}
	if (true == GameEngineInput::IsDown("InsertMove1") && _Number == 2) {

		// 대사가 나오며 전투쪽으로 무슨 값 전달하기

	}
	if (true == GameEngineInput::IsDown("InsertMove1") && _Number == 3) {

		// 대사가 나오며 전투쪽으로 무슨 값 전달하기

	}
}


//void BattleCommendActor::SetAndResize(std::vector<GameEngineRender*> _Render,  float4 _Pos)
//{
//
//	for (size_t x = 0; x < _Render.size(); x++)
//	{
//		_Render[x] = CreateRender("Font_Dialog.bmp", BattleRenderOrder::Battle_Text);
//		_Render[x]->SetPosition(_Pos + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScale));
//		_Render[x]->SetScale(TextRenderImageScale);
//		_Render[x]->SetFrame(SpaceFrameNum);
//		_Render[x]->EffectCameraOff();
//	}
//
//}

void BattleCommendActor::StringToRender(std::vector<GameEngineRender*> _Render)
{

	for (size_t x = 0; x < _Render.size(); x++) {
		_Render[x]->SetFrame(1);
	}
}


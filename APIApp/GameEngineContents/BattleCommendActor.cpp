#include "BattleCommendActor.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnum.h"

BattleCommendActor* BattleCommendActor::BattleCommendActorPtr = nullptr;

BattleCommendActor::BattleCommendActor()
{
	BattleCommendActorPtr = this;
}

BattleCommendActor::~BattleCommendActor()
{
	if (this == BattleCommendActorPtr)
	{
		BattleCommendActorPtr = nullptr;
	}
}
void BattleCommendActor::Start()
{
	SetPos({ 480,545 });
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
	if (true == IsSelected)
		return;

	B_ArrowNumberCheck();

	if (B_ArrowCheckNum == 0) {
		BattleArrowRender->SetPosition({ -430,-25 });
		StringToRender(PPCUR_R, BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterSkillList(1).ForUI_GetCurrentSkillPowerPoint());
		StringToRender(PPMAX_R, BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterSkillList(1).ForUI_GetMaxSkillPowerPoint());
	}
	if (B_ArrowCheckNum == 1) {
		BattleArrowRender->SetPosition({ -170,-25 });
		StringToRender(PPCUR_R, BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterSkillList(2).ForUI_GetCurrentSkillPowerPoint());
		StringToRender(PPMAX_R, BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterSkillList(2).ForUI_GetMaxSkillPowerPoint());
	}																						 
	if (B_ArrowCheckNum == 2) {
		BattleArrowRender->SetPosition({ -430,40 });
		StringToRender(PPCUR_R, BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterSkillList(3).ForUI_GetCurrentSkillPowerPoint());
		StringToRender(PPMAX_R, BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterSkillList(3).ForUI_GetMaxSkillPowerPoint());
	}
	if (B_ArrowCheckNum == 3) {
		BattleArrowRender->SetPosition({ -170,40 });										 
		StringToRender(PPCUR_R, BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterSkillList(4).ForUI_GetCurrentSkillPowerPoint());
		StringToRender(PPMAX_R, BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterSkillList(4).ForUI_GetMaxSkillPowerPoint());
	}
	//SKILL
	StringToRender(PoketMonSkill_R1 , BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterSkillList(1).ForUI_GetSkillName());
	StringToRender(PoketMonSkill_R2, BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterSkillList(2).ForUI_GetSkillName());
	StringToRender(PoketMonSkill_R3, BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterSkillList(3).ForUI_GetSkillName());
	StringToRender(PoketMonSkill_R4, BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterSkillList(4).ForUI_GetSkillName());
	
	//StringToRender(PPCUR_R, CURPP);
	//StringToRender(PPMAX_R, MAXPP);
	StringToRender(TYPE_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterTypeName());

	B_ArrowInput();
}


void BattleCommendActor::B_ArrowNumberCheck()
{
	if (B_ArrowCheckNum == 1 || B_ArrowCheckNum == 3) {
		if (true == GameEngineInput::IsDown("LeftMove")) {
			NextInputSOUND();
			B_ArrowCheckNum -= 1;
		}
	}
	if (B_ArrowCheckNum == 0 || B_ArrowCheckNum == 2) {
		if (true == GameEngineInput::IsDown("RightMove")) {
			NextInputSOUND();
			B_ArrowCheckNum += 1;
		}
	}
	if (B_ArrowCheckNum == 2 || B_ArrowCheckNum == 3) {
		if (true == GameEngineInput::IsDown("UpMove")) {
			NextInputSOUND();
			B_ArrowCheckNum -= 2;
		}
	}
	if (B_ArrowCheckNum == 0 || B_ArrowCheckNum == 1) {
		if (true == GameEngineInput::IsDown("DownMove")) {
			NextInputSOUND();
			B_ArrowCheckNum += 2;
		}
	}
}

void BattleCommendActor::B_ArrowInput(/*int _Number*/)
{
	if (false == GameEngineInput::IsDown("BattleSelect1111"))
		return;

	if (nullptr == CallBacks[B_ArrowCheckNum])
		return;

	NextInputSOUND();
	CallBacks[B_ArrowCheckNum]();
	IsSelected = true;
	
	//if (true == GameEngineInput::IsDown("InsertMove1") && _Number == 0) {
	//	int a = 10;
	//	// 대사가 나오며 전투쪽으로 무슨 값 전달하기
	//}
	//if (true == GameEngineInput::IsDown("InsertMove1") && _Number == 1) {
	//	int a = 10;
	//	// 대사가 나오며 전투쪽으로 무슨 값 전달하기

	//}
	//if (true == GameEngineInput::IsDown("InsertMove1") && _Number == 2) {
	//	int a = 10;
	//	// 대사가 나오며 전투쪽으로 무슨 값 전달하기

	//}
	//if (true == GameEngineInput::IsDown("InsertMove1") && _Number == 3) {
	//	int a = 10;
	//	// 대사가 나오며 전투쪽으로 무슨 값 전달하기

	//}
}



void BattleCommendActor::StringToRender(std::vector<GameEngineRender*> _Render ,std::string_view _Str)
{
	size_t StrEndIndex = _Str.size() - 1;
	int StrIndex = 0;
	std::string Str = _Str.data();
	
		for (size_t x = 0; x < _Render.size(); x++)
		{
			if (StrEndIndex < StrIndex || ' ' == Str[StrIndex])
			{
				_Render[x]->SetFrame(SpaceFrameNum);
			}
			else
			{
				if (Str[StrIndex] >= 'A' && Str[StrIndex] <= 'Z')
				{
					_Render[x]->SetFrame(Str[StrIndex] - 'A');
				}
				else if (Str[StrIndex] >= 'a' && Str[StrIndex] <= 'z')
				{
					_Render[x]->SetFrame(Str[StrIndex] - 'a' + 27);
				}
				else if (Str[StrIndex] >= '0' && Str[StrIndex] <= '9')
				{
					_Render[x]->SetFrame(Str[StrIndex] - '0' + 54);
				}
				else if (Str[StrIndex] == '\n')
				{
					while (x < _Render.size())
					{
						_Render[x]->SetFrame(SpaceFrameNum);
						x++;
					}
				}
				else
				{
					switch (Str[StrIndex])
					{
					case '!':
						_Render[x]->SetFrame(81);
						break;
					case '?':
						_Render[x]->SetFrame(82);
						break;
					case '/':
						_Render[x]->SetFrame(85);
						break;
					case '-':
						_Render[x]->SetFrame(86);
						break;
						//case '…':
						//	TextRender[y][x]->SetFrame(91);
						//	break;
					case '.':
						_Render[x]->SetFrame(92);
						break;
					case ',':
						_Render[x]->SetFrame(93);
						break;
					case '@':
						_Render[x]->SetFrame(94);
						break;
					default:
						MsgAssert("아직 생각해보지 않은 글자입니다.");
						break;
					}
				}
			}
			StrIndex++;
		}
	

}




void BattleCommendActor::NextInputSOUND()
{
	B_NextInputSOUND = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	B_NextInputSOUND.Volume(1.0f);
	B_NextInputSOUND.LoopCount(1);
}








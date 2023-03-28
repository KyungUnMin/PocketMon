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

	StringToRender(LevelUpStat1_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterMaxHP());
	//BattleCommendActor::BattleCommendActorPtr->StringToRender(LevelUpStat2_R, BattlePlayer::PlayerPtr->GetMonsterDB()->
	//BattleCommendActor::BattleCommendActorPtr->StringToRender(LevelUpStat3_R, BattlePlayer::PlayerPtr->GetMonsterDB()->
	//BattleCommendActor::BattleCommendActorPtr->StringToRender(LevelUpStat4_R, BattlePlayer::PlayerPtr->GetMonsterDB()->
	//BattleCommendActor::BattleCommendActorPtr->StringToRender(LevelUpStat5_R, BattlePlayer::PlayerPtr->GetMonsterDB()->
	//BattleCommendActor::BattleCommendActorPtr->StringToRender(LevelUpStat6_R, BattlePlayer::PlayerPtr->GetMonsterDB()->

}

void LevelUpStatUI_2::StringToRender(std::vector<GameEngineRender*> _Render, std::string_view _Str)
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

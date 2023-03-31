#include "FriendlyHPBackground.h"
#include "BattlePlayer.h"
#include "BattleMonsterPlayer.h"
#include "BattleCommendActor.h"

#include "BattlePlayer.h"
#include "BattleMonsterPlayer.h"
#include "BattleEnemy.h"

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
	RenderPtr = CreateRender("FriendlyHPBackground.bmp", BattleRenderOrder::Battle_UI);
	RenderPtr->SetScale((RenderPtr->GetImage()->GetImageScale()));
	RenderPtr->SetPosition({ 480,360 });

	HPRenderPtr = CreateRender("FriendlyHPBar.bmp", BattleRenderOrder::Battle_Text);
	EXPRenderPtr = CreateRender("FriendlyHPExp.bmp", BattleRenderOrder::Battle_Text);


	if (false == GameEngineInput::IsKey("HpDebug111"))
	{

		GameEngineInput::CreateKey("HpDebug111", 'Z');
	}
	HPRenderPtr->SetScale(float4{ 192.0f - FirstHp, 172 });
	HPRenderPtr->SetPosition({ 560 - (FirstHp)/2, 360 });
	
	float hpcur = BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterExperience() / 100.0f;
	float ExpNum = GameEngineMath::Lerp(0.0f, 256.0f, hpcur);
	EXPRenderPtr->SetScale(float4{ ExpNum,172 });
	EXPRenderPtr->SetPosition({ 528- (256-ExpNum)/2, 360 });

	PoketMonName_R.resize(PoketMonNameMax);
	PoketMonLevel_R.resize(PoketMonLevelMax);
	PoketMonHPCUR_R.resize(PoketMonLevelMax);
	PoketMonHPMAX_R.resize(PoketMonLevelMax);

	for (size_t x = 0; x < PoketMonName_R.size(); x++)
	{
		PoketMonName_R[x] = CreateRender("Font_Dialog_Black2.bmp", BattleRenderOrder::Battle_Text);
		PoketMonName_R[x]->SetPosition(PoketMonName_S + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScale));
		PoketMonName_R[x]->SetScale(TextRenderImageScale);
		PoketMonName_R[x]->SetFrame(SpaceFrameNum);
		PoketMonName_R[x]->EffectCameraOff();

	}

	for (size_t x = 0; x < PoketMonLevel_R.size(); x++)
	{
		PoketMonLevel_R[x] = CreateRender("Font_Dialog_Black2.bmp", BattleRenderOrder::Battle_Text);
		PoketMonLevel_R[x]->SetPosition(PoketMonLevel_S + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScale));
		PoketMonLevel_R[x]->SetScale(TextRenderImageScale);
		PoketMonLevel_R[x]->SetFrame(SpaceFrameNum);
		PoketMonLevel_R[x]->EffectCameraOff();

	}
	for (size_t x = 0; x < PoketMonHPCUR_R.size(); x++)
	{
		PoketMonHPCUR_R[x] = CreateRender("Font_Dialog_Black2.bmp", BattleRenderOrder::Battle_Text);
		PoketMonHPCUR_R[x]->SetPosition(PoketMonHPCUR_S + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScaleHP));
		PoketMonHPCUR_R[x]->SetScale(TextRenderImageScaleHP);
		PoketMonHPCUR_R[x]->SetFrame(SpaceFrameNum);
		PoketMonHPCUR_R[x]->EffectCameraOff();

	}
	for (size_t x = 0; x < PoketMonHPMAX_R.size(); x++)
	{
		PoketMonHPMAX_R[x] = CreateRender("Font_Dialog_Black2.bmp", BattleRenderOrder::Battle_Text);
		PoketMonHPMAX_R[x]->SetPosition(PoketMonHPMAX_S + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScaleHP));
		PoketMonHPMAX_R[x]->SetScale(TextRenderImageScaleHP);
		PoketMonHPMAX_R[x]->SetFrame(SpaceFrameNum);
		PoketMonHPMAX_R[x]->EffectCameraOff();

	}
	 SecoundHp = 192.0f - FirstHp;

}
void FriendlyHPBackground::Update(float _DeltaTime)
{
	PokeDataBase* DB = BattlePlayer::PlayerPtr->GetMonsterDB();
	if (nullptr == DB)
		return;



	// 임시로 디버깅용 현재 경험치 넣어주기 및 초깃값 셋팅
	CurExp = BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterExperience();


	StringToRender(PoketMonName_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterName());
	StringToRender(PoketMonLevel_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterLevel());
	StringToRender(PoketMonHPCUR_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterCurrentHP());
	StringToRender(PoketMonHPMAX_R, BattlePlayer::PlayerPtr->GetMonsterDB()->ForUI_GetMonsterMaxHP());


	float hpcur = BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterExperience() / 100.0f;
	float ExpNum = GameEngineMath::Lerp(0.0f, 256.0f, hpcur);


	if (true == IsExpUP)
	{
	
		NextTickTime_1 += _DeltaTime;
		if (NextTickTime_1 > 0.1f) 
		{
			NextTickTime_1 = 0;
			if (TickNumber_1 != 20)
			{
				if (TickNumber_1 == 0) 
				{
					ExpUpdate(50.0f + BattleEnemy::EnemyPtr->GetMonsterDB()->GetMonsterLevel_float(), static_cast<float>(BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterExperience()), CurMyExpPos, ExpNum);
				}
				EXPRenderPtr->SetScale(float4{ EXPTick[TickNumber_1], 172 });
				EXPRenderPtr->SetPosition({ 528.0f - (256.0f - EXPTick[TickNumber_1]) / 2 , 360.0f });
				TickNumber_1++;
			}
			if (TickNumber_1 == 20)
			{
				TickNumber_1 = 0;
				BattlePlayer::PlayerPtr->GetMonsterDB()->PlusMonsterExperience(static_cast<int>(50.0f + BattleEnemy::EnemyPtr->GetMonsterDB()->GetMonsterLevel_float()));
				IsExpUP = false;
			//	CurMyHP = DamegeTick[9];

			}

		
		}
	}


	if (BattleStartCheck == true) {


		if(TickNumber ==0)
		{
		
			HpUpdate(static_cast<float>(EnumyMonsterDamage), Num/*static_cast<float>(BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterCurrentHP()*/, SecoundHp);
		}
		NextTickTime += _DeltaTime;
		if (NextTickTime > 0.1f) {
			NextTickTime = 0;
			if (TickNumber != 10) {
				HPRenderPtr->SetScale(float4{ DamegeTick[TickNumber], 172 });
				HPRenderPtr->SetPosition({ 560.0f - (192.0f - DamegeTick[TickNumber]) / 2 , 360.0f });
				TickNumber++;
			}
		}
		
		
		if (TickNumber == 10 ) {
			TickNumber = 0;
			BattleStartCheck = false;
			Num -= static_cast<float>(EnumyMonsterDamage);
			SecoundHp = DamegeTick[9];
			if (true == IsLevelUp) {

			}
		}
		
	}
}


void FriendlyHPBackground::Render(float _DeltaTime)
{
	
}

void FriendlyHPBackground::CurHpRender(GameEngineRender* _Render, float _hp)
{
	_Render->SetScale(float4{ _hp, 172 });
	_Render->SetPosition({ 560.0f - (192.0f - _hp) / 2 , 360.0f });

}

void FriendlyHPBackground::Clear(std::vector<float> _Tick)
{
	_Tick.erase(_Tick.begin(), _Tick.end());
}


void FriendlyHPBackground::StringToRender(std::vector<GameEngineRender*> _Render, std::string_view _Str)
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


void FriendlyHPBackground::HpUpdate(float _EnumyMonsterDamage , float _MyCurHp , float _curpos )
{
	DamegeTick.clear();
	float Hpmag = _EnumyMonsterDamage / _MyCurHp;
	float damege = GameEngineMath::Lerp(_curpos, 0.0f, Hpmag);
	for (int i = 10; i >= 1; i--) {

		DamegeTick.push_back(damege + ((_curpos - damege)) / 10 * i); /*현재 HP - (데미지 / 10 *)1*/

	}

}

void FriendlyHPBackground::ExpUpdate(float _GetExp, float _MyCurExp, float _curpos, float _CurExpPos)
{

	float Expmag = _GetExp / (100.0f - _MyCurExp);
	/*if (Expmag>=1.0f)*/

	float UpExp = GameEngineMath::Lerp(0.0f, _curpos + _CurExpPos, Expmag);
	for (int i = 1; i <= 20; i++) {

		EXPTick.push_back(_CurExpPos +(UpExp / 20 )* i); /*현재 HP - (데미지 / 10 *)1*/
		

	}
	int j = 1;

	for (size_t x = 0; x < EXPTick.size(); x++) {
		if (EXPTick[x] > 256.0f) {
		
			for (size_t z = x; z < EXPTick.size(); z++) {
				if (_GetExp + _MyCurExp > 100.0f) {
					IsLevelUp = true;
					float MAXExpmag = (_GetExp + _MyCurExp - 100.0f) / 100.0f;
					float UpExp = GameEngineMath::Lerp(0.0f, 256.0f, MAXExpmag);
					EXPTick[z] = UpExp / (EXPTick.size() - x) * j;
					j++;
				}
			}
			
		}
	}

}



bool FriendlyHPBackground::IsBattleStartCheck(bool _Value)
{
	BattleStartCheck = _Value;
	return BattleStartCheck;
}

bool FriendlyHPBackground::IsExpUpCheck(bool _Value)
{
	IsExpUP = _Value;
	return IsExpUP;
}

int FriendlyHPBackground::GetMonsterDamage(int _EnumyMonsterDamage)
{
	EnumyMonsterDamage = _EnumyMonsterDamage;
	return EnumyMonsterDamage;
}

int FriendlyHPBackground::GetExpPoint(int _ExpPoint)
{
	ExpPoint = _ExpPoint;
	return ExpPoint;
}



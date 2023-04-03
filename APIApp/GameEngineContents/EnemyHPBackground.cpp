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
	RenderPtr = CreateRender("EnemyHPBackground.bmp", BattleRenderOrder::Battle_UI);
	RenderPtr->SetScale((RenderPtr->GetImage()->GetImageScale()));
	RenderPtr->SetPosition({ 280,160 });

	EnemyHPRenderPtr = CreateRender("EnemyHPBar.bmp", BattleRenderOrder::Battle_Text);
	EnemyHPRenderPtr1 = CreateRender("EnemyHP50Bar.bmp", BattleRenderOrder::Battle_Text);
	EnemyHPRenderPtr2 = CreateRender("EnemyHP30Bar.bmp", BattleRenderOrder::Battle_Text);


	if (MyCurHpNum < Hp50Under && MyCurHpNum> Hp30Under) {

		EnemyHPRenderPtr1->SetScale(float4{ MyCurHpNum, 172 });
		EnemyHPRenderPtr1->SetPosition({ 560 - (FirstHp) / 2, 360 });
	}
	else if (MyCurHpNum < Hp30Under) {
		EnemyHPRenderPtr2->SetScale(float4{ MyCurHpNum, 172 });
		EnemyHPRenderPtr2->SetPosition({ 560 - (FirstHp) / 2, 360 });
	}
	else {
		EnemyHPRenderPtr->SetScale(float4{ MyCurHpNum, 172 });
		EnemyHPRenderPtr->SetPosition({ 560 - (FirstHp) / 2, 360 });
	}


	EnemyHPRenderPtr->SetScale(float4{ 192, 172 });
	EnemyHPRenderPtr->SetPosition({ 324, 160 });



	EnemyHPRenderPtr->EffectCameraOff();
	EnemyHPRenderPtr1->EffectCameraOff();
	EnemyHPRenderPtr2->EffectCameraOff();

	EnemyPoketMonName_R.resize(PoketMonNameMax);
	EnemyPoketMonLevel_R.resize(PoketMonLevelMax);

	for (size_t x = 0; x < EnemyPoketMonName_R.size(); x++)
	{
		EnemyPoketMonName_R[x] = CreateRender("Font_Dialog_Black2.bmp", BattleRenderOrder::Battle_Text);
		EnemyPoketMonName_R[x]->SetPosition(EnemyPoketMonName_S + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScale));
		EnemyPoketMonName_R[x]->SetScale(TextRenderImageScale);
		EnemyPoketMonName_R[x]->SetFrame(SpaceFrameNum);
		EnemyPoketMonName_R[x]->EffectCameraOff();



		for (size_t x = 0; x < EnemyPoketMonLevel_R.size(); x++)
		{
			EnemyPoketMonLevel_R[x] = CreateRender("Font_Dialog_Black2.bmp", BattleRenderOrder::Battle_Text);
			EnemyPoketMonLevel_R[x]->SetPosition(EnemyPoketMonLevel_S + float4{ static_cast<float>(x) } *(TextRenderInterval + TextRenderImageScale));
			EnemyPoketMonLevel_R[x]->SetScale(TextRenderImageScale);
			EnemyPoketMonLevel_R[x]->SetFrame(SpaceFrameNum);
			EnemyPoketMonLevel_R[x]->EffectCameraOff();




		}


	}
	SecoundHp = 192.0f - FirstHp;


}
void EnemyHPBackground::Update(float _DeltaTime)
{
	PokeDataBase* DB = BattlePlayer::PlayerPtr->GetMonsterDB();
	if (nullptr == DB)
		return;

	StringToRender(EnemyPoketMonName_R, BattleEnemy::EnemyPtr->GetMonsterDB()->ForUI_GetMonsterName());
	StringToRender(EnemyPoketMonLevel_R, BattleEnemy::EnemyPtr->GetMonsterDB()->ForUI_GetMonsterLevel());
	//FriendlyHPBackground::FriendlyPtr->	RenderTick(EnemyHPRenderPtr, EnemyDamegeTick, _DeltaTime,192.0f,9 ,float4{ 324,160 });

	if (BattleStartCheck==true)
	{
		if (TickNumber_2 == 0) {
			HpUpdate(FrinedMonsterDamage, Num, SecoundHp);

		}
		NextTickTime_2 += _DeltaTime;
			if (NextTickTime_2 > 0.1f) {
				NextTickTime_2 = 0;
				if (TickNumber_2 != 10) {

					if (EnemyDamegeTick[TickNumber_2] < Hp50Under && EnemyDamegeTick[TickNumber_2]>Hp30Under) {
						EnemyHPRenderPtr->Off();
						EnemyHPRenderPtr1->SetScale(float4{ EnemyDamegeTick[TickNumber_2], 172 });
						EnemyHPRenderPtr1->SetPosition({ 324.0f - (192.0f - EnemyDamegeTick[TickNumber_2]) / 2 , 160.0f });
					}
					if (EnemyDamegeTick[TickNumber_2] < Hp30Under) {
						EnemyHPRenderPtr1->Off();
						EnemyHPRenderPtr2->SetScale(float4{ EnemyDamegeTick[TickNumber_2], 172 });
						EnemyHPRenderPtr2->SetPosition({ 324.0f - (192.0f - EnemyDamegeTick[TickNumber_2]) / 2 , 160.0f });
					}
					EnemyHPRenderPtr->SetScale(float4{ EnemyDamegeTick[TickNumber_2], 172 });
					EnemyHPRenderPtr->SetPosition({ 324.0f - (192.0f - EnemyDamegeTick[TickNumber_2]) / 2 , 160.0f });
					TickNumber_2++;
				}
			}
			if (TickNumber_2 == 10) {
				TickNumber_2 = 0;
				BattleStartCheck = false;
				Num -= static_cast<float>(FrinedMonsterDamage);
				SecoundHp = EnemyDamegeTick[9];


			}
	}
}

void EnemyHPBackground::StringToRender(std::vector<GameEngineRender*> _Render, std::string_view _Str)
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

void EnemyHPBackground::Clear(std::vector<float> _Tick)
{
	_Tick.erase(_Tick.begin(), _Tick.end());
}



bool EnemyHPBackground::IsBattleStartCheck(bool _Value)
{
	BattleStartCheck = _Value;
	return BattleStartCheck;
}


float EnemyHPBackground::GetPlayerDamage(float _EnumyMonsterDamage)
{
	FrinedMonsterDamage = _EnumyMonsterDamage;
	return FrinedMonsterDamage;
}
bool IsDeathEnumy_B = false;

void EnemyHPBackground::HpUpdate(float _FriendMonsterDamage, float _MyCurHp , float _curpos)
{
	EnemyDamegeTick.clear();

	if (_FriendMonsterDamage > _MyCurHp) {
		_FriendMonsterDamage = _MyCurHp;
		IsDeathEnumy_B = true;
	}

	float Hpmag = _FriendMonsterDamage / _MyCurHp;
	float damege = GameEngineMath::Lerp(_curpos, 0.0f, Hpmag);

	for (int i = 10; i >= 1; i--) {

		EnemyDamegeTick.push_back(damege + ((_curpos - damege)) / 10 * i); /*현재 HP - (데미지 / 10 *)1*/

	}
	if (true == IsDeathEnumy_B) {
		EnemyDamegeTick[9] = 0.0f;
		IsDeathEnumy_B = false;
	}
}

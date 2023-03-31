#include "Battle_HpUIHandlerBase.h"
#include "BattleMonsterBase.h"
#include "FriendlyHPBackground.h"

Battle_HpUIHandlerBase::Battle_HpUIHandlerBase()
{

}

Battle_HpUIHandlerBase::~Battle_HpUIHandlerBase()
{
	if (nullptr != UI)
	{
		UI->Death();
	}
}

void Battle_HpUIHandlerBase::ExpCheck()
{
	FriendlyHPBackground* FriendHpUI = dynamic_cast<FriendlyHPBackground*>(UI);
	if (nullptr == FriendHpUI)
	{
		MsgAssert("��Ʋ ����");
		return;
	}

	FriendHpUI->IsExpUpCheck(true);
}

void Battle_HpUIHandlerBase::Update(float _DeltaTime)
{
	if (true == Owner->IsDeath())
	{
		Death();
		return;
	}

	if (true == IsArrive)
		return;

	float LiveTime = GetLiveTime();
	float Ratio = (LiveTime / Duration);
	float4 NowPos = float4::LerpClamp(StartPos, DestPos, Ratio);
	UI->SetPos(NowPos + Offset);

	if (Ratio <= 1.f)
		return;

	IsArrive = true;
}

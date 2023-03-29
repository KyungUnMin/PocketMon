#include "Battle_PlayerHpUIHandler.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "BattlePlayer.h"
#include "BattleMonsterPlayer.h"
#include "FriendlyHPBackground.h"

Battle_PlayerHpUIHandler::Battle_PlayerHpUIHandler()
{

}

Battle_PlayerHpUIHandler::~Battle_PlayerHpUIHandler()
{

}


void Battle_PlayerHpUIHandler::Start()
{
	BattleMonsterPlayer* Monster = BattlePlayer::PlayerPtr->GetMonster();
	if (nullptr == Monster)
	{
		MsgAssert("�÷��̾� ���Ͱ� ������ ���Ŀ� �� UI�� ������ �� �ֽ��ϴ�");
		return;
	}

	SetOwner(Monster);
	
	UI = GetLevel()->CreateActor<FriendlyHPBackground>(UpdateOrder::Battle_Actors);
	/*UI->GetMonsterDamage(10);
	UI->IsBattleStartCheck(true);*/
	SetUI(UI);

	SetMovePoints(StartOffset, DestOffset);
	SetOffset(Offset);
}

void Battle_PlayerHpUIHandler::OnDamage(int _Value)
{
	UI->GetMonsterDamage(_Value);
	UI->IsBattleStartCheck(true);
}

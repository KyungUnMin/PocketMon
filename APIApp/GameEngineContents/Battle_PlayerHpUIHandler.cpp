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
		MsgAssert("플레이어 몬스터가 생성된 이후에 이 UI를 생성할 수 있습니다");
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

#include "BattleState_WildTalk.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include "BattlePlayer.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "Battle_Select.h"
#include "ContentsEnum.h"
#include "BattleFSM.h"
#include "BattlePlayerFSM.h"
#include "BattleEnemy.h"
#include "BattleMonsterEnemy.h"
#include "Player.h"

std::vector<std::string> BattleState_WildTalk::Texts =
{
	"",
	""
};

BattleState_WildTalk::BattleState_WildTalk()
{

}

BattleState_WildTalk::~BattleState_WildTalk()
{

}

void BattleState_WildTalk::EnterState()
{
	BattleState_TalkBase::EnterState();

	BattleMonsterEnemy* WildMonster = BattleEnemy::EnemyPtr->GetMonster();

	if (nullptr == WildMonster)
	{
		MsgAssert("���� �߻� ���� ���� ���Դϴ�");
		return;
	}

	TrainerPokemon* PlayerMonsters = Player::MainPlayer->GetPlayerPokemon();
	PlayerMonsters->NextPokemon()->ForUI_GetMonsterName();

	Texts[0] = "Wild " + WildMonster->GetName() + " Appear!";
	Texts[1] = "Go! " + WildMonster->GetName();

	//UI�� �� �ؽ�Ʈ ���
	CreateUIText(Texts);
	
	//�ؽ�Ʈ�� ���ö����� ����� �̺�Ʈ ���
	SetTextEvent(1, []
	{
		BattlePlayer::PlayerPtr->ThrowBallToCreate();
	});
}


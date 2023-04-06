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
		MsgAssert("아직 야생 몬스터 생성 전입니다");
		return;
	}

	TrainerPokemon* PlayerMonsters = Player::MainPlayer->GetPlayerPokemon();
	std::string PlayerMonName = PlayerMonsters->NextPokemon()->ForUI_GetMonsterName();

	Texts[0] = "Wild " + WildMonster->GetName() + " Appear!";
	Texts[1] = "Go! " + PlayerMonName;

	//UI에 들어갈 텍스트 등록
	CreateUIText(Texts);
	
	//텍스트가 나올때마다 실행될 이벤트 등록
	SetTextEvent(1, []
	{
		BattlePlayer::PlayerPtr->ThrowBallToCreate();
	});
}


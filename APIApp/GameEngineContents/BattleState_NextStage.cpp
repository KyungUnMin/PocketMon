#include "BattleState_NextStage.h"
#include "BattleLevel.h"
#include "BattleFSM.h"
#include "BattleEnemy.h"
#include "PocketMonCore.h"

const std::vector<std::string_view> BattleState_NextStage::Texts =
{
	"He is trying to get the next Pokemon out",
	"Please choose the Pokemon you want to fight next?",
};

BattleState_NextStage::BattleState_NextStage()
{

}

BattleState_NextStage::~BattleState_NextStage()
{

}

void BattleState_NextStage::EnterState()
{
	BattleState_TalkBase::EnterState();
	CreateUIText(Texts);
	BattleEnemy::EnemyPtr->ComeBack();

	SetTextEvent(1, []
	{
		PocketMonCore::GetInst().ChangeLevel("PokemonLevel");
	});
}

void BattleState_NextStage::Update(float _DeltaTime)
{
	BattleState_TalkBase::Update(_DeltaTime);
}

void BattleState_NextStage::ExitState()
{
	BattleState_TalkBase::ExitState();
	BattleEnemy::EnemyPtr->CreateMonster();
}

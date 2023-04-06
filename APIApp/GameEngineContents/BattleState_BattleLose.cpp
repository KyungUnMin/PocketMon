#include "BattleState_BattleLose.h"
#include <string_view>
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "BattleEnemy.h"


BattleState_BattleLose::BattleState_BattleLose()
{

}

BattleState_BattleLose::~BattleState_BattleLose()
{

}


void BattleState_BattleLose::EnterState()
{
	MakeText();

	if (true == BattleLevel::BattleLevelPtr->IsWildBattle())
		return;

	if (true == BattleLevel::BattleLevelPtr->IsBossBattle())
		return;

	BattleEnemy::EnemyPtr->ComeBack();
}

void BattleState_BattleLose::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Timer < Duration)
		return;

	if (true == IsLevelChanged)
		return;

	BattleLevel::BattleLevelPtr->ChangeFieldLevel(false);
	IsLevelChanged = true;
}

void BattleState_BattleLose::ExitState()
{
	if (false == TextInfo->IsDeath())
	{
		TextInfo->Death();
		TextInfo = nullptr;
	}

}

void BattleState_BattleLose::MakeText()
{
	BattleNpcType NpcType = BattleLevel::BattleLevelPtr->GetNpcType();

	std::string_view Text;
	switch (NpcType)
	{
	case BattleNpcType::None:
		Text = "Player defeated\nWILD POCK@MON!";
		break;
	case BattleNpcType::Rival:
		Text = "Player defeated\nRIVAL GREEN!";
		break;
	case BattleNpcType::Woong:
		Text = "Player defeated\nDIRECTOR WOONG!";
		break;
	case BattleNpcType::Leaf:
		Text = "Player defeated\nLEAF!";
		break;
	case BattleNpcType::NPC2:
	case BattleNpcType::NPC3:
		Text = "Player defeated\nSTRANGER!";
		break;
	}

	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfo->BattleSetText(Text);
}

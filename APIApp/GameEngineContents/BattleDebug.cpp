#include "BattleDebug.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include "BattleEnemy.h"
#include "PokeDataBase.h"
#include "BattleLevel.h"
#include "BattleFSM.h"
#include "BgmPlayer.h"

const std::vector<std::string_view> BattleDebug::DebugKeys =
{
	"Battle_Debug1",
	"Battle_Debug2",
	"Battle_Debug3",
	"Battle_Debug4"
};

BattleDebug::BattleDebug()
{

}

BattleDebug::~BattleDebug()
{

}

void BattleDebug::Start()
{
	BattleStateType NowState = BattleLevel::BattleLevelPtr->GetBattleFSM()->GetNowState<BattleStateType>();
	if (BattleStateType::PlayerTurn != NowState)
	{
		DebugMsgBox("�÷��̾� �����϶��� ����� ����� ����� �� �ֽ��ϴ�");
		Death();
		return;
	}

	if (false == BattleLevel::BattleLevelPtr->IsWildBattle())
	{
		DebugMsgBox("�߻� �����϶��� ����� ����� ����� �� �ֽ��ϴ�");
		Death();
		return;
	}

	float4 ScreenSize = GameEngineWindow::GetScreenSize();
	SetPos(ScreenSize.half());

	GameEngineRender* RenderPtr = CreateRender("BattleDebug.bmp", BattleRenderOrder::Fade);
	RenderPtr->SetScaleToImage();

	if (true == GameEngineInput::IsKey(DebugKeys[0]))
		return;
	
	GameEngineInput::CreateKey(DebugKeys[0], '1');
	GameEngineInput::CreateKey(DebugKeys[1], '2');
	GameEngineInput::CreateKey(DebugKeys[2], '3');
	GameEngineInput::CreateKey(DebugKeys[3], '4');
}

void BattleDebug::Update(float _DeltaTime)
{
	for (size_t i = 0; i < DebugKeys.size(); ++i)
	{
		if (false == GameEngineInput::IsDown(DebugKeys[i]))
			continue;

		ChangeWildMonster(i);
		Death();
		return;
	}
}

void BattleDebug::ChangeWildMonster(size_t _Index)
{
	PokeNumber SelectedMonster = PokeNumber::Max;
	switch (_Index)
	{
	case 0:
		SelectedMonster = PokeNumber::Pikachu;
		BgmPlayer::PlayBGM("Battle_Pikachu2.mp3");
		BgmPlayer::SetVolume(BattleLevel::BattleLevelPtr->GetWorldVolume());
		break;
	case 1:
		SelectedMonster = PokeNumber::Bulbasaur;
		break;
	case 2:
		SelectedMonster = PokeNumber::Charmander;
		break;
	case 3:
		SelectedMonster = PokeNumber::Squirtle;
		break;
	}

	BattleEnemy::EnemyPtr->ChangeMonster_ForDegug(SelectedMonster);
	Death();
}

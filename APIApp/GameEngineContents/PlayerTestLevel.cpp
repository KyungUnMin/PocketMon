#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>

#include "Player.h"
#include "PlayerTestLevel.h"





PlayerTestLevel::PlayerTestLevel()
{

}

PlayerTestLevel::~PlayerTestLevel()
{
}
void PlayerTestLevel::Loading()
{
	// ���� ����
	{
		CreateActor<Player>();
	}
		
}

void PlayerTestLevel::Update(float _DeltaTime)
{

}


void PlayerTestLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

}



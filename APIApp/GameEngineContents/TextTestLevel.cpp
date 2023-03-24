#include "TextTestLevel.h"
#include "TestScript.h"
#include "BackTextActor.h"
#include "FriendlyHPBackground.h"
#include "EnemyHPBackground.h"
#include "Battle_Select.h"
#include "BattleCommendActor.h"


#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include "PocketMonCore.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>

TextTestLevel::TextTestLevel()
{
}

TextTestLevel::~TextTestLevel()
{
}



void TextTestLevel::Loading()
{


	//CreateActor<BackTextActor>();
	//TestScript* sSSS= CreateActor<TestScript>();// ���� ���� ���ϰ�


	//���� ���� ������ �ʿ��� ��
	CreateActor<EnemyHPBackground>();
	CreateActor<FriendlyHPBackground>();

	
}

void TextTestLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("BackCenterLevel"))
	{
		PocketMonCore::GetInst().ChangeLevel("CenterLevel");
		return;
	}
}


void TextTestLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

}

void TextTestLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}


#include "TextTestLevel.h"
#include "TestScript.h"
#include "BackTextActor.h"
#include "FriendlyHPBackground.h"
#include "EnemyHPBackground.h"
#include "Battle_Select.h"
#include "BattleCommendActor.h"


#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
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


	CreateActor<BackTextActor>();
	TestScript* sSSS= CreateActor<TestScript>();// ���� ���� ���ϰ�


	//���� ���� ������ �ʿ��� ��
	CreateActor<EnemyHPBackground>();
	CreateActor<FriendlyHPBackground>();
	CreateActor<Battle_Select>()->init(sSSS);


}

void TextTestLevel::Update(float _DeltaTime)
{

}


void TextTestLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

}

void TextTestLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}


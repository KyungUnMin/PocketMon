#include "TextTestLevel.h"
#include "TestScript.h"
#include "BackTextActor.h"
#include "FriendlyHPBackground.h"
#include "EnemyHPBackground.h"
#include "Battle_Select.h"

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
	CreateActor<TestScript>();// 대사들 띄우고 뭐하고


	//띄우기 위해 조건이 필요할 때
	CreateActor<EnemyHPBackground>();
	CreateActor<FriendlyHPBackground>();
	CreateActor<Battle_Select>();
	

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


#include "TextTestLevel.h"
#include "TestScript.h"
#include "BackTextActor.h"
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
	//CreateActor<BackTextActor>();
	CreateActor<TestScript>();
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

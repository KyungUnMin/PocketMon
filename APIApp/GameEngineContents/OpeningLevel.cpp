#include "OpeningLevel.h"

#include <GameEngineBase/GameEngineTimeEvent.h>
#include <GameEnginePlatform/GameEngineWindow.h>

#include "Opening_Text.h"

OpeningLevel::OpeningLevel() 
{
}

OpeningLevel::~OpeningLevel() 
{
}

void OpeningLevel::Loading()
{
	float4 WindowSize = GameEngineWindow::GetScreenSize().half();

	OpeningText = CreateActor<Opening_Text>();
}
void OpeningLevel::Update(float _DeltaTime)
{

}

void OpeningLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	//LevelEvent.AddEvent(1.5f, std::bind([](OpeningLevel* _This)
	//	{
	//		_This->OpeningText->AlphaControl();
	//	}, this), false);
}
void OpeningLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}

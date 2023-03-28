#include "OpeningLevel.h"

#include <GameEngineBase/GameEngineTimeEvent.h>
#include <GameEnginePlatform/GameEngineWindow.h>

#include "BlackBox.h"
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

	CreateActor<BlackBox>();

	OpeningText = CreateActor<Opening_Text>();
}
void OpeningLevel::Update(float _DeltaTime)
{
	LevelEvent.Update(_DeltaTime);
}

void OpeningLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	LevelEvent.AddEvent(2.f, std::bind([](OpeningLevel* _This)
		{
			_This->OpeningText->AlphaStart();
		}, this), false);


}

void OpeningLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}

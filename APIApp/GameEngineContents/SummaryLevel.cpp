#include "SummaryLevel.h"
#include "SummaryUI.h"
SummaryLevel::SummaryLevel() 
{
}

SummaryLevel::~SummaryLevel() 
{
}

void SummaryLevel::Loading()
{
	CreateActor<SummaryUI>();
}

void SummaryLevel::Update(float _DeltaTime)
{
	DebugTextPush(GetMousePos().ToString());
}

void SummaryLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
}

void SummaryLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
}

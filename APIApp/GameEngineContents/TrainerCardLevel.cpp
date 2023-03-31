#include "TrainerCardLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include "TrainerCardUI.h"

TrainerCardLevel::TrainerCardLevel()
{

}

TrainerCardLevel::~TrainerCardLevel()
{

}

void TrainerCardLevel::Loading()
{
	ImageLoad();
	AcTrainerCardUI = CreateActor<TrainerCardUI>();
}

void TrainerCardLevel::Update(float _DeltaTime)
{
}

void TrainerCardLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
}

void TrainerCardLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
}

void TrainerCardLevel::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("FieldUI_HSM");
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("TrainerCard.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Num.bmp"))->Cut(10,1);
}

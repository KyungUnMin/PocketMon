#include "TrainerCardLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include "TrainerCardUI.h"

TrainerCardLevel* TrainerCardLevel::MainTrainerCardLevel = nullptr;

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

	if (nullptr != MainTrainerCardLevel)
	{
		MsgAssert("플레이어 상태 레벨을 중복 생성하려 했습니다");
		return;
	}

	MainTrainerCardLevel = this;
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

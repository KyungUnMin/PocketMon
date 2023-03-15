#include "TestLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include "TestActor.h"

TestLevel::TestLevel()
{

}

TestLevel::~TestLevel()
{

}

void TestLevel::Loading()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Sound");
	GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Test.mp3"));
	GameEngineResources::GetInst().SoundPlay("Test.mp3");

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Test.bmp"));

	CreateActor<TestActor>();
}

void TestLevel::Update(float _DeltaTime)
{

}

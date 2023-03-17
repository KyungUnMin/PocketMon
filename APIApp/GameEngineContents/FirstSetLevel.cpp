#include "FirstSetLevel.h"
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "FieldDialog.h"

FirstSetLevel::FirstSetLevel()
{

}

FirstSetLevel::~FirstSetLevel()
{

}

void FirstSetLevel::Loading()
{
	ImageLoad();
	AcFieldDialog = CreateActor<FieldDialog>();

	if (!GameEngineInput::IsKey("P"))
	{
		GameEngineInput::CreateKey("P", 'P');
	}
}

void FirstSetLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("P"))
	{
		AcFieldDialog->OnOffSwtich();
	}
}

void FirstSetLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
}

void FirstSetLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
}

void FirstSetLevel::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("FieldUI_HSM");
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Npc_TextFrame.bmp"));
}

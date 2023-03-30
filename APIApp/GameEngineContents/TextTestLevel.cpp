#include "TextTestLevel.h"
#include "TestScript.h"
#include "BackTextActor.h"
#include "FriendlyHPBackground.h"
#include "EnemyHPBackground.h"
#include "Battle_Select.h"
#include "BattleCommendActor.h"
#include "LevelUpStatUI.h"
#include "LevelUpStatUI_2.h"

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include "PocketMonCore.h"
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
	//TestScript* sSSS= CreateActor<TestScript>();// 대사들 띄우고 뭐하고


	//띄우기 위해 조건이 필요할 때
	//CreateActor<EnemyHPBackground>();
	//CreateActor<FriendlyHPBackground>();

//	CreateActor<BattleCommendActor>();
	/*LevelUpStatUI* NewAAA = CreateActor<LevelUpStatUI>();
	NewAAA->SetPos({ 50,70 });*/

	LevelUpStatUI_2* NewAAAA = CreateActor<LevelUpStatUI_2>();
	NewAAAA->SetPos({ 450,70 });

}

void TextTestLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("BackCenterLevel"))
	{
		PocketMonCore::GetInst().ChangeLevel("CenterLevel");
		return;
	}
	if (true == GameEngineInput::IsDown("FieldUITestSwitch"))
	{
		
		


	}
}


void TextTestLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

}

void TextTestLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}


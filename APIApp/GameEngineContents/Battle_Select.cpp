#include "Battle_Select.h"
#include "BattleCommendActor.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineResources.h>


#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include "ContentsEnum.h"


Battle_Select::Battle_Select()
{
}

Battle_Select::~Battle_Select()
{
}



void Battle_Select::init(GameEngineActor* Script)
{
	ScriptPtr = Script;

}

void Battle_Select::Start()
{
	//if (false == GameEngineInput::IsKey("InsertMove1"))
	//{

	//	GameEngineInput::CreateKey("InsertMove1", 'Z');
	//}

	SetPos({720,540});
	GameEngineRender* RenderPtr = CreateRender("Battle_Select.bmp", BattleRenderOrder::Battle_Text);
	RenderPtr->SetScale((RenderPtr->GetImage()->GetImageScale()));

	ArrowRender = CreateRender("Battle_Arrow.bmp", BattleRenderOrder::Battle_Cursor);
	ArrowRender->SetScale((ArrowRender->GetImage()->GetImageScale()));
	//back 이미지 크기 480,192   -240 ~ 240
	//이미지 크기 50,50
	// 위 아래 간의 y격차는 75  초기지점 -190,-25  >이동 x+240 밑으로 이동 +65
	ArrowRender->SetPosition({ -190,-25 });
}

void Battle_Select::Update(float _DeltaTime)
{
	ArrowNumberCheck();
	if (ArrowCheckNum == 0) {
		ArrowRender->SetPosition({ -190,-25 });
	}
	if (ArrowCheckNum == 1) {
		ArrowRender->SetPosition({ 35,-25 });
	}
	if (ArrowCheckNum == 2) {
		ArrowRender->SetPosition({ -190,40 });
	}
	if (ArrowCheckNum == 3) {
		ArrowRender->SetPosition({ 35,40 });
	}
	ArrowInput(ArrowCheckNum);
}


void Battle_Select::ArrowNumberCheck()
{
	if (ArrowCheckNum == 1 || ArrowCheckNum==3) {
		if (true == GameEngineInput::IsDown("LeftMove")) {
			SelectSOUND();
			ArrowCheckNum -= 1;
		}
	}
	if (ArrowCheckNum == 0 || ArrowCheckNum == 2) {
		if (true == GameEngineInput::IsDown("RightMove")) {
			SelectSOUND();
			ArrowCheckNum += 1;
		}
	}
	if (ArrowCheckNum == 2 || ArrowCheckNum == 3) {
		if (true == GameEngineInput::IsDown("UpMove")) {
			SelectSOUND();
			ArrowCheckNum -= 2;
		}
	}
	if (ArrowCheckNum == 0 || ArrowCheckNum == 1) {
		if (true == GameEngineInput::IsDown("DownMove")) {
			SelectSOUND();
			ArrowCheckNum += 2;
		}
	}


	
}

void Battle_Select::ArrowInput(int _Number)
{
	static const float WaitTime = 0.5f;
	if (GetLiveTime() < WaitTime)
		return;

	if (true == GameEngineInput::IsDown("BattleSelect1111")) 
	{
		if (nullptr != Callbacks[ArrowCheckNum])
		{
			SelectSOUND();
			Callbacks[ArrowCheckNum]();
			return;
		}

		/*GetLevel()->CreateActor<BattleCommendActor>();
		Off();*/
		//ScriptPtr->Off();
	}



}

void Battle_Select::Render(float _DeltaTime)
{

}

void Battle_Select::SelectSOUND()
{
	B_SelectSOUND = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	B_SelectSOUND.Volume(1.0f);
	B_SelectSOUND.LoopCount(1);
}
//void Battle_Select::CollisionCheck(float _DeltaTime)
//{
//
//}

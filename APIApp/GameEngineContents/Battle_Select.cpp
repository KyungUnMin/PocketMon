#include "Battle_Select.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
Battle_Select::Battle_Select()
{
}

Battle_Select::~Battle_Select()
{
}

void Battle_Select::Start()
{
	SetPos({720,540});
	GameEngineRender* RenderPtr = CreateRender("Battle_Select.bmp", RenderOrder::BackGround);
	RenderPtr->SetScale((RenderPtr->GetImage()->GetImageScale()));

	GameEngineRender* RenderArrow = CreateRender("Battle_Arrow.bmp", RenderOrder::Player);
	RenderArrow->SetScale((RenderArrow->GetImage()->GetImageScale()));
	//back 이미지 크기 480,192   -240 ~ 240
	//이미지 크기 50,50
	// 위 아래 간의 y격차는 75  초기지점 -190,-25  >이동 x+240 밑으로 이동 +65
	RenderArrow->SetPosition({ -190,-25 }); 
	
	//ArrowCol=CreateCollision()

}

void Battle_Select::Update(float _DeltaTime)
{

}

void Battle_Select::Render(float _DeltaTime)
{

}

//void Battle_Select::CollisionCheck(float _DeltaTime)
//{
//
//}

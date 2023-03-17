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
	//back �̹��� ũ�� 480,192   -240 ~ 240
	//�̹��� ũ�� 50,50
	// �� �Ʒ� ���� y������ 75  �ʱ����� -190,-25  >�̵� x+240 ������ �̵� +65
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

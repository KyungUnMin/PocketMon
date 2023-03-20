#include "BattleMonster_Bulbasaur.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

BattleMonster_Bulbasaur::BattleMonster_Bulbasaur()
{

}

BattleMonster_Bulbasaur::~BattleMonster_Bulbasaur()
{

}


void BattleMonster_Bulbasaur::Init(bool _IsPlayerMonster)
{
	std::string ImagePath = _IsPlayerMonster ? "BattleBulbasaurBack.bmp" : "BattleBulbasaurFront.bmp";
	RenderPtr = CreateRender(ImagePath, RenderOrder::Monster);
	RenderPtr->SetScaleToImage();
}


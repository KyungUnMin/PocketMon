#include "FieldmapCutableTree.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

FieldmapCutableTree::FieldmapCutableTree()
{
}

FieldmapCutableTree::~FieldmapCutableTree()
{
}

void FieldmapCutableTree::Start()
{
	CreateRender("CutableTree.bmp", RenderOrder::FieldMiddle)->SetScaleToImage();
}

#include "EndingTextActor.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

EndingTextActor::EndingTextActor()
{
}

EndingTextActor::~EndingTextActor()
{
}

void EndingTextActor::Start()
{
	PokemonRender = CreateRender("EndLogo.bmp", RenderOrder::EndingLastText);
	PokemonRender->SetScaleToImage();
}

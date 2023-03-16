#include "TestScript.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnum.h"

TestScript::TestScript()
{
}

TestScript::~TestScript()
{
}

void TestScript::Start()
{
	TextRender = CreateRender(RenderOrder::Player);
	Script = "oksadawda\nsadwasdawd";
	BoxScale = { 650, 300 };
	TextRender->SetText(Script, 50, "±¼¸²", TextAlign::Left, RGB(0, 0, 0), BoxScale);
	TextRender->SetPosition({ 50,500 });
	TextRender->EffectCameraOff();
}
#include "TestScript.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"


TestScript::TestScript()
{
}

TestScript::~TestScript()
{
	
}

void TestScript::Start()
{
	TextRender1 = CreateRender(RenderOrder::Battle_Text);
	BoxScale = { 650, 300 };
	
	TextRender1->SetText("UNKNOWN", 40, "±¼¸²", TextAlign::Left, RGB(0, 0, 0), BoxScale);
	TextRender1->SetPosition({ 50,490 });
	TextRender1->EffectCameraOff();
}

void TestScript::SetText(const std::string_view& _Text)
{
	TextRender1->SetText(_Text, 40, "±¼¸²", TextAlign::Left, RGB(0, 0, 0), BoxScale);
}

#include "TestScript.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnum.h"

TestScript* TestScript::TestScriptPtr;

//NPC나 야생 배틀시 값을 받아와서 텍스트 실행하자 일단 야생을 디폴트로 
TestScript::TestScript()
{
	TestScriptPtr = this;
}

TestScript::~TestScript()
{
	if (this == TestScriptPtr)
	{
		TestScriptPtr = nullptr;
	}
}

void TestScript::Start()
{
	if (false == GameEngineInput::IsKey("NextText"))
	{
		GameEngineInput::CreateKey("NextText", 'Z');
	}

	Script1 = "테스트 텍스트 띄우기\n넘어가기는 Z";
	Script2 = "앗 야생의 포켓몬 삐리리리\n넘어가기는 Z";
	Script3 = "삐리리리리 싸울까?\n넘어가기는 Z";


	TextRender1 = CreateRender(RenderOrder::Player);
	BoxScale = { 650, 300 };
	TextRender1->SetText(Script1, 40, "굴림", TextAlign::Left, RGB(0, 0, 0), BoxScale);
	TextRender1->SetPosition({ 50,490 });
	TextRender1->EffectCameraOff();

}

void TestScript::Update(float _DeltaTime)
{
	TextInput();
	if (TextCheckNumber == 0) {
	

	}
	else if (TextCheckNumber ==1) {
		TextRender1->SetText(Script2, 40, "굴림", TextAlign::Left, RGB(0, 0, 0), BoxScale);


	}
	else if (TextCheckNumber == 2) {

		TextRender1->SetText(Script3, 40, "굴림", TextAlign::Left, RGB(0, 0, 0), BoxScale);


	}
}

void TestScript::TextInput()
{
	if (true == GameEngineInput::IsDown("NextText")) {
		TextCheckNumber += 1;
	}
}

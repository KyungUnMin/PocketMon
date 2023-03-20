#include "TestScript.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnum.h"

TestScript* TestScript::TestScriptPtr;

//NPC�� �߻� ��Ʋ�� ���� �޾ƿͼ� �ؽ�Ʈ �������� �ϴ� �߻��� ����Ʈ�� 
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

	Script1 = "�׽�Ʈ �ؽ�Ʈ ����\n�Ѿ��� Z";
	Script2 = "�� �߻��� ���ϸ� �߸�����\n�Ѿ��� Z";
	Script3 = "�߸������� �ο��?\n�Ѿ��� Z";


	TextRender1 = CreateRender(RenderOrder::Player);
	BoxScale = { 650, 300 };
	TextRender1->SetText(Script1, 40, "����", TextAlign::Left, RGB(0, 0, 0), BoxScale);
	TextRender1->SetPosition({ 50,490 });
	TextRender1->EffectCameraOff();

}

void TestScript::Update(float _DeltaTime)
{
	TextInput();
	if (TextCheckNumber == 0) {
	

	}
	else if (TextCheckNumber ==1) {
		TextRender1->SetText(Script2, 40, "����", TextAlign::Left, RGB(0, 0, 0), BoxScale);


	}
	else if (TextCheckNumber == 2) {

		TextRender1->SetText(Script3, 40, "����", TextAlign::Left, RGB(0, 0, 0), BoxScale);


	}
}

void TestScript::TextInput()
{
	if (true == GameEngineInput::IsDown("NextText")) {
		TextCheckNumber += 1;
	}
}

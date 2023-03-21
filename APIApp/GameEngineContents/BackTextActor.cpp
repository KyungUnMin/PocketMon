#include "BackTextActor.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentsEnum.h"
#include "TestScript.h"

BackTextActor::BackTextActor()
{
}

BackTextActor::~BackTextActor()
{
	if (nullptr != ScriptPtr)
	{
		ScriptPtr->Death();
	}
}


void BackTextActor::Start()
{
	SetPos({480,540});
	GameEngineRender* RenderPtr = CreateRender("Combat_TextFrame.bmp", RenderOrder::Battle_UI);
	RenderPtr->SetScale((RenderPtr->GetImage()->GetImageScale()));

	ScriptPtr = GetLevel()->CreateActor<TestScript>();
}

void BackTextActor::PushTexts(const std::vector<std::string_view>& _Texts)
{
	AllTexts.resize(_Texts.size());

	for (size_t i = 0; i < AllTexts.size(); ++i)
	{
		AllTexts[i] = _Texts[i];
	}

	
}

bool BackTextActor::WriteText()
{
	if (AllTexts.size() <= CurIndex)
		return false;

	ScriptPtr->SetText(AllTexts[CurIndex++]);
	return true;
}

#include "BackTextActor.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnum.h"
#include "TestScript.h"

BackTextActor::BackTextActor()
{
}

BackTextActor::~BackTextActor()
{
	
}


void BackTextActor::Start()
{
	SetPos({480,542});
	RenderPtr = CreateRender("Combat_TextFrame.bmp", BattleRenderOrder::Battle_UI);
	RenderPtr->SetScale((RenderPtr->GetImage()->GetImageScale()));
	RenderPtr->EffectCameraOff();

	BattleTextRender.resize(LineCount);
	BattleTextRender[0].resize(OneLineSize);
	BattleTextRender[1].resize(OneLineSize);

	for (size_t y = 0; y < BattleTextRender.size(); y++)
	{
		for (size_t x = 0; x < BattleTextRender[y].size(); x++)
		{
			BattleTextRender[y][x] = CreateRender("Font_Dialog_White.bmp", BattleRenderOrder::Battle_Text);
			BattleTextRender[y][x]->SetPosition(FirstTextRenderPos + float4{ static_cast<float>(x),static_cast<float>(y) } *(TextRenderInterval + TextRenderImageScale));
			BattleTextRender[y][x]->SetScale(TextRenderImageScale);
			BattleTextRender[y][x]->SetFrame(SpaceFrameNum);
			BattleTextRender[y][x]->Off();
			BattleTextRender[y][x]->EffectCameraOff();
		}
	}
	
	//PushStart(&TestText);
}

void BackTextActor::PushScriptBegin(std::list<std::string>::iterator _Begin)
{
	TestTextIter = _Begin;
}

void BackTextActor::PushScriptEnd(std::list<std::string>::iterator _End)
{
	TestTextEndIter = _End;
}



void BackTextActor::StringToRender()
{
	const std::string Str = TestTextIter->data();

	size_t StrEndIndex = Str.size() - 1;

	int StrIndex = 0;

	for (size_t y = 0; y < BattleTextRender.size(); y++) {
		for (size_t x = 0; x < BattleTextRender[y].size(); x++) {

			if (StrEndIndex < StrIndex || ' ' == Str[StrIndex])
			{
				BattleTextRender[y][x]->SetFrame(SpaceFrameNum);
			}
			else
			{
				if (Str[StrIndex] >= 'A' && Str[StrIndex] <= 'Z')
				{
					BattleTextRender[y][x]->SetFrame(Str[StrIndex] - 'A');
				}
				else if (Str[StrIndex] >= 'a' && Str[StrIndex] <= 'z')
				{
					BattleTextRender[y][x]->SetFrame(Str[StrIndex] - 'a' + 27);
				}
				else if (Str[StrIndex] >= '0' && Str[StrIndex] <= '9')
				{
					BattleTextRender[y][x]->SetFrame(Str[StrIndex] - '0' + 54);
				}
				else if (Str[StrIndex] == '\n')
				{
					while (x < BattleTextRender[y].size())
					{
						BattleTextRender[y][x]->SetFrame(SpaceFrameNum);
						x++;
					}
				}
				else
				{
					switch (Str[StrIndex])
					{
					case '!':
						BattleTextRender[y][x]->SetFrame(81);
						break;
					case '?':
						BattleTextRender[y][x]->SetFrame(82);
						break;
					case '/':
						BattleTextRender[y][x]->SetFrame(85);
						break;
					case '-':
						BattleTextRender[y][x]->SetFrame(86);
						break;
					case '_':
						BattleTextRender[y][x]->SetFrame(91);
						break;
					case '.':
						BattleTextRender[y][x]->SetFrame(92);
						break;
					case ',':
						BattleTextRender[y][x]->SetFrame(93);
						break;
					case '@':
						BattleTextRender[y][x]->SetFrame(94);
						break;
					default:
						MsgAssert("���� �����غ��� ���� �����Դϴ�.");
						break;
					}
				}
			}
			StrIndex++;
		}
	}
	LastTextRenderIndex = FindLastTextRenderIndex();

}

void BackTextActor::ClearDialog()
{
	for (size_t y = 0; y < BattleTextRender.size(); y++)
	{
		for (size_t x = 0; x < BattleTextRender[y].size(); x++)
		{
			BattleTextRender[y][x]->SetFrame(SpaceFrameNum);
		//	BattleTextRender[y][x]->Off();
		}
	}
}


int2 BackTextActor::FindLastTextRenderIndex()
{
	int2 SaveLastRenderIndex = { 0,0 };
	for (int y = 0; y < BattleTextRender.size(); y++)
	{
		for (int x = 0; x < BattleTextRender[y].size(); x++)
		{
			if (SpaceFrameNum != BattleTextRender[y][x]->GetFrame())
			{
				SaveLastRenderIndex = { x,y };
			}
		}
	}
	return SaveLastRenderIndex;
}
void BackTextActor::Update(float _DeltaTime)
{
	if (false == IsValid)
		return;


	for (size_t i = 0; i < FirstLineRenderLen; i++)
	{
		BattleTextRender[0][i]->On();
	}

	for (size_t i = 0; i < SecondLineRenderLen; i++)
	{
		BattleTextRender[1][i]->On();
	}
	Time += _DeltaTime;
	if (Time >= PrintSpeed)
	{
		Time = 0;
		if (FirstLineRenderLen != OneLineSize)
		{
			
			++FirstLineRenderLen;
		}
		else if (SecondLineRenderLen != OneLineSize)
		{
			
			++SecondLineRenderLen;
		}

		else
		{
			return;
		}
	}
	if (BattleTextRender[LastTextRenderIndex.y][LastTextRenderIndex.x]->IsUpdate() && GameEngineInput::IsDown("BattleUI_Next")) 
	{
		if (TestText.end() == TestTextIter)
			return;

		++TestTextIter;
		if (TestTextIter != TestTextEndIter)
		{
			ClearDialog();
			StringToRender();
		}
	
	}

}

void BackTextActor::PushStart(std::list<std::string>* _Text)
{
	PushScriptBegin(_Text->begin());
	PushScriptEnd(_Text->end());

}

void BackTextActor::BattleSetText(const std::string_view& _Texts)
{
	IsValid = true;
	TestText.push_back(_Texts.data());
	PushStart(&TestText);
	StringToRender();
}






void BackTextActor::NextScriptSOUND()
{
	B_NextScriptSOUND = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	B_NextScriptSOUND.Volume(1.0f);
	B_NextScriptSOUND.LoopCount(1);
}














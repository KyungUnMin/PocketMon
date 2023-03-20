#include "FieldDialog.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>

FieldDialog* FieldDialog::MainFieldDialog = nullptr;

FieldDialog::FieldDialog()
{
	MainFieldDialog = this;
}

FieldDialog::~FieldDialog()
{

}

void FieldDialog::Off()
{
	GameEngineObject::Off();
	UpdateEnd();
}

void FieldDialog::OnOffSwtich()
{
	if (IsUpdate())
	{
		Off();
	}
	else
	{
		ConversationStart(&TestScript);
	}
}

void FieldDialog::ConversationStart(std::list<std::string>* _Script)
{
	On();
	UpdateStart(_Script);
}



void FieldDialog::Start()
{
	FieldDialogFrame = CreateRender("Npc_TextFrame.bmp", RenderOrder::Field_Dialog);
	FieldDialogFrame->SetScaleToImage();
	FieldDialogFrame->EffectCameraOff();
	SetPos(ActorPos);

	FieldDialogTextRender.resize(LineCount);
	FieldDialogTextRender[0].resize(OneLineSize);
	FieldDialogTextRender[1].resize(OneLineSize);

	for (size_t y = 0; y < FieldDialogTextRender.size(); y++)
	{
		for (size_t x = 0; x < FieldDialogTextRender[y].size(); x++)
		{
			FieldDialogTextRender[y][x] = CreateRender("Font_Dialog.bmp",RenderOrder::Field_Dialog_Text);
			FieldDialogTextRender[y][x]->SetPosition(FirstTextRenderPos + float4{ static_cast<float>(x),static_cast<float>(y) } * (TextRenderInterval + TextRenderImageScale));
			FieldDialogTextRender[y][x]->SetScale(TextRenderImageScale);
			FieldDialogTextRender[y][x]->SetFrame(SpaceFrameNum);
			FieldDialogTextRender[y][x]->Off();
			FieldDialogTextRender[y][x]->EffectCameraOff();
		}
	}
	
	ArrowRender = CreateRender(RenderOrder::Field_Dialog_Text);
	ArrowRender->EffectCameraOff();
	ArrowRender->CreateAnimation({.AnimationName = "Arrow", .ImageName = "Arrow_Dialog.bmp", .Start = 0, .End = 3, .InterTime = 0.1f});
	ArrowRender->SetScale(ArrowRenderScale);
	ArrowRender->ChangeAnimation("Arrow");

	//Test
	TestScript.push_back("ASDASDLJASL");
	TestScript.push_back("asd321as32");
	TestScript.push_back("fjkghfjgk");

	Off();
}

void FieldDialog::UpdateStart(std::list<std::string>* _Script)
{
	PushScriptBegin(_Script->begin());
	PushScriptEnd(_Script->end());
	StringToRender();
}

void FieldDialog::Update(float _DeltaTime)
{
	for (size_t i = 0; i < FirstLineRenderLen; i++)
	{
		FieldDialogTextRender[0][i]->On();
	}

	for (size_t i = 0; i < SecondLineRenderLen; i++)
	{
		FieldDialogTextRender[1][i]->On();
	}

	Time += _DeltaTime;
	if (Time >= 0.03)
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

	if (FirstLineRenderLen >= 2 && GameEngineInput::IsDown("A")) // ���ɾ����� �ٷ� �Ѿ�� �ʰ�
	{
		ScriptIter++;
		if (ScriptIter != ScriptEndIter)
		{
			ClearDialog();
			FirstLineRenderLen = 0;
			SecondLineRenderLen = 0;
			StringToRender();
		}
		else
		{
			Off();
		}
	}
}

void FieldDialog::UpdateEnd()
{
	ClearDialog();
	FirstLineRenderLen = 0;
	SecondLineRenderLen = 0;
}

void FieldDialog::PushScriptBegin(std::list<std::string>::iterator _Begin)
{
	ScriptIter = _Begin;
}

void FieldDialog::PushScriptEnd(std::list<std::string>::iterator _End)
{
	ScriptEndIter = _End;
}

void FieldDialog::StringToRender()
{
	const std::string_view& Str = ScriptIter->data();
	size_t StrEndIndex = Str.size() - 1;
	int StrIndex = 0;
	for (size_t y = 0; y < FieldDialogTextRender.size(); y++)
	{
		for (size_t x = 0; x < FieldDialogTextRender[y].size(); x++)
		{
			if (StrEndIndex < StrIndex || ' ' == Str[StrIndex])
			{
				FieldDialogTextRender[y][x]->SetFrame(SpaceFrameNum);
			}
			else
			{
				if (Str[StrIndex] >= 'A' && Str[StrIndex] <= 'Z')
				{
					FieldDialogTextRender[y][x]->SetFrame(Str[StrIndex] - 'A');
				}
				else if (Str[StrIndex] >= 'a' && Str[StrIndex] <= 'z')
				{
					FieldDialogTextRender[y][x]->SetFrame(Str[StrIndex] - 'a' + 27);
				}
				else if (Str[StrIndex] >= '0' && Str[StrIndex] <= '9')
				{
					FieldDialogTextRender[y][x]->SetFrame(Str[StrIndex] - '0' + 54);
				}
				else if (Str[StrIndex] == '\n')
				{
					while (x < FieldDialogTextRender[y].size())
					{
						FieldDialogTextRender[y][x]->SetFrame(SpaceFrameNum);
						x++;
					}
				}
				else
				{
					//switch (Str[StrIndex])
					//{
					//case '!':
					//	break;
					//case '?':
					//	break;
					//case '/':
					//	break;
					//case '-':
					//	break;
					//case '"':
					//	break;
					//case '!':
					//	break;
					//case '!':
					//	break;
					//case '!':
					//	break;
					//case '!':
					//	break;
					//case '!':
					//	break;
					//case '!':
					//	break;
					//case '!':
					//	break;
					//case '!':
					//	break;
					//case '!':
					//	break;
					//case '!':
					//	break;
					//default:
					//	MsgAssert("���� �����غ��� ���� �����Դϴ�.");
					//  break;
					//}

					MsgAssert("���� �����غ��� ���� �����Դϴ�.");
				}
			}
			StrIndex++;
		}
	}
	LastTextRenderIndex = FindLastTextRenderIndex();
	SetArrowRenderPos(LastTextRenderIndex);
}

void FieldDialog::ClearDialog()
{
	for (size_t y = 0; y < FieldDialogTextRender.size(); y++)
	{
		for (size_t x = 0; x < FieldDialogTextRender[y].size(); x++)
		{
			FieldDialogTextRender[y][x]->SetFrame(SpaceFrameNum);
			FieldDialogTextRender[y][x]->Off();
		}
	}
}

int2 FieldDialog::FindLastTextRenderIndex()
{
	int2 SaveLastRenderIndex = { 0,0 };
	for (int y = 0; y < FieldDialogTextRender.size(); y++)
	{
		for (int x = 0; x < FieldDialogTextRender[y].size(); x++)
		{
			if (SpaceFrameNum != FieldDialogTextRender[y][x]->GetFrame())
			{
				SaveLastRenderIndex = { x,y };
			}
		}
	}
	return SaveLastRenderIndex;
}

void FieldDialog::SetArrowRenderPos(const int2& _LastIndex)
{
	ArrowRender->SetPosition(FirstTextRenderPos + float4{ static_cast<float>(_LastIndex.x),static_cast<float>(_LastIndex.y) } *(TextRenderInterval + TextRenderImageScale) + ArrowRenderPlusPos);
}


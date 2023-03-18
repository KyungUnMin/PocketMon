#include "FieldDialog.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineCore/GameEngineRender.h>

FieldDialog* FieldDialog::MainFieldDialog = nullptr;

FieldDialog::FieldDialog()
{
	MainFieldDialog = this;
}

FieldDialog::~FieldDialog()
{

}

void FieldDialog::On()
{
	GameEngineObject::On();
	UpdateStart();

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
		On();
	}
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
	
	//Test
	TestScript.push_back("AAAA");
	TestScript.push_back("BBBB");
	TestScript.push_back("CCCC");

	Off();
}

void FieldDialog::UpdateStart()
{
	PushScriptBegin(TestScript);
	StringToRender(ScriptBeginIter->data());
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


}

void FieldDialog::UpdateEnd()
{
	ClearDialog();
	FirstLineRenderLen = 0;
	SecondLineRenderLen = 0;
}

void FieldDialog::PushScriptBegin(std::list<std::string> _Script)
{
	ScriptBeginIter = _Script.begin();
}

void FieldDialog::StringToRender(const std::string_view& _Str)
{
	size_t StrEndIndex = _Str.size()-1;
	int StrIndex = 0;
	for (size_t y = 0; y < FieldDialogTextRender.size(); y++)
	{
		for (size_t x = 0; x < FieldDialogTextRender[y].size(); x++)
		{
			if (StrEndIndex < StrIndex || ' ' == _Str[StrIndex])
			{
				FieldDialogTextRender[y][x]->SetFrame(SpaceFrameNum);
			}
			else
			{
				if (_Str[StrIndex] >= 'A' && _Str[StrIndex] <= 'Z')
				{
					FieldDialogTextRender[y][x]->SetFrame(_Str[StrIndex] - 'A');
				}
				else if (_Str[StrIndex] >= 'a' && _Str[StrIndex] <= 'z')
				{
					FieldDialogTextRender[y][x]->SetFrame(_Str[StrIndex] - 'a' + 27);
				}
				else if (_Str[StrIndex] >= '0' && _Str[StrIndex] <= '9')
				{
					FieldDialogTextRender[y][x]->SetFrame(_Str[StrIndex] - '0' + 54);
				}
				else if (_Str[StrIndex] == '\n')
				{
					while (x < FieldDialogTextRender[y].size())
					{
						FieldDialogTextRender[y][x]->SetFrame(SpaceFrameNum);
						x++;
					}
				}
				else
				{
					//switch (_Str[StrIndex])
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
					//	break;
					//}

					MsgAssert("아직 생각해보지 않은 글자입니다.");
				}
			}
			StrIndex++;
		}
	}
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

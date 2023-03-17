#include "FieldDialog.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineCore/GameEngineRender.h>

FieldDialog* FieldDialog::AcFeidDialog = nullptr;

FieldDialog::FieldDialog()
{
	AcFeidDialog = this;
}

FieldDialog::~FieldDialog()
{

}

void FieldDialog::Start()
{
	FieldDialogFrame = CreateRender("Npc_TextFrame.bmp", 0);
	FieldDialogFrame->SetScaleToImage();
	SetPos(ActorPos);

	FieldDialogTextRender.resize(2);
	FieldDialogTextRender[0].resize(OneLineSize);
	FieldDialogTextRender[1].resize(OneLineSize);

	for (size_t y = 0; y < FieldDialogTextRender.size(); y++)
	{
		for (size_t x = 0; x < FieldDialogTextRender[y].size(); x++)
		{
			FieldDialogTextRender[y][x] = CreateRender("Font_eng.bmp",1);
			FieldDialogTextRender[y][x]->SetPosition(FirstTextRenderPos + float4{ static_cast<float>(x),static_cast<float>(y) } * (TextRenderInterval + TextRenderImageScale));
			FieldDialogTextRender[y][x]->SetScale(TextRenderImageScale);
			FieldDialogTextRender[y][x]->SetFrame(SpaceFrameNum);
			FieldDialogTextRender[y][x]->Off();
		}
	}
}

void FieldDialog::Update(float _DeltaTime)
{
	StringToRender();
}

void FieldDialog::StringToRender()
{
	size_t StrEndIndex = Str.size()-1;
	int StrIndex = 0;
	for (size_t y = 0; y < FieldDialogTextRender.size(); y++)
	{
		for (size_t x = 0; x < FieldDialogTextRender[y].size(); x++)
		{
			if (StrEndIndex < StrIndex || ' ' == Str[StrIndex])
			{
				FieldDialogTextRender[y][x]->SetFrame(SpaceFrameNum);
				StrIndex++;
			}
			else
			{
				if (Str[StrIndex] >= 'A' && Str[StrIndex] <= 'Z')
				{
					FieldDialogTextRender[y][x]->SetFrame(Str[StrIndex] - 'A');
					StrIndex++;
				}
				else if (Str[StrIndex] >= 'a' && Str[StrIndex] <= 'z')
				{
					FieldDialogTextRender[y][x]->SetFrame(Str[StrIndex] - 'a' + 27);
					StrIndex++;
				}
				else if (Str[StrIndex] == '\n')
				{
					while (x < FieldDialogTextRender[y].size())
					{
						FieldDialogTextRender[y][x]->SetFrame(SpaceFrameNum);
						x++;
					}
					StrIndex++;
				}
				else
				{
					MsgAssert("아직 생각해보지 않은 글자입니다.");
				}
			}
		}
	}
}

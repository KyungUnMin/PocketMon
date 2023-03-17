#include "FieldDialog.h"
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
	FieldDialogTextRender[0].resize(30);
	FieldDialogTextRender[1].resize(30);

	for (size_t y = 0; y < FieldDialogTextRender.size(); y++)
	{
		for (size_t x = 0; x < FieldDialogTextRender[y].size(); x++)
		{
			FieldDialogTextRender[y][x] = CreateRender("Font_eng.bmp",1);
			FieldDialogTextRender[y][x]->SetPosition(FirstTextRenderPos + float4{ static_cast<float>(x),static_cast<float>(y) } * (TextRenderInterval + TextRenderImageScale));
			FieldDialogTextRender[y][x]->SetScale(TextRenderImageScale);
			FieldDialogTextRender[y][x]->SetFrame(SpaceFrameNum);
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
	for (size_t y = 0; y < FieldDialogTextRender.size(); y++)
	{
		for (size_t x = 0; x < FieldDialogTextRender[y].size(); x++)
		{
			if (StrEndIndex < x + y*30 || ' ' == Str[x + y])
			{
				FieldDialogTextRender[y][x]->SetFrame(SpaceFrameNum);
			}
			else
			{
				if (Str[x + y * 30] >= 'A' && Str[x + y * 30] <= 'Z')
				{
					FieldDialogTextRender[y][x]->SetFrame(Str[x + y * 30] - 'A');
				}
				else if (Str[x + y * 30] >= 'a' && Str[x + y * 30] <= 'z')
				{
					FieldDialogTextRender[y][x]->SetFrame(Str[x + y * 30] - 'a' + 27);
				}
			}

			//if (' ' == Str[x + y])
			//{
			//	FieldDialogTextRender[y][x]->SetFrame(SpaceFrameNum);
			//}
		}
	}
}

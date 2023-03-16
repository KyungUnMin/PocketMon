#include "FieldDialog.h"
#include <GameEngineCore/GameEngineRender.h>

FieldDialog::FieldDialog()
{

}

FieldDialog::~FieldDialog()
{

}

void FieldDialog::Start()
{
	FieldDialogFrame = CreateRender("Npc_TextFrame.bmp", 0);
	FieldDialogFrame->SetScaleToImage();
	SetPos(ActorPos);
}
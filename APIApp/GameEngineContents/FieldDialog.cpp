#include "FieldDialog.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>

#include "Player.h"

FieldDialog* FieldDialog::MainFieldDialog = nullptr;

FieldDialog::FieldDialog()
{
	if (MainFieldDialog != nullptr)
	{
		return;
	}
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

void FieldDialog::ConversationStart(std::list<std::string>* _Script)
{
	On();
	ScriptPtr = _Script;
	UpdateStart(_Script);
}

bool FieldDialog::IsAllScriptPrintEnd()
{
	if (FieldDialogTextRender[LastTextRenderIndex.y][LastTextRenderIndex.x]->IsUpdate() && IsLastScript())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FieldDialog::IsOneScriptPrintEnd()
{
	if (FieldDialogTextRender[LastTextRenderIndex.y][LastTextRenderIndex.x]->IsUpdate())
	{
		return true;
	}
	else
	{
		return false;
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
	
	ArrowRender = CreateRender(RenderOrder::Field_Dialog_Text);
	ArrowRender->EffectCameraOff();
	ArrowRender->CreateAnimation({.AnimationName = "Arrow", .ImageName = "Arrow_Dialog.bmp", .Start = 0, .End = 3, .InterTime = 0.1f});
	ArrowRender->SetScale(ArrowRenderScale);
	ArrowRender->ChangeAnimation("Arrow");

	Off();
}

void FieldDialog::DialogNextButtonSoundPlay()
{
	DialogNextButtonSound = GameEngineResources::GetInst().SoundPlayToControl("MenuButton.wav");
	DialogNextButtonSound.Volume(0.8f);
	DialogNextButtonSound.LoopCount(1);
}

void FieldDialog::UpdateStart(std::list<std::string>* _Script)
{
	Player::MainPlayer->SetPlayerMoveBool(false);
	ClearDialog();
	FirstLineRenderLen = 0;
	SecondLineRenderLen = 0;
	PushScriptBegin(_Script->begin());
	PushScriptEnd(_Script->end());
	StringToRender();
	ArrowRender->Off();
	IsValid = true;
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
	if (Time >= PrintSpeed)
	{
		Time = 0;
		if (FirstLineRenderLen != OneLineSize)
		{
			if (FieldDialogTextRender[LastTextRenderIndex.y][LastTextRenderIndex.x]->IsUpdate() && !IsLastScript())
			{
				ArrowRender->On();
			}
			++FirstLineRenderLen;
		}
		else if (SecondLineRenderLen != OneLineSize)
		{
			if (FieldDialogTextRender[LastTextRenderIndex.y][LastTextRenderIndex.x]->IsUpdate() && !IsLastScript())
			{
				ArrowRender->On();
			}
			++SecondLineRenderLen;
		}
		else if (SecondLineRenderLen == OneLineSize)
		{
			if (FieldDialogTextRender[LastTextRenderIndex.y][LastTextRenderIndex.x]->IsUpdate() && !IsLastScript())
			{
				ArrowRender->On();
			}
		}
		else
		{
			return;
		}
	}

	if (IsValid == false)
	{
		return;
	}

	if (FieldDialogTextRender[LastTextRenderIndex.y][LastTextRenderIndex.x]->IsUpdate() && GameEngineInput::IsDown("A")) // 말걸었을때 바로 넘어가지 않게
	{
		ScriptIter++;
		if (ScriptIter != ScriptEndIter)
		{
			ClearDialog();
			FirstLineRenderLen = 0;
			SecondLineRenderLen = 0;
			StringToRender();
			ArrowRender->Off();
			DialogNextButtonSoundPlay();
		}
		else
		{
			Off();
			DialogNextButtonSoundPlay();
		}
	}
}

void FieldDialog::ChangeRenderOrder(RenderOrder _Order)
{
	FieldDialogFrame->SetOrder(static_cast<int>(_Order));
	for (size_t y = 0; y < FieldDialogTextRender.size(); y++)
	{
		for (size_t x = 0; x < FieldDialogTextRender[y].size(); x++)
		{
			FieldDialogTextRender[y][x]->SetOrder(static_cast<int>(_Order) + 1);
		}
	}
}

void FieldDialog::UpdateEnd()
{
	Player::MainPlayer->SetPlayerMoveBool(true);
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
					switch (Str[StrIndex])
					{
					case '!':
						FieldDialogTextRender[y][x]->SetFrame(81);
						break;
					case '?':
						FieldDialogTextRender[y][x]->SetFrame(82);
						break;
					case '/':
						FieldDialogTextRender[y][x]->SetFrame(85);
						break;
					case '-':
						FieldDialogTextRender[y][x]->SetFrame(86);
						break;
					//case '…':
					//	FieldDialogTextRender[y][x]->SetFrame(91);
					//	break;
					case '.':
						FieldDialogTextRender[y][x]->SetFrame(92);
						break;
					case ',':
						FieldDialogTextRender[y][x]->SetFrame(93);
						break;
					case '@':
						FieldDialogTextRender[y][x]->SetFrame(94);
						break;
					case '$':
						FieldDialogTextRender[y][x]->SetFrame(95);
						break;
					case '`':
						FieldDialogTextRender[y][x]->SetFrame(96);
						break;
					case ':':
						FieldDialogTextRender[y][x]->SetFrame(97);
						break;
					default:
						MsgAssert("아직 생각해보지 않은 글자입니다.");
					  break;
					}
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

bool FieldDialog::IsLastScript()
{
	auto NextIter = ScriptIter;
	NextIter++;
	if (NextIter != ScriptEndIter)
	{
		return false;
	}
	else
	{
		return true;
	}
}


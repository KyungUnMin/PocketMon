#include "TextActor.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
TextActor::TextActor()
{
}

TextActor::~TextActor()
{
}

void TextActor::SetAligned(bool _IsRightAligned)
{
	RightAligned = _IsRightAligned;
}

void TextActor::SetText(const std::string_view& _Str, const std::string_view& _Font, int _Order, bool _Animation)
{
	TextAnim = _Animation;
	Clear();
	SetFont(_Font, _Order);
	size_t StrEndIndex = _Str.size() - 1;
	int StrIndex = 0;
	std::string Str = _Str.data();
	if (true == RightAligned)
	{
		for (size_t i = 0; i < _Str.size(); i++)
		{
			Str[_Str.size() - 1 - i] = _Str[i];
		}
	}
	for (size_t y = 0; y < TextRender.size(); y++)
	{
		for (size_t x = 0; x < TextRender[y].size(); x++)
		{
			if (StrEndIndex < StrIndex || ' ' == Str[StrIndex])
			{
				TextRender[y][x]->SetFrame(SpaceFrameNum);
			}
			else
			{
				if (Str[StrIndex] >= 'A' && Str[StrIndex] <= 'Z')
				{
					TextRender[y][x]->SetFrame(Str[StrIndex] - 'A');
				}
				else if (Str[StrIndex] >= 'a' && Str[StrIndex] <= 'z')
				{
					TextRender[y][x]->SetFrame(Str[StrIndex] - 'a' + 27);
				}
				else if (Str[StrIndex] >= '0' && Str[StrIndex] <= '9')
				{
					TextRender[y][x]->SetFrame(Str[StrIndex] - '0' + 54);
				}
				else if (Str[StrIndex] == '\n')
				{
					while (x < TextRender[y].size())
					{
						TextRender[y][x]->SetFrame(SpaceFrameNum);
						x++;
					}
				}
				else
				{
					switch (Str[StrIndex])
					{
					case '!':
						TextRender[y][x]->SetFrame(81);
						break;
					case '?':
						TextRender[y][x]->SetFrame(82);
						break;
					case '/':
						TextRender[y][x]->SetFrame(85);
						break;
					case '-':
						TextRender[y][x]->SetFrame(86);
						break;
						//case '…':
						//	TextRender[y][x]->SetFrame(91);
						//	break;
					case '.':
						TextRender[y][x]->SetFrame(92);
						break;
					case ',':
						TextRender[y][x]->SetFrame(93);
						break;
					case '@':
						TextRender[y][x]->SetFrame(94);
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
}

void TextActor::SetText(const std::string_view& _Str, const std::string_view& _Font, bool _Animation)
{
	SetText(_Str, _Font, static_cast<int>(RenderOrder::Field_Dialog_Text), _Animation);
}
void TextActor::SetText(const std::string_view& _Str, bool _Animation)
{
	SetText(_Str, DefalutFont, static_cast<int>(RenderOrder::Field_Dialog_Text), _Animation);
}

void TextActor::SetLine(int _LineCount)
{
	LineCount = _LineCount;
}

void TextActor::SetInterver(const float4& _Interval)
{
	TextRenderInterval = _Interval;
}

void TextActor::SetAlpha(int _Alpha)
{
	for (size_t y = 0; y < TextRender.size(); y++)
	{
		for (size_t x = 0; x < TextRender[y].size(); x++)
		{
			TextRender[y][x]->SetAlpha(_Alpha);
		}
	}
}

void TextActor::SkipAnimation()
{
	for (size_t y = 0; y < LineRenderIndex.size(); y++)
	{
		LineRenderIndex[y] = OneLineSize;
	}
}

void TextActor::SetFont(const std::string_view& _Font, int _Order)
{
	if (LineCount != TextRender.size())
	{
		TextRender.resize(LineCount);
		LineRenderIndex.resize(LineCount);
	}

	for (size_t y = 0; y < TextRender.size(); y++)
	{
		if (OneLineSize != TextRender[y].size())
		{
			TextRender[y].resize(OneLineSize);
		}
		for (size_t x = 0; x < TextRender[y].size(); x++)
		{
			TextRender[y][x] = CreateRender(_Font, _Order);
			if (true == RightAligned)
			{
				TextRender[y][x]->SetPosition(FirstTextRenderPos - float4{ static_cast<float>(x),static_cast<float>(y) } *(TextRenderInterval + TextRenderImageScale));
			}
			else
			{
				TextRender[y][x]->SetPosition(FirstTextRenderPos + float4{ static_cast<float>(x),static_cast<float>(y) } *(TextRenderInterval + TextRenderImageScale));
			}
			TextRender[y][x]->SetScale(TextRenderImageScale);
			TextRender[y][x]->SetFrame(SpaceFrameNum);
			TextRender[y][x]->EffectCameraOff();
			if (true == TextAnim)
			{
				TextRender[y][x]->Off();
			}
		}
	}
}

void TextActor::Clear()
{
	for (size_t y = 0; y < TextRender.size(); y++)
	{
		for (size_t x = 0; x < TextRender[y].size(); x++)
		{
			TextRender[y][x]->SetFrame(SpaceFrameNum);
			TextRender[y][x]->Off();
		}
	}
}

void TextActor::Start()
{

}

void TextActor::Update(float _DeltaTime)
{
	if (false == TextAnim) { return; }

	for (size_t y = 0; y < LineRenderIndex.size() ; y++)
	{
		for (size_t x = 0; x < LineRenderIndex[y]; x++)
		{
			TextRender[y][x]->On();
		}
	}

	Time += _DeltaTime;
	if (Time >= 0.03)
	{
		Time = 0;
		for (size_t y = 0; y < LineRenderIndex.size(); y++)
		{
			if (LineRenderIndex[y] < OneLineSize)
			{
				LineRenderIndex[y]++;
				return;
			}
		}
	}

}

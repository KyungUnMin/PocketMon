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
					//	break;
					//}

					MsgAssert("���� �����غ��� ���� �����Դϴ�.");
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

void TextActor::SkipAnimation()
{
	for (size_t y = 0; y < LineRenderIndex.size(); y++)
	{
		LineRenderIndex[y] = OneLineSize;
	}
}

bool TextActor::IsAnimationEnd()
{
	for (size_t y = 0; y < LineRenderIndex.size(); y++)
	{
		if (LineRenderIndex[y] < OneLineSize)
		{
			return false;
		}
	}
	return true;
}

void TextActor::SetFont(const std::string_view& _Font, int _Order)
{
	TextRender.resize(LineCount);
	LineRenderIndex.resize(LineCount);

	for (size_t y = 0; y < TextRender.size(); y++)
	{
		TextRender[y].resize(OneLineSize);
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

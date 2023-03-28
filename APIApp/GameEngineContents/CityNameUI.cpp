#include "CityNameUI.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "TextActor.h"
#include "ContentsEnum.h"

CityNameUI* CityNameUI::FieldmapCityNameUI = nullptr;

CityNameUI::CityNameUI()
{
}

CityNameUI::~CityNameUI()
{
}

void CityNameUI::Init(const float4& _StartPos, const float4& _EndPos)
{
	StartPos = _StartPos;
	DestPos = _EndPos;
}

void CityNameUI::PlayText(const std::string_view& _CityName)
{
	CityText = _CityName;
}

void CityNameUI::Start()
{
	if (nullptr != FieldmapCityNameUI)
	{
		MsgAssert("필드맵 이름 UI가 중복 생성되었습니다");
	}

	FieldmapCityNameUI = this;

	BackgroundActor = CreateRender("CityNameUI.BMP", RenderOrder::Field_MainMenu);	
	BackgroundActor->EffectCameraOff();
	BackgroundActor->SetScale(float4(400, 75));

	TextPtr = GetLevel()->CreateActor<TextActor>();
	TextPtr->SetLine(1);
}

void CityNameUI::Update(float _DeltaTime)
{
	switch (State)
	{
	case CityNameUI::TextState::Idle:
		IdleUpdate(_DeltaTime);
		return;
	case CityNameUI::TextState::Play:
		PlayUpdate(_DeltaTime);
		break;
	case CityNameUI::TextState::Reset:
		ResetUpdate(_DeltaTime);
		break;
	default:
		MsgAssert("잘못된 CityNameUI 스테이트 입니다.");
		break;
	}

	TextPtr->SetPos(GetPos() - float4(160, 0));
}

void CityNameUI::ChangeState(TextState _ChangeState)
{
	if (State == _ChangeState)
	{
		return;
	}

	switch (State)
	{
	case CityNameUI::TextState::Idle:
		IdleEnd();
		break;
	case CityNameUI::TextState::Play:
		PlayEnd();
		break;
	case CityNameUI::TextState::Reset:
		ResetEnd();
		break;
	}

	switch (_ChangeState)
	{
	case CityNameUI::TextState::Idle:
		IdleStart();
		break;
	case CityNameUI::TextState::Play:
		PlayStart();
		break;
	case CityNameUI::TextState::Reset:
		ResetStart();
		break;
	}

	State = _ChangeState;
}

void CityNameUI::IdleStart()
{

}

void CityNameUI::IdleUpdate(float _DeltaTime)
{
	if ("" != CityText)
	{
		TextPtr->SetText(CityText, "Font_Dialog_Black2.bmp", static_cast<int>(RenderOrder::Field_MainMenu));
		CityText.clear();
		ChangeState(TextState::Play);
	}
}

void CityNameUI::IdleEnd()
{

}

void CityNameUI::PlayStart()
{

}

void CityNameUI::PlayUpdate(float _DeltaTime)
{
	if ("" != CityText)
	{
		if (1.0f <= Progress)
		{
			Progress = 1.0f;
		}

		ChangeState(TextState::Reset);
	}

	Progress += _DeltaTime * Speed;
	SetPos(float4::LerpClamp(StartPos, DestPos, Progress));

	if (3.0f <= Progress)
	{
		Progress = 1.0f;
		ChangeState(TextState::Reset);
	}
}

void CityNameUI::PlayEnd()
{

}

void CityNameUI::ResetStart()
{

}

void CityNameUI::ResetUpdate(float _DeltaTime)
{
	Progress -= _DeltaTime * Speed;
	SetPos(float4::LerpClamp(StartPos, DestPos, Progress));

	if (0.0f >= Progress)
	{
		Progress = 0.0f;
		State = TextState::Idle;
	}
}

void CityNameUI::ResetEnd()
{
}
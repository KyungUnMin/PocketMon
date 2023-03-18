#include "FieldmapCity.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineCore/GameEngineRender.h>
#include "Fieldmap.h"

FieldmapCity::FieldmapCity()
{
}

FieldmapCity::~FieldmapCity()
{
}

void FieldmapCity::InitPos(const float4& _CityPos)
{
	SetPos(_CityPos);

	if (nullptr == CityRenderer)
	{
		MsgAssert("아직 필드맵 시티가 생성되지 않았습니다.");
	}

	CityPos = _CityPos - CityRenderer->GetScale().half();
}

void FieldmapCity::InitFieldRender(const std::string_view& _ImageName)
{
	if (nullptr != CityRenderer)
	{
		MsgAssert("필드맵 시티를 중복 초기화 했습니다");
	}

	CityRenderer = CreateRender(_ImageName);
	CityRenderer->SetScaleToImage();
	//CityRenderer->
}

void FieldmapCity::Update(float _DeltaTime)
{
	// 콜리전 체크해서 켰다 껏다
}
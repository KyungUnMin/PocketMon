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
		MsgAssert("���� �ʵ�� ��Ƽ�� �������� �ʾҽ��ϴ�.");
	}

	CityPos = _CityPos - CityRenderer->GetScale().half();
}

void FieldmapCity::InitFieldRender(const std::string_view& _ImageName)
{
	if (nullptr != CityRenderer)
	{
		MsgAssert("�ʵ�� ��Ƽ�� �ߺ� �ʱ�ȭ �߽��ϴ�");
	}

	CityRenderer = CreateRender(_ImageName);
	CityRenderer->SetScaleToImage();
}

void FieldmapCity::Update(float _DeltaTime)
{
	// �ݸ��� üũ�ؼ� �״� ����
}
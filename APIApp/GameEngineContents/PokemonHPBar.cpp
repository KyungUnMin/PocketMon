#include "PokemonHPBar.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
PokemonHPBar::PokemonHPBar() 
{
}

PokemonHPBar::~PokemonHPBar() 
{
}

void PokemonHPBar::SetValue(float _Value)
{
	StartValue = _Value;
	CurrentValue = _Value;
	TargetValue = _Value;

	float4 Scale = { 0, 172 };
	Scale.x = std::lerp(0, 192, CurrentValue);
	float4 Pos = { Scale.x * 0.5f , 0 };

	BarRender->SetScale(Scale);
	BarRender->SetPosition(Pos);

	if (0.5f < CurrentValue)
	{
		BarRender->SetImage("FriendlyHPBar.bmp");
	}
	else if (0.33f < CurrentValue)
	{
		BarRender->SetImage("FriendlyHP50Bar.bmp");
	}
	else
	{
		BarRender->SetImage("FriendlyHP30Bar.bmp");
	}
}

void PokemonHPBar::SetTargetValue(float _Value)
{
	StartValue = CurrentValue;
	TargetValue = _Value;
	Timer = 0;
}

void PokemonHPBar::Start()
{
	BarRender = CreateRender("FriendlyHPBar.bmp", BattleRenderOrder::Battle_Text);
	BarRender->SetScale(float4{ 192, 172 });
}

void PokemonHPBar::Update(float _DeltaTime)
{
	if (1 < Timer) { return; }
	Timer += _DeltaTime;

	CurrentValue = std::lerp(StartValue, TargetValue, Timer);

	float4 Scale = { 0, 172 };
	Scale.x = std::lerp(0, 192, CurrentValue);
	float4 Pos = {Scale.x * 0.5f , 0 };

	BarRender->SetScale(Scale);
	BarRender->SetPosition(Pos);

	if (0.5f < CurrentValue)
	{
		BarRender->SetImage("FriendlyHPBar.bmp");
	}
	else if (0.33f < CurrentValue)
	{
		BarRender->SetImage("FriendlyHP50Bar.bmp");
	}
	else
	{
		BarRender->SetImage("FriendlyHP30Bar.bmp");
	}
}


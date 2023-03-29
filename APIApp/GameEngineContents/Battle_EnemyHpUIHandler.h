#pragma once
#include "Battle_HpUIHandlerBase.h"

class Battle_EnemyHpUIHandler : public Battle_HpUIHandlerBase
{
public:
	Battle_EnemyHpUIHandler();
	~Battle_EnemyHpUIHandler() override;

	Battle_EnemyHpUIHandler(const Battle_EnemyHpUIHandler& _Other) = delete;
	Battle_EnemyHpUIHandler(Battle_EnemyHpUIHandler&& _Other) noexcept = delete;
	Battle_EnemyHpUIHandler& operator=(const Battle_EnemyHpUIHandler& _Other) = delete;
	Battle_EnemyHpUIHandler& operator=(const Battle_EnemyHpUIHandler&& _Other) noexcept = delete;

	void OnDamage(int _Value) override;

protected:
	void Start() override;

private:
	const float4 StartOffset = float4::Left * 500.f;
	const float4 DestOffset = float4::Left * 50.f;
	const float4 Offset = float4::Zero;

	class EnemyHPBackground* UI = nullptr;
};


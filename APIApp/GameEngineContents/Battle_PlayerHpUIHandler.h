#pragma once
#include "Battle_HpUIHandlerBase.h"

class Battle_PlayerHpUIHandler : public Battle_HpUIHandlerBase
{
public:
	Battle_PlayerHpUIHandler();
	~Battle_PlayerHpUIHandler() override;

	Battle_PlayerHpUIHandler(const Battle_PlayerHpUIHandler& _Other) = delete;
	Battle_PlayerHpUIHandler(Battle_PlayerHpUIHandler&& _Other) noexcept = delete;
	Battle_PlayerHpUIHandler& operator=(const Battle_PlayerHpUIHandler& _Other) = delete;
	Battle_PlayerHpUIHandler& operator=(const Battle_PlayerHpUIHandler&& _Other) noexcept = delete;

	void OnDamage(int _Value) override;

	bool IsLevelUp() override;

protected:
	void Start() override;

private:
	class FriendlyHPBackground* UI = nullptr;
	const float4 DestOffset = float4::Right * 250.f;
	const float4 StartOffset = float4::Right * 750.f;
	const float4 Offset = float4::Zero;

};


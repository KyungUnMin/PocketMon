#pragma once

#include <GameEngineCore/GameEngineActor.h>

// ���� :
class EffectBlackBox : public GameEngineActor
{
public:
	// constrcuter destructer
	EffectBlackBox();
	~EffectBlackBox();

	// delete Function
	EffectBlackBox(const EffectBlackBox& _Other) = delete;
	EffectBlackBox(EffectBlackBox&& _Other) noexcept = delete;
	EffectBlackBox& operator=(const EffectBlackBox& _Other) = delete;
	EffectBlackBox& operator=(EffectBlackBox&& _Other) noexcept = delete;

	void MoveStart()
	{
		IsStart = true;
	}

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

	float4 Winsize_h = float4::Zero;
	float4 StartPos = float4::Zero;
	float4 EndPos = float4::Zero;

	bool IsStart = false;

	void MoveUp();
};


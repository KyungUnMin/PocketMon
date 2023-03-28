#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
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

	void MoveStart_Down()
	{
		IsDownStart = true;
	}

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

	float4 Winsize_h = float4::Zero;
	float4 StartPos = float4::Zero;
	float4 EndPos = float4::Zero;
	float4 DownStartPos = float4::Zero;
	float4 DownEndPos = float4::Zero;

	float MoveTime = 0.0f;

	bool IsStart = false;
	bool IsDownStart = false;

	void MoveUp(float _Deltatime);
	void MoveUp_Down(float _Deltatime);
};


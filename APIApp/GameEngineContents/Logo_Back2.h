#pragma once

#include <GameEngineCore/GameEngineActor.h>

// ���� :
class Logo_Back2 : public GameEngineActor
{
public:
	// constrcuter destructer
	Logo_Back2();
	~Logo_Back2();

	// delete Function
	Logo_Back2(const Logo_Back2& _Other) = delete;
	Logo_Back2(Logo_Back2&& _Other) noexcept = delete;
	Logo_Back2& operator=(const Logo_Back2& _Other) = delete;
	Logo_Back2& operator=(Logo_Back2&& _Other) noexcept = delete;

	void LerpStart()
	{
		IsStart = true;
	}

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

	float4 StartPos = float4::Zero;
	float4 EndPos = float4::Zero;

	float MoveTime = 0.0f;
	bool IsStart = false;
};


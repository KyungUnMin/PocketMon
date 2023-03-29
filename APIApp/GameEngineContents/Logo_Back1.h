#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Logo_Back1 : public GameEngineActor
{
public:
	// constrcuter destructer
	Logo_Back1();
	~Logo_Back1();

	// delete Function
	Logo_Back1(const Logo_Back1& _Other) = delete;
	Logo_Back1(Logo_Back1&& _Other) noexcept = delete;
	Logo_Back1& operator=(const Logo_Back1& _Other) = delete;
	Logo_Back1& operator=(Logo_Back1&& _Other) noexcept = delete;

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


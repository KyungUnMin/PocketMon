#pragma once

#include <GameEngineCore/GameEngineActor.h>

// ���� :
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

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:

};


#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Logo_Back3 : public GameEngineActor
{
public:
	// constrcuter destructer
	Logo_Back3();
	~Logo_Back3();

	// delete Function
	Logo_Back3(const Logo_Back3& _Other) = delete;
	Logo_Back3(Logo_Back3&& _Other) noexcept = delete;
	Logo_Back3& operator=(const Logo_Back3& _Other) = delete;
	Logo_Back3& operator=(Logo_Back3&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:

};


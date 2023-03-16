#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BackTextActor : public GameEngineActor
{
public:
	// constrcuter destructer
	BackTextActor();
	~BackTextActor();

	// delete Function
	BackTextActor(const BackTextActor& _Other) = delete;
	BackTextActor(BackTextActor&& _Other) noexcept = delete;
	BackTextActor& operator=(const BackTextActor& _Other) = delete;
	BackTextActor& operator=(BackTextActor&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};


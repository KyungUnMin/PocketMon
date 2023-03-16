#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class CenterActor : public GameEngineActor
{
public:
	// constrcuter destructer
	CenterActor();
	~CenterActor();

	// delete Function
	CenterActor(const CenterActor& _Other) = delete;
	CenterActor(CenterActor&& _Other) noexcept = delete;
	CenterActor& operator=(const CenterActor& _Other) = delete;
	CenterActor& operator=(CenterActor&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};


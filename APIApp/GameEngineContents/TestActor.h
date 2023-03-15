#pragma once
#include <GameEngineCore/GameEngineActor.h>

class TestActor : public GameEngineActor
{
public:
	TestActor();
	~TestActor();

	TestActor(const TestActor& _Other) = delete;
	TestActor(TestActor&& _Other) noexcept = delete;
	TestActor& operator=(const TestActor& _Other) = delete;
	TestActor& operator=(const TestActor&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};


#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class TestLevel : public GameEngineLevel
{
public:
	TestLevel();
	~TestLevel();

	TestLevel(const TestLevel& _Other) = delete;
	TestLevel(TestLevel&& _Other) noexcept = delete;
	TestLevel& operator=(const TestLevel& _Other) = delete;
	TestLevel& operator=(const TestLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeStart(GameEngineLevel* _PrevLevel) override{}
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override{}

private:

};


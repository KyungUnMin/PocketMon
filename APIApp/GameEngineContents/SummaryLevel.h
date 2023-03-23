#pragma once
#include <GameEngineCore/GameEngineLevel.h>
// Ό³Έν :
class SummaryLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	SummaryLevel();
	~SummaryLevel();

	// delete Function
	SummaryLevel(const SummaryLevel& _Other) = delete;
	SummaryLevel(SummaryLevel&& _Other) noexcept = delete;
	SummaryLevel& operator=(const SummaryLevel& _Other) = delete;
	SummaryLevel& operator=(SummaryLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
private:

};


#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class TrainerCardUI;
class TrainerCardLevel : public GameEngineLevel
{
public:
	// construtor destructor
	TrainerCardLevel();
	~TrainerCardLevel();

	// delete Function
	TrainerCardLevel(const TrainerCardLevel& _Other) = delete;
	TrainerCardLevel(TrainerCardLevel&& _Other) noexcept = delete;
	TrainerCardLevel& operator=(const TrainerCardLevel& _Other) = delete;
	TrainerCardLevel& operator=(TrainerCardLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel);
	void LevelChangeStart(GameEngineLevel* _PrevLevel);

private:
	TrainerCardUI* AcTrainerCardUI = nullptr;

	void ImageLoad();
};


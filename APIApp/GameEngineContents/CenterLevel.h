#pragma once

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineResources.h>

// Ό³Έν :
class CenterLevel : public GameEngineLevel
{
public:
	GameEngineSoundPlayer BGMPlayer;

	// constrcuter destructer
	CenterLevel();
	~CenterLevel();

	// delete Function
	CenterLevel(const CenterLevel& _Other) = delete;
	CenterLevel(CenterLevel&& _Other) noexcept = delete;
	CenterLevel& operator=(const CenterLevel& _Other) = delete;
	CenterLevel& operator=(CenterLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;

private:

};


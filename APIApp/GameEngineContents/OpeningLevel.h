#pragma once

#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class Opening_Text;
class OpeningLevel : public GameEngineLevel
{
public:
	GameEngineTimeEvent LevelEvent;

	// constrcuter destructer
	OpeningLevel();
	~OpeningLevel();

	// delete Function
	OpeningLevel(const OpeningLevel& _Other) = delete;
	OpeningLevel(OpeningLevel&& _Other) noexcept = delete;
	OpeningLevel& operator=(const OpeningLevel& _Other) = delete;
	OpeningLevel& operator=(OpeningLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;

private:
	Opening_Text* OpeningText = nullptr;

};


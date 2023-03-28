#pragma once

#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class EffectBlackBox;
class Opening_Text;
class Logo_Charizard;
class Logo_Charizard_White;
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
	EffectBlackBox* EffectBox = nullptr;
	Opening_Text* OpeningText = nullptr;
	Logo_Charizard* Zardlogo = nullptr;
	Logo_Charizard_White* Zardlogo_White = nullptr;
};


#pragma once

#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class EffectBlackBox;
class Opening_Text;
class Logo_Charizard;
class Logo_Charizard_White;
class Logo_Back1;
class Logo_Back2;
class Logo_Back3;
class Logo_Pokemon;
class Logo_Fireredversion;
class Logo_PressStart;
class Logo_Backeffect;
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

	static OpeningLevel* GetOpeningLevelPtr()
	{
		return OpeningLevelPtr;
	}
	
	EffectBlackBox* GetEffectBlackBox2()
	{
		return EffectBox2;
	}

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;

private:
	static OpeningLevel* OpeningLevelPtr;
	
	EffectBlackBox* EffectBox1 = nullptr;
	EffectBlackBox* EffectBox2 = nullptr;
	EffectBlackBox* EffectBox3 = nullptr;
	EffectBlackBox* EffectBox4 = nullptr;
	EffectBlackBox* EffectBox5 = nullptr;
	EffectBlackBox* EffectBox6 = nullptr;

	Opening_Text* OpeningText = nullptr;
	
	Logo_Charizard* Zardlogo = nullptr;
	Logo_Charizard_White* Zardlogo_White = nullptr;
	Logo_Back1* RedBack = nullptr;
	Logo_Back2* GreenBack = nullptr;
	Logo_Back3* BlackBack = nullptr;

	Logo_Pokemon* PokemonTitle = nullptr;
	Logo_Fireredversion* FireV = nullptr;
	Logo_PressStart* PressStart = nullptr;
	Logo_Backeffect* Burnning = nullptr;
};


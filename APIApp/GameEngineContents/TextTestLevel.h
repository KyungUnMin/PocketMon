#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class TextTestLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	TextTestLevel();
	~TextTestLevel();

	// delete Function
	TextTestLevel(const TextTestLevel& _Other) = delete;
	TextTestLevel(TextTestLevel&& _Other) noexcept = delete;
	TextTestLevel& operator=(const TextTestLevel& _Other) = delete;
	TextTestLevel& operator=(TextTestLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;
private:

};


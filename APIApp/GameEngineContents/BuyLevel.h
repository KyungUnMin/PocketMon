#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class BuyLevel : public GameEngineLevel
{
public:
	// construtor destructor
	BuyLevel();
	~BuyLevel();

	// delete Function
	BuyLevel(const BuyLevel& _Other) = delete;
	BuyLevel(BuyLevel&& _Other) noexcept = delete;
	BuyLevel& operator=(const BuyLevel& _Other) = delete;
	BuyLevel& operator=(BuyLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) {}

private:

};


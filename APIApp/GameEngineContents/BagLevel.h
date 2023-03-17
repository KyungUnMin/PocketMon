#pragma once
#include <GameEngineCore/GameEngineLevel.h>
// Ό³Έν : 
class BagLevel : public GameEngineLevel
{
public:
	// constructer destructer
	BagLevel();
	~BagLevel();
	
	// delete Function
	BagLevel(const BagLevel& _Other) = delete;
	BagLevel(BagLevel&& _Other) = delete;
	BagLevel& operator=(const BagLevel& _Other) = delete;
	BagLevel& operator=(BagLevel&& _Other) = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
private:

};

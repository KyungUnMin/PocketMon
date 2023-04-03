#pragma once
#include <GameEngineCore/GameEngineActor.h>
class PlayTime : public GameEngineActor
{
public:
	static PlayTime* MianPlayTime;

	// construtor destructor
	PlayTime();
	~PlayTime();

	// delete Function
	PlayTime(const PlayTime& _Other) = delete;
	PlayTime(PlayTime&& _Other) noexcept = delete;
	PlayTime& operator=(const PlayTime& _Other) = delete;
	PlayTime& operator=(PlayTime&& _Other) noexcept = delete;

	int Hour = 0;
	int Minute = 0;
	float Second = 0;
	void Update(float _DeltaTime) override;

protected:


private:


};


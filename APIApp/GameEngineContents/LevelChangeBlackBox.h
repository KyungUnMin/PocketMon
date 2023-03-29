#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class LevelChangeBlackBox : public GameEngineActor
{
public:
	// constrcuter destructer
	LevelChangeBlackBox();
	~LevelChangeBlackBox();

	// delete Function
	LevelChangeBlackBox(const LevelChangeBlackBox& _Other) = delete;
	LevelChangeBlackBox(LevelChangeBlackBox&& _Other) noexcept = delete;
	LevelChangeBlackBox& operator=(const LevelChangeBlackBox& _Other) = delete;
	LevelChangeBlackBox& operator=(LevelChangeBlackBox&& _Other) noexcept = delete;

	void BlackBoxAlphaStart()
	{
		IsStart = true;
	}

	bool GetIsEnd()
	{
		return IsEnd;
	}

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

	int AlphaValue = 0;
	float AlphaTime = 0.0f;
	bool IsStart = false;
	bool IsEnd = false;

	void AlphaSet(float _Deltatime);
};


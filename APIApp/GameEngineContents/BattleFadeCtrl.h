#pragma once
#include <functional>
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;

class BattleFadeCtrl : public GameEngineActor
{
public:
	enum class FadeType
	{
		WhiteIn,
		WhiteOut,
		BlackIn,
		BlackOut,

		UNKNOWN
	};

	BattleFadeCtrl();
	~BattleFadeCtrl() override;

	BattleFadeCtrl(const BattleFadeCtrl& _Other) = delete;
	BattleFadeCtrl(BattleFadeCtrl&& _Other) noexcept = delete;
	BattleFadeCtrl& operator=(const BattleFadeCtrl& _Other) = delete;
	BattleFadeCtrl& operator=(const BattleFadeCtrl&& _Other) noexcept = delete;

	void Init(FadeType _FadeType, const std::function<void()>& _Event = nullptr);
	
	inline void SetDuration(float _Time)
	{
		Duration = _Time;
	}

protected:
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* FadeRender = nullptr;
	std::function<void()> Event = nullptr;
	FadeType Type = FadeType::UNKNOWN;
	float Duration = 0.5f;
};


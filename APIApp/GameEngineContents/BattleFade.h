#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <functional>

class GameEngineRender;
class BattleFade : public GameEngineActor
{
private:
	enum class FadeState
	{
		In,
		Out,
	};
public:
	static BattleFade* GetFieldmapBattleFade()
	{
		return FieldmapBattleFade;
	}

private:
	static BattleFade* FieldmapBattleFade;
public:
	BattleFade();
	~BattleFade();

	BattleFade(const BattleFade& _Other) = delete;
	BattleFade(BattleFade&& _Other) noexcept = delete;
	BattleFade& operator=(const BattleFade& _Other) = delete;
	BattleFade& operator=(BattleFade&& _Other) noexcept = delete;

	void PlayBattleFade(int _Count, float _Speed, std::function<void()> _EndEvent);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* FadeRender = nullptr;
	GameEngineRender* FadeUpRender = nullptr;
	GameEngineRender* FadeDownRender = nullptr;

	float ProgressTime = 0.0f;
	float Speed = 0.0f;

	int LoopCount = 2;
	int CurCount = 0;

	bool IsLastFadePlay = false;

	FadeState State = FadeState::In;
	std::function<void()> EndEvent = nullptr;

	float4 FadeUpStartPos = float4::Zero;
	float4 FadeUpEndPos = float4::Zero;
	float4 FadeDownStartPos = float4::Zero;
	float4 FadeDownEndPos = float4::Zero;
};


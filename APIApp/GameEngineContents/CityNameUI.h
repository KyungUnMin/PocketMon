#pragma once
#include <GameEngineCore/GameEngineActor.h>

class TextActor;
class GameEngineRender;
class CityNameUI : public GameEngineActor
{
public:
	static CityNameUI* FieldmapCityNameUI;

private:
	enum class TextState
	{
		Idle,
		Play,
		Reset
	};
public:
	CityNameUI();
	~CityNameUI();

	CityNameUI(const CityNameUI& _Other) = delete;
	CityNameUI(CityNameUI&& _Other) noexcept = delete;
	CityNameUI& operator=(const CityNameUI& _Other) = delete;
	CityNameUI& operator=(CityNameUI&& _Other) noexcept = delete;

	void Init(const float4& _StartPos, const float4& _EndPos);
	void PlayText(const std::string_view& _CityName);

	inline void SetSpeed(float _Speed)
	{
		Speed = _Speed;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	GameEngineRender* BackgroundActor = nullptr;
	TextActor* TextPtr = nullptr;

	std::string CityText = "";

	TextState State = TextState::Idle;

	float4 StartPos = float4::Zero;
	float4 DestPos = float4::Zero;
	float Progress = 0.0f;
	float Speed = 1.0f;

	void ChangeState(TextState _ChangeState);

	void IdleStart();
	void IdleUpdate(float _DeltaTime);
	void IdleEnd();

	void PlayStart();
	void PlayUpdate(float _DeltaTime);
	void PlayEnd();

	void ResetStart();
	void ResetUpdate(float _DeltaTime);
	void ResetEnd();
};
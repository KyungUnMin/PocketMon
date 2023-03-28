#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <string>

enum class FadeState
{
	FadeIn,
	FadeOut
};
// Ό³Έν :
class LevelChangeFade : public GameEngineActor
{
public:
	// constrcuter destructer
	LevelChangeFade();
	~LevelChangeFade();

	static LevelChangeFade* MainLevelFade;

	void LevelChangeFadeOut(GameEngineLevel* _Level);
	void LevelChangeFadeOut(const std::string_view& _LevelName);

	// delete Function
	LevelChangeFade(const LevelChangeFade& _Other) = delete;
	LevelChangeFade(LevelChangeFade&& _Other) noexcept = delete;
	LevelChangeFade& operator=(const LevelChangeFade& _Other) = delete;
	LevelChangeFade& operator=(LevelChangeFade&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
private:
	std::string_view NextLevelName = "";
	FadeState StateValue = FadeState::FadeIn;
	GameEngineRender* FadeRender = nullptr;
	const float FadeSpeed = 5.0f;
	float Timer = 0;
};


#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class LevelChangeFade : GameEngineActor
{
public:
	// constrcuter destructer
	LevelChangeFade();
	~LevelChangeFade();

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
	GameEngineRender* FadeRender = nullptr;
	float Timer = 0;
};


#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class GameEngineRender;

enum class BattleFieldType
{
	Indoor,
	Grass,
	Stone,
};

class BattleLevel : public GameEngineLevel
{
public:
	BattleLevel();
	~BattleLevel() override;

	BattleLevel(const BattleLevel& _Other) = delete;
	BattleLevel(BattleLevel&& _Other) noexcept = delete;
	BattleLevel& operator=(const BattleLevel& _Other) = delete;
	BattleLevel& operator=(const BattleLevel&& _Other) noexcept = delete;

	//맵 레벨에서 배틀레벨로 전환될때 호출해주시면 됩니다.
	void Init(BattleFieldType _FieldType = BattleFieldType::Grass);

protected:
	void Loading() override{}
	void Update(float _DeltaTime) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel);
	void LevelChangeStart(GameEngineLevel* _PrevLevel);

private:
	GameEngineRender* FadeDownRender = nullptr;
	GameEngineRender* FadeUpRender = nullptr;

};


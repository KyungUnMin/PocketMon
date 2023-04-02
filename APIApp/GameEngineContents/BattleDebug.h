#pragma once
#include <GameEngineCore/GameEngineActor.h>

class BattleDebug : public GameEngineActor
{
public:
	static const std::vector<std::string_view> DebugKeys;

	BattleDebug();
	~BattleDebug() override;

	BattleDebug(const BattleDebug& _Other) = delete;
	BattleDebug(BattleDebug&& _Other) noexcept = delete;
	BattleDebug& operator=(const BattleDebug& _Other) = delete;
	BattleDebug& operator=(const BattleDebug&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime)  override;

private:
	void ChangeWildMonster(size_t _Index);
};


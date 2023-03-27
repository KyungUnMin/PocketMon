#pragma once
#include "BattleCommendActor.h"
#include "BattlePlayer.h"
#include "BattleEnemy.h"
#include "BattleCommendActor.h"
#include "FriendlyHPBackground.h"

// Ό³Έν :
class LevelUpStatUI : public GameEngineActor
{
public:

	static LevelUpStatUI* LevelUpStatUIPtr;
	LevelUpStatUI();
	~LevelUpStatUI() override;

	// delete Function
	LevelUpStatUI(const LevelUpStatUI& _Other) = delete;
	LevelUpStatUI(LevelUpStatUI&& _Other) noexcept = delete;
	LevelUpStatUI& operator=(const LevelUpStatUI& _Other) = delete;
	LevelUpStatUI& operator=(LevelUpStatUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;


private:



};


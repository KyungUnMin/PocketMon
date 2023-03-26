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
	std::vector<GameEngineRender*> LevelUpStat1_R;
	std::vector<GameEngineRender*> LevelUpStat2_R;
	std::vector<GameEngineRender*> LevelUpStat3_R;
	std::vector<GameEngineRender*> LevelUpStat4_R;
	std::vector<GameEngineRender*> LevelUpStat5_R;
	std::vector<GameEngineRender*> LevelUpStat6_R;


	float4 EnemyPoketMonName_S = { 100,120 };
	float4 EnemyPoketMonLevel_S = { 385,120 };

	float4 TextRenderImageScale = { 20, 40 };
	float4 TextRenderInterval = { 0,12 };

	int SpaceFrameNum = 26;
	int PoketMonStatMax = 4;


	GameEngineRender* LevelUpStatUIPtr_R = nullptr;
	std::vector<float> EnemyDamegeTick;

};


#pragma once
#include "BattleCommendActor.h"
#include "BattlePlayer.h"
#include "BattleEnemy.h"
#include "BattleCommendActor.h"
#include "FriendlyHPBackground.h"

// ���� :
class LevelUpStatUI_2 : public GameEngineActor
{
public:

	static LevelUpStatUI_2* LevelUpStatUIPtr_2;
	LevelUpStatUI_2();
	~LevelUpStatUI_2() override;

	// delete Function
	LevelUpStatUI_2(const LevelUpStatUI_2& _Other) = delete;
	LevelUpStatUI_2(LevelUpStatUI_2&& _Other) noexcept = delete;
	LevelUpStatUI_2& operator=(const LevelUpStatUI_2& _Other) = delete;
	LevelUpStatUI_2& operator=(LevelUpStatUI_2&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void StringToRender(std::vector<GameEngineRender*> _Render, std::string_view _Str);


private:
	std::vector<GameEngineRender*> LevelUpStat1_R;
	std::vector<GameEngineRender*> LevelUpStat2_R;
	std::vector<GameEngineRender*> LevelUpStat3_R;
	std::vector<GameEngineRender*> LevelUpStat4_R;
	std::vector<GameEngineRender*> LevelUpStat5_R;
	std::vector<GameEngineRender*> LevelUpStat6_R;



	float4 TextRenderImageScale = { 20, 45 };
	float4 TextRenderInterval = { 0,12 };

	int SpaceFrameNum = 26;
	int PoketMonStatMax = 4;

	float4 LevelUpStatPos = { 430,215 };
	//float4 PoketMonLevel_S = { 640,317 };

	GameEngineRender* LevelUpStatUIPtr_R = nullptr;
	std::vector<float> EnemyDamegeTick;

};


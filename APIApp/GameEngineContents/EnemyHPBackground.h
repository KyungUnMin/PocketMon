#pragma once
#include "BattleCommendActor.h"
#include "BattlePlayer.h"
#include "BattleEnemy.h"
#include "BattleCommendActor.h"
#include "FriendlyHPBackground.h"
#include "BattleEnemy.h"
// Ό³Έν :
class EnemyHPBackground : public GameEngineActor
{
public:
	static EnemyHPBackground* EnemyPtr;
	EnemyHPBackground();
	~EnemyHPBackground() override;

	// delete Function
	EnemyHPBackground(const EnemyHPBackground& _Other) = delete;
	EnemyHPBackground(EnemyHPBackground&& _Other) noexcept = delete;
	EnemyHPBackground& operator=(const EnemyHPBackground& _Other) = delete;
	EnemyHPBackground& operator=(EnemyHPBackground&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void StringToRender(std::vector<GameEngineRender*> _Render, std::string_view _Str);
	void Clear(std::vector<float> _Tick);


	bool IsBattleStartCheck(bool _Value);
	float GetPlayerDamage(float _EnumyMonsterDamage);
	void HpUpdate(float _EnumyMonsterDamage, float _MyCurHp);


private:

	PokeDataBase NewTestMon1 = PokeDataBase::PokeCreate(4, 15);

	std::vector<GameEngineRender*> EnemyPoketMonName_R;
	std::vector<GameEngineRender*> EnemyPoketMonLevel_R;


	float4 EnemyPoketMonName_S = { 100,120 };
	float4 EnemyPoketMonLevel_S = { 385,120 };

	float4 TextRenderImageScale = { 20, 40 };
	float4 TextRenderInterval = { 0,12 };

	int SpaceFrameNum = 26;
	int PoketMonNameMax = 12;
	int PoketMonLevelMax = 2;
	float NextTickTime_2 = 0.0f;
	int TickNumber_2 = 0;
	GameEngineRender* EnemyHPRenderPtr = nullptr;
	std::vector<float> EnemyDamegeTick;




	float CurMyHP = 0.0f;

	float FrinedMonsterDamage = 0.0f;
	float MyCurHp = 0.0f;
	bool BattleStartCheck = false;
};


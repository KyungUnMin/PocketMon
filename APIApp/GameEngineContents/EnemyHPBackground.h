#pragma once
#include "BattleCommendActor.h"
#include "BattlePlayer.h"
#include "BattleEnemy.h"
#include "BattleCommendActor.h"
#include "FriendlyHPBackground.h"
#include "BattleEnemy.h"
// ���� :
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
	void Clear(std::vector<float> _Tick);


	bool IsBattleStartCheck(bool _Value);
	float GetPlayerDamage(float _EnumyMonsterDamage);
	void HpUpdate(float _EnumyMonsterDamage, float _MyCurHp, float _curpos);

	GameEngineRender* GetWindowPtr()
	{
		return RenderPtr;
	}

	GameEngineRender* GetHPPtr()
	{
		return EnemyHPRenderPtr;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void StringToRender(std::vector<GameEngineRender*> _Render, std::string_view _Str);


private:

	PokeDataBase NewTestMon1 = PokeDataBase::PokeCreate(4, 15);

	std::vector<GameEngineRender*> EnemyPoketMonName_R;
	std::vector<GameEngineRender*> EnemyPoketMonLevel_R;

	GameEngineRender* RenderPtr = nullptr;

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
	GameEngineRender* EnemyHPRenderPtr1 = nullptr;
	GameEngineRender* EnemyHPRenderPtr2 = nullptr;
	std::vector<float> EnemyDamegeTick;


	float Num = static_cast<float>(BattleEnemy::EnemyPtr->GetMonsterDB()->GetMonsterCurrentHP());
	float Num1 = static_cast<float>(BattleEnemy::EnemyPtr->GetMonsterDB()->GetMonsterMaxHP_int());
	float FirstNum = Num / Num1;
	float FirstHp = GameEngineMath::Lerp(192.0f, 0.0f, FirstNum);
	float MyCurHpNum = CurMyHP - FirstHp;

	float SecoundHp = 0.0f;

	float Hp50Under = 98.0f;
	float Hp30Under = 48.0f;



	float CurMyHP = 192.0f;

	float FrinedMonsterDamage = 0.0f;
	float MyCurHp = 0.0f;
	bool BattleStartCheck = false;
};


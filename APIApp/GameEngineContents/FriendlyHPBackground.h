#pragma once
#include "HpBackGroundMove.h"
#include "BattleCommendActor.h"
#include <vector>
#include <GameEngineContents/PokeDataBase.h>
#include "BattleEnemy.h"
// Ό³Έν :
class FriendlyHPBackground : public GameEngineActor
{
public:
	static FriendlyHPBackground* FriendlyPtr;
	FriendlyHPBackground();
	~FriendlyHPBackground() override;

	// delete Function
	FriendlyHPBackground(const FriendlyHPBackground& _Other) = delete;
	FriendlyHPBackground(FriendlyHPBackground&& _Other) noexcept = delete;
	FriendlyHPBackground& operator=(const FriendlyHPBackground& _Other) = delete;
	FriendlyHPBackground& operator=(FriendlyHPBackground&& _Other) noexcept = delete;


	bool IsBattleStartCheck(bool _Value);
	bool IsExpUpCheck(bool _Value);

	int GetMonsterDamage(int _EnumyMonsterDamage);
	int GetExpPoint(int _ExpPoint);
	void HpUpdate(float _EnumyMonsterDamage, float _MyCurHp , float _curpos );
	void ExpUpdate(float _EnumyMonsterDamage, float _MyCurHp, float _curpos , float _CurExpPos);

	void StringToRender(std::vector<GameEngineRender*> _Render, std::string_view _Str);
	void CurHpRender(GameEngineRender* _Render, float _hp);
	void Clear(std::vector<float> _Tick);
	GameEngineRender* GetWindowPtr()
	{
		return RenderPtr;
	}

	GameEngineRender* GetHPPtr()
	{
		return HPRenderPtr;
	}

	GameEngineRender* GetEXPPtr()
	{
		return EXPRenderPtr;
	}
	
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;


private:

	PokeDataBase NewTestMon = PokeDataBase::PokeCreate(4, 15);

	std::vector<GameEngineRender*> PoketMonName_R;
	std::vector<GameEngineRender*> PoketMonLevel_R;

	std::vector<GameEngineRender*> PoketMonHPCUR_R;
	std::vector<GameEngineRender*> PoketMonHPMAX_R;

	GameEngineRender* RenderPtr = nullptr;
	GameEngineRender* HPRenderPtr = nullptr;
	GameEngineRender* HPRenderPtr1 = nullptr;
	GameEngineRender* HPRenderPtr2 = nullptr;

	GameEngineRender* EXPRenderPtr = nullptr;


	float4 TextRenderImageScale = { 20, 40 };

	float4 TextRenderImageScaleHP = { 15, 30 };

	float4 TextRenderInterval = { 0,12 };

	int SpaceFrameNum = 26;
	float4 PoketMonName_S = { 340,320 };
	float4 PoketMonLevel_S = { 640,317 };

	float4 PoketMonHPCUR_S = { 565,388 };
	float4 PoketMonHPMAX_S = { 630,387 };

	int PoketMonNameMax = 12;
	int PoketMonLevelMax = 2;


	std::vector<float> DamegeTick;

	bool BattleStartCheck = false;

	std::vector<float> EXPTick;

	float NextTickTime = 0.0f;
	float NextTickTime_1 = 0.0f;

	float Num =	static_cast<float>( BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterCurrentHP());
	float Num1 = static_cast<float>(BattlePlayer::PlayerPtr->GetMonsterDB()->GetMonsterMaxHP_int());

	float FirstNum = Num / Num1;
	float FirstHp = GameEngineMath::Lerp(192.0f, 0.0f, FirstNum);

	float CurMyHP = 192.0f;
	//
	float CurMyExpPos = 256.0f;

	int EnumyMonsterDamage = 0;
	float MyCurHp = 0.0f;
	int TickNumber = 0;
	int TickNumber_1 = 0;
	
	bool IsExpUP = false;
	bool IsLevelUp = false;

	float SecoundHp = 0.0f;
	float MyCurHpNum = CurMyHP - FirstHp;
	float Hp50Under = 98.0f;
	float Hp30Under = 48.0f;

	int ExpPoint = 0;
	int CurExp = 0;
	
};


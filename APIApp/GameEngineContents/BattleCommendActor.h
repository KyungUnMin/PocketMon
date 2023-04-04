#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineContents/PokeDataBase.h>
#include <GameEngineCore/GameEngineResources.h>

#include <functional>
#include "BattlePlayer.h"
#include "BattleMonsterPlayer.h"


class PokeSkillBase;

class BattleCommendActor : public GameEngineActor
{
public:
	static BattleCommendActor* BattleCommendActorPtr;

	// constrcuter destructer
	BattleCommendActor();
	~BattleCommendActor();

	// delete Function
	BattleCommendActor(const BattleCommendActor& _Other) = delete;
	BattleCommendActor(BattleCommendActor&& _Other) noexcept = delete;
	BattleCommendActor& operator=(const BattleCommendActor& _Other) = delete;
	BattleCommendActor& operator=(BattleCommendActor&& _Other) noexcept = delete;


	inline void SetCallBack(size_t _Index, std::function<void()> _CallBack)
	{
		CallBacks[_Index] = _CallBack;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void B_ArrowNumberCheck();
	void B_ArrowInput(/*int _Number*/);
	void StringToRender(std::vector<GameEngineRender*> _Render, std::string_view _Str);

	void NextInputSOUND();
//	void SetAndResize(std::vector<GameEngineRender*> _Render, float4 _Pos);

	GameEngineRender* BattleArrowRender= nullptr;

private:

	PokeDataBase NewTestMon2 = PokeDataBase::PokeCreate(4, 15);

	std::vector<GameEngineRender*> PoketMonSkill_R1;
	std::vector<GameEngineRender*> PoketMonSkill_R2;
	std::vector<GameEngineRender*> PoketMonSkill_R3;
	std::vector<GameEngineRender*> PoketMonSkill_R4;

	float4 OneTextRenderPos_S = { -400,-25 };
	float4 TwoTextRenderPos_S = { -140,-25 };
	float4 ThreeRenderPos_S = { -400, 40 };
	float4 FourTextRenderPos_S = { -140,40 };

	float4 SkillTextRenderImageScale = { 17, 34 };
	float4 TextRenderInterval = { 0,12 };
	int SpaceFrameNum = 26;
	int SkillLineMax = 12;



	std::vector<GameEngineRender*> PPCUR_R;
	std::vector<GameEngineRender*> PPMAX_R;
	std::vector<GameEngineRender*> TYPE_R;

	float4 PPCurRenderPos_S = { 345,-25 };
	float4 PPMaxRenderPos_S = { 410,-25 };
	float4 TypeRenderPos_S = { 300, 40 };

	float4 PPTextRenderImageScale = { 20, 50 };

	int PPLineMax = 2;
	int TypeLineMax = 6;

	int B_ArrowCheckNum = 0;

	std::string Skill1 = "";
	std::string Skill2 = "";
	std::string Skill3 = "";
	std::string Skill4 = "";


	bool IsSelected = false;
	std::vector<std::function<void()>> CallBacks = std::vector<std::function<void()>>(4);


	GameEngineSoundPlayer B_NextInputSOUND;


};
#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <functional>
#include <GameEngineContents/PokeDataBase.h>

class PokeSkillBase;
// 설명 :
class BattleCommendActor : public GameEngineActor
{
public:
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


//	void SetAndResize(std::vector<GameEngineRender*> _Render, float4 _Pos);
	void StringToRender(std::vector<GameEngineRender*> _Render, std::string_view _Str);

	GameEngineRender* BattleArrowRender= nullptr;

private:

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

	//포켓몬 스킬
	PokeDataBase* MyPoketMon = PokeDataBase::PokeCreate(1, 15);

	std::string_view TestText = "AAAAA";

	std::string Skill_1 = MyPoketMon->GetMonsterSkillList(1)->ForUI_GetSkillName();
	std::string Skill_2 = MyPoketMon->GetMonsterSkillList(2)->ForUI_GetSkillName();
	std::string Skill_3 = MyPoketMon->GetMonsterSkillList(3)->ForUI_GetSkillName();
	std::string Skill_4 = MyPoketMon->GetMonsterSkillList(4)->ForUI_GetSkillName();

	std::string Type = MyPoketMon->ForUI_GetMonsterTypeName();

	//스킬 PP  CUR PP는 실시간으로 바뀔 예정인데 어떻게 하면될까 일단 임시로 만들자
	//첫번째 스킬
	std::string CURPP_1 = MyPoketMon->GetMonsterSkillList(1)->ForUI_GetCurrentSkillPowerPoint();
	std::string MAXPP_1 = MyPoketMon->GetMonsterSkillList(1)->ForUI_GetMaxSkillPowerPoint();
	//두번째 스킬
	std::string CURPP_2 = MyPoketMon->GetMonsterSkillList(2)->ForUI_GetCurrentSkillPowerPoint();
	std::string MAXPP_2 = MyPoketMon->GetMonsterSkillList(2)->ForUI_GetMaxSkillPowerPoint();
	//세번째 스킬
	std::string CURPP_3 = MyPoketMon->GetMonsterSkillList(3)->ForUI_GetCurrentSkillPowerPoint();
	std::string MAXPP_3 = MyPoketMon->GetMonsterSkillList(3)->ForUI_GetMaxSkillPowerPoint();
	//네번째 스킬
	std::string CURPP_4 = MyPoketMon->GetMonsterSkillList(4)->ForUI_GetCurrentSkillPowerPoint();
	std::string MAXPP_4 = MyPoketMon->GetMonsterSkillList(4)->ForUI_GetMaxSkillPowerPoint();



	bool IsSelected = false;
	std::vector<std::function<void()>> CallBacks = std::vector<std::function<void()>>(4);

};
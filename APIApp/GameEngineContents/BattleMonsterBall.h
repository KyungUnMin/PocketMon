#pragma once
#include <GameEngineCore/GameEngineActor.h>


class GameEngineRender;
enum class BattleMonsterBall_Movement;
class BattleMonsterBallFSM;

enum class BattleBallType
{
	Create_MonsterBall,
	Catch_MonsterBall,
	Catch_MasterBall
};

class BattleMonsterBall : public GameEngineActor
{
public:
	static const std::string_view ThrowAniName;
	static const std::string_view OpenAniName;
	static const std::string_view RollAniName;
	static const std::string_view IdleAniName;

	static const std::string_view MasterBallName;
	static const std::string_view MonsterBallName;


	BattleMonsterBall();
	~BattleMonsterBall() override;

	BattleMonsterBall(const BattleMonsterBall& _Other) = delete;
	BattleMonsterBall(BattleMonsterBall&& _Other) noexcept = delete;
	BattleMonsterBall& operator=(const BattleMonsterBall& _Other) = delete;
	BattleMonsterBall& operator=(const BattleMonsterBall&& _Other) noexcept = delete;

	void Init(BattleBallType _Type);


	inline GameEngineRender* GetRender()
	{
		return RenderPtr;
	}


protected:
	void Update(float _DeltaTime) override;

private:
	const float4 RenderScale = float4{ 64.f, 64.f };
	GameEngineRender* RenderPtr = nullptr;
	BattleMonsterBallFSM* FsmPtr = nullptr;

	void CreateThrowAni(const std::string_view& _Name);
	void CreateOpenAni(const std::string_view& _Name);
	void CreateRollAni(const std::string_view& _Name);
};


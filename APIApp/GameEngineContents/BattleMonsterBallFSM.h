#pragma once
#include "BattleFSMBase.h"
#include <vector>

enum class BattleMonsterBall_Movement
{
	Create,
	Opened,
	ShakeVertical,
	ShakeHorizon,
	Catch,
	Fade,

	COUNT,
};

class BattleMonsterBall;
enum class BattleBallType;

class BattleMonsterBallFSM : public BattleFSMBase
{
public:
	BattleMonsterBallFSM();
	~BattleMonsterBallFSM() override;

	BattleMonsterBallFSM(const BattleMonsterBallFSM& _Other) = delete;
	BattleMonsterBallFSM(BattleMonsterBallFSM&& _Other) noexcept = delete;
	BattleMonsterBallFSM& operator=(const BattleMonsterBallFSM& _Other) = delete;
	BattleMonsterBallFSM& operator=(const BattleMonsterBallFSM&& _Other) noexcept = delete;


	

	inline BattleMonsterBall* GetMonsterBall()
	{
		return MonsterBall;
	}

	void Init(BattleBallType _Type, BattleMonsterBall* _Ball);

protected:


private:
	BattleMonsterBall* MonsterBall = nullptr;

	void InitToCreate();
	void InitToCatch();
};


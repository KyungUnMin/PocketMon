#pragma once
#include "BattleStateBase.h"
#include <string_view>
#include <functional>

class BackTextActor;

class BattleState_TalkBase : public BattleStateBase
{
public:
	BattleState_TalkBase();
	virtual ~BattleState_TalkBase() = 0;

	BattleState_TalkBase(const BattleState_TalkBase& _Other) = delete;
	BattleState_TalkBase(BattleState_TalkBase&& _Other) noexcept = delete;
	BattleState_TalkBase& operator=(const BattleState_TalkBase& _Other) = delete;
	BattleState_TalkBase& operator=(const BattleState_TalkBase&& _Other) noexcept = delete;

	void Update(float _DeltaTime) override;
	

protected:
	void EnterState() override;
	void ExitState() override;

	void CreateUIText(const std::vector<std::string>& _Texts);
	void SetTextEvent(size_t _Index, std::function<void()> _Event);

	template <typename StateType>
	void SetNextState(StateType _NextState)
	{
		NextState = static_cast<int>(_NextState);
	}

	std::vector<std::string> InitNPCTexts(const std::string_view& _NpcName);

private:
	BackTextActor* TextInfoUI = nullptr;

	float Timer = -1.6f;
	int CurTextNum = 0;
	std::vector<std::pair<std::string ,std::function<void()>>> TextEvents;

	int NextState = -1;
};




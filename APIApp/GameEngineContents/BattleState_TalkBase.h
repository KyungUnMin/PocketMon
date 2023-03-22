#pragma once
#include "BattleStateBase.h"
#include <string_view>
#include <functional>

class BackTextActor;
class Battle_MonsterAppearEffect;

class BattleState_TalkBase : public BattleStateBase
{
public:
	BattleState_TalkBase();
	virtual ~BattleState_TalkBase() = 0;

	BattleState_TalkBase(const BattleState_TalkBase& _Other) = delete;
	BattleState_TalkBase(BattleState_TalkBase&& _Other) noexcept = delete;
	BattleState_TalkBase& operator=(const BattleState_TalkBase& _Other) = delete;
	BattleState_TalkBase& operator=(const BattleState_TalkBase&& _Other) noexcept = delete;

	void Start();
	void Update(float _DeltaTime) override;
	

protected:
	void CreateUIText(const std::vector<std::string_view>& _Texts);
	void SetTextEvent(size_t _Index, std::function<void()> _Event);

	inline Battle_MonsterAppearEffect* GetAppearEffect()
	{
		return AppearEffect;
	}

	inline BackTextActor* GetBackUI()
	{
		return BackUI;
	}

private:
	BackTextActor* BackUI = nullptr;
	Battle_MonsterAppearEffect* AppearEffect = nullptr;

	int CurTextNum = 0;
	std::vector<std::function<void()>> TextEvents;
};




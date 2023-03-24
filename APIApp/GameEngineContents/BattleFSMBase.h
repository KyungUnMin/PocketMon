#pragma once
#include <vector>

class BattleFSM_StateBase;
enum class BattleFieldType;
enum class BattleNpcType;

class BattleFSMBase
{
public:
	BattleFSMBase();
	virtual ~BattleFSMBase();

	BattleFSMBase(const BattleFSMBase& _Other) = delete;
	BattleFSMBase(BattleFSMBase&& _Other) noexcept = delete;
	BattleFSMBase& operator=(const BattleFSMBase& _Other) = delete;
	BattleFSMBase& operator=(const BattleFSMBase&& _Other) noexcept = delete;

	void Init(BattleFieldType _FieldType, BattleNpcType _NpcType){}
	void ChangeState(BattleFSM_StateBase* _NextState);
	void Update(float _DeltaTime);

protected:

private:
	std::vector<BattleFSM_StateBase*> AllState;
	BattleFSM_StateBase* CurState = nullptr;
};


#pragma once
#include <map>
#include <memory>

enum class BattleStateType
{
	WildTalk,


};

class BattleStateBase;
class GameEngineLevel;

class BattleFSM
{
public:
	BattleFSM();
	~BattleFSM();

	BattleFSM(const BattleFSM& _Other) = delete;
	BattleFSM(BattleFSM&& _Other) noexcept = delete;
	BattleFSM& operator=(const BattleFSM& _Other) = delete;
	BattleFSM& operator=(const BattleFSM&& _Other) noexcept = delete;

	void Init();
	void CreateState(BattleStateType _Type);
	void ChangeState(BattleStateType _Type);
	void Update(float _DeltaTime);
	
protected:

private:
	std::map<BattleStateType, std::shared_ptr<BattleStateBase>> AllState;
	std::shared_ptr<BattleStateBase> CurState = nullptr;

};


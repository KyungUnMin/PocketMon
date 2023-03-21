#pragma once
#include <map>

class BattleFSM
{
public:
	BattleFSM();
	~BattleFSM();

	BattleFSM(const BattleFSM& _Other) = delete;
	BattleFSM(BattleFSM&& _Other) noexcept = delete;
	BattleFSM& operator=(const BattleFSM& _Other) = delete;
	BattleFSM& operator=(const BattleFSM&& _Other) noexcept = delete;

	void Update(float _DeltaTime);

protected:

private:


};


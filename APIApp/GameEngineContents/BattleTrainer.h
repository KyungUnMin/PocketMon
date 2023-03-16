#pragma once


class BattleTrainer
{
public:
	BattleTrainer();
	~BattleTrainer();

	BattleTrainer(const BattleTrainer& _Other) = delete;
	BattleTrainer(BattleTrainer&& _Other) noexcept = delete;
	BattleTrainer& operator=(const BattleTrainer& _Other) = delete;
	BattleTrainer& operator=(const BattleTrainer&& _Other) noexcept = delete;

protected:

private:

};


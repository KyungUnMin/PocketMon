#pragma once
#include "HpBackGroundMove.h"
// Ό³Έν :
class EnemyHPBackground : public HpBackGroundMove
{
public:
	static EnemyHPBackground* EnemyPtr;
	EnemyHPBackground();
	~EnemyHPBackground() override;

	// delete Function
	EnemyHPBackground(const EnemyHPBackground& _Other) = delete;
	EnemyHPBackground(EnemyHPBackground&& _Other) noexcept = delete;
	EnemyHPBackground& operator=(const EnemyHPBackground& _Other) = delete;
	EnemyHPBackground& operator=(EnemyHPBackground&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};


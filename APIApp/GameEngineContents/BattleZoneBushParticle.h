#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;
class BattleZoneBushParticle : public GameEngineActor
{
public:
	BattleZoneBushParticle();
	~BattleZoneBushParticle();

	BattleZoneBushParticle(const BattleZoneBushParticle& _Other) = delete;
	BattleZoneBushParticle(BattleZoneBushParticle&& _Other) noexcept = delete;
	BattleZoneBushParticle& operator=(const BattleZoneBushParticle& _Other) = delete;
	BattleZoneBushParticle& operator=(BattleZoneBushParticle&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	GameEngineRender* AnimRender = nullptr;
};
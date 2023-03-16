#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <string_view>
#include <GameEngineCore/GameEngineResources.h>
// Ό³Έν :
class PlayerTestLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	PlayerTestLevel();
	~PlayerTestLevel();

	// delete Function
	PlayerTestLevel(const PlayerTestLevel& _Other) = delete;
	PlayerTestLevel(PlayerTestLevel&& _Other) noexcept = delete;
	PlayerTestLevel& operator=(const PlayerTestLevel& _Other) = delete;
	PlayerTestLevel& operator=(PlayerTestLevel&& _Other) noexcept = delete;



protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {};
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;


private:

};


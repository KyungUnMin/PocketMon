#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;
enum class BattleFieldType;
	
class BattleBackGround : public GameEngineActor
{
public:
	BattleBackGround();
	~BattleBackGround();

	BattleBackGround(const BattleBackGround& _Other) = delete;
	BattleBackGround(BattleBackGround&& _Other) noexcept = delete;
	BattleBackGround& operator=(const BattleBackGround& _Other) = delete;
	BattleBackGround& operator=(const BattleBackGround&& _Other) noexcept = delete;

	void Init(BattleFieldType _BattleType);

protected:
	void Update(float _DeltaTime) override;
	
private:
	float4 ScreenSize = float4::Zero;
	GameEngineRender* FadeUp = nullptr;
	GameEngineRender* FadeDown = nullptr;
	const float FadeDuration = 1.f;

	void CreateField(BattleFieldType _BattleType);
	void CreateFadeEffect();
	void FadeMove();
};


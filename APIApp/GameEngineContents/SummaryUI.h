#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class GameEngineRender;
class TextActor;
class SummaryUI : public GameEngineActor
{
public:
	// constrcuter destructer
	SummaryUI();
	~SummaryUI();

	// delete Function
	SummaryUI(const SummaryUI& _Other) = delete;
	SummaryUI(SummaryUI&& _Other) noexcept = delete;
	SummaryUI& operator=(const SummaryUI& _Other) = delete;
	SummaryUI& operator=(SummaryUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	GameEngineLevel* CurrentLevel = nullptr;
	GameEngineRender* InfoBack = nullptr;
};


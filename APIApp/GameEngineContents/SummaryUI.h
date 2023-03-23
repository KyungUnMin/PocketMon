#pragma once
#include <GameEngineCore/GameEngineActor.h>
// ���� :
class GameEngineRender;
class PokemonLevel;
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
	PokemonLevel* CurrentLevel = nullptr;
	GameEngineRender* InfoBack = nullptr;
};


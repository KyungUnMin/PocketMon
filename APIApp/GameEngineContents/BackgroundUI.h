#pragma once
#include <GameEngineCore/GameEngineActor.h>

class BackgroundUI : public GameEngineActor
{
public:
	BackgroundUI();
	~BackgroundUI();

	BackgroundUI(const BackgroundUI& _Other) = delete;
	BackgroundUI(BackgroundUI&& _Other) noexcept = delete;
	BackgroundUI& operator=(const BackgroundUI& _Other) = delete;
	BackgroundUI& operator=(BackgroundUI&& _Other) noexcept = delete;

protected:
	void Start() override;
private:

};
#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnum.h"

class GameEngineRender;
class YesNoMenu : public GameEngineActor
{
public:
	// construtor destructor
	YesNoMenu();
	~YesNoMenu();

	// delete Function
	YesNoMenu(const YesNoMenu& _Other) = delete;
	YesNoMenu(YesNoMenu&& _Other) noexcept = delete;
	YesNoMenu& operator=(const YesNoMenu& _Other) = delete;
	YesNoMenu& operator=(YesNoMenu&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	static YesNoMenu* MainYesNoMenu;

	float4 ActorPos = { 480, 320 };

	GameEngineRender* MenuRender = nullptr;

	GameEngineRender* ArrowRender = nullptr;
};


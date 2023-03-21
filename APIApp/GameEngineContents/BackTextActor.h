#pragma once
#include <GameEngineCore/GameEngineActor.h>

class TestScript;

class BackTextActor : public GameEngineActor
{
public:
	BackTextActor();
	~BackTextActor() override;

	BackTextActor(const BackTextActor& _Other) = delete;
	BackTextActor(BackTextActor&& _Other) noexcept = delete;
	BackTextActor& operator=(const BackTextActor& _Other) = delete;
	BackTextActor& operator=(BackTextActor&& _Other) noexcept = delete;

	void PushTexts(const std::vector<std::string_view>& _Texts);
	bool WriteText();

protected:
	void Start() override;

private:
	int CurIndex = 0;
	std::vector<std::string> AllTexts;
	TestScript* ScriptPtr = nullptr;
};


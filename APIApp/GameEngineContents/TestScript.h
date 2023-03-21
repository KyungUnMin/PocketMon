#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class TestScript : public GameEngineActor
{
public:
	TestScript();
	~TestScript();

	// delete Function
	TestScript(const TestScript& _Other) = delete;
	TestScript(TestScript&& _Other) noexcept = delete;
	TestScript& operator=(const TestScript& _Other) = delete;
	TestScript& operator=(TestScript&& _Other) noexcept = delete;

	void SetText(const std::string_view& _Text);

protected:
	void Start() override;

private:
	GameEngineRender* TextRender1 = nullptr;
	float4 BoxScale = float4::Zero;
};

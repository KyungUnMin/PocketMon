#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class TestScript : public GameEngineActor
{
public:
	// constrcuter destructer
	TestScript();
	~TestScript();

	// delete Function
	TestScript(const TestScript& _Other) = delete;
	TestScript(TestScript&& _Other) noexcept = delete;
	TestScript& operator=(const TestScript& _Other) = delete;
	TestScript& operator=(TestScript&& _Other) noexcept = delete;

protected:
	void Start() override;

private:
	GameEngineRender* TextRender = nullptr;
	std::string Script = "HELLO WORLD";
	float4 BoxScale = float4::Zero;

};


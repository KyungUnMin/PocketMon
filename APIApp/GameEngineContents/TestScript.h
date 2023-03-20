#pragma once
#include <GameEngineCore/GameEngineActor.h>

// 설명 :
class TestScript : public GameEngineActor
{
public:
	static TestScript* TestScriptPtr;
	// constrcuter destructer
	TestScript();
	~TestScript();

	// delete Function
	TestScript(const TestScript& _Other) = delete;
	TestScript(TestScript&& _Other) noexcept = delete;
	TestScript& operator=(const TestScript& _Other) = delete;
	TestScript& operator=(TestScript&& _Other) noexcept = delete;


	int GetTextCount()   // 이거 사용해서 카운트에 따라 애니메이션 실행.
	{
		return TextCheckNumber;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void TextInput();
private:
	GameEngineRender* TextRender1 = nullptr;

	std::string Script1 = "HELLO WORLD";
	std::string Script2 = "HELLO WORLD";
	std::string Script3 = "HELLO WORLD";


	int TextCheckNumber = 0;

	float4 BoxScale = float4::Zero;

};


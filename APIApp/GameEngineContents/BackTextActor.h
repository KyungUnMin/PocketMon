#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "int2.h"
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

	void BattleSetText(const std::string_view& _Texts);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void PushStart(std::list<std::string>* _Text);
	void PushScriptBegin(std::list<std::string>::iterator _Begin);
	void PushScriptEnd(std::list<std::string>::iterator _End);

	int GetNowIndex(int _Count) {
		return IndexCount;
	}

	
	void ClearDialog();

	void StringToRender();


private:


	std::vector<std::vector<GameEngineRender*>> BattleTextRender = std::vector<std::vector<GameEngineRender*>>();
	int OneLineSize = 30;
	int LineCount = 2;
	int SpaceFrameNum = 26;

	int FirstLineRenderLen = 0;
	int SecondLineRenderLen = 0;

	int IndexCount = 0;

	std::list<std::string> TestText = std::list<std::string>();
	std::list<std::string>::iterator TestTextIter = std::list<std::string>::iterator();
	std::list<std::string>::iterator TestTextEndIter = std::list<std::string>::iterator();


	float4 TextRenderImageScale = { 24, 48 };
	float4 FirstTextRenderPos = { -420,-28 };
	float4 TextRenderInterval = { 0,12 };

	int2 LastTextRenderIndex = { -1,-1 };
	int2 FindLastTextRenderIndex();



	int CurIndex = 0;
	std::vector<std::string> AllTexts;
	TestScript* ScriptPtr = nullptr;
};


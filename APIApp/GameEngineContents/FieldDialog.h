#pragma once
#include <functional>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineActor.h>
#include "int2.h"
#include "ContentsEnum.h"

class GameEngineRender;
struct TestItem;
class FieldDialog : public GameEngineActor
{
public:
	// construtor destructor
	FieldDialog();
	~FieldDialog();

	// delete Function
	FieldDialog(const FieldDialog& _Other) = delete;
	FieldDialog(FieldDialog&& _Other) noexcept = delete;
	FieldDialog& operator=(const FieldDialog& _Other) = delete;
	FieldDialog& operator=(FieldDialog&& _Other) noexcept = delete;

	void Off() override;

	static FieldDialog* GetFieldDialog()
	{
		return MainFieldDialog;
	}

	void ConversationStart(std::list<std::string>* _Script);
	bool IsAllScriptPrintEnd();
	bool IsOneScriptPrintEnd();

	bool IsValid = true;

	//std::string_view GetCurScript()
	//{
	//	return ScriptIter->data();
	//}

	std::list<std::string>* GetCurScriptPtr() const
	{
		return ScriptPtr;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	void ChangeRenderOrder(RenderOrder _Order);

private:
	
	static FieldDialog* MainFieldDialog;

	float4 ActorPos = {480,544};
	GameEngineRender* FieldDialogFrame = nullptr;

	std::vector<std::vector<GameEngineRender*>> FieldDialogTextRender = std::vector<std::vector<GameEngineRender*>>();
	int OneLineSize = 33;
	int LineCount = 2;
	float4 TextRenderImageScale = { 24, 48 };
	float4 FirstTextRenderPos = { -388,-28 };
	float4 TextRenderInterval = { 0,12 };
	int SpaceFrameNum = 26;
	float PrintSpeed = 0.03f;

	std::list<std::string>::iterator ScriptIter = std::list<std::string>::iterator();
	std::list<std::string>::iterator ScriptEndIter = std::list<std::string>::iterator();

	std::list<std::string>* ScriptPtr = nullptr;

	float Time = 0;
	int FirstLineRenderLen = 0;
	int SecondLineRenderLen = 0;

	GameEngineRender* ArrowRender = nullptr;
	float4 ArrowRenderScale = { 40, 48 };
	float4 ArrowRenderPlusPos = { 36,0 };
	int2 LastTextRenderIndex = { -1,-1 };

	GameEngineSoundPlayer DialogNextButtonSound = GameEngineSoundPlayer();
	void DialogNextButtonSoundPlay();

	void UpdateStart(std::list<std::string>* _Script);
	void PushScriptBegin(std::list<std::string>::iterator _Begin);
	void PushScriptEnd(std::list<std::string>::iterator _End);
	void StringToRender();

	void UpdateEnd();

	void ClearDialog();

	int2 FindLastTextRenderIndex();
	void SetArrowRenderPos(const int2& _LastIndex);

	bool IsLastScript();
};


#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;
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

	void On() override;
	void Off() override;
	void OnOffSwtich() override;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	
	static FieldDialog* AcFeidDialog;

	float4 ActorPos = {480,544};
	GameEngineRender* FieldDialogFrame = nullptr;

	std::vector<std::vector<GameEngineRender*>> FieldDialogTextRender = std::vector<std::vector<GameEngineRender*>>();
	int OneLineSize = 30;
	int LineCount = 2;
	float4 TextRenderImageScale = { 24, 48 };
	float4 FirstTextRenderPos = { -388,-28 };
	float4 TextRenderInterval = { 0,12 };
	int SpaceFrameNum = 26;

	std::string Str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\nabcdefghijklmnopqrstuvwxyz";
	
	float Time = 0;
	int FirstLineRenderLen = 0;
	int SecondLineRenderLen = 0;

	void UpdateStart();
	void UpdateEnd();

	void StringToRender();
	void ClearDialog();
};


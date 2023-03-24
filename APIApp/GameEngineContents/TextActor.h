#pragma once
#include <GameEngineCore/GameEngineActor.h>

class TextActor : public GameEngineActor
{
public:
	// constructer destructer
	TextActor();
	~TextActor();

	void SetAligned(bool _IsRightAligned);
	void SetText(const std::string_view& _Str, const std::string_view& _Font, int _Order, bool _Animation = false);
	void SetText(const std::string_view& _Str, const std::string_view& _Font, bool _Animation = false);
	void SetText(const std::string_view& _Str, bool _Animation = false);
	void SetLine(int _LineCount);
	void SetInterver(const float4& _Interval);
	void SetAlpha(int _Alpha);
	void SkipAnimation();
	void Clear();
	// delete Function
	TextActor(const TextActor& _Other) = delete;
	TextActor(TextActor&& _Other) = delete;
	TextActor& operator=(const TextActor& _Other) = delete;
	TextActor& operator=(TextActor&& _Other) = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	const std::string_view DefalutFont = "Font_Dialog.bmp";
	const int SpaceFrameNum = 26;
	std::vector<std::vector<GameEngineRender*>> TextRender = std::vector<std::vector<GameEngineRender*>>();
	bool TextAnim = false;
	bool RightAligned = false;
	int OneLineSize = 30;
	int LineCount = 3;
	float4 FirstTextRenderPos = { 0, 0 };
	float4 TextRenderImageScale = { 24, 48 };
	float4 TextRenderInterval = { 0,12 };

	float Time = 0;
	std::vector<int> LineRenderIndex = std::vector<int>(0);
	std::list<std::string> TestScript = std::list<std::string>();

	void SetFont(const std::string_view& _Font, int _Order);
	
};


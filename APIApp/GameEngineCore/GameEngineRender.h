#pragma once
#include <GameEnginePlatform/GameEngineImage.h>
#include <map>
#include "GameEngineComponent.h"
// 랜더링에 관련된 기능을 모두 집약한다.

enum class TextAlign
{
	Left = DT_LEFT,
	Right = DT_RIGHT,
	Center = DT_CENTER
};

class FrameAnimationParameter
{
public:
	std::string_view AnimationName = "";
	std::string_view ImageName = "";
	std::string_view FilterName = "";
	int Start = 0;
	int End = 0;
	int CurrentIndex = 0;
	float InterTime = 0.1f;
	bool Loop = true;
	std::vector<int> FrameIndex = std::vector<int>();
	std::vector<float> FrameTime = std::vector<float>();
};


// 설명 :
class GameEngineActor;
class GameEngineLevel;
class GameEngineRender : public GameEngineComponent
{
	friend GameEngineActor;
	friend GameEngineLevel;

public:
	// constrcuter destructer
	GameEngineRender();
	~GameEngineRender();

	// delete Function
	GameEngineRender(const GameEngineRender& _Other) = delete;
	GameEngineRender(GameEngineRender&& _Other) noexcept = delete;
	GameEngineRender& operator=(const GameEngineRender& _Other) = delete;
	GameEngineRender& operator=(GameEngineRender&& _Other) noexcept = delete;

	inline GameEngineImage* GetImage()
	{
		return Image;
	}

	inline int GetFrame()
	{
		return Frame;
	}

	inline void SetTransColor(int _Color)
	{
		TransColor = _Color;
	}

	inline void SetEffectCamera(bool _Effect)
	{
		IsEffectCamera = _Effect;
	}

	inline void EffectCameraOff()
	{
		SetEffectCamera(false);
	}

	inline void EffectCameraOn()
	{
		SetEffectCamera(true);
	}

	inline int GetTextHeight()
	{
		return TextHeight;
	}

	inline void SetAlpha(int _Alpha)
	{
		Alpha = _Alpha;
	}

	inline float GetAngle(float _Angle)
	{
		return Angle;
	}

	inline void SetAngleAdd(float _Angle)
	{
		Angle += _Angle;
	}

	inline void SetAngle(float _Angle)
	{
		Angle = _Angle;
	}

	inline void SetTextBoxScale(float4 _TextBoxScale)
	{
		TextBoxScale = _TextBoxScale;
	}

	void SetRotFilter(const std::string_view& _ImageName);

	void SetImage(const std::string_view& _ImageName);

	void SetImageToScaleToImage(const std::string_view& _ImageName);

	void SetScaleToImage();

	void SetFrame(int _Frame);

	bool IsAnimationEnd();
	void CreateAnimation(const FrameAnimationParameter& _Paramter);
	void ChangeAnimation(const std::string_view& _AnimationName, bool _ForceChange = false);

	void SetOrder(int _Order) override;


	void SetText(const std::string_view& _Text, const int _TextHeight = 20, const std::string_view& _TextType = "굴림", const TextAlign _TextAlign = TextAlign::Center, const COLORREF _TextColor = RGB(0, 0, 0), float4 TextBoxScale = float4::Zero);

protected:

private:
	GameEngineImage* Image = nullptr;
	GameEngineImage* RotationFilter = nullptr;

	bool IsEffectCamera = true;

	int TransColor = RGB(255, 0, 255);

	int Frame = 0;

	int Alpha = 255;

	void Render(float _DeltaTime);

	void TextRender(float _DeltaTime);
	void ImageRender(float _DeltaTime);

	class FrameAnimation
	{
	public:
		GameEngineRender* Parent = nullptr;
		// 짤려있는 이미지여야 한다.
		GameEngineImage* Image = nullptr;
		GameEngineImage* FilterImage = nullptr;
		std::vector<int> FrameIndex;
		std::vector<float> FrameTime;
		int CurrentIndex = 0;
		float CurrentTime = 0.0f;
		bool Loop = true;


		bool IsEnd();

		void Render(float _DeltaTime);

		void Reset() 
		{
			CurrentIndex = 0;
			CurrentTime = 0.0f;
		}
	};

	std::map<std::string, FrameAnimation> Animation;
	FrameAnimation* CurrentAnimation = nullptr;

	/// <summary>
	/// TextRender
	/// </summary>
	std::string RenderText = std::string();
	int TextHeight = 0;
	std::string TextType = std::string();
	TextAlign Align = TextAlign::Left;
	COLORREF TextColor = RGB(0, 0, 0);
	float4 TextBoxScale;

	// 회전하면서 반투명도 하고 싶어요 => 안됩니다.
	float Angle = 0.0f;

	// 그런걸 하면 HBRUSH 만드는데 사용하고 나면 Release
	// GameEngineImage를 참조해라.
};


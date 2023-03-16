#pragma once
#include <string>
#include <string_view>
#include <GameEngineCore/GameEngineObject.h>
#include <GameEngineBase/GameEngineMath.h>

class GameEngineRender;
class GameEngineActor;
class LetterRenderObject : public GameEngineObject
{
public:
	// construtor destructor
	LetterRenderObject();
	~LetterRenderObject();

	// delete Function
	LetterRenderObject(const LetterRenderObject& _Other) = delete;
	LetterRenderObject(LetterRenderObject&& _Other) noexcept = delete;
	LetterRenderObject& operator=(const LetterRenderObject& _Other) = delete;
	LetterRenderObject& operator=(LetterRenderObject&& _Other) noexcept = delete;

protected:


private:
	int Order = 0;
	float4 FontScale = { 24, 48 };
	float4 Pos = float4::Zero;
	std::string Str = std::string();
	int TransColor = RGB(255, 0, 255);

	bool CameraEffect = false;

	std::vector<GameEngineRender*> LetterRenders = std::vector<GameEngineRender*>();
};


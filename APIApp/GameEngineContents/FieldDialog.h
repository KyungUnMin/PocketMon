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

protected:
	void Start() override;

private:
	
	float4 ActorPos = {480,544};
	GameEngineRender* FieldDialogFrame = nullptr;

};


#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class SkillActor_ThunderBack : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_ThunderBack();
	~SkillActor_ThunderBack();

	// delete Function
	SkillActor_ThunderBack(const SkillActor_ThunderBack& _Other) = delete;
	SkillActor_ThunderBack(SkillActor_ThunderBack&& _Other) noexcept = delete;
	SkillActor_ThunderBack& operator=(const SkillActor_ThunderBack& _Other) = delete;
	SkillActor_ThunderBack& operator=(SkillActor_ThunderBack&& _Other) noexcept = delete;

	void FadeInStart()
	{
		IsFadeInStart = true;
		IsFadeOutStart = false;
	}

	void FadeOutStart()
	{
		IsFadeOutStart = true;
		IsFadeInStart = false;
	}

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

	bool IsFadeInStart = false;
	bool IsFadeOutStart = false;
	bool FadeInEnd = false;

	float FadeInTime = 0.0f;
	float FadeOutTime = 0.0f;

	int AlphaValue = 5;

	void FadeIn(float _Deltatime);
	void FadeOut(float _Deltatime);

};
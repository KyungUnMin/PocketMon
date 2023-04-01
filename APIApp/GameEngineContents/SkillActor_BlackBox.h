#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class SkillActor_BlackBox : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_BlackBox();
	~SkillActor_BlackBox();

	// delete Function
	SkillActor_BlackBox(const SkillActor_BlackBox& _Other) = delete;
	SkillActor_BlackBox(SkillActor_BlackBox&& _Other) noexcept = delete;
	SkillActor_BlackBox& operator=(const SkillActor_BlackBox& _Other) = delete;
	SkillActor_BlackBox& operator=(SkillActor_BlackBox&& _Other) noexcept = delete;

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

	float FadeInTime = 0.0f;
	float FadeOutTime = 0.0f;

	int AlphaValue = 0;

	void FadeIn(float _Deltatime);
	void FadeOut(float _Deltatime);

};

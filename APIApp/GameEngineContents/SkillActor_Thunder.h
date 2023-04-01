#pragma once

#include <GameEngineCore/GameEngineActor.h>

enum class ThunderSet
{
	Thunder1,
	Thunder2,
	Thunder3,
};

// Ό³Έν :
class SkillActor_Thunder : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_Thunder();
	~SkillActor_Thunder();

	// delete Function
	SkillActor_Thunder(const SkillActor_Thunder& _Other) = delete;
	SkillActor_Thunder(SkillActor_Thunder&& _Other) noexcept = delete;
	SkillActor_Thunder& operator=(const SkillActor_Thunder& _Other) = delete;
	SkillActor_Thunder& operator=(SkillActor_Thunder&& _Other) noexcept = delete;

	void ThunderSetting(ThunderSet _Number);

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

	bool Num1 = false;
	bool Num2 = false;
	bool Num3 = false;
	bool IsStart = false;

};

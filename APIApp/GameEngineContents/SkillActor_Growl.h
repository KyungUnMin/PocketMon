#pragma once

#include <GameEngineCore/GameEngineActor.h>

enum class GrowlSet
{
	Growl1,
	Growl2,
	Growl3,
};

// Ό³Έν :
class SkillActor_Growl : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_Growl();
	~SkillActor_Growl();

	// delete Function
	SkillActor_Growl(const SkillActor_Growl& _Other) = delete;
	SkillActor_Growl(SkillActor_Growl&& _Other) noexcept = delete;
	SkillActor_Growl& operator=(const SkillActor_Growl& _Other) = delete;
	SkillActor_Growl& operator=(SkillActor_Growl&& _Other) noexcept = delete;

	void GrowlSetting(int _Number);

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


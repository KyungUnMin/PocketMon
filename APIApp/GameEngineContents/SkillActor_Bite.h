#pragma once

#include <GameEngineCore/GameEngineActor.h>

enum class BiteSet
{
	Bite1,
	Bite2,
};

// Ό³Έν :
class SkillActor_Bite : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_Bite();
	~SkillActor_Bite();

	// delete Function
	SkillActor_Bite(const SkillActor_Bite& _Other) = delete;
	SkillActor_Bite(SkillActor_Bite&& _Other) noexcept = delete;
	SkillActor_Bite& operator=(const SkillActor_Bite& _Other) = delete;
	SkillActor_Bite& operator=(SkillActor_Bite&& _Other) noexcept = delete;

	void BiteSetting(int _Number);

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

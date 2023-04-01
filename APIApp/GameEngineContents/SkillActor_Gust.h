#pragma once

#include <GameEngineCore/GameEngineActor.h>

// ���� :
class SkillActor_Gust : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_Gust();
	~SkillActor_Gust();

	// delete Function
	SkillActor_Gust(const SkillActor_Gust& _Other) = delete;
	SkillActor_Gust(SkillActor_Gust&& _Other) noexcept = delete;
	SkillActor_Gust& operator=(const SkillActor_Gust& _Other) = delete;
	SkillActor_Gust& operator=(SkillActor_Gust&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

};

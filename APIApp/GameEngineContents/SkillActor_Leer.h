#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class SkillActor_Leer : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_Leer();
	~SkillActor_Leer();

	// delete Function
	SkillActor_Leer(const SkillActor_Leer& _Other) = delete;
	SkillActor_Leer(SkillActor_Leer&& _Other) noexcept = delete;
	SkillActor_Leer& operator=(const SkillActor_Leer& _Other) = delete;
	SkillActor_Leer& operator=(SkillActor_Leer&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

};


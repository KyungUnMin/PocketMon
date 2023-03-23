#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class PokeSkill;

class Battle_SkillEffect : public GameEngineActor
{
public:
	Battle_SkillEffect();
	~Battle_SkillEffect() override;

	Battle_SkillEffect(const Battle_SkillEffect& _Other) = delete;
	Battle_SkillEffect(Battle_SkillEffect&& _Other) noexcept = delete;
	Battle_SkillEffect& operator=(const Battle_SkillEffect& _Other) = delete;
	Battle_SkillEffect& operator=(const Battle_SkillEffect&& _Other) noexcept = delete;

	//Duration을 돌려줌, Event를 이용해 알아서 처리하게끔
	float Init(PokeSkill _SkillType, 
		const std::string_view& _SkillName,
		GameEngineActor* _Owner);

protected:


private:
	/*static const std::vector<float> AniDurations;
	static const std::vector<bool> IsMove;
	static const std::vector<int> AniFrmCnt;*/

	struct SkiilAniData
	{
		float Duration = 0.f;
		bool IsMoveAni = false;

	};


};


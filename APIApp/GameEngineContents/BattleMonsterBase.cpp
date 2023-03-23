#include "BattleMonsterBase.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "PokeDataBase.h"
#include "ContentsEnum.h"
#include "PokeSkillBase.h"


BattleMonsterBase::BattleMonsterBase()
{
	
}

BattleMonsterBase::~BattleMonsterBase()
{

}



void BattleMonsterBase::Init(PokeNumber _MonsterType)
{
	SetName(NameEnumToString[static_cast<size_t>(_MonsterType)]);
	DbPtr = PokeDataBase::PokeCreate(static_cast<int>(_MonsterType) + 1);
}




GameEngineRender* BattleMonsterBase::DamageBySkill(PokeSkill _SkillType)
{
	


	return CreateSkiilEffect(_SkillType);
}


GameEngineRender* BattleMonsterBase::CreateSkiilEffect(PokeSkill _SkillType)
{
	//임시, 크기 얼마가 될 지 모름
	static const float4 RenderScale = float4{ 256.f, 256.f };

	std::string ImagePath = SkiilEnumToString[static_cast<size_t>(_SkillType)].data();
	ImagePath = "BattleSkill_" + ImagePath + ".bmp";

	/*GameEngineRender* SkillRender = CreateRender(BattleRenderOrder::SkillEffect);
	SkillRender->CreateAnimation
	({
		.AnimationName = "Skiil",
		.ImageName = ImagePath,
		.Start = 0,
		.End = SkiilAniFrame[static_cast<size_t>(_SkillType)],
		.Loop = false
	});*/

	return nullptr;
}



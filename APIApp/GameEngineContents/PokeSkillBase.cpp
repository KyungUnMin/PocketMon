#include "PokeSkillBase.h"

PokeSkillBase::PokeSkillBase() 
{
}

PokeSkillBase::~PokeSkillBase() 
{
}

void PokeSkillBase::CreateSkill(std::string_view _SkillName)
{
	if ("�����ġ��" == _SkillName)
	{
		Tackle();
	}
}

void PokeSkillBase::Tackle()
{
	int a = 0;
}
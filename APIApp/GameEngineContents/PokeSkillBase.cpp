#include "PokeSkillBase.h"

PokeSkillBase::PokeSkillBase() 
{
}

PokeSkillBase::~PokeSkillBase() 
{
}

void PokeSkillBase::CreateSkill(std::string_view _SkillName)
{
	if ("몸통박치기" == _SkillName)
	{
		Tackle();
	}
}

void PokeSkillBase::Tackle()
{
	int a = 0;
}
#pragma once

#include <string>
#include <map>

// 설명 :
class PokeSkillBase
{
public:
	// constrcuter destructer
	PokeSkillBase();
	~PokeSkillBase();

	// delete Function
	PokeSkillBase(const PokeSkillBase& _Other) = delete;
	PokeSkillBase(PokeSkillBase&& _Other) noexcept = delete;
	PokeSkillBase& operator=(const PokeSkillBase& _Other) = delete;
	PokeSkillBase& operator=(PokeSkillBase&& _Other) noexcept = delete;

	void CreateSkill(std::string_view _SkillName);

protected:

private:
	std::map<std::string, PokeSkillBase*> AllSkills = std::map<std::string, PokeSkillBase*>();
	
	std::string SkillName = "몸통박치기";

	bool IsAttacskill = true;

	int SkillType = 0;
	int SkillDamage = 0;
	int SkillDebuff = 0;
	int SkillPowerPoint = 0;

	void Tackle();
};


#pragma once

#include <string>

// ���� :
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

protected:

private:
	std::string SkillName = "�����ġ��";

	bool IsAttacskill = true;

	int SkillType = 0;
	int SkillDamage = 0;
	int SkillDebuff = 0;
	int SkillPowerPoint = 0;


};


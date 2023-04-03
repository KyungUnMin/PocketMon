#include "PokeDataBase.h"

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineRandom.h>

#include "PokeSkillBase.h"

PokeDataBase::PokeDataBase() 
{
}

PokeDataBase::~PokeDataBase() 
{
}

//////////////////////////////////////////////////////////////// 푸키먼 데이터 생성 함수

PokeDataBase PokeDataBase::PokeCreate(int _PokeDexNumber, int _Level)
{
	int ChangePokeNumber = _PokeDexNumber - 1;
	int MaxNumber = static_cast<int>(PokeNumber::Max);

	if (ChangePokeNumber >= MaxNumber)
	{
		MsgAssert("포켓몬 넘버는 14(롱스톤)까지만 존재합니다.");
	}
	else if (ChangePokeNumber < 0)
	{
		MsgAssert("포켓몬 넘버는 1(이상해씨) 미만일 수 없습니다.");
	}

	if (_Level <= 0)
	{
		MsgAssert("레벨이 0인 포켓몬은 생성할 수 없습니다.");
	}

	PokeDataBase PoKeCreatePtr;

	PoKeCreatePtr.PokeDexNumber = static_cast<PokeNumber>(ChangePokeNumber);

	switch (PoKeCreatePtr.PokeDexNumber)
	{
	case PokeNumber::Bulbasaur:
	{
		BulbasaurData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::TailWhip, PoKeCreatePtr);
		
		if (PoKeCreatePtr.MonsterLevel >= 10)
		{
			PokeSkillInit(3, PokeSkill::VineWhip, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 2;
		}
		if (PoKeCreatePtr.MonsterLevel >= 15)
		{
			PokeSkillInit(4, PokeSkill::RazorLeaf, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 4;
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
	}
	break;
	case PokeNumber::Ivysaur:
	{
		IvysaurData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::TailWhip, PoKeCreatePtr);

		if (PoKeCreatePtr.MonsterLevel >= 10)
		{
			PokeSkillInit(3, PokeSkill::VineWhip, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 2;
		}
		if (PoKeCreatePtr.MonsterLevel >= 15)
		{
			PokeSkillInit(4, PokeSkill::RazorLeaf, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 4;
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
	}
	break;
	case PokeNumber::Venusaur:
	{
		VenusaurData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::TailWhip, PoKeCreatePtr);

		if (PoKeCreatePtr.MonsterLevel >= 10)
		{
			PokeSkillInit(3, PokeSkill::VineWhip, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 2;
		}
		if (PoKeCreatePtr.MonsterLevel >= 15)
		{
			PokeSkillInit(4, PokeSkill::RazorLeaf, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 4;
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
	}
	break;
	case PokeNumber::Charmander:
	{
		CharmanderData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Scratch, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::Growl, PoKeCreatePtr );
		
		if (PoKeCreatePtr.MonsterLevel >= 10)
		{
			PokeSkillInit(3, PokeSkill::Ember, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 2;
		}
		if (PoKeCreatePtr.MonsterLevel >= 15)
		{
			PokeSkillInit(4, PokeSkill::Leer, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 4;
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
	}
	break;
	case PokeNumber::Charmeleon:
	{
		CharmeleonData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Scratch, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::Growl, PoKeCreatePtr);

		if (PoKeCreatePtr.MonsterLevel >= 10)
		{
			PokeSkillInit(3, PokeSkill::Ember, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 2;
		}
		if (PoKeCreatePtr.MonsterLevel >= 15)
		{
			PokeSkillInit(4, PokeSkill::Leer, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 4;
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
	}
	break;
	case PokeNumber::Charizard:
	{
		CharizardData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Scratch, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::Growl, PoKeCreatePtr);

		if (PoKeCreatePtr.MonsterLevel >= 10)
		{
			PokeSkillInit(3, PokeSkill::Ember, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 2;
		}
		if (PoKeCreatePtr.MonsterLevel >= 15)
		{
			PokeSkillInit(4, PokeSkill::Leer, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 4;
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
	}
	break;
	case PokeNumber::Squirtle:
	{
		SquirtleData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::TailWhip, PoKeCreatePtr);

		if (PoKeCreatePtr.MonsterLevel >= 10)
		{
			PokeSkillInit(3, PokeSkill::Bubble, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 2;
		}
		if (PoKeCreatePtr.MonsterLevel >= 15)
		{
			PokeSkillInit(4, PokeSkill::WaterGun, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 4;
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
	}
	break;
	case PokeNumber::Wartortle:
	{
		WartortleData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::TailWhip, PoKeCreatePtr);

		if (PoKeCreatePtr.MonsterLevel >= 10)
		{
			PokeSkillInit(3, PokeSkill::Bubble, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 2;
		}
		if (PoKeCreatePtr.MonsterLevel >= 15)
		{
			PokeSkillInit(4, PokeSkill::WaterGun, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 4;
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
	}
	break;
	case PokeNumber::Blastoise:
	{
		BlastoiseData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::TailWhip, PoKeCreatePtr);

		if (PoKeCreatePtr.MonsterLevel >= 10)
		{
			PokeSkillInit(3, PokeSkill::Bubble, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 2;
		}
		if (PoKeCreatePtr.MonsterLevel >= 15)
		{
			PokeSkillInit(4, PokeSkill::WaterGun, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 4;
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
	}
	break;
	case PokeNumber::Pidgey:
	{
		PidgeyData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::Growl, PoKeCreatePtr);

		if (PoKeCreatePtr.MonsterLevel >= 10)
		{
			PokeSkillInit(3, PokeSkill::Gust, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 2;
		}
		if (PoKeCreatePtr.MonsterLevel >= 15)
		{
			PokeSkillInit(4, PokeSkill::QuickAttack, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 4;
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
	}
	break;
	case PokeNumber::Rattata:
	{
		RattataData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::TailWhip, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::QuickAttack, PoKeCreatePtr);

		if (PoKeCreatePtr.MonsterLevel >= 15)
		{
			PokeSkillInit(4, PokeSkill::HyperFang, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 4;
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
	}
	break;
	case PokeNumber::Spearow:
	{
		SpearowData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Peck, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::Growl, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::Leer, PoKeCreatePtr);

		if (PoKeCreatePtr.MonsterLevel >= 15)
		{
			PokeSkillInit(4, PokeSkill::FuryAttack, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 4;
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
	}
	break;
	case PokeNumber::Geodude:
	{
		GeodudeData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::DefenseCurl, PoKeCreatePtr);

		if (PoKeCreatePtr.MonsterLevel >= 20)
		{
			PokeSkillInit(3, PokeSkill::Earthquake, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 2;
		}
		if (PoKeCreatePtr.MonsterLevel >= 300)
		{
			PokeSkillInit(4, PokeSkill::StoneEdge, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 4;
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
			PoKeCreatePtr.SkillCount = 3;
		}
	}
	break;
	case PokeNumber::Onix:
	{
		OnixData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::DefenseCurl, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
		PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);

		PoKeCreatePtr.SkillCount = 2;
	}
	break;
	case PokeNumber::Pikachu:
	{
		PikachuData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::TailWhip, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
		PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);

		PoKeCreatePtr.SkillCount = 2;
	}
	break;
	default:
	break;
	}

	// AllPokemons.push_back(PoKeCreatePtr);

	return PoKeCreatePtr;
}

//////////////////////////////////////////////////////////////// 푸키먼 전투 후 경험치 획득

// 몬스터를 처치하면 경험치 획득
bool PokeDataBase::PokeExperienceGain(PokeDataBase& _Ownerpokemon, PokeDataBase& _knockeddownpokemon)
{
	bool IsLevelUp = false;

	int Basicvalue = 50;
	int Knockpokelevel = _knockeddownpokemon.GetMonsterLevel_int();
	int Acquisitionvalue = Basicvalue + Knockpokelevel;

	_Ownerpokemon.PlusMonsterExperience(Acquisitionvalue);
	int Newexperience = _Ownerpokemon.GetMonsterExperience();

	if (100 <= Newexperience)
	{
		PokeLevelUp(_Ownerpokemon);
		int Residue = Newexperience - 100;
		_Ownerpokemon.Experience = Residue;
		IsLevelUp = true;
	}

	// 얻은 경험치
	return IsLevelUp;
}

// 일정 경험치 이상을 획득할 경우 레벨이 증가
void PokeDataBase::PokeLevelUp(PokeDataBase& _Ownerpokemon)
{
	_Ownerpokemon.MaxHealthPoint += 1;
	_Ownerpokemon.AttackPower += 1;
	_Ownerpokemon.Defense += 1;
	_Ownerpokemon.SpecialAttackPower += 1;
	_Ownerpokemon.SpecialDefense += 1;
	_Ownerpokemon.Agility += 1;

	_Ownerpokemon.MonsterLevel += 1;
	
	// 현재체력 갱신 (레벨업시 Max 상태로 변경)
	int RenewalcurrentHP = _Ownerpokemon.GetMonsterMaxHP_int();
	_Ownerpokemon.SetMonsterCurrentHP(RenewalcurrentHP);
}

//////////////////////////////////////////////////////////////// 푸키먼 데이터 생성 보조

// PokeCreate() 함수를 호출하면 해당 구역의 함수를 연계적으로 호출하여 데이터를 입력해줍니다.
// 데이터 생성 보조 함수와 푸키먼 데이터 함수가 있습니다 (1번부터 14번까지).

// 푸키먼 스킬 이닛
void PokeDataBase::PokeSkillInit(int _Skillslot, PokeSkill _SkillName, PokeDataBase& _PoKeCreatePtr)
{
	PokeSkillBase Skill;
	Skill.InitCreateSkill(_SkillName);

	_PoKeCreatePtr.GetMonsterSkillList(_Skillslot).InitCreateSkill(_SkillName);
	
	// _PoKeCreatePtr.SkillList[_Skillslot - 1] = Skill;
	// AllSkills.push_back(_PoKeCreatePtr.SkillList[_Skillslot - 1]);
}

// 성별 결정
void PokeDataBase::GenderDecision(PokeDataBase& _PoKeCreatePtr)
{
	int RandValue = GameEngineRandom::MainRandom.RandomInt(1, 2);

	if (1 == RandValue)
	{
		_PoKeCreatePtr.IsMan = true;  // 수컷
	}
	else
	{
		_PoKeCreatePtr.IsMan = false; // 암컷
	}
}

// 성격 결정
void PokeDataBase::PersonalityDecision(PokeDataBase& _PoKeCreatePtr)
{
	int RandValue = GameEngineRandom::MainRandom.RandomInt(0, 24);

	_PoKeCreatePtr.Personality = static_cast<PokePersonality>(RandValue);

	// 오류로 인해 임시 반환 값
	// return PokePersonality::Adamant;
}

// 레벨 설정 시 레벨이 1보다 높다면 스탯 증가
void PokeDataBase::PokeStatusUp(PokeDataBase& _PoKeCreatePtr)
{
	_PoKeCreatePtr.MaxHealthPoint += 1;
	_PoKeCreatePtr.AttackPower += 1;
	_PoKeCreatePtr.Defense += 1;
	_PoKeCreatePtr.SpecialAttackPower += 1;
	_PoKeCreatePtr.SpecialDefense += 1;
	_PoKeCreatePtr.Agility += 1;

	_PoKeCreatePtr.CurrentHealthPoint = _PoKeCreatePtr.MaxHealthPoint;
}

// No.1 이상해씨
void PokeDataBase::BulbasaurData(int _Level, PokeDataBase& PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);                            // 성별 결정 (암, 수)
	PersonalityDecision(PoKeCreatePtr);                       // 성격 결정 (신중한 등)
	PoKeCreatePtr.Type = PokeType::Grass;                    // 포켓몬 타입 
	PoKeCreatePtr.Characteristic = PokeCharacteristic::심록; // 포켓몬 특성
	PoKeCreatePtr.Name = "Bulbasaur";                        // 포켓몬 디폴트 이름
	PoKeCreatePtr.TypeName = "Grass";                        // 포켓몬 타입 이름
	PoKeCreatePtr.NumberName = "001";                        // 포켓몬 넘버 이름
	
	PoKeCreatePtr.MaxHealthPoint = 26;                       // 포켓몬 기초 최대 체력
	PoKeCreatePtr.CurrentHealthPoint = 26;                   // 포켓몬 기초 잔여 체력
	PoKeCreatePtr.AttackPower = 49;                          // 포켓몬 기초 공격력
	PoKeCreatePtr.Defense = 49;                              // 포켓몬 기초 방어력
	PoKeCreatePtr.SpecialAttackPower = 65;                   // 포켓몬 기초 특수공격력
	PoKeCreatePtr.SpecialDefense = 65;                       // 포켓몬 기초 특수방어력 // "특수"는 마법공격, 마법방어로, 노말은 물리공격, 물리방어로 생각하면 됩니다.
	PoKeCreatePtr.Agility = 45;                              // 포켓몬 기초 스피드
	
	int PlusLevel = PoKeCreatePtr.MonsterLevel + _Level;     // 야생 포켓몬 스폰 목적 시, 레벨을 입력해줍니다.

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr.MonsterLevel = PlusLevel;

	PoKeCreatePtr.PokeDexText = "From birth, they carry plant seeds on their back.";
}

// No.2 이상해풀
void PokeDataBase::IvysaurData(int _Level, PokeDataBase& PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr.Type = PokeType::Grass;
	PoKeCreatePtr.Characteristic = PokeCharacteristic::심록;
	PoKeCreatePtr.Name = "Ivysaur";
	PoKeCreatePtr.TypeName = "Grass";
	PoKeCreatePtr.NumberName = "002";

	PoKeCreatePtr.MaxHealthPoint = 40;
	PoKeCreatePtr.CurrentHealthPoint = 40;
	PoKeCreatePtr.AttackPower = 62;
	PoKeCreatePtr.Defense = 63;
	PoKeCreatePtr.SpecialAttackPower = 80;
	PoKeCreatePtr.SpecialDefense = 80;
	PoKeCreatePtr.Agility = 60;
	
	int PlusLevel = PoKeCreatePtr.MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr.MonsterLevel = PlusLevel;

	PoKeCreatePtr.PokeDexText = "As nutrients are absorbed, flower buds grow.";
}
// No.3 이상해꽃
void PokeDataBase::VenusaurData(int _Level, PokeDataBase& PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr.Type = PokeType::Grass;
	PoKeCreatePtr.Characteristic = PokeCharacteristic::심록;
	PoKeCreatePtr.Name = "Venusaur";
	PoKeCreatePtr.TypeName = "Grass";
	PoKeCreatePtr.NumberName = "003";

	PoKeCreatePtr.MaxHealthPoint = 60;
	PoKeCreatePtr.CurrentHealthPoint = 60;
	PoKeCreatePtr.AttackPower = 82;
	PoKeCreatePtr.Defense = 83;
	PoKeCreatePtr.SpecialAttackPower = 100;
	PoKeCreatePtr.SpecialDefense = 100;
	PoKeCreatePtr.Agility = 80;
	
	int PlusLevel = PoKeCreatePtr.MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr.MonsterLevel = PlusLevel;

	PoKeCreatePtr.PokeDexText = "A captivating fragrance spreads from the flowers, soothing the spirits of those who fight.";
}

// No.4 파이리
void PokeDataBase::CharmanderData(int _Level, PokeDataBase& PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr.Type = PokeType::Fire;
	PoKeCreatePtr.Characteristic = PokeCharacteristic::맹화;
	PoKeCreatePtr.Name = "Charmander";
	PoKeCreatePtr.TypeName = "Fire";
	PoKeCreatePtr.NumberName = "004";

	PoKeCreatePtr.MaxHealthPoint = 21;
	PoKeCreatePtr.CurrentHealthPoint = 21;
	PoKeCreatePtr.AttackPower = 52;
	PoKeCreatePtr.Defense = 43;
	PoKeCreatePtr.SpecialAttackPower = 60;
	PoKeCreatePtr.SpecialDefense = 50;
	PoKeCreatePtr.Agility = 65;
	
	int PlusLevel = PoKeCreatePtr.MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr.MonsterLevel = PlusLevel;

	PoKeCreatePtr.PokeDexText = "The enchanting fragrance of flowers relieves people`s fatigue.";
}

// No.5 리자드
void PokeDataBase::CharmeleonData(int _Level, PokeDataBase& PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr.Type = PokeType::Fire;
	PoKeCreatePtr.Characteristic = PokeCharacteristic::맹화;
	PoKeCreatePtr.Name = "Charmeleon";
	PoKeCreatePtr.TypeName = "Fire";
	PoKeCreatePtr.NumberName = "005";

	PoKeCreatePtr.MaxHealthPoint = 38;
	PoKeCreatePtr.CurrentHealthPoint = 38;
	PoKeCreatePtr.AttackPower = 64;
	PoKeCreatePtr.Defense = 58;
	PoKeCreatePtr.SpecialAttackPower = 80;
	PoKeCreatePtr.SpecialDefense = 65;
	PoKeCreatePtr.Agility = 80;
	
	int PlusLevel = PoKeCreatePtr.MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr.MonsterLevel = PlusLevel;

	PoKeCreatePtr.PokeDexText = "It attacks with its strong tail and sharp claws.";
}

// No.6 리자몽
void PokeDataBase::CharizardData(int _Level, PokeDataBase& PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr.Type = PokeType::Fire;
	PoKeCreatePtr.Characteristic = PokeCharacteristic::맹화;
	PoKeCreatePtr.Name = "Charizard";
	PoKeCreatePtr.TypeName = "Fire";
	PoKeCreatePtr.NumberName = "006";

	PoKeCreatePtr.MaxHealthPoint = 58;
	PoKeCreatePtr.CurrentHealthPoint = 58;
	PoKeCreatePtr.AttackPower = 84;
	PoKeCreatePtr.Defense = 78;
	PoKeCreatePtr.SpecialAttackPower = 109;
	PoKeCreatePtr.SpecialDefense = 85;
	PoKeCreatePtr.Agility = 100;
	
	int PlusLevel = PoKeCreatePtr.MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr.MonsterLevel = PlusLevel;

	PoKeCreatePtr.PokeDexText = "It can fly up to 1400 m above the ground using its wings.";
}

// No.7 꼬부기
void PokeDataBase::SquirtleData(int _Level, PokeDataBase& PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr.Type = PokeType::Water;
	PoKeCreatePtr.Characteristic = PokeCharacteristic::급류;
	PoKeCreatePtr.Name = "Squirtle";
	PoKeCreatePtr.TypeName = "Water";
	PoKeCreatePtr.NumberName = "007";

	PoKeCreatePtr.MaxHealthPoint = 24;
	PoKeCreatePtr.CurrentHealthPoint = 24;
	PoKeCreatePtr.AttackPower = 48;
	PoKeCreatePtr.Defense = 65;
	PoKeCreatePtr.SpecialAttackPower = 50;
	PoKeCreatePtr.SpecialDefense = 64;
	PoKeCreatePtr.Agility = 43;
	
	int PlusLevel = PoKeCreatePtr.MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr.MonsterLevel = PlusLevel;

	PoKeCreatePtr.PokeDexText = "It hides its head inside its shell and fires a powerful water cannon.";
}

// No.8 어니부기
void PokeDataBase::WartortleData(int _Level, PokeDataBase& PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr.Type = PokeType::Water;
	PoKeCreatePtr.Characteristic = PokeCharacteristic::급류;
	PoKeCreatePtr.Name = "Wartortle";
	PoKeCreatePtr.TypeName = "Water";
	PoKeCreatePtr.NumberName = "008";

	PoKeCreatePtr.MaxHealthPoint = 39;
	PoKeCreatePtr.CurrentHealthPoint = 39;
	PoKeCreatePtr.AttackPower = 63;
	PoKeCreatePtr.Defense = 80;
	PoKeCreatePtr.SpecialAttackPower = 65;
	PoKeCreatePtr.SpecialDefense = 80;
	PoKeCreatePtr.Agility = 58;
	
	int PlusLevel = PoKeCreatePtr.MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr.MonsterLevel = PlusLevel;

	PoKeCreatePtr.PokeDexText = "They are popular as pets. The tail is a symbol of longevity.";
}

// No.9 거북왕
void PokeDataBase::BlastoiseData(int _Level, PokeDataBase& PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr.Type = PokeType::Water;
	PoKeCreatePtr.Characteristic = PokeCharacteristic::급류;
	PoKeCreatePtr.Name = "Blastoise";
	PoKeCreatePtr.TypeName = "Water";
	PoKeCreatePtr.NumberName = "009";

	PoKeCreatePtr.MaxHealthPoint = 59;
	PoKeCreatePtr.CurrentHealthPoint = 59;
	PoKeCreatePtr.AttackPower = 83;
	PoKeCreatePtr.Defense = 100;
	PoKeCreatePtr.SpecialAttackPower = 85;
	PoKeCreatePtr.SpecialDefense = 105;
	PoKeCreatePtr.Agility = 78;
	
	int PlusLevel = PoKeCreatePtr.MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr.MonsterLevel = PlusLevel;

	PoKeCreatePtr.PokeDexText = "Fires water from a cannon attached to its back.";
}

// No.10 구구
void PokeDataBase::PidgeyData(int _Level, PokeDataBase& PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr.Type = PokeType::Flying;
	PoKeCreatePtr.Characteristic = PokeCharacteristic::날카로운눈;
	PoKeCreatePtr.Name = "Pidgey";
	PoKeCreatePtr.TypeName = "Flying";
	PoKeCreatePtr.NumberName = "010";

	PoKeCreatePtr.MaxHealthPoint = 25;
	PoKeCreatePtr.CurrentHealthPoint = 25;
	PoKeCreatePtr.AttackPower = 45;
	PoKeCreatePtr.Defense = 40;
	PoKeCreatePtr.SpecialAttackPower = 35;
	PoKeCreatePtr.SpecialDefense = 35;
	PoKeCreatePtr.Agility = 56;
	
	int PlusLevel = PoKeCreatePtr.MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr.MonsterLevel = PlusLevel;

	PoKeCreatePtr.PokeDexText = "Doesn`t like to fight. It hunts small bugs hiding in the grass.";
}

// No.11 꼬렛
void PokeDataBase::RattataData(int _Level, PokeDataBase& PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr.Type = PokeType::Normal;
	PoKeCreatePtr.Characteristic = PokeCharacteristic::근성;
	PoKeCreatePtr.Name = "Rattata";
	PoKeCreatePtr.TypeName = "Normal";
	PoKeCreatePtr.NumberName = "011";

	PoKeCreatePtr.MaxHealthPoint = 18;
	PoKeCreatePtr.CurrentHealthPoint = 18;
	PoKeCreatePtr.AttackPower = 56;
	PoKeCreatePtr.Defense = 35;
	PoKeCreatePtr.SpecialAttackPower = 25;
	PoKeCreatePtr.SpecialDefense = 35;
	PoKeCreatePtr.Agility = 72;
	
	int PlusLevel = PoKeCreatePtr.MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr.MonsterLevel = PlusLevel;

	PoKeCreatePtr.PokeDexText = "Its long canines grow throughout its life and must be sharpened periodically.";
}

// No.12 깨비참
void PokeDataBase::SpearowData(int _Level, PokeDataBase& PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr.Type = PokeType::Flying;
	PoKeCreatePtr.Characteristic = PokeCharacteristic::날카로운눈;
	PoKeCreatePtr.Name = "Spearow";
	PoKeCreatePtr.TypeName = "Flying";
	PoKeCreatePtr.NumberName = "012";

	PoKeCreatePtr.MaxHealthPoint = 26;
	PoKeCreatePtr.CurrentHealthPoint = 26;
	PoKeCreatePtr.AttackPower = 60;
	PoKeCreatePtr.Defense = 30;
	PoKeCreatePtr.SpecialAttackPower = 31;
	PoKeCreatePtr.SpecialDefense = 31;
	PoKeCreatePtr.Agility = 70;
	
	int PlusLevel = PoKeCreatePtr.MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr.MonsterLevel = PlusLevel;

	PoKeCreatePtr.PokeDexText = "It flies all over the place without stopping.";
}

// No.13 꼬마돌
void PokeDataBase::GeodudeData(int _Level, PokeDataBase& PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr.Type = PokeType::Rock;
	PoKeCreatePtr.Characteristic = PokeCharacteristic::돌머리;
	PoKeCreatePtr.Name = "Geodude";
	PoKeCreatePtr.TypeName = "Rock";
	PoKeCreatePtr.NumberName = "013";

	PoKeCreatePtr.MaxHealthPoint = 20;
	PoKeCreatePtr.CurrentHealthPoint = 20;
	PoKeCreatePtr.AttackPower = 80;
	PoKeCreatePtr.Defense = 80;
	PoKeCreatePtr.SpecialAttackPower = 30;
	PoKeCreatePtr.SpecialDefense = 30;
	PoKeCreatePtr.Agility = 20;
	
	int PlusLevel = PoKeCreatePtr.MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr.MonsterLevel = PlusLevel;

	PoKeCreatePtr.PokeDexText = "Because it is round and easy to hold, it can be thrown at opponents.";
}

// No.14 롱스톤
void PokeDataBase::OnixData(int _Level, PokeDataBase& PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr.Type = PokeType::Rock;
	PoKeCreatePtr.Characteristic = PokeCharacteristic::돌머리;
	PoKeCreatePtr.Name = "Onix";
	PoKeCreatePtr.TypeName = "Rock";
	PoKeCreatePtr.NumberName = "014";

	PoKeCreatePtr.MaxHealthPoint = 25;
	PoKeCreatePtr.CurrentHealthPoint = 25;
	PoKeCreatePtr.AttackPower = 45;
	PoKeCreatePtr.Defense = 120;
	PoKeCreatePtr.SpecialAttackPower = 30;
	PoKeCreatePtr.SpecialDefense = 45;
	PoKeCreatePtr.Agility = 70;
	
	int PlusLevel = PoKeCreatePtr.MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr.MonsterLevel = PlusLevel;

	PoKeCreatePtr.PokeDexText = "They usually live in the soil. It can travel at 80 km/h inside the soil.";
}

// No.15 피카츄
void PokeDataBase::PikachuData(int _Level, PokeDataBase& PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr.Type = PokeType::Electro;
	PoKeCreatePtr.Characteristic = PokeCharacteristic::정전기;
	PoKeCreatePtr.Name = "Pikachu";
	PoKeCreatePtr.TypeName = "Electro";
	PoKeCreatePtr.NumberName = "015";

	PoKeCreatePtr.MaxHealthPoint = 35;
	PoKeCreatePtr.CurrentHealthPoint = 35;
	PoKeCreatePtr.AttackPower = 55;
	PoKeCreatePtr.Defense = 70;
	PoKeCreatePtr.SpecialAttackPower = 50;
	PoKeCreatePtr.SpecialDefense = 50;
	PoKeCreatePtr.Agility = 90;

	int PlusLevel = PoKeCreatePtr.MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr.MonsterLevel = PlusLevel;

	PoKeCreatePtr.PokeDexText = "It has small electrical pouches on either side of its cheeks. When a crisis is sensed, it discharges.";
}

PokeDataBase PokeDataBase::SpecialPokeCreate(SpecialPokeEnum _Enum, int _Level)
{
	PokeDataBase PoKeCreatePtr;

	switch (_Enum)
	{
	case SpecialPokeEnum::StartingBulbasaur:

		PoKeCreatePtr.PokeDexNumber = PokeNumber::Blastoise;

		BulbasaurData(10, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::Growl, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::VineWhip, PoKeCreatePtr);
		PokeSkillInit(4, PokeSkill::RazorLeaf, PoKeCreatePtr);

		PoKeCreatePtr.SkillCount = 4;

		break;
	case SpecialPokeEnum::StartingCharmander:

		PoKeCreatePtr.PokeDexNumber = PokeNumber::Charmander;

		CharmanderData(10, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Scratch, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::Leer, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::Ember, PoKeCreatePtr);
		PokeSkillInit(4, PokeSkill::Flamethrower, PoKeCreatePtr);

		PoKeCreatePtr.SkillCount = 4;

		break;
	case SpecialPokeEnum::StartingSquirtle:

		PoKeCreatePtr.PokeDexNumber = PokeNumber::Squirtle;

		SquirtleData(10, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::TailWhip, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::Bubble, PoKeCreatePtr);
		PokeSkillInit(4, PokeSkill::WaterGun, PoKeCreatePtr);

		PoKeCreatePtr.SkillCount = 4;

		break;
	case SpecialPokeEnum::CatchPidgey:

		PoKeCreatePtr.PokeDexNumber = PokeNumber::Pidgey;

		PidgeyData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Peck, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::FeatherDance, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::Gust, PoKeCreatePtr);
		PokeSkillInit(4, PokeSkill::AirSlash, PoKeCreatePtr);

		PoKeCreatePtr.SkillCount = 4;

		break;
	case SpecialPokeEnum::CatchRattata:
		
		PoKeCreatePtr.PokeDexNumber = PokeNumber::Rattata;

		RattataData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Bite, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::SuperFang, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::HyperFang, PoKeCreatePtr);
		PokeSkillInit(4, PokeSkill::DoubleEdge, PoKeCreatePtr);

		PoKeCreatePtr.SkillCount = 4;

		break;
	case SpecialPokeEnum::CatchSpearow:

		PoKeCreatePtr.PokeDexNumber = PokeNumber::Spearow;

		SpearowData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Peck, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::FastMove, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::QuickAttack, PoKeCreatePtr);
		PokeSkillInit(4, PokeSkill::AirSlash, PoKeCreatePtr);

		PoKeCreatePtr.SkillCount = 4;

		break;
	case SpecialPokeEnum::CatchPikachu:

		PoKeCreatePtr.PokeDexNumber = PokeNumber::Pikachu;

		PikachuData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::QuickAttack, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::Leer, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::Thunderbolt, PoKeCreatePtr);
		PokeSkillInit(4, PokeSkill::Thunder, PoKeCreatePtr);

		PoKeCreatePtr.SkillCount = 4;

		break;
	case SpecialPokeEnum::MasterPikachu:

		PoKeCreatePtr.PokeDexNumber = PokeNumber::Pikachu;

		PikachuData(99, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::QuickAttack, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::Earthquake, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::Thunderbolt, PoKeCreatePtr);
		PokeSkillInit(4, PokeSkill::Thunder, PoKeCreatePtr);

		PoKeCreatePtr.SkillCount = 4;

		break;
	case SpecialPokeEnum::UngGeodude:

		PoKeCreatePtr.PokeDexNumber = PokeNumber::Geodude;

		GeodudeData(12, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::DefenseCurl, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::RockThrow, PoKeCreatePtr);
		PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);

		PoKeCreatePtr.SkillCount = 4;

		break;
	case SpecialPokeEnum::UngOnix:

		PoKeCreatePtr.PokeDexNumber = PokeNumber::Onix;

		OnixData(18, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::Magnitude, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::DragonBreath, PoKeCreatePtr);
		PokeSkillInit(4, PokeSkill::Earthquake, PoKeCreatePtr);

		PoKeCreatePtr.SkillCount = 4;

		break;
	default:
		break;
	}

	return PoKeCreatePtr;
}
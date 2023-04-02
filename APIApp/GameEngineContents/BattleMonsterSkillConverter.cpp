#include "BattleMonsterBase.h"

const std::vector<std::string_view> BattleMonsterBase::SkiilEnumToString =
{
	"Scratch",					    // 0 ������
	"Growl",						    // 1 �����Ҹ�
	"Ember",						    // 2 �Ҳɼ���
	"Leer",							  // 3 °������
	"Slash",							  // 4 �������
	"Flamethrower",				// 5 ȭ�����
	"Tackle",								// 6 �����ġ��
	"TailWhip",							  // 7 ��������
	"Bubble",								 // 8 ��ǰ
	"WaterGun",						    // 9 ������
	"Withdraw",						    // 10 ����������
	"SkullBash",							  // 11 ����Ʈ��ġ��
	"HydroPump",							   // 12 ���̵������
	"LeechSeed",								 // 13 ���Ѹ���
	"VineWhip",								// 14 ����ä��
	"RazorLeaf",								// 15 �ٳ�������
	"SleepPowder",					  // 16 ���鰡��
	"SolarBeam",						 // 17 �ֶ��
	"SandAttack",						  // 18 �𷡻Ѹ���
	"Gust",								// 19 �ٶ�����Ű��
	"QuickAttack",							// 20 ������ȭ
	"Twister",								// 21 ȸ����
	"FeatherDance",					// 22 ���д�
	"WingAttack",						// 23 ����ġ��
	"AirSlash",						 // 24 �������
	"Peck",							// 25 �ɱ�
	"FuryAttack",					  // 26 �������
	"Pursuit",						// 27 ���󰡶�����
	"FastMove",				   // 28 ����̵�
	"Assurance",				   // 29 �ºα�����
	"DrillPeck",					 // 30 ȸ���θ�
	"DefenseCurl",					 // 31 ��ũ����
	"RockPolish",						// 32 ��ĿƮ
	"RockThrow",						  // 33 ��������
	"Magnitude",						// 34 �ű״�Ʃ��
	"Selfdestruct",					// 35 ����
	"Earthquake",						 // 36 ����
	"StoneEdge",						// 37 ���濡��
	"Bind",							// 38 ���̱�
	"RockTomb",					// 39 �ϼ�����
	"DragonBreath",				// 40 ���Ǽ���
	"IronTail",					// 41 ���̾�����
	"SandTomb",				    // 42 ������
	"Bite",								// 43 ����
	"HyperFang",			    // 44 �ʻ�մ�
	"Crunch",					 // 45 ������μ���
	"SuperFang",				 // 46 �г��Ǿմ�
	"DoubleEdge"			  // 47 ���ǻ�����Ŭ
	//"Unknown"							// 48 Max
};

const std::vector<std::string_view> BattleMonsterBase::NameEnumToString =
{
	"Bulbasaur",				  // 0 �̻��ؾ�
	"Ivysaur",					// 1 �̻���Ǯ
	"Venusaur",				  // 2 �̻��ز�
	"Charmander",			// 3 ���̸�
	"Charmeleon",			// 4 ���ڵ�
	"Charizard",				// 5 ���ڸ�
	"Squirtle",					// 6 ���α�
	"Wartortle",				// 7 ��Ϻα�
	"Blastoise",				 // 8 �źϿ�
	"Pidgey",					// 9 ����
	"Rattata",				 // 10 ����
	"Spearow",				  // 11 ������
	"Geodude",				   // 12 ������
	"Onix",					   // 13 �ս���
	"Pikachu",			//14��ī��
	//"Max"					   // max
};


void BattleMonsterBase::SetPlayerOffset()
{
	PokeNumber Id = DbPtr->GetPokeNumber_enum();
	float4 Offset = float4::Zero;

	switch (Id)
	{
	case PokeNumber::Bulbasaur:
	case PokeNumber::Ivysaur:
	case PokeNumber::Venusaur:
		break;

	case PokeNumber::Charmander:
	case PokeNumber::Charmeleon:
		Offset = float4::Up * 20.f;
	case PokeNumber::Charizard:
		break;

	case PokeNumber::Squirtle:
	case PokeNumber::Wartortle:
	case PokeNumber::Blastoise:
		break;

	case PokeNumber::Pidgey:
		break;
	case PokeNumber::Rattata:
		break;
	case PokeNumber::Spearow:
		break;

	case PokeNumber::Geodude:
		break;
	case PokeNumber::Onix:
		break;
	case PokeNumber::Pikachu:
		break;
	}

	SetMove(Offset);
}

void BattleMonsterBase::SetEnemyOffset()
{
	PokeNumber Id = DbPtr->GetPokeNumber_enum();
	float4 Offset = float4::Zero;

	switch (Id)
	{
	case PokeNumber::Bulbasaur:
	case PokeNumber::Ivysaur:
	case PokeNumber::Venusaur:
		break;

	case PokeNumber::Charmander:
	case PokeNumber::Charmeleon:
	case PokeNumber::Charizard:
		break;

	case PokeNumber::Squirtle:
	case PokeNumber::Wartortle:
	case PokeNumber::Blastoise:
		break;

	case PokeNumber::Pidgey:
		break;
	case PokeNumber::Rattata:
		break;
	case PokeNumber::Spearow:
		break;

	case PokeNumber::Geodude:
		break;
	case PokeNumber::Onix:
		Offset = float4::Up * 50.f;
		break;
	case PokeNumber::Pikachu:
		break;
	}

	SetMove(Offset);
}
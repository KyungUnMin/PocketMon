#include "BattleLevel.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include "BattleBackGround.h"
#include "BattlePlayer.h"
#include "BattleEnemy.h"

#include "BackTextActor.h"
#include "Battle_Select.h"
#include "BattleCommendActor.h"
#include "EnemyHPBackground.h"
#include "FriendlyHPBackground.h"
#include "HpBackGroundMove.h"
#include "TestScript.h"
#include "PocketMonCore.h"
#include "BattleFSM.h"
#include "BagLevel.h"
#include "PokemonLevel.h"
#include "CenterLevel.h"
#include "BattleFadeCtrl.h"
#include "Player.h"
#include "BattleDefine.h"
#include "BgmPlayer.h"
#include "Battle_PlayerHpUIHandler.h"

BattleLevel* BattleLevel::BattleLevelPtr = nullptr;
const std::string_view  BattleLevel::BattleKeyName = "Battle_Z";
const char BattleLevel::BattleKey = 'Z';

const std::string_view BattleLevel::BattleBgmName = "Battle_WildBGM.mp3";
const std::string_view BattleLevel::VictoryBgmName = "_.mp3";

BattleLevel::BattleLevel()
{
	BattleLevelPtr = this;
}

BattleLevel::~BattleLevel()
{
	if (this == BattleLevelPtr)
	{
		BattleLevelPtr = nullptr;
	}

	if (nullptr != BattleFsmPtr)
	{
		delete BattleFsmPtr;
		BattleFsmPtr = nullptr;
	}
}




void BattleLevel::Loading()
{
	GameEngineInput::CreateKey(BattleKeyName, BattleKey);
}

void BattleLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	BattleFadeCtrl* Fade = CreateActor<BattleFadeCtrl>(UpdateOrder::Battle_Actors);
	Fade->Init(BattleFadeCtrl::FadeType::BlackIn);
	Fade->SetDuration(0.1f);
	IsBgmFadeOut = false;
	IsBattleEndValue = false;

	//�ӽ� �ڵ�, ������θ� ���ʿ��� ȣ�����־�� ��, ���߿� ���� ����
	BagLevel* BagUILevel = dynamic_cast<BagLevel*>(_PrevLevel);
	if (nullptr != BagUILevel)
		return;

	PokemonLevel* MonsterChangeLevel = dynamic_cast<PokemonLevel*>(_PrevLevel);
	if (nullptr != MonsterChangeLevel)
		return;

	CenterLevel* ChangedCenterLevel = dynamic_cast<CenterLevel*>(_PrevLevel);
	if (nullptr == ChangedCenterLevel)
		return;

	TrainerPokemon* PlayerMonsters = Player::MainPlayer->GetPlayerPokemon();
	//PlayerMonsters->AddPokemon(PokeDataBase::PokeCreate(PokeNumber::Bulbasaur, 10));
	PlayerMonsters->AddSpecialPokemon(SpecialPokeEnum::StartingBulbasaur, 10);


	//Init({ PokeDataBase::PokeCreate(PokeNumber::Rattata) }, GroundType::Grass);
	//Init({ PokeDataBase::PokeCreate(1) }, GroundType::Beige, BattleNpcType::Rival);
	//Init({ PokeDataBase::PokeCreate(PokeNumber::Pikachu)}, GroundType::Beige, BattleNpcType::Leaf);
	//Init({ PokeDataBase::PokeCreate(1) }, GroundType::Beige, BattleNpcType::NPC2);
	Init({ PokeDataBase::PokeCreate(PokeNumber::Geodude), PokeDataBase::PokeCreate(PokeNumber::Onix) }, GroundType::Rock, BattleNpcType::Woong);
}

void BattleLevel::Init(
	const std::vector<PokeDataBase>& _EnemyMonsters, 
	GroundType _FieldType, BattleNpcType _NpcType)
{
	Init_Level(_EnemyMonsters, FieldConvertor(_FieldType), _NpcType);
}

void BattleLevel::Init_Level(
	const std::vector<PokeDataBase>& _EnemyMonsters, 
	BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	BattleType = _NpcType;
	PrevLevelVolume = BgmPlayer::GetVolume();
	CreateBGM(BattleType, _EnemyMonsters);

	//��� �� �÷��̾�� ������� �ٴ� �̹����� �ʱ�ȭ
	InitActors(_FieldType, _NpcType, _EnemyMonsters);

	BattleFsmPtr = new BattleFSM(nullptr);
	BattleFsmPtr->Init(_FieldType, _NpcType);
}

void BattleLevel::InitActors(
	BattleFieldType _FieldType, BattleNpcType _NpcType, 
	const std::vector<PokeDataBase>& _EnemyMonsters)
{
	CreateActor<BattleBackGround>(UpdateOrder::Battle_Actors)->Init(_FieldType);

	BattlePlayer* Player = CreateActor<BattlePlayer>(UpdateOrder::Battle_Actors);
	Player->Init(_FieldType, _NpcType);

	BattleEnemy* Enemy = CreateActor<BattleEnemy>(UpdateOrder::Battle_Actors);
	Enemy->Init(_FieldType, _NpcType, _EnemyMonsters);
}


void BattleLevel::CreateBGM(BattleNpcType _BattleType, const std::vector<PokeDataBase>& _EnemyMonsters)
{
	switch (_BattleType)
	{
	case BattleNpcType::Rival:
		BgmPlayer::PlayBGM("Battle_Gym1.mp3");
		//BgmPlayer::SetVolume(WorldBgmVolumn);
		return;
	case BattleNpcType::Woong:
		BgmPlayer::PlayBGM("Battle_Master.mp3");
		//BgmPlayer::SetVolume(WorldBgmVolumn);
		return;
	case BattleNpcType::Leaf:
		BgmPlayer::PlayBGM("Battle_Gym2.mp3");
		//BgmPlayer::SetVolume(WorldBgmVolumn);
		return;
	case BattleNpcType::NPC2:
	case BattleNpcType::NPC3:
		BgmPlayer::PlayBGM("Battle_Npc.mp3");
		//BgmPlayer::SetVolume(WorldBgmVolumn);
		return;
	case BattleNpcType::None:
	default:
		break;
	}

	for (const PokeDataBase& Monster :  _EnemyMonsters)
	{
		if (PokeNumber::Pikachu != Monster.GetPokeNumber_enum())
			continue;

		BgmPlayer::PlayBGM("Battle_Pikachu2.mp3");
		//BgmPlayer::SetVolume(WorldBgmVolumn);
		return;
	}

	BgmPlayer::PlayBGM("Battle_WildBGM.mp3");
	//BgmPlayer::SetVolume(WorldBgmVolumn);
}




void BattleLevel::Update(float _DeltaTime)
{
	//FadeOutBGM(_DeltaTime);

	//�׽�Ʈ��
	if (true == TestKeyUpdate())
		return;

	if (nullptr == BattleFsmPtr)
		return;

	BattleFsmPtr->Update(_DeltaTime);
}

bool BattleLevel::TestKeyUpdate()
{
	if (true == GameEngineInput::IsDown("BackCenterLevel"))
	{
		Clear();
		PocketMonCore::GetInst().ChangeLevel("CenterLevel");
		return true;
	}


	return false;
}





void BattleLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	//�������� �̵��ϴ� ��쿣 Actor���� �������� ����
	BagLevel* BagUILevel = dynamic_cast<BagLevel*>(_NextLevel);
	if (nullptr != BagUILevel)
		return;

	PokemonLevel* MonsterChangeLevel = dynamic_cast<PokemonLevel*>(_NextLevel);
	if (nullptr != MonsterChangeLevel)
		return;

	
}





void BattleLevel::UsePortionItem()
{
	BattleStateType NowFsmType = BattleFsmPtr->GetNowState<BattleStateType>();

	if (BattleStateType::PlayerTurn != NowFsmType)
	{
		MsgAssert("���� ��Ʋ FSM�� Player���ʰ� �ƴմϴ�");
		return;
	}

	BattleMonsterPlayer* PlayerMonster = BattlePlayer::PlayerPtr->GetMonster();
	PlayerMonster->GetHpUI()->ReCreateUI();
	BattleFsmPtr->ChangeState(BattleStateType::UseItem);
}

void BattleLevel::UseMonsterBall(ItemCode _MonsterBallType)
{
	if (BattleStateType::PlayerTurn != BattleFsmPtr->GetNowState<BattleStateType>())
	{
		MsgAssert("[��Ʋerror] : �÷��̾� ���ʰ� �ƴ� ��쿡 ���ͺ��� ����� �� �����ϴ�");
		return;
	}

	if (ItemCode::MasterBall != _MonsterBallType && ItemCode::MonsterBall != _MonsterBallType)
	{
		MsgAssert("[��Ʋerror] : �Է����� ���� ItemCode�� ���ͺ� ������ �ƴմϴ�");
		return;
	}

	bool IsMasterBall = (ItemCode::MasterBall == _MonsterBallType) ? true : false;
	BattleFsmPtr->ChangeState(BattleStateType::ThrowMonsterBall);
	BattlePlayer::PlayerPtr->ThrowBallToCatch(IsMasterBall);
}


void BattleLevel::LockWildPocketMon()
{
	if (BattleStateType::ThrowMonsterBall != BattleFsmPtr->GetNowState<BattleStateType>())
	{
		MsgAssert("���ͺ��� ���������� �߻����ϸ��� ������ �ֽ��ϴ�");
		return;
	}

	BattleFsmPtr->ChangeState(BattleStateType::CatchWildMonster);
}

void BattleLevel::UnlockWildPocketMon()
{
	if (BattleStateType::ThrowMonsterBall != BattleFsmPtr->GetNowState<BattleStateType>())
	{
		MsgAssert("���ͺ��� ���������� ���Ͱ� Ż���� �� �ֽ��ϴ�");
		return;
	}

	BattleFsmPtr->ChangeState(BattleStateType::CatchFailWildMonster);
}



void BattleLevel::ChangePlayerMonster(PokeNumber _NextMonster)
{
	/*TrainerPokemon* Mon = Player::MainPlayer->GetPlayerPokemon();
	Mon->NextPokemon();*/

	//BattleMonsterPlayer* PlayerMonster = BattlePlayer::PlayerPtr->GetMonster();

	BattleMonsterPlayer* PlayerMonster = BattlePlayer::PlayerPtr->GetMonster();
	PlayerMonster->Death();
	BattleFsmPtr->ChangeState(BattleStateType::PlayerMonsterChange);
}


void BattleLevel::ChangeFieldLevel(bool IsWin, bool _FadeColorBlack, float _FadeDuration)
{
	BattleFadeCtrl::FadeType FadeType = _FadeColorBlack ? BattleFadeCtrl::FadeType::BlackOut : BattleFadeCtrl::FadeType::WhiteOut;

	BattleFadeCtrl* Fade = CreateActor<BattleFadeCtrl>(UpdateOrder::Battle_Actors);
	Fade->Init(FadeType, std::bind(&BattleLevel::Clear, this), false);
	Fade->SetDuration(_FadeDuration);
	FadeDuration = _FadeDuration;
	IsBgmFadeOut = true;
	IsBattleEndValue = true;

	if (true == IsWin)
		return;

	Player::MainPlayer->SetPlayerDeath();
}


void BattleLevel::FadeOutBGM(float _DeltaTime)
{
	if (false == IsBgmFadeOut)
		return;

	static float Timer = 0.f;

	Timer += _DeltaTime;
	if (FadeDuration < Timer)
	{
		IsBgmFadeOut = false;
		Timer = 0.f;
		return;
	}

	float Ratio = (Timer / FadeDuration);
	if (1.f < Ratio)
	{
		Ratio = 1.f;
	}

	float NowVolumn = WorldBgmVolumn * (1.f - Ratio);
	BgmPlayer::SetVolume(NowVolumn);
}



void BattleLevel::Clear()
{
	if (nullptr != BattleFsmPtr)
	{
		delete BattleFsmPtr;
		BattleFsmPtr = nullptr;
	}

	std::vector<GameEngineActor*> Actors = GetActors(UpdateOrder::Battle_Actors);
	for (GameEngineActor* Actor : Actors)
	{
		Actor->Death();
	}

	Actors.clear();
	//BgmPlayer::SetVolume(PrevLevelVolume);

	TrainerPokemon* MonsterBag = Player::MainPlayer->GetPlayerPokemon();
	std::vector<PokeDataBase>& Monsters = MonsterBag->GetPokemonsRef();

	for (PokeDataBase& Monster : Monsters)
	{
		Monster.Resetbuffstack();
	}

	
	PocketMonCore::GetInst().ChangeLevel("FieldmapLevel");
}





bool BattleLevel::IsBattleSelectTurn()
{
	return BattleStateType::PlayerTurn == BattleFsmPtr->GetNowState<BattleStateType>();
}



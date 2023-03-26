#include "BattleMonsterBall.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterBallFSM.h"
#include "ContentsEnum.h"

const std::string_view BattleMonsterBall::ThrowAniName = "Throw";
const std::string_view BattleMonsterBall::OpenAniName = "Open";
const std::string_view BattleMonsterBall::RollAniName = "Roll";
const std::string_view BattleMonsterBall::IdleAniName = "Idle";

const std::string_view BattleMonsterBall::MasterBallName = "BattleMasterBall";
const std::string_view BattleMonsterBall::MonsterBallName = "BattleMonsterBall";

BattleMonsterBall::BattleMonsterBall()
{
	FsmPtr = new BattleMonsterBallFSM;
}

BattleMonsterBall::~BattleMonsterBall()
{
	if (nullptr != FsmPtr)
	{
		delete FsmPtr;
		FsmPtr = nullptr;
	}

}


void BattleMonsterBall::Init(BattleBallType _Type)
{
	std::string_view Name = MonsterBallName;
	if (BattleBallType::Catch_MasterBall == _Type)
	{
		Name = MasterBallName;
	}

	RenderPtr = CreateRender(BattleRenderOrder::MonsterBall);
	RenderPtr->SetScale(RenderScale);

	CreateThrowAni(Name);
	CreateOpenAni(Name);
	CreateRollAni(Name);

	FsmPtr->Init(_Type, this);
}


void BattleMonsterBall::CreateThrowAni(const std::string_view& _Name)
{
	std::string ImagePath = _Name.data() + std::string(".bmp");

	const size_t FrameCnt = 8;
	std::vector<int> FrmIndex(FrameCnt);
	for (size_t i = 0; i < FrmIndex.size(); ++i)
	{
		FrmIndex[i] = static_cast<int>(FrameCnt - i - 1);
	}

	RenderPtr->CreateAnimation
	({
		.AnimationName = ThrowAniName,
		.ImageName = ImagePath,
		.InterTime = 0.03f,
		.FrameIndex = FrmIndex
	});
}

void BattleMonsterBall::CreateOpenAni(const std::string_view& _Name)
{
	std::string ImagePath = _Name.data() + std::string("Open.bmp");

	RenderPtr->CreateAnimation
	({
		.AnimationName = OpenAniName,
		.ImageName = ImagePath,
		.Start = 0,
		.End = 1,
		.InterTime = 0.1f,
		.Loop = false
	});
}

void BattleMonsterBall::CreateRollAni(const std::string_view& _Name)
{
	std::string ImagePath = _Name.data() + std::string("Roll.bmp");

	std::vector<int> AniFrm = { 1, 2, 1, 0 , 1, 1};

	RenderPtr->CreateAnimation
	({
		.AnimationName = RollAniName,
		.ImageName = ImagePath,
		.InterTime = 0.1f,
		.Loop = true,
		.FrameIndex = AniFrm,
	});
}







void BattleMonsterBall::Update(float _DeltaTime)
{
	FsmPtr->Update(_DeltaTime);
}

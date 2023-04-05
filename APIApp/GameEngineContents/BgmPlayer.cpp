#include "BgmPlayer.h"
#include <GameEngineCore/GameEngineResources.h>

GameEngineSoundPlayer BgmPlayer::MainBGM;
std::string BgmPlayer::BgmName = "";
float BgmPlayer::VolumeValue = 1.f;

void BgmPlayer::PlayBGM(const std::string_view& _BgmName, bool _IsLoop)
{
	if (_BgmName == BgmName)
	{
		return;
	}

	if (true == MainBGM.VaildCheck())
	{
		MainBGM.Stop();
	}

	MainBGM = GameEngineResources::GetInst().SoundPlayToControl(_BgmName);
	
	if (true == _IsLoop)
	{
		MainBGM.LoopCount(10000);
	}
	else
	{
		MainBGM.LoopCount(0);
	}

	BgmName = _BgmName;
}

void BgmPlayer::StopCurBGM(bool _IsLoop)
{
	MainBGM.Stop();
}

void BgmPlayer::PlayCurBGM(bool _IsLoop)
{
	MainBGM = GameEngineResources::GetInst().SoundPlayToControl(BgmName);
	if (true == _IsLoop)
	{
		MainBGM.LoopCount(10000);
	}
	else
	{
		MainBGM.LoopCount(0);
	}
}

void BgmPlayer::SetVolume(float _Volumn)
{
	VolumeValue = _Volumn;
	MainBGM.Volume(VolumeValue);
}

BgmPlayer::BgmPlayer()
{
}

BgmPlayer::~BgmPlayer()
{
}

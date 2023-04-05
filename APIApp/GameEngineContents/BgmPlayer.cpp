#include "BgmPlayer.h"
#include <GameEngineCore/GameEngineResources.h>

GameEngineSoundPlayer BgmPlayer::MainBGM;
GameEngineSoundPlayer BgmPlayer::EffectSound;
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
		MainBGM.LoopCount(1);
	}
}

void BgmPlayer::SoundPlayBgmPause(const std::string_view& _EffectName, float _Volume)
{
	EffectSound = GameEngineResources::GetInst().SoundPlayToControl(_EffectName);
	EffectSound.Volume(_Volume);
	EffectSound.LoopCount(1);
	PauseOn();
}

void BgmPlayer::PauseOn()
{
	if (true == MainBGM.VaildCheck())
	{
		MainBGM.PauseOn();
	}
}

void BgmPlayer::PauseOff()
{
	if (true == MainBGM.VaildCheck())
	{
		MainBGM.PauseOff();
	}
}

void BgmPlayer::SetVolume(float _Volumn)
{
	VolumeValue = _Volumn;
	MainBGM.Volume(VolumeValue);
}

void BgmPlayer::Update(float _DeltaTime)
{
	if (false == EffectSound.VaildCheck())
	{
		return;
	}

	if (false == EffectSound.IsPlaying())
	{
		EffectSound.ResetSound();
		PauseOff();
	}
}

BgmPlayer::BgmPlayer()
{
}

BgmPlayer::~BgmPlayer()
{
}

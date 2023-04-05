#include "BgmPlayer.h"
#include <GameEnginePlatform/GameEngineSound.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>

GameEngineSoundPlayer BgmPlayer::MainBGM;
GameEngineSoundPlayer BgmPlayer::EffectSound;
std::string BgmPlayer::BgmName = "";
float BgmPlayer::VolumeValue = 1.f;
bool BgmPlayer::FadeCheck = false;

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

void BgmPlayer::PlayBGMFade(const std::string_view& _BgmName, bool _IsLoop)
{
	if (_BgmName == BgmName)
	{
		return;
	}

	if (true == MainBGM.VaildCheck())
	{
		SoundFadeStop(MainBGM, 0.7);
	}

	MainBGM = SoundFadePlay(_BgmName, 2.0, VolumeValue);

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

void BgmPlayer::SoundFadePauseOff(FMOD::Channel* _Channel, double _Time, float _Volume)
{
	if (nullptr == _Channel)
	{
		MsgAssert("해당 사운드가 존재하지 않습니다");
		return;
	}

	int Rate = 0;
	unsigned long long ParentClock = 0u;

	FMOD::System* SoundSys = nullptr;
	_Channel->getSystemObject(&SoundSys);
	SoundSys->getSoftwareFormat(&Rate, 0, 0);
	_Channel->getDSPClock(nullptr, &ParentClock);

	unsigned long long EndClock = static_cast<unsigned long long>(ParentClock + (Rate * _Time));

	_Channel->removeFadePoints(0, INT64_MAX);
	_Channel->addFadePoint(ParentClock, 0.0f);
	_Channel->addFadePoint(EndClock, _Volume);
	_Channel->setDelay(0, 0, false);
	_Channel->setPaused(false);
}

void BgmPlayer::SoundFadePauseOff(GameEngineSoundPlayer& _Sound, double _Time, float _Volume)
{
	SoundFadePauseOff(_Sound.GetChannel(), _Time, _Volume);
}

GameEngineSoundPlayer BgmPlayer::SoundFadePlay(const std::string_view& _SoundName, double _Time, float _Volume)
{
	GameEngineSoundPlayer NewSoundPlayer = GameEngineResources::GetInst().SoundPlayToControl(_SoundName);
	SoundFadePauseOff(NewSoundPlayer, _Time, _Volume);
	return NewSoundPlayer;
}

void BgmPlayer::SoundFadeStop(FMOD::Channel* _Channel, double _Time, bool _IsStop)
{
	if (nullptr == _Channel)
	{
		MsgAssert("존재하지 않은 사운드를 컨트롤하려 했습니다");
		return;
	}

	int Rate = 0;
	unsigned long long ParentClock = 0u;
	float CurVolume = 0.0f;

	_Channel->setLoopCount(1);
	FMOD::System* SoundSys = nullptr;
	_Channel->getSystemObject(&SoundSys);
	SoundSys->getSoftwareFormat(&Rate, 0, 0);
	_Channel->getDSPClock(nullptr, &ParentClock);
	_Channel->getVolume(&CurVolume);

	unsigned long long EndClock = static_cast<unsigned long long>(ParentClock + (Rate * _Time));

	_Channel->removeFadePoints(0, INT64_MAX);
	_Channel->addFadePoint(ParentClock, CurVolume);
	_Channel->addFadePoint(EndClock, static_cast<unsigned __int64>(0.0f));
	_Channel->setDelay(ParentClock, EndClock, _IsStop);
}

void BgmPlayer::SoundFadeStop(GameEngineSoundPlayer& _Sound, double _Time, bool _IsStop)
{
	SoundFadeStop(_Sound.GetChannel(), _Time, _IsStop);
}

void BgmPlayer::SoundPlayBgmPause(const std::string_view& _EffectName, float _Volume)
{
	EffectSound = GameEngineResources::GetInst().SoundPlayToControl(_EffectName);
	EffectSound.Volume(_Volume);
	EffectSound.LoopCount(1);
	PauseOn();
	FadeCheck = false;
}

void BgmPlayer::SoundPlayBgmPauseFade(const std::string_view& _EffectName, float _Volume)
{
	EffectSound = GameEngineResources::GetInst().SoundPlayToControl(_EffectName);
	EffectSound.Volume(_Volume);
	EffectSound.LoopCount(1);
	PauseOnFade();
	FadeCheck = true;
}

void BgmPlayer::PauseOn()
{
	if (true == MainBGM.VaildCheck())
	{
		MainBGM.PauseOn();
	}
}

void BgmPlayer::PauseOnFade()
{
	SoundFadeStop(MainBGM, 0.7, false);
}

void BgmPlayer::PauseOff()
{
	if (true == MainBGM.VaildCheck())
	{
		MainBGM.PauseOff();
	}
}

void BgmPlayer::PauseOffFade()
{
	SoundFadePauseOff(MainBGM, 2.0, VolumeValue);
}

void BgmPlayer::SetVolume(float _Volumn)
{
	VolumeValue = _Volumn;
	MainBGM.Volume(VolumeValue);
}
 
void BgmPlayer::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("FadeOnBGM"))
	{
		SoundFadePauseOff(MainBGM, 3.0, 1.0f);
	}

	if (true == GameEngineInput::IsDown("FadeOutBGM"))
	{
		SoundFadeStop(MainBGM, 1.0f, false);
	}

	if (false == EffectSound.VaildCheck())
	{
		return;
	}

	if (false == EffectSound.IsPlaying())
	{
		EffectSound.ResetSound();

		if (true == FadeCheck)
		{
			PauseOffFade();
		}
		else
		{
			PauseOff();
		}
	}
}

BgmPlayer::BgmPlayer()
{
}

BgmPlayer::~BgmPlayer()
{
}

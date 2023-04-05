#pragma once
#include <string>
#include <GameEnginePlatform/GameEngineSound.h>

class BgmPlayer
{
	friend class PocketMonCore;
public:
	static void PlayBGM(const std::string_view& _BgmName, bool _IsLoop = true);
	static void PlayBGMFade(const std::string_view& _BgmName, bool _IsLoop = true);

	static void StopCurBGM(bool _IsLoop = true);
	static void PlayCurBGM(bool _IsLoop = true);

	static void SoundFadePauseOff(FMOD::Channel* _Channel, double _Time, float _Volume = 1.0f);
	static void SoundFadePauseOff(class GameEngineSoundPlayer& _Sound, double _Time, float _Volume = 1.0f);
	static class GameEngineSoundPlayer SoundFadePlay(const std::string_view& _SoundName, double _Time, float _Volume = 1.0f);

	static void SoundFadeStop(FMOD::Channel* _Channel, double _Time, bool _IsStop = true);
	static void SoundFadeStop(class GameEngineSoundPlayer& _Sound, double _Time, bool _IsStop = true);
	
	static void SoundPlayBgmPause(const std::string_view& _EffectName, float _Volume = 1.0f);
	static void SoundPlayBgmPauseFade(const std::string_view& _EffectName, float _Volume = 1.0f);

	static void PauseOn();
	static void PauseOnFade();
	static void PauseOff();
	static void PauseOffFade();

	static float GetVolume()
	{
		return VolumeValue;
	}

	static void SetVolume(float _Volumn);

private:
	static class GameEngineSoundPlayer MainBGM;
	static class GameEngineSoundPlayer EffectSound;
	static std::string BgmName;
	static float VolumeValue;
	static bool FadeCheck;
	
	static void Update(float _DeltaTime);

protected:
	
private:
	BgmPlayer();
	~BgmPlayer();

	BgmPlayer(const BgmPlayer& _Other) = delete;
	BgmPlayer(BgmPlayer&& _Other) noexcept = delete;
	BgmPlayer& operator=(const BgmPlayer& _Other) = delete;
	BgmPlayer& operator=(BgmPlayer&& _Other) noexcept = delete;

};


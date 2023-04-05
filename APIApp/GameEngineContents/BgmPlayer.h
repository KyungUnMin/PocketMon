#pragma once
#include <string>
#include <GameEnginePlatform/GameEngineSound.h>

class BgmPlayer
{
	friend class PocketMonCore;
public:
	static void PlayBGM(const std::string_view& _BgmName, bool _IsLoop = true);
	static void StopCurBGM(bool _IsLoop = true);
	static void PlayCurBGM(bool _IsLoop = true);

	static void SoundPlayBgmPause(const std::string_view& _EffectName);
	static void PauseOn();
	static void PauseOff();

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


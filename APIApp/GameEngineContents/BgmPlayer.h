#pragma once
#include <string>
#include <GameEnginePlatform/GameEngineSound.h>

class BgmPlayer
{
public:
	static void PlayBGM(const std::string_view& _BgmName, bool _IsLoop = true);
	static void StopCurBGM(bool _IsLoop = true);
	static void PlayCurBGM(bool _IsLoop = true);

private:
	static class GameEngineSoundPlayer MainBGM;
	static std::string BgmName;

protected:
	
private:
	BgmPlayer();
	~BgmPlayer();

	BgmPlayer(const BgmPlayer& _Other) = delete;
	BgmPlayer(BgmPlayer&& _Other) noexcept = delete;
	BgmPlayer& operator=(const BgmPlayer& _Other) = delete;
	BgmPlayer& operator=(BgmPlayer&& _Other) noexcept = delete;

};


#include "BgmPlayer.h"
#include <GameEngineCore/GameEngineResources.h>

GameEngineSoundPlayer BgmPlayer::MainBGM;
std::string BgmPlayer::BgmName = "";

void BgmPlayer::PlayBGM(const std::string_view& _BgmName)
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
	MainBGM.LoopCount(10000);
	BgmName = _BgmName;
}

BgmPlayer::BgmPlayer()
{
}

BgmPlayer::~BgmPlayer()
{
}

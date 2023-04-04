#include "BgmPlayer.h"
#include <GameEngineCore/GameEngineResources.h>

GameEngineSoundPlayer BgmPlayer::MainBGM;
std::string BgmPlayer::BgmName = "";

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

BgmPlayer::BgmPlayer()
{
}

BgmPlayer::~BgmPlayer()
{
}

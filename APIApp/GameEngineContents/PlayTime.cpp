#include "PlayTime.h"
PlayTime* PlayTime::MianPlayTime = nullptr;

PlayTime::PlayTime()
{
	MianPlayTime = this;
}

PlayTime::~PlayTime()
{

}

void PlayTime::Update(float _DeltaTime)
{
	Second += _DeltaTime;
	if (Second >= 60)
	{
		Minute++;
		Second = 0;
	}

	if (Minute >= 60)
	{
		Hour++;
		Minute = 0;
	}
}

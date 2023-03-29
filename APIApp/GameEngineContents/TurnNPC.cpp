#include "TurnNPC.h"
#include "ContentsEnum.h"

TurnNPC::TurnNPC()
{
}

TurnNPC::~TurnNPC() 
{
}

void TurnNPC::IdleUpdate(float _DeltaTime)
{
	TurnProgress += _DeltaTime;

	if (TurnTime <= TurnProgress)
	{
		TurnProgress -= TurnTime;

		if (TurnDirEnum == TurnDir::Left)
		{
			Look(TurnLeftDir(Dir));
		}
		else
		{
			Look(TurnRightDir(Dir));
		}
	}

	BaseNPC::IdleUpdate(_DeltaTime);
}


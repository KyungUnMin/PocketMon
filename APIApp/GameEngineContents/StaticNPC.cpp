#include "StaticNPC.h"
#include "ContentsEnum.h"

StaticNPC::StaticNPC() :
	BaseDir(LookDir::Up)
{
}

StaticNPC::~StaticNPC() 
{
}

void StaticNPC::IdleUpdate(float _DeltaTime)
{
	if (BaseDir != Dir)
	{
		Look(BaseDir);
	}

	BaseNPC::IdleUpdate(_DeltaTime);
}

void StaticNPC::MoveEnd()
{
	BaseNPC::MoveEnd();
}

void StaticNPC::InteractionEnd()
{
	BaseNPC::InteractionEnd();
	Look(BaseDir);
}

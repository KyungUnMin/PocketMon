#include "StaticNPC.h"
#include "ContentsEnum.h"

StaticNPC::StaticNPC() :
	BaseDir(LookDir::Up)
{
}

StaticNPC::~StaticNPC() 
{
}

void StaticNPC::MoveEnd()
{
	BaseNPC::MoveEnd();
	Look(BaseDir);
}

void StaticNPC::InteractionEnd()
{
	BaseNPC::InteractionEnd();
	Look(BaseDir);
}

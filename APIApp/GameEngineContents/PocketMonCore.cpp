#include "PocketMonCore.h"

#include "CenterLevel.h"
#include "FieldmapLevel.h"

PocketMonCore PocketMonCore::Core;

PocketMonCore::PocketMonCore()
{

}

PocketMonCore::~PocketMonCore()
{

}

void PocketMonCore::Start()
{
	bool* FOR_DEBUG = new bool;

	CreateLevel<CenterLevel>("CenterLevel");
	CreateLevel<FieldmapLevel>("FieldmapLevel");

	ChangeLevel("CenterLevel");
}

void PocketMonCore::Update()
{

}

void PocketMonCore::End()
{

}

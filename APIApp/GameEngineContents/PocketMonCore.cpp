#include "PocketMonCore.h"

#include "CenterLevel.h"

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

	CreateLevel<CenterLevel>("CenterLesvel");

	ChangeLevel("CenterLevel");
}

void PocketMonCore::Update()
{

}

void PocketMonCore::End()
{

}

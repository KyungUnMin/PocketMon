#include "PocketMonCore.h"

#include "CenterLevel.h"
#include "TextTestLevel.h"


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
	CreateLevel<TextTestLevel>("TextTestLevel");

	ChangeLevel("CenterLevel");
}

void PocketMonCore::Update()
{

}

void PocketMonCore::End()
{

}

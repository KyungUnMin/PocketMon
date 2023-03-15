#include "PocketMonCore.h"
#include "TestLevel.h"

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

	CreateLevel<TestLevel>("TestLevel");
	ChangeLevel("TestLevel");
}

void PocketMonCore::Update()
{

}

void PocketMonCore::End()
{

}

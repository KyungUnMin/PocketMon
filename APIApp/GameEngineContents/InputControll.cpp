#include "InputControll.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineRandom.h>

int InputControll::InputHandle = -1;
bool InputControll::UseHandleCheck = false;

InputControll::InputControll()
{
}

InputControll::~InputControll()
{
}

bool InputControll::CanControll()
{
	return !UseHandleCheck;
}

int InputControll::UseControll()
{
	if (true == UseHandleCheck)
	{
		MsgAssert("컨트롤러가 사용되고 있는 상태에서 컨트롤러를 사용하려 했습니다");
		return -1;
	}

	InputHandle = GameEngineRandom::MainRandom.RandomInt(0, 1000000);
	UseHandleCheck = true;
	return InputHandle;
}

int InputControll::ResetControll(int _Handle)
{
	if (InputHandle != _Handle)
	{
		MsgAssert("잘못된 인풋 컨트롤 핸들을 참조했습니다");
		return -999;
	}

	InputHandle = -1;
	UseHandleCheck = false;

	return InputHandle;
}
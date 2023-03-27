#include "InputControll.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineRandom.h>

int InputControll::InputHandle = -1;
bool InputControll::UseHandleCheck = false;
bool InputControll::IsDoubelCheckValue = false;

InputControll::InputControll()
{
}

InputControll::~InputControll()
{
}

bool InputControll::CanControll(int _Handle = -1)
{
	if (InputHandle == _Handle)
	{
		return true;
	}

	return !UseHandleCheck;
}

int InputControll::UseControll()
{
	if (true == UseHandleCheck)
	{
		MsgAssert("��Ʈ�ѷ��� ���ǰ� �ִ� ���¿��� ��Ʈ�ѷ��� ����Ϸ� �߽��ϴ�");
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
		MsgAssert("�߸��� ��ǲ ��Ʈ�� �ڵ��� �����߽��ϴ�");
		return -999;
	}

	InputHandle = -1;
	UseHandleCheck = false;

	return InputHandle;
}

void InputControll::UsedKey()
{
	IsDoubelCheckValue = true;
}

bool InputControll::IsCurFrameUsedKey()
{
	return IsDoubelCheckValue;
}

void InputControll::ResetDoubleCheck()
{
	IsDoubelCheckValue = false;
}
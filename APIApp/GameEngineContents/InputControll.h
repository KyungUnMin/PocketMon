#pragma once


class InputControll
{

public:
	// 현재 컨트롤이 가능한지 여부
	//static bool CanControll();
	//static int UseControll();
	//static void ResetControll();
private:
	//static int InputHandle;
	//static bool UseHandleCheck;

protected:

private:
	InputControll();
	~InputControll();

	InputControll(const InputControll& _Other) = delete;
	InputControll(InputControll&& _Other) noexcept = delete;
	InputControll& operator=(const InputControll& _Other) = delete;
	InputControll& operator=(InputControll&& _Other) noexcept = delete;

};
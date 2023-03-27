#pragma once


class InputControll
{

public:
	// 현재 컨트롤이 가능한지 여부
	static bool CanControll();

	// 내가 컨트롤러를 사용하겠다
	static int UseControll();

	// 컨트롤러 반환
	static int ResetControll(int _Handle);
private:
	static int InputHandle;
	static bool UseHandleCheck;

protected:

private:
	InputControll();
	~InputControll();

	InputControll(const InputControll& _Other) = delete;
	InputControll(InputControll&& _Other) noexcept = delete;
	InputControll& operator=(const InputControll& _Other) = delete;
	InputControll& operator=(InputControll&& _Other) noexcept = delete;

};
#pragma once


class InputControll
{

public:
	// 현재 컨트롤이 가능한지 여부
	static bool CanControll(int _Handle = -14230948);

	// 내가 컨트롤러를 사용하겠다
	static int UseControll();

	// 컨트롤러 반환
	static int ResetControll(int _Handle);

	// 중복체크 해야할 경우 해당 함수를 호출해 더블체크
	static void UsedKey();

	// 이번 프레임에 키가 눌렸는가
	static bool IsCurFrameUsedKey();

	// 더블체크 초기화
	static void ResetDoubleCheck();


private:
	static int InputHandle;
	static bool UseHandleCheck;
	static bool IsDoubelCheckValue;

protected:

private:
	InputControll();
	~InputControll();

	InputControll(const InputControll& _Other) = delete;
	InputControll(InputControll&& _Other) noexcept = delete;
	InputControll& operator=(const InputControll& _Other) = delete;
	InputControll& operator=(InputControll&& _Other) noexcept = delete;

};
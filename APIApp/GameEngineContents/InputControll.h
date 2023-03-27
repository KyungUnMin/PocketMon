#pragma once


class InputControll
{

public:
	// ���� ��Ʈ���� �������� ����
	static bool CanControll(int _Handle = -1);

	// ���� ��Ʈ�ѷ��� ����ϰڴ�
	static int UseControll();

	// ��Ʈ�ѷ� ��ȯ
	static int ResetControll(int _Handle);

	// �ߺ�üũ �ؾ��� ��� �ش� �Լ��� ȣ���� ����üũ
	static void UsedKey();

	// �̹� �����ӿ� Ű�� ���ȴ°�
	static bool IsCurFrameUsedKey();

	// ����üũ �ʱ�ȭ
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
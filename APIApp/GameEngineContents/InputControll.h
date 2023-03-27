#pragma once


class InputControll
{

public:
	// ���� ��Ʈ���� �������� ����
	static bool CanControll();

	// ���� ��Ʈ�ѷ��� ����ϰڴ�
	static int UseControll();

	// ��Ʈ�ѷ� ��ȯ
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
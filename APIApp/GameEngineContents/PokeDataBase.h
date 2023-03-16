#pragma once

class GameEngineRender;

// ���� :
class PokeDataBase
{
public:
	// constrcuter destructer
	PokeDataBase();
	~PokeDataBase();

	// delete Function
	PokeDataBase(const PokeDataBase& _Other) = delete;
	PokeDataBase(PokeDataBase&& _Other) noexcept = delete;
	PokeDataBase& operator=(const PokeDataBase& _Other) = delete;
	PokeDataBase& operator=(PokeDataBase&& _Other) noexcept = delete;

protected:

private:
	// ���� �̹���
	GameEngineRender* MonsterImage = nullptr;

	// �������ͽ�
	int Hp = 0;
	int Attack

};


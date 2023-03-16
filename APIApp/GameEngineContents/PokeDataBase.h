#pragma once

class GameEngineRender;

// 설명 :
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
	// 몬스터 이미지
	GameEngineRender* MonsterImage = nullptr;

	// 스테이터스
	int Hp = 0;
	int Attack

};


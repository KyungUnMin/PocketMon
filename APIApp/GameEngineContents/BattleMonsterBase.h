#pragma once
#include <GameEngineCore/GameEngineActor.h>

class PokeDataBase;
class GameEngineLevel;
enum class PokeNumber;

class BattleMonsterBase : public GameEngineActor
{
public:
	static BattleMonsterBase* CreateMonster(
		GameEngineLevel* _Level, 
		PokeNumber _MonType,
		bool _IsPlayerMonster);

	BattleMonsterBase();
	~BattleMonsterBase() override;

	BattleMonsterBase(const BattleMonsterBase& _Other) = delete;
	BattleMonsterBase(BattleMonsterBase&& _Other) noexcept = delete;
	BattleMonsterBase& operator=(const BattleMonsterBase& _Other) = delete;
	BattleMonsterBase& operator=(const BattleMonsterBase&& _Other) noexcept = delete;

	virtual void Init(bool _IsPlayerMonster) = 0;

	inline PokeDataBase* GetDB()
	{
		return DbPtr;
	}

protected:

private:
	PokeDataBase* DbPtr = nullptr;
};


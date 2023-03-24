#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentsEnum.h"

class GameEngineRender;
class TestScript;
class Battle_Select;
class BattleFSM;
class BackTextActor;
enum class PokeNumber;
enum class ItemCode;


enum class BattleFieldType
{
	Indoor,
	Forest0,	//�Ϲ� ��
	Forest1,	//��Ͻ�
	Forest2,	//�������� ���� �� ���� ��
	Gym,
};

enum class BattleNpcType
{
	None,

	Woong
};


class BattleLevel : public GameEngineLevel
{
public:
	static BattleLevel* BattleLevelPtr;
	static const std::string_view  BattleKeyName;
	static bool Debug_LevelChanged;

	BattleLevel();
	~BattleLevel() override;

	BattleLevel(const BattleLevel& _Other) = delete;
	BattleLevel(BattleLevel&& _Other) noexcept = delete;
	BattleLevel& operator=(const BattleLevel& _Other) = delete;
	BattleLevel& operator=(const BattleLevel&& _Other) noexcept = delete;

	//�� �������� ��Ʋ������ ��ȯ�ɶ� ȣ�����ֽø� �˴ϴ�.
	void Init(
		BattleFieldType _FieldType,
		BattleNpcType _NpcType = BattleNpcType::None);

	inline BattleFSM* GetBattleFSM()
	{
		return BattleFsmPtr;
	}

	void PassPlayerTurn();

	void UseMonsterBall(ItemCode _MonsterBallType);

	void ChangePlayerMonster(PokeNumber _NextMonster);

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel);
	void LevelChangeStart(GameEngineLevel* _PrevLevel);

private:
	static const char BattleKey;

	GameEngineRender* FadeDownRender = nullptr;
	GameEngineRender* FadeUpRender = nullptr;

	BattleFSM* BattleFsmPtr = nullptr;

	void InitGroundRenders(BattleFieldType _FieldType);
};


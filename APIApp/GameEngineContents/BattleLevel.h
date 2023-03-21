#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentsEnum.h"

class GameEngineRender;
class TestScript;
class Battle_Select;

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

protected:
	void Loading() override{}
	void Update(float _DeltaTime) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel);
	void LevelChangeStart(GameEngineLevel* _PrevLevel);

private:
	GameEngineRender* FadeDownRender = nullptr;
	GameEngineRender* FadeUpRender = nullptr;

	TestScript* ScriptPtr = nullptr;
	Battle_Select* BattleCursor = nullptr;
};


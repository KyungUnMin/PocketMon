#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentsEnum.h"

class GameEngineRender;
class TestScript;
class Battle_Select;
class BackTextActor;
class BattleFSM;
class BackTextActor;

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

	inline BackTextActor* GetTextInfoUI()
	{
		return TextInfoUI;
	}

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
	BackTextActor* TextInfoUI = nullptr;

	void InitGroundRenders(BattleFieldType _FieldType);
};


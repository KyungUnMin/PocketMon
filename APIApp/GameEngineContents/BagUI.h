#pragma once
#include <vector>
#include <GameEngineCore/GameEngineActor.h>
enum class BagSpace
{
	Items,
	KeyItems,
	PokeBalls
};

// ���� : ������ �����ϴ� Ŭ����
// �ʵ�, ������ �������� ����ϴ� ��ɵ��� �����Ѵ�
class GameEngineRender;
class TextActor;
class BagUI : public GameEngineActor
{
public:
	// constructer destructer
	BagUI();
	~BagUI();
	
	// delete Function
	BagUI(const BagUI& _Other) = delete;
	BagUI(BagUI&& _Other) = delete;
	BagUI& operator=(const BagUI& _Other) = delete;
	BagUI& operator=(BagUI&& _Other) = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _PrevLevel) override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
private:

	BagSpace CurrentSpace = BagSpace::Items;

	// _____________Renders
	GameEngineRender* BagRender = nullptr;		// ���� �̹���
	GameEngineRender* IconRender = nullptr;		// ������ ������

	GameEngineRender* LeftArrow = nullptr;		// ���� �̵� - ���� ȭ��ǥ
	GameEngineRender* RightArrow = nullptr;		// ���� �̵� - ������ ȭ��ǥ
	GameEngineRender* SpaceText = nullptr;		// ���� �̵� - �������� ���� �ؽ�Ʈ

	GameEngineRender* UpArrow = nullptr;		// ������ ��� - �� ȭ��ǥ
	GameEngineRender* DownArrow = nullptr;		// ������ ��� - �Ʒ� ȭ��ǥ
	GameEngineRender* CurrentCursor = nullptr;	// ������ ��� - �������� ������ ǥ��

	std::vector<TextActor*> Items = std::vector<TextActor*>(5);
	std::vector<TextActor*> KeyItems = std::vector<TextActor*>(5);
	std::vector<TextActor*> PokeBalls = std::vector<TextActor*>(5);
	TextActor* ItemInfo = nullptr;

	void ChangeSpace(BagSpace _Space);
	void ChangeSpaceLeft();
	void ChangeSpaceRight();

};

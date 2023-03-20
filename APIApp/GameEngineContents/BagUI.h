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
private:
	class Item
	{
		friend BagUI;
	public:
		Item(std::string_view _Name, std::string_view _Information, int _ItemCode, int _Num)
		:Name(_Name), Information(_Information), ItemCode(_ItemCode), Num(_Num){}

		std::string_view Name;
		std::string_view Information;
		int ItemCode;
		int Num;	// ����
	};
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
	GameEngineRender* CursorRender = nullptr;	// ������ ��� - �������� ������ ǥ��

	std::vector<Item> Items = std::vector<Item>();
	std::vector<Item> KeyItems = std::vector<Item>();
	std::vector<Item> PokeBalls = std::vector<Item>();

	std::vector<TextActor*> ItemName = std::vector<TextActor*>(5);
	TextActor* ItemInfo = nullptr;

	int CurrentCursor = 0;

	void ChangeSpace(BagSpace _Space);
	void ChangeSpaceLeft();
	void ChangeSpaceRight();

	void CursorUp();
	void CursorDown();
};

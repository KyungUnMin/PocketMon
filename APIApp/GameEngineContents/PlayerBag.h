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
// �ʵ�, ������ BagLevel�� �̵��� �� Ŭ������ �����۵��� �����մϴ�
// �����
// 1. ChangeLevel�� BagLevel�� �̵�
// 2. �������� ���õǸ� BagLevel�� �̵��ϱ��� Level�� �ٽ� �̵��˴ϴ�.
// 3. MainBag ���� ItemCode�� �޾ƿͼ� ���� �������� �ڵ带 �� �� �ֽ��ϴ�.
class GameEngineRender;
class TextActor;
class PlayerBag : public GameEngineActor
{
private:
	class Item
	{
		friend PlayerBag;
	public:
		Item(std::string_view _Name, std::string_view _Information, int _ItemCode)
		:Name(_Name), Information(_Information), ItemCode(_ItemCode){}

		std::string_view Name;
		std::string_view Information;
		int ItemCode;
		int Num = 1;	// ����
	};
public:
	// constructer destructer
	PlayerBag();
	~PlayerBag();

	static PlayerBag* MainBag;
	int GetItemCode()
	{
		return ItemCode;
	}
	void AddItem(int _ItemCode);
	void RemoveItem(int _ItemCode);

	// delete Function
	PlayerBag(const PlayerBag& _Other) = delete;
	PlayerBag(PlayerBag&& _Other) = delete;
	PlayerBag& operator=(const PlayerBag& _Other) = delete;
	PlayerBag& operator=(PlayerBag&& _Other) = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _PrevLevel) override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
private:
	GameEngineLevel* PrevLevel = nullptr;
	bool IsBattle = false;
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
	std::vector<TextActor*> ItemNum = std::vector<TextActor*>(5);
	std::vector<TextActor*> ItemNumSign = std::vector<TextActor*>(5);
	TextActor* ItemInfo = nullptr;

	size_t CurrentCursor = 0;
	int ItemCode = 0;

	void ChangeSpace(BagSpace _Space);
	void ChangeSpaceLeft();
	void ChangeSpaceRight();

	void CursorUp();
	void CursorDown();
	void CursorMove();
	void CursorMove(int _Cursor);

	void ItemSelect();
};

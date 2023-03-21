#pragma once
#include <vector>
#include <list>
#include <functional>
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
		Item(std::string_view _Name, std::string_view _Information, int _ItemCode, bool _IsBattleItem)
		:Name(_Name), Information(_Information), ItemCode(_ItemCode), IsBattleItem(_IsBattleItem){}

		std::string_view Name;
		std::string_view Information;
		int ItemCode;
		int Num = 1;	// ����
		bool IsBattleItem;	// ��Ʋ�� ��밡�ɿ���
	};
public:
	// constructer destructer
	PlayerBag();
	~PlayerBag();

	static PlayerBag* MainBag;
	// ����� �������� �ڵ带 �޴� �Լ�, ����� ��� 29
	int GetItemCode()
	{
		return ItemCode;
	}
	void AddItem(int _ItemCode);
	void RemoveItem(int _ItemCode);
	void BattleOn();

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
	BagSpace CurrentSpace = BagSpace::Items;
	const int CancelCode = 29;
	int ItemCode = 0;
	size_t CurrentCursor = 0;
	size_t CurrentSelectCursor = 0;
	int SelectSize = 0;
	bool IsBattle = false;
	bool IsItemSelect = false;
	

	// _____________Renders
	GameEngineRender* BagRender = nullptr;		// ���� �̹���
	GameEngineRender* TextBox = nullptr;		// �ؽ�Ʈ ����
	GameEngineRender* SelectBox = nullptr;		// ���� ����
	GameEngineRender* IconRender = nullptr;		// ������ ������

	GameEngineRender* LeftArrow = nullptr;		// ���� �̵� - ���� ȭ��ǥ
	GameEngineRender* RightArrow = nullptr;		// ���� �̵� - ������ ȭ��ǥ
	GameEngineRender* SpaceText = nullptr;		// ���� �̵� - �������� ���� �ؽ�Ʈ

	GameEngineRender* UpArrow = nullptr;		// ������ ��� - �� ȭ��ǥ
	GameEngineRender* DownArrow = nullptr;		// ������ ��� - �Ʒ� ȭ��ǥ
	GameEngineRender* CursorRender = nullptr;	// ������ ��� - �������� ������ ǥ��
	GameEngineRender* SelectCursorRender = nullptr;

	std::vector<Item> Items = std::vector<Item>();
	std::vector<Item> KeyItems = std::vector<Item>();
	std::vector<Item> PokeBalls = std::vector<Item>();

	std::vector<TextActor*> ItemName = std::vector<TextActor*>(5);
	std::vector<TextActor*> ItemNum = std::vector<TextActor*>(5);
	std::vector<TextActor*> ItemNumSign = std::vector<TextActor*>(5);
	TextActor* ItemSelectText = nullptr;
	TextActor* SelectText = nullptr;
	TextActor* ItemInfo = nullptr;

	std::vector<std::function<void()>> SelectFunctions = std::vector<std::function<void()>>(4);




	void ChangeSpace(BagSpace _Space);
	void ChangeSpaceLeft();
	void ChangeSpaceRight();

	void CursorUp();
	void CursorDown();
	void CursorMove();
	void CursorMove(int _Cursor);



	void SelectOn();
	void SelectOff();
	void SelectUp();
	void SelectDown();
	void SelectMove();
	void SelectMenu();

	void ItemUse();
	void ItemGive();
	void Cancel();
};

#pragma once
#include <vector>
#include <GameEngineCore/GameEngineActor.h>
enum class BagSpace
{
	Items,
	KeyItems,
	PokeBalls
};
// 설명 : 가방을 관리하는 클래스
// 필드, 전투중 BagLevel로 이동시 이 클래스가 아이템들을 관리합니다
// 사용방법
// 1. ChangeLevel로 BagLevel로 이동
// 2. 아이템이 선택되면 BagLevel로 이동하기전 Level로 다시 이동됩니다.
// 3. MainBag 에게 ItemCode를 받아와서 사용된 아이템의 코드를 알 수 있습니다.
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
		int Num = 1;	// 개수
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
	GameEngineRender* BagRender = nullptr;		// 가방 이미지
	GameEngineRender* IconRender = nullptr;		// 아이템 아이콘

	GameEngineRender* LeftArrow = nullptr;		// 가방 이동 - 왼쪽 화살표
	GameEngineRender* RightArrow = nullptr;		// 가방 이동 - 오른쪽 화살표
	GameEngineRender* SpaceText = nullptr;		// 가방 이동 - 선택중인 가방 텍스트

	GameEngineRender* UpArrow = nullptr;		// 아이템 목록 - 위 화살표
	GameEngineRender* DownArrow = nullptr;		// 아이템 목록 - 아래 화살표
	GameEngineRender* CursorRender = nullptr;	// 아이템 목록 - 선택중인 아이템 표시

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

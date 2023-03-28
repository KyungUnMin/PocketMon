#pragma once
#include <vector>
#include <list>
#include <functional>
#include <GameEngineBase/GameEngineTimeEvent.h>
#include <GameEngineCore/GameEngineActor.h>
#include "Item.h"
enum class BagSpace
{
	Items,
	KeyItems,
	PokeBalls,
};
enum class BagAnim
{
	Idle,
	LeftTurn,
	RightTurn,
	UpMove,
	DownMove
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
	
public:
	// constructer destructer
	PlayerBag();
	~PlayerBag();

	static PlayerBag* MainBag;
	// 사용한 아이템의 코드를 받는 함수, 취소한 경우 29
	ItemCode GetItemCode()
	{
		return CurrentItemCode;
	}
	// 가방에 아이템을 추가
	void AddItem(ItemCode _ItemCode);
	// 가방에 정해진 개수만큼 아이템을 추가
	void AddItem(ItemCode _ItemCode, int _Num);
	void RemoveItem(ItemCode _ItemCode);
	void BattleOn();
	bool GetIsBattle() {
		return IsBattle;
	}

	int GetMoney()
	{
		return Money;
	}
	void AddMoney(int _Money)
	{
		Money += _Money;
	}
	void MinusMoney(int _Money)
	{
		Money -= _Money;
	}
	void SetMoney(int _Money)
	{
		Money = _Money;
	}
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
	GameEngineTimeEvent TimeEvent;
	BagAnim AnimState = BagAnim::Idle;
	BagSpace CurrentSpace = BagSpace::Items;
	ItemCode CurrentItemCode = ItemCode::Cancel;
	size_t CurrentCursor = 0;
	size_t CurrentSelectCursor = 0;
	int SelectSize = 0;
	bool IsBattle = false;
	bool IsItemSelect = false;
	bool IsStop = false;
	int Money = 10000;
	// _____________Renders
	GameEngineRender* BagRender = nullptr;		// 가방 이미지
	GameEngineRender* TextBox = nullptr;		// 텍스트 상자
	GameEngineRender* SelectBox = nullptr;		// 선택 상자
	GameEngineRender* IconRender = nullptr;		// 아이템 아이콘

	GameEngineRender* LeftArrow = nullptr;		// 가방 이동 - 왼쪽 화살표
	GameEngineRender* RightArrow = nullptr;		// 가방 이동 - 오른쪽 화살표
	GameEngineRender* SpaceText = nullptr;		// 가방 이동 - 선택중인 가방 텍스트

	GameEngineRender* UpArrow = nullptr;		// 아이템 목록 - 위 화살표
	GameEngineRender* DownArrow = nullptr;		// 아이템 목록 - 아래 화살표
	GameEngineRender* CursorRender = nullptr;	// 아이템 목록 - 선택중인 아이템 표시
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


	void ChangeAnimation(BagAnim _AnimState);

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

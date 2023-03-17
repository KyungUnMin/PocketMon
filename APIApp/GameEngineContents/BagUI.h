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
// 필드, 전투중 아이템을 사용하는 기능들을 구현한다
class GameEngineRender;
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
	GameEngineRender* BagRender = nullptr;		// 가방 이미지
	GameEngineRender* IconRender = nullptr;		// 아이템 아이콘

	GameEngineRender* LeftArrow = nullptr;		// 가방 이동 - 왼쪽 화살표
	GameEngineRender* RightArrow = nullptr;		// 가방 이동 - 오른쪽 화살표
	GameEngineRender* SpaceText = nullptr;		// 가방 이동 - 선택중인 가방 텍스트

	GameEngineRender* UpArrow = nullptr;		// 아이템 목록 - 위 화살표
	GameEngineRender* DownArrow = nullptr;		// 아이템 목록 - 아래 화살표
	GameEngineRender* CurrentArrow = nullptr;	// 아이템 목록 - 선택중인 아이템 표시

	void ChangeSpace(BagSpace _Space);
	void ChangeSpaceLeft();
	void ChangeSpaceRight();
};

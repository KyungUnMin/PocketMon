#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>


#include "FieldmapCity.h"
#include "Fieldmap.h"

enum class PlayerState
{
	IDLE,
	MOVE,
	
};

enum class NPCtalkValue
{
	NONE,
	UP, //1
	DOWN, //2
	RIGHT, //3
	LEFT, //4
};
class Player : public GameEngineActor
{
public:
	static Player* MainPlayer;

	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);
	void Render(float _DeltaTime);
	void NPCtalkValueSet();
	void ChangeLevelCheck();

	void PlayerKeyLoad();
	void PlayerRenderLoad();
	void PlayerCollisionSet();

	float GetPlayerMoveTile()
	{
		return MoveTile;
	}

	void SetPlayerSpeed(float _PlayerTileSpeed)
	{
		MoveTile = _PlayerTileSpeed;
	}

	NPCtalkValue GetPlayerNPCtalkValue()
	{
		return TalkValue;
	}

	void SetPlayerMoveBool(bool _PlayerMoveValue)
	{
		PlayerMoveBool = _PlayerMoveValue;
	}
	bool GetPlayerMoveBool()
	{
		return PlayerMoveBool;
	}

	int2 GetPlayerIndex()
	{
		return Playerindex;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	//플레이어Render
	GameEngineRender* Players = nullptr;
	GameEngineRender* BikePlayers = nullptr;
	//플레이어Collision
	GameEngineCollision* RedCollision = nullptr;

	std::string DirString = "Right_";
	PlayerState StateValue = PlayerState::IDLE;

	//////////State//////////
	void DirCheck(const std::string_view& _AnimationName);
	
	void ChangeState(PlayerState _State);
	void UpdateState(float _Time);

	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

	


	//미완성 값들
	//////////Speed&Pos//////////
	float MoveTile = 100.0f;
	float4 MoveDir = float4::Zero;
	int2 Playerindex = int2::Zero;
	/////////////////////////////
	

	/////////Lerf값///////////
	float4 StartPos = float4::Zero;
	float4 EndPos = float4::Zero;


	//플레이어<->NPC 방향제어enum class
	NPCtalkValue TalkValue = NPCtalkValue::NONE;
	//플레이어 이동제어 Bool값
	bool PlayerMoveBool = true;

	float PlayerTime = 0.0f;
};


#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>

#include "FieldmapCity.h"
#include "Fieldmap.h"
#include "list"
#include "TrainerPokemon.h"
#include "vector"

enum class PlayerState
{
	IDLE,
	MOVE,
	JUMP,
};

enum class NPCtalkValue
{
	NONE,
	UP, //1
	DOWN, //2
	RIGHT, //3
	LEFT, //4
};

enum class LookDir;
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

	void NPCtalkValueSet();
	void ChangeLevelCheck();

	void PlayerKeyLoad();
	void PlayerRenderLoad();
	void PlayerCollisionSet();

	void PlayerAutoMove();
	void InsertPlayerPos(float4 _Pos)
	{
		NextMovePos.push_back(_Pos);
	}
	void InsertPlayerPos(int2 _index)
	{
		float4 M_index = Fieldmap::GetPos(_index);
		NextMovePos.push_back(M_index);
	}

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

	bool VaildJumpUp();
	bool VaildJumpDown();
	bool VaildJumpLeft();
	bool VaildJumpRight();

	void JumpRight();
	void JumpUp();
	void JumpLeft();
	void JumpDown();

	bool IsPlayerDirUp()
	{
		return IsPlayerDirUP;
	}
	bool IsPlayerDirDown()
	{
		return IsPlayerDirDOWN;
	}
	bool IsPlayerDirRight()
	{
		return IsPlayerDirRIGHT;
	}
	bool IsPlayerDirLeft()
	{
		return IsPlayerDirLEFT;
	}

	bool GetIsRideValue()
	{
		return IsRide;
	}
	void SetRideValue(bool _truefalse)
	{
		IsRide = _truefalse;
	}

	LookDir GetDir() const
	{
		return Dir;
	}
	TrainerPokemon* GetPlayerPokemon()
	{
		return PlayerPokemon;
	}

	void SetPlayerDirRight()
	{
		Dir = LookDir::Right;
		Players->ChangeAnimation("Right_Idle");
	}
	void SetPlayerDirLeft()
	{
		Dir = LookDir::Left;
		Players->ChangeAnimation("Left_Idle");
	}
	void SetPlayerDirDown()
	{
		Dir = LookDir::Down;
		Players->ChangeAnimation("Down_Idle");
	}
	void SetPlayerDirUp()
	{
		Dir = LookDir::Up;
		Players->ChangeAnimation("Up_Idle");
	}

	/////////PlayerDeathCheck

	void SetPlayerDeath()
	{
		IsPlayerDeath = true;
		PlayerDeathCheckFunction();
	}


	
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;
private:
	//�÷��̾ ���ϰ��ִ� ���ϸ�
	TrainerPokemon* PlayerPokemon=nullptr;
	//�÷��̾�Render
	GameEngineRender* Players = nullptr;
	GameEngineRender* BikePlayers = nullptr;
	GameEngineRender* Shadow = nullptr;
	//�÷��̾�Collision
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
	
	void JumpStart();
	void JumpUpdate(float _Time);
	void JumpEnd();
	
	//////////Speed&Pos//////////
	float MoveTile = 100.0f;
	float4 MoveDir = float4::Zero;
	int2 Playerindex = int2::Zero;
	float PlayerMoveSpeed = 5.0f;
	/////////////////////////////
	

	/////////Lerf��///////////
	float4 StartPos = float4::Zero;
	float4 EndPos = float4::Zero;

	float4 JumpStartPos = float4::Zero;
	float4 JumpEndPos = float4::Zero;

	float JumpHeight = 150.0f;

	//�÷��̾�<->NPC ��������enum class
	NPCtalkValue TalkValue = NPCtalkValue::NONE;

	//�÷��̾� �̵����� Bool��
	int InputControlHandle = 0;
	bool PlayerMoveBool = true;

	bool Istrue = true;
	bool IsPlayerDirUP = true;
	bool IsPlayerDirDOWN = true;
	bool IsPlayerDirLEFT = true;
	bool IsPlayerDirRIGHT = true;

	
	//�̵��ð�
	float PlayerJumpTime = 0.0f;
	float PlayerTime = 0.0f;
	//Bike���
	bool IsRide = false;
	//Gold
	int Gold = 0;

	////////���� �� index
	LookDir Dir;
	int2 NextJumpIndex = int2::Zero;
	//AutoMove Pos���� �����ϴ� list
	std::list<float4> NextMovePos = std::list<float4>();
	


	//////////DeathCheckbool
	void PlayerDeathCheckFunction();
	bool IsPlayerDeath = false;
};


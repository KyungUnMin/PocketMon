#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
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

	float GetPlayerSpeed()
	{
		return MoveSpeed;
	}

	void SetPlayerSpeed(float _PlayerSpeed)
	{
		MoveSpeed = _PlayerSpeed;
	}

	NPCtalkValue GetPlayerNPCtalkValue()
	{
		return TalkValue;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	GameEngineRender* Players = nullptr;
	GameEngineRender* BikePlayers = nullptr;


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

	
	//////////Speed&Pos//////////
	float MoveSpeed = 200.0f;
	float4 MoveDir = float4::Zero;
	

	NPCtalkValue TalkValue = NPCtalkValue::NONE;


};


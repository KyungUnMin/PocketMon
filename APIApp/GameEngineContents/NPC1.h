#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineContents/int2.h>

#include <functional>


class NPC1 : public GameEngineActor
{
public:
	NPC1();
	~NPC1();

	// delete Function
	NPC1(const NPC1& _Other) = delete;
	NPC1(NPC1&& _Other) noexcept = delete;
	NPC1& operator=(const NPC1& _Other) = delete;
	NPC1& operator=(NPC1&& _Other) noexcept = delete;


	void ImageLoad();
	void Render(float _DeltaTime);

	void MovePattern1();
	void MovePattern2();
	void MovePattern3();
	void MovePattern4();

	int2 GetNPCindex()
	{
		return NPC1index;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	GameEngineRender* R_NPC1 = nullptr;
	GameEngineCollision* C_NPC_U = nullptr;
	GameEngineCollision* C_NPC_D = nullptr;
	GameEngineCollision* C_NPC_R = nullptr;
	GameEngineCollision* C_NPC_L = nullptr;

	bool NPC1ImageLoad = true;

	int2 NPC1index = int2::Zero;


	std::list<std::string> Script = std::list<std::string>();
	

	bool NPC1MoveValue;

	float DefaultMoveTime = 0.0f;
	float4 MoveStartPos = float4::Zero;
	float4 MoveEndPos = float4::Zero;
};


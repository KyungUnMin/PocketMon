#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineContents/int2.h>

#include <functional>

#include "BaseNPC.h"



class ShopNpc : public BaseNPC
{
public:
	ShopNpc();
	~ShopNpc();

	// delete Function
	ShopNpc(const ShopNpc& _Other) = delete;
	ShopNpc(ShopNpc&& _Other) noexcept = delete;
	ShopNpc& operator=(const ShopNpc& _Other) = delete;
	ShopNpc& operator=(ShopNpc&& _Other) noexcept = delete;


	void ImageLoad();
	void Render(float _DeltaTime);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	void IdleStart() {}
	void IdleUpdate(float _DeltaTime) {}
	void IdleEnd() {}

	void MoveStart() {}
	void MoveUpdate(float _DeltaTime) {}
	void MoveEnd() {}

	/*void InteractionStart();
	void InteractionUpdate(float _DeltaTime);
	void InteractionEnd();*/

private:
	GameEngineRender* R_NPC1 = nullptr;
	GameEngineCollision* C_NPC_R = nullptr;
	bool NPC1ImageLoad = true;

	float4 StartPos = float4::Zero;
	float4 EndPos = float4::Zero;

	float MoveTime = 0.0f;
};


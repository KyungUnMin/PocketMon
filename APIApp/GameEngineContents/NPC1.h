#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineContents/int2.h>


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

	int2 GetNPCindex()
	{
		return NPC1index;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	GameEngineRender* R_NPC1 = nullptr;

	bool NPC1ImageLoad = true;

	int2 NPC1index = int2::Zero;
	
};


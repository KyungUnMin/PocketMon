#pragma once
#include <GameEngineCore/GameEngineCore.h>

class PocketMonCore : public GameEngineCore
{
public:
	static PocketMonCore& GetInst()
	{
		return Core;
	}

	PocketMonCore(const PocketMonCore& _Other) = delete;
	PocketMonCore(PocketMonCore&& _Other) noexcept = delete;
	PocketMonCore& operator=(const PocketMonCore& _Other) = delete;
	PocketMonCore& operator=(const PocketMonCore&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
	static PocketMonCore Core;

	PocketMonCore();
	~PocketMonCore();
};


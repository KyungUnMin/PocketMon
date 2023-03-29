#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Opening_largeST : public GameEngineActor
{
public:
	// constrcuter destructer
	Opening_largeST();
	~Opening_largeST();

	// delete Function
	Opening_largeST(const Opening_largeST& _Other) = delete;
	Opening_largeST(Opening_largeST&& _Other) noexcept = delete;
	Opening_largeST& operator=(const Opening_largeST& _Other) = delete;
	Opening_largeST& operator=(Opening_largeST&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

};


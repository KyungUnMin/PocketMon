#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Opening_smallST : public GameEngineActor
{
public:
	// constrcuter destructer
	Opening_smallST();
	~Opening_smallST();

	// delete Function
	Opening_smallST(const Opening_smallST& _Other) = delete;
	Opening_smallST(Opening_smallST&& _Other) noexcept = delete;
	Opening_smallST& operator=(const Opening_smallST& _Other) = delete;
	Opening_smallST& operator=(Opening_smallST&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:

};


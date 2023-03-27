#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Opening_Freaklogo : public GameEngineActor
{
public:
	// constrcuter destructer
	Opening_Freaklogo();
	~Opening_Freaklogo();

	// delete Function
	Opening_Freaklogo(const Opening_Freaklogo& _Other) = delete;
	Opening_Freaklogo(Opening_Freaklogo&& _Other) noexcept = delete;
	Opening_Freaklogo& operator=(const Opening_Freaklogo& _Other) = delete;
	Opening_Freaklogo& operator=(Opening_Freaklogo&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:

};


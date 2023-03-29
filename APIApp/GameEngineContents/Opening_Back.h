#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Opening_Back : public GameEngineActor
{
public:
	// constrcuter destructer
	Opening_Back();
	~Opening_Back();

	// delete Function
	Opening_Back(const Opening_Back& _Other) = delete;
	Opening_Back(Opening_Back&& _Other) noexcept = delete;
	Opening_Back& operator=(const Opening_Back& _Other) = delete;
	Opening_Back& operator=(Opening_Back&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

};


#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν : 
class BagUI : public GameEngineActor
{
public:
	// constructer destructer
	BagUI();
	~BagUI();
	
	// delete Function
	BagUI(const BagUI& _Other) = delete;
	BagUI(BagUI&& _Other) = delete;
	BagUI& operator=(const BagUI& _Other) = delete;
	BagUI& operator=(BagUI&& _Other) = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:

};

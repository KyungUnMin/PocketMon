#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineResources.h>

#include <functional>
#include <vector>

// Ό³Έν :
class Battle_Select : public GameEngineActor
{
public:
	// constrcuter destructer
	Battle_Select();
	~Battle_Select();

	// delete Function
	Battle_Select(const Battle_Select& _Other) = delete;
	Battle_Select(Battle_Select&& _Other) noexcept = delete;
	Battle_Select& operator=(const Battle_Select& _Other) = delete;
	Battle_Select& operator=(Battle_Select&& _Other) noexcept = delete;

	void init(GameEngineActor* Script);

	inline void ResizeCallBacks(size_t _Size)
	{
		Callbacks.resize(_Size, nullptr);
	}

	inline void SetCallBack(size_t _Index, std::function<void()> _Func)
	{
		Callbacks[_Index] = _Func;
	}


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
//	void CollisionCheck(float _DeltaTime);
	void ArrowNumberCheck();
	void ArrowInput(int _Number);
	void SelectSOUND();

private:
	std::vector<std::function<void()>> Callbacks;

	GameEngineRender* ArrowRender = nullptr;

	int ArrowCheckNum = 0;

	GameEngineActor* ScriptPtr = nullptr;


	GameEngineSoundPlayer B_SelectSOUND;

};


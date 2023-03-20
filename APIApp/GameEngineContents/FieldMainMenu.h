#pragma once
#include <GameEngineCore/GameEngineActor.h>
class GameEngineRender;
class FieldMainMenu : public GameEngineActor
{
public:
	// construtor destructor
	FieldMainMenu();
	~FieldMainMenu();

	// delete Function
	FieldMainMenu(const FieldMainMenu& _Other) = delete;
	FieldMainMenu(FieldMainMenu&& _Other) noexcept = delete;
	FieldMainMenu& operator=(const FieldMainMenu& _Other) = delete;
	FieldMainMenu& operator=(FieldMainMenu&& _Other) noexcept = delete;

protected:
	void Start() override;

private:
	std::list<GameEngineRender*> FieldMainMenuRender = std::list<GameEngineRender*>();

};


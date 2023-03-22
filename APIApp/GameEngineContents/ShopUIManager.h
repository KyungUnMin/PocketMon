#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <list>

class FieldmapLevel;
class ShopMainMenu;
class FieldDialog;
class ShopUIManager : public GameEngineActor
{
public:
	// construtor destructor
	ShopUIManager();
	~ShopUIManager();

	// delete Function
	ShopUIManager(const ShopUIManager& _Other) = delete;
	ShopUIManager(ShopUIManager&& _Other) noexcept = delete;
	ShopUIManager& operator=(const ShopUIManager& _Other) = delete;
	ShopUIManager& operator=(ShopUIManager&& _Other) noexcept = delete;

	void On() override;
	void Off() override;
	void OnOffSwtich() override;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	FieldmapLevel* ParentLevel = nullptr;
	FieldDialog* AcFielDialog = nullptr;
	ShopMainMenu* AcShopMainMenu = nullptr;

	std::list<std::string> WelcomeScript = std::list<std::string>();

	void UpdateStart();

};


#pragma once
#include "StaticNPC.h"

enum class ItemCode;
class ItemNPC : public StaticNPC
{
public:
	ItemNPC();
	~ItemNPC();

	ItemNPC(const ItemNPC& _Other) = delete;
	ItemNPC(ItemNPC&& _Other) noexcept = delete;
	ItemNPC& operator=(const ItemNPC& _Other) = delete;
	ItemNPC& operator=(ItemNPC&& _Other) noexcept = delete;

	void InitNPC(const std::string_view& _Name, const std::string_view& _ImageName, BattleNpcType _Type) override;
	void InitItemData(ItemCode _Code, int _Count, std::string _ItemName = "Item");

protected:
	void IdleUpdate(float _DeltaTime) override;
	void InteractionStart() override;
	void InteractionEnd() override;

private:
	ItemCode Code;
	int Count = 1;
	std::string ItemName = "";
};


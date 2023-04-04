#include "ItemNPC.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "ItemDataBase.h"
#include "Fieldmap.h"
#include "PlayerBag.h"

ItemNPC::ItemNPC() :
	Code(ItemCode::MonsterBall),
	Count(1)
{
}

ItemNPC::~ItemNPC()
{
}

void ItemNPC::InitNPC(const std::string_view& _Name, const std::string_view& _ImageName, BattleNpcType _Type)
{
	BaseNPC::InitNPC(_Name, _ImageName, _Type);
	NPCRender->SetScale(NPCRender->GetScale() * 0.7f);
}

void ItemNPC::InitItemData(ItemCode _Code, int _Count, std::string _ItemName)
{
	Code = _Code;
	Count = _Count;
	ItemName = _ItemName;
}

void ItemNPC::IdleUpdate(float _DeltaTime)
{
	if (false == NPCRender->IsUpdate())
	{
		return;
	}

	StaticNPC::IdleUpdate(_DeltaTime);
}

void ItemNPC::InteractionStart()
{
	std::string Commnet = "Congratulations! You obtained an ";
	Commnet += ItemName;
	Commnet += ".";

	ScriptDatas[0].push_back(Commnet);
	ScriptDatas[0].push_back("Your adventure just got even more exciting.\nGet stronger and enjoy even more epic adventures!");

	StaticNPC::InteractionStart();
}

void ItemNPC::InteractionEnd()
{
	PlayerBag::MainBag->AddItem(Code, 1);
	StaticNPC::InteractionEnd();
	Fieldmap::SetWalkable(CityName, Fieldmap::GetIndex(GetPos()), true);
	NPCRender->Off();
}

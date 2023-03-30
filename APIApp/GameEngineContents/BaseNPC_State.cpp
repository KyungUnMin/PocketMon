#include "BaseNPC.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include "Fieldmap.h"
#include "InputControll.h"
#include "FieldDialog.h"
#include "Player.h"
#include "BattleLevel.h"
#include "BattleFadeCtrl.h"

// Idle
void BaseNPC::IdleStart()
{
	PlayAnimation();
}

void BaseNPC::IdleUpdate(float _DeltaTime)
{
	if (false == IsBattleEnd && true == CheckInteractionTrigger())
	{
		Look(GetDir(Fieldmap::GetIndex(GetPos()), Fieldmap::GetIndex(Player::MainPlayer->GetPos())));
		ChangeState(NPCState::interaction);
		return;
	}

	if (0 < MovePoints.size())
	{

		MoveStartPos = GetPos();
		MoveStartIndex = Fieldmap::GetIndex(MoveStartPos);

		MoveEndPos = MovePoints.front();
		MoveEndIndex = Fieldmap::GetIndex(MoveEndPos);

		if (false == Fieldmap::Walkable(MoveEndIndex))
		{
			return;
		}

		MovePoints.pop_front();
		Look(MoveStartIndex, MoveEndIndex);

		ChangeState(NPCState::Move);
		return;
	}
}

void BaseNPC::IdleEnd()
{

}

// Move
void BaseNPC::MoveStart()
{
	PlayAnimation();
	MoveProgress = 0.0f;

	Fieldmap::SetWalkable(CityName, MoveEndIndex, false);
}

void BaseNPC::MoveUpdate(float _DeltaTime)
{
	MoveProgress += _DeltaTime * MoveSpeed;
	SetPos(float4::LerpClamp(MoveStartPos, MoveEndPos, MoveProgress));

	if (1.0f <= MoveProgress)
	{
		ChangeState(NPCState::Idle);
		return;
	}
}

void BaseNPC::MoveEnd()
{
	MoveProgress = 0.0f;
	Fieldmap::SetWalkable(CityName, MoveStartIndex, true);
}

// Interaction
void BaseNPC::InteractionStart()
{
	PlayAnimation();

	InputHandle = InputControll::UseControll();
	InputControll::UsedKey();

	if (TriggerType == InteractionTriggerType::Look)
	{
		Player* MainPlayerPtr = Player::MainPlayer;

		MoveStartPos = GetPos();
		MoveStartIndex = Fieldmap::GetIndex(MoveStartPos);

		MoveEndIndex = Fieldmap::GetIndex(MainPlayerPtr->GetPos());
		MoveEndPos = Fieldmap::GetPos(MoveEndIndex);

		float4 MoveDir = (MoveStartPos - MoveEndPos);

		MoveEndPos += MoveDir.NormalizeReturn() * Fieldmap::TileSize;

		AnimationName = "Move";
		PlayAnimation();

		MoveDistance = MoveDir.Size() / Fieldmap::TileSize;
		MoveProgress = 0.0f;

		Fieldmap::SetWalkable(CityName, MoveStartIndex, true);
		Fieldmap::SetWalkable(CityName, Fieldmap::GetIndex(MoveEndPos), false);

	}
	else if (ScriptDatas.size() != 0)
	{
		FieldDialog::GetFieldDialog()->ConversationStart(&ScriptDatas);
	}
}

void BaseNPC::InteractionUpdate(float _DeltaTime)
{
	if (TriggerType == InteractionTriggerType::Look)
	{
		if (false == FieldDialog::GetFieldDialog()->IsUpdate())
		{
			if (true == IsBattleEnd)
			{
				ChangeState(NPCState::Idle);
				return;
			}

			MoveProgress += _DeltaTime * MoveSpeed / MoveDistance;
			SetPos(float4::LerpClamp(MoveStartPos, MoveEndPos, MoveProgress));

			if (1.0f <= MoveProgress)
			{
				AnimationName = "Idle";
				PlayAnimation();

				IsBattleEnd = true;
				FieldDialog::GetFieldDialog()->ConversationStart(&ScriptDatas);
			}
		}
	}
	else
	{
		if (ScriptDatas.size() == 0)
		{
			ChangeState(NPCState::Idle);
		}

		if (false == FieldDialog::GetFieldDialog()->IsUpdate())
		{
			ChangeState(NPCState::Idle);
		}
	}
}

void BaseNPC::InteractionEnd()
{
	for (const std::function<void()>& Func : InteractionFuncs)
	{
		if (nullptr == Func)
		{
			MsgAssert("nullptr func NPC �̺�Ʈ�� ȣ���Ϸ� �߽��ϴ�");
			return;
		}

		Func();
	}

	InteractionFuncs.clear();

	for (const std::function<void()>& Func : LoopInteractionFuncs)
	{
		if (nullptr == Func)
		{
			MsgAssert("nullptr func NPC �̺�Ʈ�� ȣ���Ϸ� �߽��ϴ�");
			return;
		}

		Func();
	}

	if (PokemonDatas.GetPokemonCount() != 0)
	{
		IsBattleEnd = true;

		GroundType GroundType = Fieldmap::GetGroundType(Player::MainPlayer->GetPos());
		BattleLevel::BattleLevelPtr->Init(PokemonDatas.GetPokemons(), GroundType::Grass, Type);

		BattleFadeCtrl* Fade = GetLevel()->CreateActor<BattleFadeCtrl>();
		Fade->Init(BattleFadeCtrl::FadeType::BlackOut, std::bind(

			[](BaseNPC* _this)
			{
				_this->InputHandle = InputControll::ResetControll(_this->InputHandle);
				GameEngineCore::GetInst()->ChangeLevel("BattleLevel");
			},
			this));
		Fade->On();
	}
	else if (InputHandle >= 0)
	{
		InputHandle = InputControll::ResetControll(InputHandle);
	}
}

void BaseNPC::AddPokeData(int _Index, int _Level)
{
	if (6 == PokemonDatas.GetPokemonCount())
	{
		MsgAssert("Npc�� 6���� �ʰ��� ���ϸ��� ������ �� �����ϴ�.");
		return;
	}

	PokemonDatas.AddPokemon(_Index, _Level);
}

void BaseNPC::AddPokeData(PokeDataBase _Data)
{
	if (6 == PokemonDatas.GetPokemonCount())
	{
		MsgAssert("Npc�� 6���� �ʰ��� ���ϸ��� ������ �� �����ϴ�.");
		return;
	}

	PokemonDatas.AddPokemon(_Data);
}

void BaseNPC::AddInteractionFunc(std::function<void()> _Func, bool _IsLoop )
{
	if (nullptr == _Func)
	{
		MsgAssert("nullptr func�� NPC ��ȣ�ۿ� �̺�Ʈ�� ����Ϸ� �߽��ϴ�");
		return;
	}

	if (true == _IsLoop)
	{
		LoopInteractionFuncs.push_back(_Func);
	}
	else
	{
		InteractionFuncs.push_back(_Func);
	}	
}
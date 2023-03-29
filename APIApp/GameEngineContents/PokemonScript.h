#pragma once
#include <map>
#include <GameEngineBase/GameEngineDebug.h>

class PokemonScript
{
public:
	static void AddScript(int _EventNumber)
	{
		if (ScriptCheckList.find(_EventNumber) != ScriptCheckList.end())
		{
			MsgAssert("���� �ѹ��� ��ũ��Ʈ�� ����Ϸ� �߽��ϴ�.");
			return;
		}

		ScriptCheckList[_EventNumber] = false;
	}

	static void EndScript(int _EventNumber)
	{
		if (ScriptCheckList.find(_EventNumber) == ScriptCheckList.end())
		{
			MsgAssert("�ش� ��ũ��Ʈ�� �������� �ʽ��ϴ�.");
			return;
		}

		ScriptCheckList[_EventNumber] = true;
	}	
	
	static bool IsScriptEnd(int _EventNumber)
	{
		if (ScriptCheckList.find(_EventNumber) == ScriptCheckList.end())
		{
			MsgAssert("�ش� ��ũ��Ʈ�� �������� �ʽ��ϴ�.");
			return false;
		}

		return ScriptCheckList[_EventNumber];
	}

private:
	static std::map<int, bool> ScriptCheckList;

private:
	PokemonScript();
	~PokemonScript();

	PokemonScript(const PokemonScript& _Other) = delete;
	PokemonScript(PokemonScript&& _Other) noexcept = delete;
	PokemonScript& operator=(const PokemonScript& _Other) = delete;
	PokemonScript& operator=(PokemonScript&& _Other) noexcept = delete;
};
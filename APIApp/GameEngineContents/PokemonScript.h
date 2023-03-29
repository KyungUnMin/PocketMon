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
			MsgAssert("같은 넘버의 스크립트를 등록하려 했습니다.");
			return;
		}

		ScriptCheckList[_EventNumber] = false;
	}

	static void EndScript(int _EventNumber)
	{
		if (ScriptCheckList.find(_EventNumber) == ScriptCheckList.end())
		{
			MsgAssert("해당 스크립트가 존재하지 않습니다.");
			return;
		}

		ScriptCheckList[_EventNumber] = true;
	}	
	
	static bool IsScriptEnd(int _EventNumber)
	{
		if (ScriptCheckList.find(_EventNumber) == ScriptCheckList.end())
		{
			MsgAssert("해당 스크립트가 존재하지 않습니다.");
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
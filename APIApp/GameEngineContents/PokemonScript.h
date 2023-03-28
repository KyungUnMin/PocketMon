#pragma once
#include <map>

class PokemonScript
{
public:
	enum class Script
	{
		TEST
	};
public:
	static void AddScript(int _EventNumber)
	{
	
	}

	static void EndScript(int _EventNumber)
	{
	
	}	
	
	static bool IsScriptEnd(int _EventNumber)
	{
		return false;
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
#pragma once
#include <Windows.h>
#include <assert.h>
#include <string>

// ���� :
class GameEngineDebug
{
public:

	// delete Function
	GameEngineDebug(const GameEngineDebug& _Other) = delete;
	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
	GameEngineDebug& operator=(GameEngineDebug&& _Other) noexcept = delete;

	static void LeakCheck();
	static void LeakPointBreak(int _Point);

protected:

private:
	// constrcuter destructer
	GameEngineDebug();
	~GameEngineDebug();

};


#define MsgAssert(MsgText) std::string ErrorText = MsgText; MessageBoxA(nullptr, ErrorText.c_str(), "Error", MB_OK); assert(false);
#define DebugMsgBox(MsgText) std::string MsgboxText = MsgText; MessageBoxA(nullptr, MsgboxText.c_str(), "Debug", MB_OK);
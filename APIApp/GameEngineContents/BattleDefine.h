#pragma once
#include <string_view>

class BattleDefine
{
public:
	BattleDefine(const BattleDefine& _Other) = delete;
	BattleDefine(BattleDefine&& _Other) noexcept = delete;
	BattleDefine& operator=(const BattleDefine& _Other) = delete;
	BattleDefine& operator=(const BattleDefine&& _Other) noexcept = delete;

	static const float WorldVolumn;

	static const std::string_view SfxName_Tackle;
	static const std::string_view SfxName_BallPop;

protected:

private:
	BattleDefine();
	~BattleDefine();
};


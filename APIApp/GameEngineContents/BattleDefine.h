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
	static const std::string_view SfxName_WildCatchCorrect;
	static const std::string_view SfxName_Runaway;
	static const std::string_view SfxName_MonsterKill;



	static const std::string_view SfxName_BallMoveVertical;
	static const std::string_view SfxName_BallMoveHorizon;
	static const std::string_view SfxName_BallInput;
	static const std::string_view SfxName_BallSwing;





	static const std::string_view BgmName_VictoryNormal;
	static const std::string_view BgmName_VictoryGym;





protected:

private:
	BattleDefine();
	~BattleDefine();
};


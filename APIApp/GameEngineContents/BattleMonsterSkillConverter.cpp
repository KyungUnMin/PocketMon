#include "BattleMonsterBase.h"

const std::vector<std::string_view> BattleMonsterBase::SkiilEnumToString =
{
	"Scratch",					    // 0 할퀴기
	"Growl",						    // 1 울음소리
	"Ember",						    // 2 불꽃세례
	"Leer",							  // 3 째려보기
	"Slash",							  // 4 베어가르기
	"Flamethrower",				// 5 화염방사
	"Tackle",								// 6 몸통박치기
	"TailWhip",							  // 7 꼬리흔들기
	"Bubble",								 // 8 거품
	"WaterGun",						    // 9 물대포
	"Withdraw",						    // 10 껍질에숨기
	"SkullBash",							  // 11 로케트박치기
	"HydroPump",							   // 12 하이드로펌프
	"LeechSeed",								 // 13 씨뿌리기
	"VineWhip",								// 14 덩굴채찍
	"RazorLeaf",								// 15 잎날가르기
	"SleepPowder",					  // 16 수면가루
	"SolarBeam",						 // 17 솔라빔
	"SandAttack",						  // 18 모래뿌리기
	"Gust",								// 19 바람일으키기
	"QuickAttack",							// 20 전광석화
	"Twister",								// 21 회오리
	"FeatherDance",					// 22 깃털댄스
	"WingAttack",						// 23 날개치기
	"AirSlash",						 // 24 에어슬래시
	"Peck",							// 25 쪼기
	"FuryAttack",					  // 26 마구찌르기
	"Pursuit",						// 27 따라가때리기
	"FastMove",				   // 28 고속이동
	"Assurance",				   // 29 승부굳히기
	"DrillPeck",					 // 30 회전부리
	"DefenseCurl",					 // 31 웅크리기
	"RockPolish",						// 32 록커트
	"RockThrow",						  // 33 돌떨구기
	"Magnitude",						// 34 매그니튜드
	"Selfdestruct",					// 35 자폭
	"Earthquake",						 // 36 지진
	"StoneEdge",						// 37 스톤에지
	"Bind",							// 38 조이기
	"RockTomb",					// 39 암석봉인
	"DragonBreath",				// 40 용의숨결
	"IronTail",					// 41 아이언테일
	"SandTomb",				    // 42 모래지옥
	"Bite",								// 43 물기
	"HyperFang",			    // 44 필살앞니
	"Crunch",					 // 45 깨물어부수기
	"SuperFang",				 // 46 분노의앞니
	"DoubleEdge"			  // 47 이판사판태클
	//"Unknown"							// 48 Max
};

const std::vector<std::string_view> BattleMonsterBase::NameEnumToString =
{
	"Bulbasaur",				  // 0 이상해씨
	"Ivysaur",					// 1 이상해풀
	"Venusaur",				  // 2 이상해꽃
	"Charmander",			// 3 파이리
	"Charmeleon",			// 4 리자드
	"Charizard",				// 5 리자몽
	"Squirtle",					// 6 꼬부기
	"Wartortle",				// 7 어니부기
	"Blastoise",				 // 8 거북왕
	"Pidgey",					// 9 구구
	"Rattata",				 // 10 꼬렛
	"Spearow",				  // 11 깨비참
	"Geodude",				   // 12 꼬마돌
	"Onix"					   // 13 롱스톤
	//"Max"					   // 14 max
};

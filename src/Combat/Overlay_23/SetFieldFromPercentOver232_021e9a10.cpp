#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

int LoadBattleBlock020ac4c0(void* dst);

int GetFieldPercentOver232_020a08a4(BattleRecordSnapshot* p);

extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e9a10
ARM int SetFieldFromPercentOver232_021e9a10(void* obj) {
	BattleRecordSnapshot record;
	LoadBattleBlock020ac4c0(&record);
	int pct = GetFieldPercentOver232_020a08a4(&record);
	func_ov017_021d6134(obj, pct);
	return 1;
}

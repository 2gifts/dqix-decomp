#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

int LoadBattleBlock020ac4c0(void* dst);

int GetFieldPercentOver448(BattleRecordSnapshot* p);

extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e99dc
ARM int SetFieldFromPercentOver448_021e99dc(void* obj) {
	BattleRecordSnapshot record;
	LoadBattleBlock020ac4c0(&record);
	int pct = GetFieldPercentOver448(&record);
	func_ov017_021d6134(obj, pct);
	return 1;
}

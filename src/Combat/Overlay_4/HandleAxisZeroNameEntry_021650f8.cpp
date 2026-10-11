#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"

struct AxisFloats0203b5f8;
int IsAxisIntZero(struct AxisFloats0203b5f8* s, int axis);
int GetGlobalField0x1c020421a0(void);
struct Info02011930;
unsigned char GetAndConsumeNameEntries02011930(void* obj, struct Info02011930* info, void* name1, void* name2);
extern "C" void func_ov011_021848a0(void* obj, int val);
unsigned char CopyToRegion0x6482IfDst(char* obj, void* dst);
void StoreInvalidTreasureMapMetadata(char* obj);
extern "C" void func_ov017_0218d77c(int obj, int a);

// USA: func_ov004_021650f8
ARM int HandleAxisZeroNameEntry_021650f8(void* a1) {
#if defined(jpn)
 enum { fieldOffset = 0x868 };
#else
 enum { fieldOffset = 0x998 };
#endif
    GameState* battle = GameState::GetInstance();
    struct AxisFloats0203b5f8* axis = ((struct AxisFloats0203b5f8*)func_ov017_0218b5b0());
    if (IsAxisIntZero(axis, 0) == 0) goto ret0;
    if (IsAxisIntZero(axis, 1) != 0) goto mainlogic;
ret0:
    return 0;

mainlogic:
    if (*(void**)((char*)GetGlobalField0x1c020421a0() + fieldOffset) != NULL) return 0;

    if (GetAndConsumeNameEntries02011930(battle, NULL, NULL, NULL) != 0) {
        func_ov011_021848a0(a1, 0x6b);
        goto end;
    }

    if (CopyToRegion0x6482IfDst((char*)battle, NULL) != 0) {
        StoreInvalidTreasureMapMetadata((char*)GameState::GetInstance());
        func_ov017_0218d77c((int)((struct AxisFloats0203b5f8*)func_ov017_0218b5b0()), 2);
        func_ov011_021848a0(a1, 0x64);
        goto end;
    }

    func_ov011_021848a0(a1, 0x64);

end:
    return 0;
}

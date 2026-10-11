#include <globaldefs.h>
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "GameState/GameState.h"

struct S02046b1c;
int GetField0x3acValue(GameState* battleStruct);
int GetField0x0List02046b1c(struct S02046b1c* p);
extern "C" void _Z18InitStruct02070378Pc(void* obj);
struct FieldFlagBlock;
void ResetAndEnableFieldFlag(struct FieldFlagBlock* block);

struct Evt021cf5d4 {
    unsigned char pad0[4];
    unsigned short field4;
    signed char field6;
    unsigned char field7;
};

struct S3f8_cf5d4 {
    short field0;
    char field2;
    char pad[0x70 - 3];
};

// JPN: func_ov017_021cfa84
// USA: func_ov017_021cf5d4
extern "C" ARM void func_ov017_021cf5d4(void* unused0, struct Evt021cf5d4* evt, GameState* battle, unsigned char* table) {
#if defined(jpn)
 enum {regionalOffset0=0x4ec};
#else
 enum {regionalOffset0=0x6fc};
#endif
    int v = GetField0x3acValue(battle);
    if (evt->field6 != v) {
        return;
    }
    struct S02046b1c* list = *(struct S02046b1c**)(table + 0x3000 + regionalOffset0);
    if (GetField0x0List02046b1c(list) != 0) {
        return;
    }
    struct S3f8_cf5d4 buf;
    _Z18InitStruct02070378Pc(&buf);
    buf.field0 = evt->field4;
    buf.field2 = 1;
    if (evt->field7 != 0) {
        ResetAndEnableFieldFlag((struct FieldFlagBlock*)battle);
    }
    _Z28CallFunc0200fbb4AtField0x3f8Pv(battle, &buf);
}

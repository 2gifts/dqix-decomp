#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

void SetField5cb0AndRecordByte0_02010774(char* obj, int v);
void SetField5cb4AndRecordByte1_020107a8(char* obj, int v);
void SetSlotByte020107dc(char* base, int val);
void SetField5cbcValue_02010810(char* obj, int value);
struct Struct020a99d0;
void CopyStruct020a99d0(struct Struct020a99d0* dst, struct Struct020a99d0* src);

struct Ctx020a9a50 {
    int f0;
    int f4;
    int f8;
    int fc;
    char pad10[0x342 - 0x10];
    unsigned char f342;
};

// USA: func_020a9a50  (semantic: ApplyContextToTarget_020a9a50)
extern "C" ARM int func_020a9a50(Ctx020a9a50* ctx, char* dst, int flag) {
    char* battle = (char*)GameState::GetInstance();
    SetField5cb0AndRecordByte0_02010774(battle, ctx->f0);
    SetField5cb4AndRecordByte1_020107a8(battle, ctx->f4);
    SetSlotByte020107dc(battle, ctx->f8);
    SetField5cbcValue_02010810(battle, ctx->fc);
    if (flag != 0) {
        memcpy(dst, (char*)ctx + 0x10, 0x8c);
        memcpy(dst + 0x8c, (char*)ctx + 0x9c, 0x15f);
        memcpy(dst + 0x2c0, (char*)ctx + 0x2d0, 0xc);
        memcpy(dst + 0x2cc, (char*)ctx + 0x2dc, 0x66);
        *(unsigned char*)(dst + 0x332) = ctx->f342;
    } else {
        CopyStruct020a99d0((struct Struct020a99d0*)dst, (struct Struct020a99d0*)((char*)ctx + 0x10));
    }
    return 1;
}

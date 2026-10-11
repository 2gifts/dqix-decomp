#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container020e0310;

int IsField0x118Equal2(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
int GetField0x3acValue(GameState* battleStruct);
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendNameTag(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);

extern short data_ov000_021834bc[];

// USA: func_ov000_021775a4  (semantic: AppendNameList_021775a4)
extern "C" ARM void func_ov000_021775a4(void* base, char* dst) {
    if (dst == NULL) return;

#if defined(jpn)
    signed char cursor = *(signed char*)((char*)base + 0x1f00 + 0xa2);
#else
    signed char cursor = *(signed char*)((char*)base + 0x1d00 + 0x6a);
#endif
    int n = 0;

    if (IsField0x118Equal2(base)) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    void* p = func_0202ae18();
    int count = 3;
    if (CheckField0NonZero((int*)p)) {
        if (GetField0x3acValue(GameState::GetInstance()) == 0) count = 4;
    }

    struct Container020e0310* c = (struct Container020e0310*)((char*)base + 0xb8);
    for (int i = 0; i < count; i++) {
        int name = GetFieldByKey020e0434(c, data_ov000_021834bc[i]);
        AppendNameTag(dst, n, (const char*)name);
        if (i != count - 1) {
            int sep = GetFieldByKey020e0434(c, 0);
            AppendString02042058(dst, (const char*)sep);
        }
        n++;
    }
}

#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern int data_ov023_021fdd6c;
extern "C" void* __clear(void* dst, int count);
extern "C" int func_020426bc(void* src, void* dst, int flag);
int StringLength_020d2ff0(const char* s);
int FindEntryIndexByKey020424e4(int key, int tableIdx);
extern "C" void func_02042764(void* a, void* b, int flag);

struct Entry0204254c {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};
struct Entry0204254c* FindEntryByKey0204254c(int key, int tableIdx);
int AppendXTag_02041a28(char* dst, int x);
void AppendString02042058(char* dst, const char* src);
int AppendYTag_02041a5c(char* dst, int y);

#if defined(jpn)
extern "C" void func_020420e8(char*, int);
extern "C" void func_02042428(char*, int);
struct TableA68;
char* FindEntryByKey_02072a68(TableA68*, int);
int AppendXYTag_02041a90(char*, int, int);
#endif

// USA: func_ov023_021e8cdc
extern "C" ARM void func_ov023_021e8cdc(char* obj) {
    int len;
    if (*(int*)(obj + 0x5f4) == 0) return;
    char* dst = *(char**)(obj + 0x5d8);

#if defined(jpn)
    char* battle = (char*)GameState::GetInstance() + 0x3c + 0x5400;
    func_020420e8(dst, 8);
    func_02042428(dst, 12);
    AppendString02042058(dst, FindEntryByKey_02072a68(*(TableA68**)(obj + 0x5f4), 0x73));
    dst += strlen(dst);
    char* src = battle + 8;
    if (*(char**)(obj + 0x600)) src = *(char**)(obj + 0x600);
    for (int row = 0; row < 3; ++row) {
        memcpy(dst, src, 0x26);
        src += 0x26;
        dst += 0x26;
        if (row != 2) {
            AppendXYTag_02041a90(dst, 1, row * 0x13 + 0x1b);
            dst += strlen(dst);
            memcpy(dst, FindEntryByKey_02072a68(*(TableA68**)(obj + 0x5f4), 0x7b), 2);
            dst += 2;
        }
    }
#else
    char* battle = (char*)GameState::GetInstance() + 0x29c + 0x5400;

    char buf[0x43a];
    __clear(buf, 0x3a);
    __clear(buf + 0x3a, 0x400);

    char* src = *(char**)(obj + 0x600);
    if (src != 0) {
        len = func_020426bc(src, buf, 1);
    } else {
        len = StringLength_020d2ff0(battle + 8);
        memcpy(buf, battle + 8, len);
    }

    signed char idxByte = (signed char)FindEntryIndexByKey020424e4((int)&data_ov023_021fdd6c, 1);
    for (; len < 0x39; len++) buf[len] = idxByte;

    func_02042764(buf, buf + 0x3a, 1);

    char* p = buf + 0x3a;
    int x = 0xf;
    int resetX = x;
    int y = 8;
    int col = 0;
    for (;;) {
        if (*p == 0) return;
        int step = 1;
        struct Entry0204254c* e = FindEntryByKey0204254c((int)p, step);
        if (e != 0) {
            AppendXTag_02041a28(dst, x);
            AppendString02042058(dst, (const char*)e->val);
            step = e->field5;
        }
        col++;
        p += step;
        x += 0xc;
        if (col == 0x13) {
            y += 0x13;
            x = resetX;
            col = 0;
            AppendYTag_02041a5c(dst, y);
        }
    }
#endif
}

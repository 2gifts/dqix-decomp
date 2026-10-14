#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct_0205d81c;
void* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
extern "C" int func_02050064(void* obj);
extern "C" void* __clear(void* dst, int count);
extern "C" int func_020426bc(void* src, void* dst, int flag);
int StringLength_020d2ff0(const char* s);
extern "C" void func_ov023_021e709c(void* ctx, void* arr, int index);
void* GetTableEntry0204a5e4(int a, int b);
void CleanInvalidateCacheRange(void const*, unsigned int);
void CleanCacheRange(void const*, unsigned int);

struct Data021ffa44 {
    int flags;
    void (*fn)(void*, void*, unsigned);
};
extern struct Data021ffa44 data_ov023_021ffa44;

struct Nibbles_021e8270 {
    unsigned char lo : 4;
    unsigned char hi : 4;
};

// USA: func_ov023_021e8270
extern "C" ARM void func_ov023_021e8270(char* obj) {
    char* src = *(char**)(obj + 0x600);
    void* elem = FindElementByC40205d81c((struct Struct_0205d81c*)(obj + 0x78), 0xd);
    if (elem == 0) return;

    char* dst = *(char**)((char*)elem + 0x8);
    int off = *(int*)((char*)elem + 0xa0);
    unsigned int size = *(unsigned int*)((char*)elem + 0xa4);
    char* base2 = (char*)func_02050064(elem);
    void* field4 = *(void**)((char*)elem + 0x4);
    memcpy(dst, base2 + off, size);

    char* battle = (char*)GameState::GetInstance() + 0x29c + 0x5400;

    char buf[0x43a];
    __clear(buf, 0x3a);
    __clear(buf + 0x3a, 0x400);

    int len;
    if (src != 0) {
        len = func_020426bc(src, buf, 1);
    } else {
        len = StringLength_020d2ff0(battle + 8);
        memcpy(buf, battle + 8, len);
    }

    func_ov023_021e709c(elem, buf, len - 1);
    func_ov023_021e709c(elem, buf, len);
    func_ov023_021e709c(elem, buf, len + 1);

    if (!(data_ov023_021ffa44.flags & 1)) {
        struct Nibbles_021e8270* nib = (struct Nibbles_021e8270*)((char*)field4 + 0x1c);
        data_ov023_021ffa44.fn = (void(*)(void*, void*, unsigned))GetTableEntry0204a5e4(nib->lo, nib->hi);
        data_ov023_021ffa44.flags |= 1;
    }
    CleanInvalidateCacheRange(dst, size);
    data_ov023_021ffa44.fn(dst, (void*)off, size);
    CleanCacheRange(dst, size);
}

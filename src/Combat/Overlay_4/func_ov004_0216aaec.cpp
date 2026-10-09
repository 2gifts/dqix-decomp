#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct IdList0216aaec {
    int ids[7];
};

struct Ctx0216aaec {
    char pad[0x8c];
    unsigned char bits[1];
};

struct Allocated0216aaec {
    char pad[4];
    SafeAllocator allocator;
};

struct Node0216aaec {
    char pad[0x20];
    void* buffer;
};

struct TableA68;
struct StoreStruct;
struct ToggleState;
struct SetFlagStruct;

extern "C" struct Ctx0216aaec* func_0205ec34(void);
int TestBitInByteArray(int unused, unsigned char* arr, int index);
int GetField5cbcValue(char* state);
extern "C" struct Allocated0216aaec* func_ov011_021845f8(void* ctx, int v);
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" struct Node0216aaec* func_ov023_021f6880(void* list, int id);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" struct TableA68* func_ov023_021fa598(void* obj);
extern "C" struct StoreStruct* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* obj);
extern "C" void func_02046380(struct StoreStruct* g);
void StoreInArray0x8b0(struct StoreStruct* s, int index, int value);
void* FindEntryByKey(struct TableA68* table, int key);
extern "C" void func_02046608(struct StoreStruct* a, int b, void* c, void* d, int e, int f, int g);
extern "C" void _Z27SetOffset100Fields_021f8960Pcss(char* base, short a, short b);
void SetToggleState(struct ToggleState* s, int a, int b);
void SetFlag0x9c6(struct SetFlagStruct* p, int value);

extern struct IdList0216aaec data_ov004_02170138;

// USA: func_ov004_0216aaec
extern "C" ARM int func_ov004_0216aaec(void* a) {
    GameState* state = GameState::GetInstance();
    struct Ctx0216aaec* ctx = func_0205ec34();
    struct IdList0216aaec list = data_ov004_02170138;
    unsigned char count = 0;
    int i;
    for (i = 0; i < 7; i++) {
        if (TestBitInByteArray((int)ctx, ctx->bits, list.ids[i])) {
            count++;
        }
    }
    int key = GetField5cbcValue((char*)state);

    struct Allocated0216aaec* alloc = func_ov011_021845f8(a, 4);
    if (alloc == 0) {
        return 0;
    }
    alloc->allocator.GetSizeWithLargestBlockRemoved();

    struct Node0216aaec* node = func_ov023_021f6880(func_ov011_021849c8(a), 0x192);
    if (node == 0) {
        return 0;
    }
    if (func_ov023_021f6f10(node) != 4) {
        return 0;
    }
    struct TableA68* table = func_ov023_021fa598(node);
    struct StoreStruct* g = _Z26GetGlobalField0x1c020421a0v();
    void* buf = alloc->allocator.Allocate(4);
    if (func_0202c540(func_0202ae18()) != 0) {
        key = 1000;
    }
    memset(buf, 0, 0x960);
    func_02046380(g);
    StoreInArray0x8b0(g, 0, count);
    func_02046608(g, 0xc, FindEntryByKey(table, (short)key), buf, 0xd7, 0, 1);

    struct Node0216aaec* holder = func_ov023_021f6880(func_ov011_021849c8(a), 0x32);
    if (holder != 0) {
        holder->buffer = buf;
    }

    struct Node0216aaec* panel = func_ov023_021f6880(func_ov011_021849c8(a), 0xc8);
    if (panel != 0 && func_ov023_021f6f10(panel) == 6) {
        _Z27SetOffset100Fields_021f8960Pcss((char*)panel, 0, 4);
    }

    struct ToggleState* toggle = (struct ToggleState*)func_ov017_0218b5b0()->unknown_ptr_36d0;
    SetToggleState(toggle, 1, 0);
    SetFlag0x9c6((struct SetFlagStruct*)toggle, 0);
    return 0;
}

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

extern "C" int func_020dc920(int a, int b, int c, int d);
extern "C" int func_0207c378(void* obj, int value, int amount, int key);
extern "C" void func_02052d7c(void* obj, int index, short value);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void func_ov017_021c3fb4(int id, int flag);
extern "C" void func_ov017_021c4418(int id, int flag);
extern "C" void func_ov017_0218f5a4(void* a, int i, int b, int c, int d);

int GetField0x3acValue(GameState*);
void* GetPtrField0x2a04(GameState*);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
int CheckSubstructByte0x7cPositive(signed char*);
int IsField0Null(void**);
GameObject* GetCombatantWithFlag0x100(GameState*, int);
int TryClearFlags0x130(unsigned char*, unsigned short);
extern "C" void _Z26EnqueueEventTag34_021d27a0hhh(unsigned char, unsigned char, unsigned char);
void* GetData02108e10();
extern "C" void* _Z24SearchBothTables02079e2cPci(char*, int);
struct Obj02048350;
extern "C" int _Z22ConsumeCounter02048350P11Obj02048350i(struct Obj02048350*, int);

extern "C" void _Z33CallEnqueueEvent94IfFlag_021a5a68v();
typedef void (*EnqueueTag34Fn)(int tag, int first, int second);
typedef void (*EnqueueEvent94Fn)(void* obj, int arg);

struct Party02a04 {
    char pad0[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct Global020421a0 {
    char pad0[0x998];
    int field998;
};

struct Slot021d27e4 {
    char pad0[8];
    unsigned int keyBits : 4;
    unsigned int mid : 14;
    unsigned int active : 1;
    unsigned int rest : 13;
    char padc[0xc];
    short value;
};

struct Evt021d27e4 {
    char pad0[4];
    unsigned char type;
    signed char first;
    signed char second;
};

struct Entry021d27e4 {
    char pad0[8];
    unsigned int low : 8;
};

struct SlotMap021d27e4 {
    signed char slots[11];
};

extern SlotMap021d27e4 data_ov017_021d6d0c;

// USA: func_ov017_021d27e4
extern "C" ARM void func_ov017_021d27e4(void* unused0, Evt021d27e4* evt, GameState* gs, unsigned char* ctx) {
    GetField0x3acValue(gs);
    Party02a04* party = (Party02a04*)GetPtrField0x2a04(gs);
    signed char first = evt->first;
    signed char second = evt->second;
    unsigned char* ids = party->ids;
    int hasFirst = 0;
    int hasSecond = 0;
    int count = party->count;
    int i;
    for (i = 0; i < count; i++) {
        unsigned char id = ids[i];
        if (id == first) hasFirst = 1;
        if (id == second) hasSecond = 1;
    }

    switch (evt->type) {
    case 1: {
        if (!hasSecond) return;
        int ok = 1;
        if (((Global020421a0*)_Z26GetGlobalField0x1c020421a0v())->field998 != 0) ok = 0;
        if (CheckSubstructByte0x7cPositive((signed char*)gs->GetUnknownGameObject()) != 0) ok = 0;
        if (IsField0Null(*(void***)(ctx + 0x3000 + 0x6fc)) == 0) ok = 0;
        if (func_020dc920((unsigned char)first, 1, 1, 0) == 0) ok = 0;
        if (ok) {
            int flagged = 0;
            GameObject* c = GetCombatantWithFlag0x100(gs, second);
            if (c != NULL) {
                if (**(unsigned int**)((char*)c + 0x130) & 4) flagged = 1;
            }
            if (flagged) {
                party = (Party02a04*)GetPtrField0x2a04(gs);
                SlotMap021d27e4 map = data_ov017_021d6d0c;
                int done = 0;
                for (int j = 0; j < 11; j++) {
                    if (j == 2 || j == 3 || j == 4) continue;
                    Slot021d27e4* slot = (Slot021d27e4*)(*(char**)((char*)c + 0x150) + 0x194 + (unsigned char)j * 0x20);
                    if (slot != NULL && slot->active) {
                        func_0207c378((char*)party + 0x1d4, slot->value, 1, slot->keyBits);
                        func_02052d7c(c, map.slots[j], -1);
                        done = 1;
                    }
                }
                if (done) {
                    TryClearFlags0x130((unsigned char*)c, 4);
                    func_ov017_021c9e00(second, 0, 0, 1);
                    func_ov017_021c3fb4(second, 1);
                    func_ov017_021c4418(second, -1);
                    GameResources* g = func_ov017_0218b5b0();
                    BackgroundLoader::GetInstance();
                    func_ov017_0218f5a4(g, second, 1, 0, 0);
                    ((EnqueueTag34Fn)_Z26EnqueueEventTag34_021d27a0hhh)(2, first, second);
                    return;
                }
            }
        }
        ((EnqueueTag34Fn)_Z26EnqueueEventTag34_021d27a0hhh)(3, first, second);
        return;
    }
    case 2: {
        if (!hasFirst) return;
        Entry021d27e4* entry = (Entry021d27e4*)_Z24SearchBothTables02079e2cPci((char*)GetData02108e10(), 0xd1);
        if (entry != NULL) {
            GameObject* c = GetCombatantWithFlag0x100(gs, first);
            if (c != NULL) {
                _Z22ConsumeCounter02048350P11Obj02048350i((struct Obj02048350*)c, entry->low);
                func_ov017_021c9e00(first, 0, 0, 1);
            }
        }
        ((EnqueueEvent94Fn)_Z33CallEnqueueEvent94IfFlag_021a5a68v)(*(void**)(ctx + 0x3000 + 0x71c), 0xb);
        return;
    }
    case 3:
        if (!hasFirst) return;
        ((EnqueueEvent94Fn)_Z33CallEnqueueEvent94IfFlag_021a5a68v)(*(void**)(ctx + 0x3000 + 0x71c), 0xc);
        return;
    }
}

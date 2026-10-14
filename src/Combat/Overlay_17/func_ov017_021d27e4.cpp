#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
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
extern "C" void* _Z24SearchBothTables02079e2cPci(char*, int);
struct Obj02048350;
extern "C" int _Z22ConsumeCounter02048350P11Obj02048350i(struct Obj02048350*, int);

#if defined(jpn)
extern "C" void func_ov017_021a64a0(void*, int);
#else
extern "C" void _Z33CallEnqueueEvent94IfFlag_021a5a68v();
#endif
typedef void (*EnqueueTag34Fn)(int tag, int first, int second);
typedef void (*EnqueueEvent94Fn)(void* obj, int arg);

#if defined(jpn)
enum { MessageActiveOffset = 0x868, EquipmentPointerOffset = 0x144 };
#else
enum { MessageActiveOffset = 0x998, EquipmentPointerOffset = 0x150 };
#endif

struct Slot021d27e4 {
    char pad0[8];
    unsigned int keyBits : 4;
    unsigned int mid : 14;
    unsigned int active : 1;
    unsigned int rest : 13;
    char padc[0xc];
    short value;
    unsigned char unknown1a[6];
};

struct Evt021d27e4 {
    unsigned char tag;
    char pad0[3];
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

#if defined(jpn)
extern SlotMap021d27e4 data_ov017_021d7154;
#else
extern SlotMap021d27e4 data_ov017_021d6d0c;
#endif

// USA: func_ov017_021d27e4
extern "C" ARM void func_ov017_021d27e4(void* unused0, Evt021d27e4* evt, GameState* gs, GameResources* ctx) {
    GetField0x3acValue(gs);
    unsigned char* party = static_cast<unsigned char*>(GetPtrField0x2a04(gs));
    signed char first = evt->first;
    signed char second = evt->second;
    unsigned char* ids = party + 0xf78;
    int hasFirst = 0;
    int hasSecond = 0;
    int count = party[0xf7c];
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
        if ((*reinterpret_cast<int*>(static_cast<char*>(_Z26GetGlobalField0x1c020421a0v()) + MessageActiveOffset)) != 0) ok = 0;
        if (CheckSubstructByte0x7cPositive((signed char*)gs->GetUnknownGameObject()) != 0) ok = 0;
        if (IsField0Null(static_cast<void**>(ctx->unknown_ptr_array_36fc[0])) == 0) ok = 0;
        if (func_020dc920((unsigned char)first, 1, 1, 0) == 0) ok = 0;
        if (ok) {
            int flagged = 0;
            GameObject* c = GetCombatantWithFlag0x100(gs, second);
            if (c != NULL) {
                if (**(unsigned int**)((char*)c + 0x130) & 4) flagged = 1;
            }
            if (flagged) {
                party = static_cast<unsigned char*>(GetPtrField0x2a04(gs));
#if defined(jpn)
                SlotMap021d27e4 map = data_ov017_021d7154;
#else
                SlotMap021d27e4 map = data_ov017_021d6d0c;
#endif
                int done = 0;
                for (int j = 0; j < 11; j++) {
                    if (j == 2 || j == 3 || j == 4) continue;
                    Slot021d27e4* slot = reinterpret_cast<Slot021d27e4*>(*reinterpret_cast<char**>(reinterpret_cast<char*>(c) + EquipmentPointerOffset) + 0x194) + (unsigned char)j;
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
#if defined(jpn)
        func_ov017_021a64a0(ctx->unknown_ptr_array_371c[0], 0xb);
#else
        ((EnqueueEvent94Fn)_Z33CallEnqueueEvent94IfFlag_021a5a68v)(ctx->unknown_ptr_array_371c[0], 0xb);
#endif
        return;
    }
    case 3:
        if (!hasFirst) return;
#if defined(jpn)
        func_ov017_021a64a0(ctx->unknown_ptr_array_371c[0], 0xc);
#else
        ((EnqueueEvent94Fn)_Z33CallEnqueueEvent94IfFlag_021a5a68v)(ctx->unknown_ptr_array_371c[0], 0xc);
#endif
        return;
    }
}

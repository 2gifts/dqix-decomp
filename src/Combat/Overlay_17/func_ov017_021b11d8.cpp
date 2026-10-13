#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct;
struct SearchStruct0202c1a4;

struct SearchStruct {
    char unk0[0xfc0];
    int busy;
};

struct Slot_021b11d8 {
    char data[6];
    signed char owner;
    unsigned char f7;
    unsigned char f8;
    signed char f9;
};

struct Entry021b11d8 {
    char pad0[2];
    unsigned short bit0 : 1;
    unsigned short mask : 4;
};

struct Node021b11d8 {
    unsigned char pad0[1];
    unsigned char flag1;
    unsigned char pad2[6];
    unsigned char mode;
    unsigned char count;
    unsigned char flags;
    unsigned char padB;
    unsigned short timer;
};

extern "C" void* func_0202ae18(void);
extern "C" void func_ov017_021c37a4(void);
extern "C" void func_ov017_021d1118(int a, int b, int c, int d);
extern "C" void func_ov017_021d1014(int a, int b, int c);
extern "C" void func_ov017_021d0b30(int a, int b, int c);
extern "C" void _Z27EnqueueEventTag173_021d1810tth(int a, int b, signed char c);
extern "C" int _Z24SetSearchFlagBit0202c660P12SearchStructi(SearchStruct* obj, int value);
extern "C" int _Z24TestBitBySignedByteIndexP12SearchStructi(SearchStruct* obj, int index);
extern "C" int _Z28TestMaskBitBySignedByteIndexP12SearchStructi(SearchStruct* obj, int index);
extern "C" Entry021b11d8* _Z25GetEntryBySignedByteIndexP12SearchStructi(SearchStruct* obj, int index);
int IsFieldMinusOne(int* obj);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* obj);
extern "C" int _Z18GetField0x3acValueP9GameState(GameState* battleStruct);
extern "C" int func_ov017_02195658(GameResources* res);

// USA: func_ov017_021b11d8
extern "C" ARM void func_ov017_021b11d8(void* obj, void* node) {
    Node021b11d8* self = (Node021b11d8*)obj;
    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    SearchStruct* search = (SearchStruct*)func_0202ae18();
    unsigned char mode = self->mode;
    if (mode == 0) {
        self->count = (unsigned char)GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search);
        self->flags = 0;
        for (int i = 0; i < 4; i++) {
            if (i != self->count) {
                if (_Z24TestBitBySignedByteIndexP12SearchStructi(search, i) != 0) {
                    self->flags |= (1 << i);
                }
            }
        }
        _Z27EnqueueEventTag173_021d1810tth(2, -1, (signed char)_Z18GetField0x3acValueP9GameState(gs));
        func_ov017_021d1118(-1, 1, 1, 2);
        func_ov017_021d1014(-1, 1, 0);
        self->mode++;
        return;
    }
    if (mode == 1) {
        Slot_021b11d8* slot = (Slot_021b11d8*)((char*)GameState::GetInstance() + 0x74c0);
        for (int i = 0; i < 3; i++, slot++) {
            if (slot->owner < 4) {
                continue;
            }
            if (slot->f7 != 0 || slot->f8 != 0) {
                return;
            }
            if (slot->f9 >= 0) {
                return;
            }
        }
        self->mode++;
        return;
    }
    if (mode == 2) {
        func_ov017_021d0b30(9, 0, 0);
        _Z24SetSearchFlagBit0202c660P12SearchStructi(search, 0);
        self->mode++;
        return;
    }
    if (mode != 3) {
        return;
    }
    if (IsFieldMinusOne((int*)search) != 0) {
        goto done;
    }
    {
        int slot = func_ov017_02195658(res);
        if (slot > 0) {
            self->flags &= ~(1 << slot);
        }
    }
    if (search->busy == 0) {
        for (int i = 1; i < 4; i++) {
            if ((self->flags & (1 << i)) != 0) {
                if (_Z28TestMaskBitBySignedByteIndexP12SearchStructi(search, i) == 0) {
                    self->flags &= ~(1 << i);
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if ((self->flags & (1 << i)) != 0) {
            Entry021b11d8* e = _Z25GetEntryBySignedByteIndexP12SearchStructi(search, i);
            if (e == 0) {
                continue;
            }
            int bit = 1 << self->count;
            unsigned short m = e->mask;
            if ((m & bit) != 0) {
                return;
            }
        }
    }
    if (self->timer >= 0x3e8) {
        goto done;
    }
    if (search->busy != 0) {
        return;
    }
    self->timer += gs->GetEffectiveDeltaTime();
    return;
done:
    func_ov017_021c37a4();
    self->flag1 = 1;
}
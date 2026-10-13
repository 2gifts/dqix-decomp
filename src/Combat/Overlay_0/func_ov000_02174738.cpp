#include <globaldefs.h>
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"

struct Obj0216fe74 {
    char pad0[0x40];
    char* arr;
    char pad1[0xa];
    unsigned short count;
};

char* GetBoundedArrayElement0x40(struct Obj0216fe74* obj, unsigned int index);

struct Entry02174738 {
    char pad0[0x24];
    unsigned char field24;
    char pad25[0x4c - 0x25];
    int field4c;
#if defined(jpn)
    char pad50[0x488 - 0x50];
#else
    char pad50[0x448 - 0x50];
#endif
};

struct Group02174738 {
    char pad0[0x20];
    void* vram;
    char pad17c[0x800 - 0x24];
    struct Entry02174738 entries[4];
};

struct Obj02174738 {
    char pad0[0x6c];
    signed char order[4];
    char pad70[0x158 - 0x70];
    struct Group02174738 group;
};

struct S_b20c {
    int field0;
    int field4;
    unsigned char field8;
};

struct TextSlot02174738 {
    int a;
    short b;
    short c;
    short d;
    short e;
};

extern "C" int _Z18GetField0x3acValueP9GameState(GameState* battleStruct);
void ClearTwoWordsAndByte(struct S_b20c* obj);
extern "C" void _Z18SetField0_0205b220Pvi(void* obj, int value);
extern "C" void _Z29SetFieldsAt0x4And0x8_0205b228Pvih(void* obj, int value, unsigned char flag);
extern "C" void* _Z21GetTableEntry020421b0i(int idx);
void SetOrClearFlag0x4At0x24(void* obj, int cond);

extern "C" void func_ov000_021710ac(struct Entry02174738* obj, int combatantId, int flag);
extern "C" void func_ov000_02171138(void* obj);
extern "C" void func_ov000_02174b14(struct Obj02174738* obj);
extern "C" int func_ov017_021bdbcc();
extern "C" int func_020420e8(char* label, int extra);
extern "C" void func_0205b234(struct S_b20c* a, short b, int c, void* buf, unsigned char d, unsigned char e);

extern char data_ov000_0218405b;
extern int data_ov000_02183ff0;

// USA: func_ov000_02174738
extern "C" ARM void func_ov000_02174738(struct Obj02174738* self, int id) {
    int valid;
    if (id >= 0) {
        if (id <= 3) {
            valid = 1;
            goto checkvalid;
        }
    }
    valid = 0;
checkvalid:
    if (!valid) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        signed char* ord = (signed char*)((int)self + 0x6c);
        signed char* ord2 = ord;
        struct Entry02174738* e = &self->group.entries[ord2[i]];
        if (id == e->field4c) {
            func_ov000_02171138(e);
            func_ov000_02174b14(self);
            return;
        }
    }

    void* vram = self->group.vram;
    char* info;
    char* info2;
    GameObject* c = GameState::GetInstance()->GetPartyMemberByIndex(id);
    if (c != NULL) {
        char* slot = GetBoundedArrayElement0x40((struct Obj0216fe74*)((char*)self + 0x11c),
                                                (unsigned short)(id + 0x20));
        if (slot != NULL) {
          info = *(char**)(slot + 8);
          if (info != NULL) {
            int idx950 = *(int*)(*(char**)((char*)c + 0x150) + 0x950);
            unsigned char sel = (unsigned char)(idx950 * 4 + 0x28);
            func_ov017_0218b5b0();
            if (func_ov017_021bdbcc() != 0) {
                sel = 0x28;
            }
            memcpy(vram, _Z21GetTableEntry020421b0i(sel), 0x80);

            unsigned short tm = *(unsigned short*)(info + 4) & 0x3ff;
            unsigned int off = tm << 7;
            CleanInvalidateCacheRange(vram, 0x80);
            LoadToSubObjVRAM(vram, off, 0x80);
            CleanCacheRange(vram, 0x80);
          }
        }
        {
            char* slot2 = GetBoundedArrayElement0x40((struct Obj0216fe74*)((char*)self + 0x11c),
                                                     (unsigned short)(id + 0x24));
            if (slot2 != NULL) {
              info2 = *(char**)(slot2 + 8);
              if (info2 != NULL) {
                memset(vram, 0, 0x80);
                struct S_b20c local;
                struct TextSlot02174738 text;
                text.a = 0;
                text.b = 0;
                text.c = 0;
                text.d = 0x10;
                text.e = 0x10;
                ClearTwoWordsAndByte(&local);
                _Z18SetField0_0205b220Pvi(&local, (int)vram);
                _Z29SetFieldsAt0x4And0x8_0205b228Pvih(&local, (int)&text, 1);
                char* field150 = *(char**)((char*)c + 0x150);
                int idx = *(int*)(field150 + 0x950);
                char* p = field150 + idx * 2 + 0x100;
                unsigned short val = *(unsigned short*)(p + 0x6c);
                char label[8];
                sprintf(label, &data_ov000_0218405b, val);
                short posX = (short)(0x10 - func_020420e8(label, 0));
                func_0205b234(&local, posX, 0, label, 0xf, 0);

                unsigned short tm2 = *(unsigned short*)(info2 + 4) & 0x3ff;
                unsigned int off2 = tm2 << 7;
                CleanInvalidateCacheRange(vram, 0x80);
                LoadToSubObjVRAM(vram, off2, 0x80);
                CleanCacheRange(vram, 0x80);
              }
            }
        }
    }

    GameState* bs = GameState::GetInstance();
    for (int i = 0; i < 4; i++) {
        struct Entry02174738* e = &self->group.entries[self->order[i]];
        if (self->order[i] != id) {
            continue;
        }
        if (e->field4c >= 0) {
            continue;
        }
        func_ov000_021710ac(e, id, id == _Z18GetField0x3acValueP9GameState(bs));
        SetOrClearFlag0x4At0x24(e, id == _Z18GetField0x3acValueP9GameState(bs));
        func_ov000_02171138(e);
        data_ov000_02183ff0 = data_ov000_02183ff0 + 1;
        func_ov000_02174b14(self);
        if (data_ov000_02183ff0 > 4) {
            data_ov000_02183ff0 = 4;
        }
        return;
    }
}

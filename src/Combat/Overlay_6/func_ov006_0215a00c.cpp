#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

struct Obj2081;
struct Container02080f8c;
struct Obj3a8Timer_02159fb0;
struct GameStateStub;
struct CombatantObj { char pad0[4]; short id; };
struct CombatantText { int data[3]; };

struct StoreStruct {
    void* field0;
    char pad4[0x14];
    void* field18;
    char pad1c[0x40];
    char* field5c;
};

struct Sub170 { char data[0x7c]; };
struct ParseEntry { char pad0[5]; signed char adv:6; };

struct Sub300 {
    char pad0[0x4c];
    int field34c;
    char pad50[0x78 - 0x50];
    short arr78[3];
    short field7e;
    unsigned short field80;
    short field82;
    char pad84[3];
    unsigned char field387;
    char pad388[0x92 - 0x88];
    unsigned char field392;
    char pad393[1];
    unsigned short field94;
    char pad96[2];
};

struct Obj0215a00c {
    int field0;
    char pad4[0x10];
    void* field14;
    char pad18[0x1c];
    int field34;
    char pad38[0x158 - 0x38];
    struct Container020e0310 field158;
    char pad160[0x170 - 0x160];
    struct Sub170 field170;
    short field1ec;
    char pad1ee[0x300 - 0x1ee];
    struct Sub300 sub;
    char pad398[0x3b0 - 0x398];
    int field3b0;
};

void ClearElementFlag0x20_02080c20(struct Obj2081*, int);
extern "C" void func_020813ec(void*, int);
int GetFieldByKey020e0434(struct Container020e0310*, int);
struct StoreStruct* GetGlobalField0x1c020421a0();
extern "C" void func_02046380(struct StoreStruct*);
void* CallFunc020e52a0_020e5294(void*, int);
void StoreInArray0x8b0_020465c0(struct StoreStruct*, int, int);
void InitObjFromCombatantId020e4bf4(void*, int);
extern "C" void func_02046608(struct StoreStruct*, int, const char*, char*, int, int, int);
char* FindEntryByKey0204254c(int, int);
extern "C" void __clear(void*, int);
void SetEntryFirstField02080f8c(Container02080f8c*, int, int);
void UpdateField3a8Timer_02159fb0(struct Obj3a8Timer_02159fb0*);
extern char data_ov006_0215ffd2[];
extern char data_ov006_0215ffea[];

// USA: func_ov006_0215a00c
extern "C" ARM void func_ov006_0215a00c(struct Obj0215a00c* self) {
    char buf[0x400];
    struct CombatantText combatant;
    int i;

    unsigned char state = self->sub.field392;
    if (state == 0) {
        if (self->sub.field94 & 0x20) {
            ClearElementFlag0x20_02080c20((struct Obj2081*)self->field14, 0);
            func_020813ec(self->field14, 0);
        }
        self->sub.field94 &= ~0x20;
        self->sub.field80 = 0;
        if (GetFieldByKey020e0434(&self->field158, self->sub.field7e) == 0) {
            self->sub.field7e = -1;
        }
        self->field3b0 = -1;
        self->sub.field392 = self->sub.field392 + 1;
        return;
    }
    if (state == 1) {
        struct StoreStruct* fmt = GetGlobalField0x1c020421a0();
        char* base = fmt->field5c;
        memset(base, 0, 0x960);
        func_02046380(fmt);

        unsigned short rem = 0;
        if (self->field34 != 0) {
            void* res = CallFunc020e52a0_020e5294(&self->field170, self->field1ec);
            if (res != 0) {
                fmt->field18 = res;
            }
            rem = (unsigned short)((self->sub.field82 / 10) * 10);
        }
        StoreInArray0x8b0_020465c0(fmt, 0, self->sub.field387);
        StoreInArray0x8b0_020465c0(fmt, 1, rem);

        struct CombatantObj* gobj = (struct CombatantObj*)((GameState*)((struct GameStateStub*)GameState::GetInstance()))->GetUnknownGameObject();
        if (gobj != 0) {
            InitObjFromCombatantId020e4bf4(&combatant, gobj->id);
            fmt->field0 = &combatant;
        }

        short* tp = (short*)data_ov006_0215ffd2;
        for (i = 0; ; i++) {
            short cur = *tp;
            if (cur < 0) break;
            if (cur == self->sub.field7e) {
                void* res = CallFunc020e52a0_020e5294(&self->field170, self->sub.arr78[i]);
                if (res != 0) {
                    fmt->field18 = res;
                }
                break;
            }
            tp++;
        }

        const char* msg = (const char*)GetFieldByKey020e0434(&self->field158, self->sub.field7e);
        func_02046608(fmt, 0xc, msg, base, 0xe3, 0, 1);

        char* p = base + self->sub.field80;
        unsigned short pos = self->sub.field80;
        int old = self->field0 >> 4;
        self->field0 += (self->sub.field34c << 4);
        i = self->field0 >> 4;
        int limit = i - old;
        if (self->field0 >= 0xffffff) {
            self->field0 = 0;
        }

        int count = 0;
        int one = 1;
        while (count < limit) {
            signed char ch = ((signed char*)p)[0];
            if (ch == 0) break;
            signed char step = 1;
            if (ch == 0x5c && ((signed char*)p)[1] == 0x6e) {
                p += 2;
                pos += 2;
            } else {
                ParseEntry* e = (ParseEntry*)FindEntryByKey0204254c((int)p, 1);
                if (e != 0) {
                    step = e->adv;
                }
                p += step;
                pos = (unsigned short)(pos + step);
            }
            count++;
        }
        if (self->sub.field80 >= pos) {
            self->sub.field7e = -1;
        }
        self->sub.field80 = pos;
        __clear(buf, 0x400);
        memcpy(buf, base, pos);
        SetEntryFirstField02080f8c((struct Container02080f8c*)self->field14, 1, (int)buf);
        func_020813ec(self->field14, 1);
        ClearElementFlag0x20_02080c20((struct Obj2081*)self->field14, 1);
        self->field3b0 = 1;

        short* tp2 = (short*)data_ov006_0215ffea;
        for (;;) {
            short cur2 = *tp2;
            if (cur2 < 0) break;
            if (cur2 == self->sub.field7e) {
                self->field3b0 = -1;
                break;
            }
            tp2++;
        }
        UpdateField3a8Timer_02159fb0((struct Obj3a8Timer_02159fb0*)self);
    }
}

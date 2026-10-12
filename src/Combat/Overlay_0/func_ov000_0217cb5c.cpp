#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kindsOffset = 0x1f98 };
#else
enum { kindsOffset = 0x1d60 };
#endif

struct Struct_0205c570;
struct Obj0205eaa0;
struct Entry_0205d6a0;
struct Struct0217f8c0;
struct TableEntry0217f8c0;

struct Battle {
    char pad0[0x70];
    signed char members[4];
    char pad1[0x17c - 0x74];
    int field17c;
    char pad2[0x188 - 0x180];
    char entryList[kindsOffset - 0x188];
    signed char kinds[8];
    signed char kindIndex;
    signed char mode;
    unsigned char step;
    char pad3[5];
    unsigned char field70;
    char pad4;
    unsigned short flags;
};

struct Party {
    char p[0xf7c];
    unsigned char count;
};

struct Combatant {
    char p[0x10];
    char slots[8];
    signed char slot;
};

extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(Struct_0205c570*);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0*, int, int);
void* GetPtrField0x2a04(GameState*);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(Entry_0205d6a0*, int);
extern "C" TableEntry0217f8c0* _Z30FindMatchingTableEntry0217f8c0P14Struct0217f8c0(Struct0217f8c0*);
extern Obj0205eaa0 data_02108760;
extern "C" {
void func_02012fe4();
int func_ov000_0217c594(void*, int);
void _Z22CopyStaticData02174da4iPv(void*, void*);
void func_ov000_02177038(void*, int, int, int, int);
int func_ov000_0217f990(void*);
Combatant* func_ov000_02161318(void*, int);
void func_ov000_02176634(void*, void*, int, int, int);
void func_ov000_02176e3c(void*, int, int, int, int, int);
void func_ov000_02180394(void*);
}

// USA: func_ov000_0217cb5c
extern "C" ARM void func_ov000_0217cb5c(Battle* self, int a, int b)
{
    func_02012fe4();
    self->flags |= 0x100;
    int mode = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)self->entryList);
    if (mode < 0) mode = 0;
    self->mode = mode;
    if (func_ov000_0217c594(self, 0)) {
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
        int table[4];
        _Z22CopyStaticData02174da4iPv(self, table);
        switch (table[self->mode]) {
        case 0:
            func_ov000_02177038(self, 0, self->kinds[self->kindIndex], a, b);
            self->kindIndex++;
            self->kinds[self->kindIndex] = 13;
            _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)self->entryList, 1);
            self->flags |= 4;
            if (func_ov000_0217f990(self) == 0) {
                self->flags &= ~4;
                self->field17c = -1;
                GameState* game = GameState::GetInstance();
                Party* party = (Party*)GetPtrField0x2a04(game);
                unsigned char count = party->count;
                for (unsigned char i = 0; i < count; i++) {
                    Combatant* c = func_ov000_02161318(self, self->members[i]);
                    if (c) {
                        c->slots[c->slot] = 100;
                    }
                }
            }
            break;
        case 1:
            func_ov000_02177038(self, 0, self->kinds[self->kindIndex], a, b);
            self->step = 0;
            self->kindIndex++;
            self->kinds[self->kindIndex] = 2;
            func_ov000_02176634(self, _Z30FindMatchingTableEntry0217f8c0P14Struct0217f8c0((Struct0217f8c0*)self), 2, a, b);
            break;
        case 2:
            self->flags &= ~0x100;
            func_ov000_02176e3c(self, 0, self->kinds[self->kindIndex], a, b, 1);
            self->field70 = 0;
            self->kindIndex++;
            self->kinds[self->kindIndex] = 10;
            break;
        case 3:
            func_ov000_02177038(self, 0, self->kinds[self->kindIndex], a, b);
            self->kindIndex++;
            self->kinds[self->kindIndex] = 11;
            _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)self->entryList, 1);
            func_ov000_02180394(self);
            break;
        }
    }
}

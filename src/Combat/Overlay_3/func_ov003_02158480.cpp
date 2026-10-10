#include <globaldefs.h>
#include "GameState/GameState.h"

struct EntryList;

struct PartyStatusPanel {
    char unk_0[0x18];
    EntryList* entries;
    char unk_1c[0x20 - 0x1c];
    int* slots;
    char unk_24[0x1f2 - 0x24];
    unsigned char memberIds[4];
    unsigned char memberCount;
    signed char selected;
};

extern "C" void _Z22SetSublistEntriesFlag1Pvi(void*, int);
extern "C" void _Z22SetSublistEntriesFlag2Pvi(void*, int);
extern "C" void _Z24SetEntryFlagById02080b40Pvi(void*, int);
extern "C" void _Z18DispatchEntryOp0x8Pvi(void*, int);
extern "C" int _Z28CountNonZeroEntries_0215570cP11Obj0215570c(PartyStatusPanel*);
extern "C" unsigned char* _Z15GetFieldAt0x150Ph(unsigned char*);
extern "C" void _Z31ClearSublistEntryFlag2_020806c4Pvi(void*, int);
extern "C" void _Z19SetEntryHalfword0xePvii(void*, int, int);
extern "C" void _Z26SetEntryFirstField02080fa8P17Container02080fa8ii(void*, int, int);
extern "C" void _Z27GetEntryFieldsAt0x602080828PviPsS0_(void*, int, short*, short*);
extern "C" void _Z23GetEntryOutputs020808c8PviPsS0_(void*, int, short*, short*);
extern "C" void _Z27SetEntryFieldsAt0x602080854Pviii(void*, int, int, int);
extern "C" void _Z30ResolveEntryValueByKey02080fe0Pvii(void*, int, int);
extern "C" void _Z22SetEntryHighNibble0x13P17Container02080cc0ii(void*, int, int);
extern "C" void _Z32GetSublistEntryScaledXY_020807c4PviPsS0_(void*, int, short*, short*);
extern "C" void _Z27GetEntryFieldsAt0xE02080878PviPsS0_(void*, int, short*, short*);
extern "C" void _Z24SetEntryScaledXY020807fcPviii(void*, int, int, int);
extern "C" void _Z27SetEntryFieldsAt0xE020808a4Pviii(void*, int, int, int);
extern "C" void func_020813ec(void*, int);

// USA: func_ov003_02158480
extern "C" ARM void func_ov003_02158480(PartyStatusPanel* self) {
    EntryList* entries = self->entries;
    short row = 0x13;
    short col = 0x1f;
    short sub = 0x2b;
    short cell = 0x37;

    _Z22SetSublistEntriesFlag1Pvi(entries, 6);
    _Z22SetSublistEntriesFlag2Pvi(entries, 6);
    _Z24SetEntryFlagById02080b40Pvi(entries, 0x43);
    _Z18DispatchEntryOp0x8Pvi(entries, 0x43);

    int count = _Z28CountNonZeroEntries_0215570cP11Obj0215570c(self);
    int r8 = -1;
    if (count <= 6) {
        r8 = 7;
    } else if (count >= 7 && count <= 8) {
        r8 = 8;
    } else if (count >= 9 && count <= 10) {
        r8 = 9;
    }

    GameState* gs = GameState::GetInstance();
    unsigned char* member = (unsigned char*)gs->GetPartyMemberByIndex(self->selected);
    if (member != NULL) {
        unsigned char* base = _Z15GetFieldAt0x150Ph(member);
        for (unsigned char i = 0; i < 12; i++) {
            int slot = self->slots[i];
            if (slot != 0) {
                _Z31ClearSublistEntryFlag2_020806c4Pvi(entries, row);
                _Z24SetEntryFlagById02080b40Pvi(entries, row);
                _Z24SetEntryFlagById02080b40Pvi(entries, col);
                _Z24SetEntryFlagById02080b40Pvi(entries, sub);
                _Z19SetEntryHalfword0xePvii(entries, row, (short)(slot - 1));
                _Z26SetEntryFirstField02080fa8P17Container02080fa8ii(entries, sub,
                    *(unsigned short*)(base + 0x16c + slot * 2));

                unsigned char* entry = base + slot;
                unsigned char kind = entry[0x186];
                if (kind != 0) {
                    short hi = (short)(kind + 0x12);
                    int shade = 5;
                    if (kind == 10) {
                        shade = 0xd;
                    }

                    short a, b, c, d;
                    _Z27GetEntryFieldsAt0x602080828PviPsS0_(entries, row, &a, &b);
                    _Z23GetEntryOutputs020808c8PviPsS0_(entries, row, &c, &d);
                    _Z27SetEntryFieldsAt0x602080854Pviii(entries, cell, (short)(a + c + 1), b);
                    _Z24SetEntryFlagById02080b40Pvi(entries, cell);
                    _Z30ResolveEntryValueByKey02080fe0Pvii(entries, cell, hi);
                    _Z22SetEntryHighNibble0x13P17Container02080cc0ii(entries, cell, shade);
                }
            }
            row = (short)(row + 1);
            col = (short)(col + 1);
            sub = (short)(sub + 1);
            cell = (short)(cell + 1);
        }
    }

    if (r8 > 0) {
        short e, f, g, h;
        _Z32GetSublistEntryScaledXY_020807c4PviPsS0_(entries, r8, &e, &f);
        _Z27GetEntryFieldsAt0xE02080878PviPsS0_(entries, r8, &g, &h);
        _Z24SetEntryScaledXY020807fcPviii(entries, 6, e, f);
        _Z27SetEntryFieldsAt0xE020808a4Pviii(entries, 6, g, h);
        _Z32GetSublistEntryScaledXY_020807c4PviPsS0_(entries, 6, &e, &f);
        _Z27GetEntryFieldsAt0xE02080878PviPsS0_(entries, 6, &g, &h);
    }
    func_020813ec(entries, 6);
}

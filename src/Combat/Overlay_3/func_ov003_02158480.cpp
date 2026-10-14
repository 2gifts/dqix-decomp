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

void SetSublistEntriesFlag1(void*, int);
void SetSublistEntriesFlag2(void*, int);
void SetEntryFlagById02080b40(void*, int);
void DispatchEntryOp0x8(void*, int);
extern "C" int _Z28CountNonZeroEntries_0215570cP11Obj0215570c(PartyStatusPanel*);
unsigned char* GetFieldAt0x150(unsigned char*);
void ClearSublistEntryFlag2_020806c4(void*, int);
void SetEntryHalfword0xe(void*, int, int);
extern "C" void _Z26SetEntryFirstField02080fa8P17Container02080fa8ii(void*, int, int);
void GetEntryFieldsAt0x602080828(void*, int, short*, short*);
void GetEntryOutputs020808c8(void*, int, short*, short*);
void SetEntryFieldsAt0x602080854(void*, int, int, int);
void ResolveEntryValueByKey02080fe0(void*, int, int);
extern "C" void _Z22SetEntryHighNibble0x13P17Container02080cc0ii(void*, int, int);
void GetSublistEntryScaledXY_020807c4(void*, int, short*, short*);
void GetEntryFieldsAt0xE02080878(void*, int, short*, short*);
void SetEntryScaledXY020807fc(void*, int, int, int);
void SetEntryFieldsAt0xE020808a4(void*, int, int, int);
extern "C" void func_020813ec(void*, int);

// USA: func_ov003_02158480
extern "C" ARM void func_ov003_02158480(PartyStatusPanel* self) {
    EntryList* entries = self->entries;
    short row = 0x13;
    short col = 0x1f;
    short sub = 0x2b;
    short cell = 0x37;

    SetSublistEntriesFlag1(entries, 6);
    SetSublistEntriesFlag2(entries, 6);
    SetEntryFlagById02080b40(entries, 0x43);
    DispatchEntryOp0x8(entries, 0x43);

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
        unsigned char* base = GetFieldAt0x150(member);
        for (unsigned char i = 0; i < 12; i++) {
            int slot = self->slots[i];
            if (slot != 0) {
                ClearSublistEntryFlag2_020806c4(entries, row);
                SetEntryFlagById02080b40(entries, row);
                SetEntryFlagById02080b40(entries, col);
                SetEntryFlagById02080b40(entries, sub);
                SetEntryHalfword0xe(entries, row, (short)(slot - 1));
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
                    GetEntryFieldsAt0x602080828(entries, row, &a, &b);
                    GetEntryOutputs020808c8(entries, row, &c, &d);
                    SetEntryFieldsAt0x602080854(entries, cell, (short)(a + c + 1), b);
                    SetEntryFlagById02080b40(entries, cell);
                    ResolveEntryValueByKey02080fe0(entries, cell, hi);
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
        GetSublistEntryScaledXY_020807c4(entries, r8, &e, &f);
        GetEntryFieldsAt0xE02080878(entries, r8, &g, &h);
        SetEntryScaledXY020807fc(entries, 6, e, f);
        SetEntryFieldsAt0xE020808a4(entries, 6, g, h);
        GetSublistEntryScaledXY_020807c4(entries, 6, &e, &f);
        GetEntryFieldsAt0xE02080878(entries, 6, &g, &h);
    }
    func_020813ec(entries, 6);
}

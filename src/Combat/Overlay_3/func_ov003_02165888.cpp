#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Container02080cc0;
struct Container02080f8c;
struct Container02080fa8;
struct Container020e0310 { char pad[4]; };
struct StatusOwner02081198;
struct StatusOwner02081164;

int SetSublistEntriesFlag1_02080b54(void* obj, int id);
int SetEntryFlagById02080b2c(void* obj, int id);
int SetEntryFlagById02080b40(void* obj, int id);
void SetEntryHighNibble0x13(struct Container02080cc0* obj, int id, int value);
extern "C" int func_020dcc98(int combatantId);
int* GetFieldAt0x150_02053c6c(unsigned char* p);
void SetEntryFirstField02080f8c(Container02080f8c*, int, int);
void ResolveEntryValueByKey02080fe0(void*, int, int);
void SetEntryFirstField02080fa8(struct Container02080fa8*, int, int);
void SetEntryHalfword0xe_0208103c(void*, int, int);
void GetEntryFieldsAt0x602080828(void*, int, short*, short*);
extern "C" void _Z23GetEntryOutputs020808c8PviPsS0_(void*, short, short*, short*);
void SetEntryFieldsAt0x602080854(void*, int, int, int);
int GetFieldByKey020e0434(struct Container020e0310*, int);
void SetEntryNibbleByShortId(struct StatusOwner02081198* owner, int id, int enable);
void SetEntryFlag0x2ByShortId(struct StatusOwner02081164* obj, int id, int value);
extern "C" int func_020813ec(void* obj, int id);
extern "C" void func_ov003_02160678(void* self);
extern "C" void func_ov003_02160794(void* self);

struct Profile {
    char pad[0x16c];
    unsigned short unk16c;
    char pad187[0x186 - 0x16e];
    unsigned char unk186 : 8;
    char pad187b[0x49c - 0x187];
    unsigned char unk49c : 1;
    char pad49d[0x950 - 0x49d];
    int unk950;
};

struct EntryList {
    char pad[0x36];
    short field36;
};

struct StatusPanel {
    char pad[0x2dc];
    Container020e0310 cont2dc;
    char pad2e0[0x324 - 0x2e0];
    struct Container02080cc0* elementObj;
    char pad328[0x468 - 0x328];
    unsigned char counters[4];
    char pad46c[0x4ad - 0x46c];
    unsigned char count4ad;
    char pad4ae[0x4bd - 0x4ae];
    unsigned char flag4bd;
};

// USA: func_ov003_02165888
extern "C" ARM void func_ov003_02165888(StatusPanel* self) {
    struct Container02080cc0* elementObj = self->elementObj;
    int idA;
    int color;
    int idC;
    int v;
    int key;
    GameState* gs;
    GameObject* member;
    char* nm;
    unsigned char* ids;
    unsigned char count;
    short t16, t14, t12, t10;
    unsigned char i;
    int idB;

    SetSublistEntriesFlag1_02080b54(elementObj, 0x13);
    gs = GameState::GetInstance();

    ids = (unsigned char*)self + 0xa9 + 0x400;
    idA = 0x55;
    self->flag4bd = (unsigned char)idA;
    count = self->count4ad;
    idB = 0x68;
    idC = 0xcf;
    memset((unsigned char*)self + 0x68 + 0x400, 0, 4);

    for (i = 0; i < 4; i++) {
        color = 0xf;
        SetEntryFlagById02080b2c(elementObj, idC);

        if (i < count) {
            int j;
            struct Profile* prof;
            member = gs->GetPartyMemberByIndex(ids[i]);
            if (member == 0) continue;

            for (color = 0; color < 3; color++) {
                SetEntryFlagById02080b40(elementObj, (short)(idA + color * 4));
            }
            SetEntryFlagById02080b40(elementObj, idB);

            color = func_020dcc98((signed char)ids[i]);
            if (idA == ((struct EntryList*)elementObj)->field36 && color == 0xf) {
                color = 0xa;
            }
            for (j = 0; j < 3; j++) {
                SetEntryHighNibble0x13(elementObj, (short)(idA + j * 4), color);
            }
            SetEntryHighNibble0x13(elementObj, idB, color);

            v = -1;
            prof = (struct Profile*)GetFieldAt0x150_02053c6c((unsigned char*)member);
            ((unsigned char*)self + i)[0x468] = (unsigned char)(prof->unk49c + 1);
            nm = (char*)member->baseStats_;
            SetEntryFirstField02080f8c((struct Container02080f8c*)elementObj, idA, (int)nm);
            if (prof->unk950 != 0) {
                v = (short)(prof->unk950 + 0x11);
            }
            ResolveEntryValueByKey02080fe0(elementObj, (short)(idA + 4), v);
            SetEntryFirstField02080fa8(
                (struct Container02080fa8*)elementObj, (short)(idA + 8),
                *(unsigned short*)((char*)prof + prof->unk950 * 2 + 0x16c));

            {
                struct Profile* p3 = *(struct Profile**)((char*)member + 0x150);
                unsigned char* row = (unsigned char*)p3 + p3->unk950;
                unsigned char kind = row[0x186];
                SetEntryHalfword0xe_0208103c(elementObj, idC, (short)(kind + 0x64));
                if (kind != 0) {
                    color = 5;
                    if (kind == 0xa) {
                        color = 0xd;
                    }
                    SetEntryHighNibble0x13(elementObj, idC, color);
                    SetEntryFlagById02080b40(elementObj, idC);
                    key = i + 0x59;
                    GetEntryFieldsAt0x602080828(elementObj, (short)key, &t16, &t14);
                    _Z23GetEntryOutputs020808c8PviPsS0_(elementObj, key, &t12, &t10);
                    SetEntryFieldsAt0x602080854(elementObj, idC, (short)(t16 + t12 + 1), t14);
                    SetEntryHighNibble0x13(elementObj, idC, color);
                    SetEntryFlagById02080b40(elementObj, idC);
                }
            }
        } else {
            if (idA == ((struct EntryList*)elementObj)->field36) {
                color = 0xa;
            }
            SetEntryFlagById02080b40(elementObj, idA);
            nm = (char*)GetFieldByKey020e0434(&self->cont2dc, 0x7530);
            SetEntryFirstField02080f8c((struct Container02080f8c*)elementObj, idA, (int)nm);
            SetEntryHighNibble0x13(elementObj, idA, color);
        }

        idA = (short)(idA + 1);
        idC = (short)(idC + 1);
        idB = (short)(idB + 1);
    }

    SetEntryNibbleByShortId((struct StatusOwner02081198*)elementObj, 0x13, 1);
    SetEntryFlag0x2ByShortId((struct StatusOwner02081164*)elementObj, 0x13, 1);
    func_020813ec(elementObj, 0x13);
    func_ov003_02160678(self);
    func_ov003_02160794(self);
}

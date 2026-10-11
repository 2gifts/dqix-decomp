#include "GameState/GameState.h"
#include <globaldefs.h>

struct BitArray020839dc;
struct Holder0209a9dc;

struct Entry_02157174 {
    int f0;
    int f4;
    unsigned int pad8 : 10;
    unsigned int flag8 : 2;
    unsigned int rest8 : 20;
    int fc;
    int f10;
    int f14;
    unsigned int pad18 : 12;
    unsigned int kind18 : 4;
    unsigned int rest18 : 16;
};

struct Skill_0209a594 {
    int f0;
    int f4;
    unsigned short h8;
};

extern "C" int _Z28CollectSetBitIndices020839dcP16BitArray020839dcPhi(struct BitArray020839dc *s, unsigned char *out, int max);
extern "C" void *__clear(void *dst, int count);
int LookupValuesByIds(Holder0209a9dc *holder, unsigned char *bits, unsigned int count, unsigned short *out);
void *GetData02108e10(void);
extern "C" Entry_02157174 *_Z24SearchBothTables02079e2cPci(char *p, int key);
extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" int func_0209ab7c(void *holder, void *member, unsigned char *bits);
int TestBitInArray0x8ec(unsigned char *obj, int index);
extern "C" Skill_0209a594 *func_0209a594(void *p, int id);
void *GetFieldAt0x150(unsigned char *member);

// USA: func_ov002_02157174
extern "C" ARM void func_ov002_02157174(char *self, int combatantId) {
    unsigned char bits[0x42];
    short ids[0x42];
    unsigned char i;
    Entry_02157174 **out;
    unsigned char *member;
    unsigned char *pm;
    int n;
    int count;
    char *table;
    int j;
    int k;
    unsigned short b;
    for (i = 0; i < 0x20; i++) {
        *(int *) (self + i * 4 + 0x24a0) = 0;
    }
    *(unsigned char *) (self + 0x2520) = 0;
    out                                = (Entry_02157174 **) (self + 0x4a0 + 0x2000);
    member                             = (unsigned char *) GetCombatantWithFlag0x100(GameState::GetInstance(), combatantId);
    if (member == 0) {
        return;
    }
    pm = (unsigned char *) GetFieldAt0x150(member);
    if (pm == 0) {
        return;
    }
    n = _Z28CollectSetBitIndices020839dcP16BitArray020839dcPhi((struct BitArray020839dc *) pm, bits, 0x42);
    __clear(ids, 0x84);
    n     = LookupValuesByIds((Holder0209a9dc *) (self + 0x44 + 0x2400), bits, n, (unsigned short *) ids);
    count = 0;
    table = (char *) GetData02108e10();
    for (j = 0; j < n; j++) {
        Entry_02157174 *e = _Z24SearchBothTables02079e2cPci(table, ids[j]);
        if (e != 0 && bits[j] == 0x3c) {
            if (e->flag8 & 1) {
                out[count] = e;
                count++;
            }
        }
    }
    if (*(int *) (*(char **) (member + 0x150) + 0x950) == 0) {
        memset(bits, 0, 0x42);
        n = _Z28CollectSetBitIndices020839dcP16BitArray020839dcPhi((struct BitArray020839dc *) pm, bits, 0x42);
    } else {
        memset(bits, 0, 0x42);
        n = func_0209ab7c(self + 0x44 + 0x2400, member, bits);
    }
    memset(ids, 0, 0x84);
    n = LookupValuesByIds((Holder0209a9dc *) (self + 0x44 + 0x2400), bits, n, (unsigned short *) ids);
    for (k = 0; k < n; k++) {
        Entry_02157174 *e = _Z24SearchBothTables02079e2cPci(table, ids[k]);
        if (e != 0 && bits[k] != 0x3c) {
            if (e->flag8 & 1) {
                out[count] = e;
                count++;
            }
        }
    }
    for (b = 0; b < 0x11f; b++) {
        if (TestBitInArray0x8ec(pm, b)) {
            Skill_0209a594 *s = func_0209a594(self + 0x3c + 0x2400, b);
            if (s != 0 && s->h8 != 0) {
                Entry_02157174 *e = _Z24SearchBothTables02079e2cPci(table, (short) s->h8);
                if (e != 0 && e->kind18 == 1) {
                    if (e->flag8 & 1) {
                        out[count] = e;
                        count++;
                    }
                }
            }
        }
    }
    *(unsigned char *) (self + 0x2520) = count;
}

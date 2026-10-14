#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Action_021fb490 {
    unsigned int field_0x0;
    unsigned int unused_0x4;
    unsigned int unused_0x8 : 8;
    unsigned int mode : 2;
    unsigned int unused_0x8b : 4;
    unsigned int key : 8;
    unsigned int unused_0x8c : 10;
    unsigned int field_0xc;
    unsigned int flags;
    unsigned int unused_0x14 : 28;
    unsigned int targetKind : 4;
    unsigned int unused_0x18;
    unsigned int unused_0x1c : 14;
    unsigned int range : 5;
    unsigned int unused_0x1c2 : 13;
};
struct EntryFlags9_021fb490 {
    unsigned char weight : 6;
    unsigned char flag : 1;
    unsigned char sel : 1;
};
struct Entry_021fb490 {
    float value;
    unsigned char id, flag, index, percent, kind;
    EntryFlags9_021fb490 flags9;
    unsigned char padding[2];
};
struct AddEntryList_021f6a1c {
    Entry_021fb490 entries[16];
    int count;
    float threshold;
    AddEntryList_021f6a1c() { memset(this, 0, sizeof(*this)); }
};
struct Info_021fb490 {
    unsigned char padding[0xa];
    unsigned short unused : 12;
    unsigned short flag : 1;
};
struct Unit_021fb490 {
    unsigned char padding_0x0[4];
    short field_0x4;
    unsigned char padding_0x6[0x138 - 6];
    unsigned int* stats;
    unsigned char padding_0x13c[0x144 - 0x13c];
    struct Info_021fb490* info;
    unsigned char padding_0x148[0x17c - 0x148];
    unsigned char group;
    unsigned char GetGroup() const { return group; }
};
struct ActionWork_021fb490 {
    unsigned char padding[0x3ec];
    int scaling;
    Action_021fb490* action;
    unsigned char padding_0x3f4[5];
    unsigned char eligible;
    unsigned char padding_0x3fa[2];
    AddEntryList_021f6a1c* list;
    Entry_021fb490 savedEntry;
    Unit_021fb490* target;
    int targetIndex;
};
struct Context_021fb490 {
    unsigned char padding_0x0[8];
    unsigned char* actor;
    unsigned char padding_0xc[0x2c - 0xc];
    unsigned char flag_0x2c;
    unsigned char padding_0x2d[0x34 - 0x2d];
    unsigned char flag_0x34;
    unsigned char padding_0x35[0x7c - 0x35];
    Unit_021fb490* units[8];
    int count;
    unsigned char padding_0xa0[0x25c - 0xa0];
    ActionWork_021fb490 work;
};
struct Bits2f4_021fb490 { unsigned int bit0 : 1; unsigned int bit1 : 1; };
struct FlagObj_021da998;
struct FlagObj_021dd260;

int GetFieldAt0x150(unsigned char*);
void* GetData02108e10();
void* LookupElementByKey02079ee0(void*, int);
float LookupTableD0Clamped(int);
extern "C" float _fmul(float, float);
extern "C" int _fgeq(float, float);
int IsFlagBit8388608Set_021da998(FlagObj_021da998*);
int IsFlagBit24Set_021dd260(FlagObj_021dd260*);
void AddEntryIfUnderLimit16_021f6a1c(AddEntryList_021f6a1c*, void*);
extern "C" void func_ov024_021f8938(void*, float*, float*, int, void*, void*);
extern "C" void func_ov024_021fa7ec(void*, float*, float*, float*, int*, float, float, void*, void*, int);
extern "C" void func_ov024_021f8d80(void*, int*, void*, void*, int, float*, float*, int, void*);
extern "C" void func_ov024_021f6a4c(void*, void*);
extern "C" void func_ov024_021fd858(void*);
extern "C" void func_ov024_021f9874(void*, void*, int, int);

struct Row_021fb490 {
    unsigned char a;
    unsigned char b;
    unsigned char carry;
};
extern const Row_021fb490 data_ov024_021ff002[];

// USA: func_ov024_021fb490
extern "C" ARM void func_ov024_021fb490(Context_021fb490* context) {
#if defined(jpn)
    enum { regionalOffset0 = 0x144 };
#else
    enum { regionalOffset0 = 0x150 };
#endif
    float hi[8];
    float lo[8];
    float avg[8];
    Action_021fb490* action;
    void* data;
    int total;
    void* element;
    unsigned char* actor;
    Unit_021fb490** units;
    actor = context->actor;
    GetFieldAt0x150(context->actor);
    data = GetData02108e10();
    action = context->work.action;
    int scaling = context->work.scaling;
    if (action->mode == 2) return;
    float value;
    float spread;
    int outIndex;
    value = 0;
    spread = 0;
    outIndex = -1;
    func_ov024_021f8938(context, &value, &spread, scaling, action, actor);
    units = context->units;
    total = context->count;
    element = LookupElementByKey02079ee0(data, action->key);
    for (int j = 0; j < total; j++) {
        lo[j] = 0;
        avg[j] = 0;
        hi[j] = 0;
        float* pHi = &hi[j];
        float* pLo = &lo[j];
        float* pAvg = &avg[j];
        Unit_021fb490* unit = units[j];
        if (!unit->info || !unit->info->flag || (action->flags & 0x1000000)) {
            func_ov024_021fa7ec(context, pHi, pLo, pAvg, &outIndex, value, spread, element, unit, j);
        }
    }
    int kind = action->targetKind;
    if (kind == 5) {
        char* p = (char*)(*(int**)(actor + regionalOffset0)) + 0x2f4;
        if (p) {
            Bits2f4_021fb490* bits = (Bits2f4_021fb490*)p;
            if (bits->bit1) kind = 3;
            else if (bits->bit0) kind = 4;
            else kind = 2;
        }
    }
    if (kind != 2 && kind != 4 && kind != 3) return;
    unsigned int row = action->range;
    short a;
    short b;
    unsigned char carry;
    int product;
    if (row <= 11) {
        a = data_ov024_021ff002[row].a;
        b = data_ov024_021ff002[row].b;
        product = a * b;
        carry = data_ov024_021ff002[row].carry;
    } else {
        return;
    }
    int selected = -1;
    if (kind == 2 && a == 1) {
        func_ov024_021f8d80(context, &selected, action, context->units, context->count, avg, lo, product, actor);
    }
    AddEntryList_021f6a1c list;
    memset(&list, 0, sizeof(list));
    int count = 0;
    int flag = 0;
    int lookups = 0;
    int i = 0;
    unsigned char weight = product;
    for (; i < context->count; i++) {
        context->flag_0x2c = 0;
        if (selected >= 0 && selected != i) continue;
        if (outIndex == i) context->flag_0x34 = 1;
        count++;
        Unit_021fb490* unit = units[i];
        if (action->flags & 0x400) {
            if (unit->stats[0x14 / 4] & 0x200) flag = 1;
        }
        if (kind != 2 && (context->work.action->flags & 0x20000)) {
            avg[i] = _fmul(avg[i], LookupTableD0Clamped((signed char)lookups));
            lookups++;
        }
        Entry_021fb490 entry;
        entry.flag = 1;
        entry.percent = 100;
        entry.kind = 0;
        entry.value = avg[i];
        entry.index = i;
        entry.flags9.weight = weight;
        entry.flags9.flag = carry;
        AddEntryIfUnderLimit16_021f6a1c(&list, &entry);
        if (hi[i] >= 0.1f && !IsFlagBit8388608Set_021da998((FlagObj_021da998*)actor) &&
            !IsFlagBit24Set_021dd260((FlagObj_021dd260*)actor)) {
            context->work.list = &list;
            func_ov024_021f6a4c(&context->work.savedEntry, &entry);
            context->work.target = unit;
            context->work.targetIndex = i;
            func_ov024_021fd858(context);
        }
        int last = 0;
        if (i == context->count - 1) last = 1;
        else if (kind == 2) last = 1;
        else if (kind == 4) {
            if (unit->GetGroup() != units[i + 1]->GetGroup()) last = 1;
        }
        if (!last) continue;
        if (count >= 2) {
            if (carry) flag = 1;
        }
        if (count <= 1) carry = 0;
        if (!flag) {
            int p3 = (unsigned char)unit->field_0x4;
            int p2 = unit->GetGroup();
            if (kind == 4) p3 = 0xff;
            else if (kind == 3) { p3 = 0xff; p2 = p3; }
            func_ov024_021f9874(context, &list, p2, p3);
        }
        memset(&list, 0, sizeof(list));
        count = 0;
        flag = 0;
        lookups = 0;
    }
}

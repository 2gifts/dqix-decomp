#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct TableA68;
struct StoreStruct;
struct Obj9b6c;
struct Obj02046574;
extern "C" void* func_ov023_021f6524(void* ctx, int value);
extern "C" struct TableA68* func_ov004_02168b08(void* a, int key);
int GetGlobalField0x1c020421a0(void);
void* GetFieldAt0x150(unsigned char* obj);
extern "C" void* func_0205ec34(void* obj);
extern "C" int func_ov023_021f9bc8(char* obj);
unsigned int GetTableEntry_021f9b6c(struct Obj9b6c* obj, unsigned int a, unsigned int b);
extern "C" void __clear(void* buf, int len);
extern "C" void func_02042764(const char* name, char* dest, int flag);
void* GetNodeIfType8_02168a6c(void* a, int id);
char* FindEntryByKey(struct TableA68* table, int key);
extern "C" void func_02046380(void* global);
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
extern "C" void func_02046608(void* a, int b, char* c, char* d, int e, int f, int g);
char* FindSubstring(char* haystack, char* needle);
int LoadBattleBlock020ac4c0(void* dst);
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);
int TestBitInByteArray(int unused, unsigned char* arr, int index);
void SetByteInRange(unsigned char* base, int index, unsigned char value);
void SetByteAtIndex(unsigned char* base, int index, unsigned char value);
int DispatchNodeIfState6_021f6680(void* obj, int id);

struct Packed02169b4c {
    unsigned int w0A : 14;
    unsigned int w0B : 17;
    unsigned int w0C : 1;
    unsigned int w4A : 14;
    unsigned int w4B : 17;
    unsigned int w4C : 1;
    unsigned int w8A : 7;
    unsigned int w8B : 7;
    unsigned int w8C : 7;
    unsigned int w8D : 7;
    unsigned int w8E : 4;
    unsigned int wcA : 10;
    unsigned int wcB : 14;
    unsigned int wcC : 7;
    unsigned int wcD : 1;
    unsigned int w10A : 9;
    unsigned int w10B : 14;
    unsigned int w10C : 7;
    unsigned int w10D : 2;
    short f14;
    unsigned char f16 : 1;
};

struct Area02169b4c {
    char pad[6];
    char name[0xe];
    struct Packed02169b4c rec;
};

struct Blk02169b4c {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    unsigned short f04;
    unsigned char f06;
    unsigned char f07;
    unsigned int f08 : 24;
    unsigned int f08hi : 8;
    unsigned int f0cA : 14;
    unsigned int f0cB : 14;
    unsigned int f0cC : 4;
    char rest[0xb0 - 0x10];
};

struct Ctx02169b4c {
    char pad[0x190];
    char* f190;
    struct Packed02169b4c* f194;
    unsigned char f198;
    char pad199[3];
    char* f19c;
};

struct Grid02169b4c { char pad[0x5c]; short f5c; };
struct Triple02169b4c { int a, b, c; };

class Node02169b4c {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Apply(struct Triple02169b4c* t);
    virtual struct Triple02169b4c Get();
    char pad4[8];
    unsigned char b0 : 3;
    unsigned char hidden : 1;
    char pad0d[0x20 - 0xd];
    char* text;
    char pad24[0x45 - 0x24];
    unsigned char f45a : 1;
    unsigned char mode : 6;
};

extern struct Ctx02169b4c* data_ov004_02171030;
extern char data_ov004_02170704[];

// USA: func_ov004_02169b4c
extern "C" ARM int func_ov004_02169b4c(void* a) {
    char* areas = data_ov004_02171030->f190;
    if (!areas) return 0;

    struct Grid02169b4c* grid = (struct Grid02169b4c*)func_ov023_021f6524(a, 0x64);
    struct TableA68* tblA = func_ov004_02168b08(a, 3);
    void* g = (void*)GetGlobalField0x1c020421a0();
    unsigned char* prot = (unsigned char*)GetFieldAt0x150((unsigned char*)GameState::GetInstance()->GetProtagonist());
    unsigned char* flags = (unsigned char*)func_0205ec34(prot);
    struct TableA68* tbl9 = func_ov004_02168b08(a, 9);
    struct TableA68* tbl6 = func_ov004_02168b08(a, 6);
    struct TableA68* tbl7 = func_ov004_02168b08(a, 7);
    short f5c = grid->f5c;
    int areaIdx = func_ov023_021f9bc8((char*)grid);
    int idx = areaIdx + f5c * 8;
    if (!GetTableEntry_021f9b6c((struct Obj9b6c*)grid, (unsigned short)areaIdx, 0)) return 0;

    struct Area02169b4c* area = (struct Area02169b4c*)(areas + 4) + idx;
    char buf[0x30];
    __clear(buf, 0x30);
    char* name;
    struct Packed02169b4c* rec;
    if (data_ov004_02171030->f198) {
        name = (char*)(prot + 0x3c);
        rec = data_ov004_02171030->f194;
    } else {
        rec = &area->rec;
        func_02042764(area->name, buf, 1);
        name = buf;
    }

    char* out = data_ov004_02171030->f19c;
    memset(out, 0, 4);
    Node02169b4c* node;

    node = (Node02169b4c*)GetNodeIfType8_02168a6c(a, 0x190);
    node->mode = 2;
    sprintf(out, FindEntryByKey(tblA, 0x23), rec->w0A);
    node->text = out;
    out += strlen(out) + 1;

    node = (Node02169b4c*)GetNodeIfType8_02168a6c(a, 0x1c2);
    node->mode = 2;
    sprintf(out, FindEntryByKey(tblA, 0x23), rec->w8A);
    node->text = out;
    out += strlen(out) + 1;

    node = (Node02169b4c*)GetNodeIfType8_02168a6c(a, 0x191);
    node->mode = 2;
    sprintf(out, FindEntryByKey(tblA, 0x23), rec->w4A);
    node->text = out;
    out += strlen(out) + 1;

    node = (Node02169b4c*)GetNodeIfType8_02168a6c(a, 0x1c3);
    node->mode = 2;
    sprintf(out, FindEntryByKey(tblA, 0x23), rec->w8B);
    node->text = out;
    out += strlen(out) + 1;

    func_02046380(g);
    char* title;
    if (rec->f14 >= 700) {
        title = FindEntryByKey(tbl9, (short)(rec->f14 + 20000));
    } else if (rec->f16) {
        title = FindEntryByKey(tbl7, rec->f14);
    } else {
        title = FindEntryByKey(tbl6, rec->f14);
    }
    SetIndexedName02046574((struct Obj02046574*)g, 0, title);
    SetIndexedName02046574((struct Obj02046574*)g, 1, name);
    func_02046608(g, 0xa, FindEntryByKey(tblA, 0x22), out, 0xf0, 1, 0);

    node = (Node02169b4c*)GetNodeIfType8_02168a6c(a, 0x192);
    node->text = out;
    struct Triple02169b4c t = node->Get();
    t.b = 0x7000;
    if (FindSubstring(out, data_ov004_02170704)) t.b = 0x2000;
    node->Apply(&t);
    out += strlen(out) + 1;

    func_02046380(g);
    unsigned char count = 0;
    unsigned char mask = 0;
    struct Blk02169b4c blk;
    LoadBattleBlock020ac4c0(&blk);
    mask |= 1;
    StoreInArray0x8b0((struct StoreStruct*)g, count++, rec->w4B);
    if (TestBitInByteArray((int)flags, flags + 0x8c, 0x1198)) {
        mask |= 2;
        StoreInArray0x8b0((struct StoreStruct*)g, count++, rec->w0B);
    }
    mask |= 4;
    StoreInArray0x8b0((struct StoreStruct*)g, count++, rec->wcA);
    if (blk.f08hi) {
        mask |= 8;
        StoreInArray0x8b0((struct StoreStruct*)g, count++, rec->w10A);
    }
    if (blk.f0cB) {
        mask |= 0x10;
        StoreInArray0x8b0((struct StoreStruct*)g, count++, rec->wcB);
    }
    if (TestBitInByteArray((int)flags, flags + 0x8c, 0x1199)) {
        mask |= 0x20;
        StoreInArray0x8b0((struct StoreStruct*)g, count++, rec->w10B);
    }

    unsigned char k = 0;
    int i;
    for (i = 0; i < 6; i++) {
        if (mask & (1 << i)) {
            SetByteInRange((unsigned char*)g, k, 5);
            SetByteAtIndex((unsigned char*)g, k, 1);
            strcpy(out, FindEntryByKey(tblA, (short)(i + 0x28)));
            int base = k * 3;
            node = (Node02169b4c*)GetNodeIfType8_02168a6c(a, base + 0x1f4);
            if (!node) continue;
            node->text = out;
            out += strlen(out) + 1;
            func_02046608(g, 8, FindEntryByKey(tblA, (short)(k + 0x14)), out, 0x100, 0, 0);
            node = (Node02169b4c*)GetNodeIfType8_02168a6c(a, base + 0x1f5);
            if (!node) continue;
            node->text = out;
            out += strlen(out) + 1;
            int key;
            if (i == 5) {
                key = 0x30;
            } else if ((i == 2) | (i == 3)) {
                key = 0x2f;
            } else {
                key = 0x2e;
            }
            strcpy(out, FindEntryByKey(tblA, key));
            node = (Node02169b4c*)GetNodeIfType8_02168a6c(a, base + 0x1f6);
            if (!node) continue;
            node->text = out;
            out += strlen(out) + 1;
            k++;
        }
    }
    for (int j = k; j < 6; j++) {
        int base = j * 3;
        ((Node02169b4c*)GetNodeIfType8_02168a6c(a, base + 0x1f4))->hidden = 1;
        ((Node02169b4c*)GetNodeIfType8_02168a6c(a, base + 0x1f5))->hidden = 1;
        ((Node02169b4c*)GetNodeIfType8_02168a6c(a, base + 0x1f6))->hidden = 1;
    }

    func_02046380(g);
    StoreInArray0x8b0((struct StoreStruct*)g, 0, rec->w8C);
    SetByteInRange((unsigned char*)g, 0, 3);
    SetByteAtIndex((unsigned char*)g, 0, 1);
    StoreInArray0x8b0((struct StoreStruct*)g, 1, rec->wcC);
    SetByteInRange((unsigned char*)g, 1, 3);
    SetByteAtIndex((unsigned char*)g, 1, 1);
    StoreInArray0x8b0((struct StoreStruct*)g, 2, rec->w8D);
    SetByteInRange((unsigned char*)g, 2, 3);
    SetByteAtIndex((unsigned char*)g, 2, 1);
    StoreInArray0x8b0((struct StoreStruct*)g, 3, rec->w10C);
    SetByteInRange((unsigned char*)g, 3, 3);
    SetByteAtIndex((unsigned char*)g, 3, 1);

    int rows = (mask & 2) ? 4 : 3;
    for (int r = 0; r < rows; r++) {
        func_02046608(g, 8, FindEntryByKey(tblA, (short)(r + 0x1e)), out, 0x100, 0, 0);
        ((Node02169b4c*)GetNodeIfType8_02168a6c(a, r * 2 + 6 + 0x200))->text = out;
        out += strlen(out) + 1;
    }
    if (rows == 3) {
        ((Node02169b4c*)GetNodeIfType8_02168a6c(a, 0x19c))->hidden = 1;
        ((Node02169b4c*)GetNodeIfType8_02168a6c(a, 0x20c))->hidden = 1;
        ((Node02169b4c*)GetNodeIfType8_02168a6c(a, 0x20d))->hidden = 1;
    }

    DispatchNodeIfState6_021f6680(a, 0x18);
    DispatchNodeIfState6_021f6680(a, 0x19);
    DispatchNodeIfState6_021f6680(a, 0x1c);
    DispatchNodeIfState6_021f6680(a, 0x1a);
    DispatchNodeIfState6_021f6680(a, 0x1d);
    DispatchNodeIfState6_021f6680(a, 0x1b);
    return 0;
}

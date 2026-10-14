#include <globaldefs.h>
#include "GameState/GameState.h"

struct Quest0218aa24 {
    char pad0[0xc];
    unsigned int kind : 4;
    unsigned int pad0c_4 : 4;
    unsigned int scroll : 7;
    unsigned int pad0c_15 : 17;
    char pad10[0x2e - 0x10];
    unsigned char female : 1;
    unsigned char pad2e_1 : 7;
    char pad2f[0x4e - 0x2f];
    unsigned char pad4e_0 : 1;
    unsigned char rank : 4;
    unsigned char pad4e_5 : 3;
    unsigned char level;
};

struct Stars0218aa24 {
    unsigned char count : 8;
};

struct PartyData0218aa24 {
    char pad0[0x16c];
    unsigned short scroll[(0x186 - 0x16c) / 2];
    Stars0218aa24 rank[0x49c - 0x186];
    unsigned char female : 1;
    unsigned char pad49c_1 : 7;
    char pad49d[0x950 - 0x49d];
    int vocation;
};

struct Member0218aa24 {
    char pad0[0x150];
    PartyData0218aa24* data;
};

struct Ent0218aa24 {
    char pad0[0x56a];
    unsigned char level;
};

struct Link0218aa24 {
    char pad0[0x115];
    signed char level115;
    char pad116[0x13d - 0x116];
    signed char level13d;
};

struct Self0218aa24 {
    char pad0[0x18];
    char list[0xb8 - 0x18];
    short b8;
    short ba;
    short bc;
    short be;
    short c0;
    short c2;
    short c4;
    short c6;
    char padc8;
    unsigned char c9;
    char padca[0xcd - 0xca];
    unsigned char cd;
    char padce[0x1f8 - 0xce];
    Link0218aa24* link;
    char pad1fc[0x278 - 0x1fc];
    char texts[0x2a0 - 0x278];
    char* text;
    char pad2a4[0xdf6 - 0x2a4];
    char codes[0xe1c - 0xdf6];
    unsigned int e1c_lo : 12;
    unsigned int e1c_title : 4;
    unsigned int e1c_scroll : 5;
    unsigned int e1c_hi : 11;
    char pad_e20[0xeb9 - 0xe20];
    signed char member;
    char pad_eba[0xebc - 0xeba];
    Quest0218aa24* quest;
};

struct TableA68;
struct Struct0205de24;
struct Struct_0205d81c;

extern char data_ov008_0218b590[];

void* GetGlobalField0x1c020421a0();
extern "C" void __clear(void* p, unsigned int size);
extern "C" void func_02046380(void* w);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(void* w, int idx, char* str);
extern "C" void _Z17StoreInArray0x8b0P11StoreStructii(void* w, int idx, int value);
extern "C" char* _Z14FindEntryByKeyP8TableA68i(void* table, int key);
extern "C" void func_02046608(void* w, int a, char* str, char* buf, int b, int c, int d);
extern "C" int func_020420e8(const char* text, int large);
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(void* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void* memset(void* p, int v, unsigned int n);
extern "C" Ent0218aa24* _Z15GetFieldAt0x150Ph(Member0218aa24* m);
extern "C" void func_ov008_0218b240(Self0218aa24* self);
extern "C" void func_02042764(const void* codes, char* text, int value);
extern "C" void* _Z23FindElementByC40205d81cP15Struct_0205d81ci(void* s, int key);
int AppendXYTag(char* dst, int x, int y);
void AppendString02042058(char* text, const char* append);
void AppendLineXTag02041cf4(char* dst, int color, int a, int b, int c);
int AppendPaletteTag(char* dst, int palette);
extern "C" void _Z14SetByteAtIndexPhih(void* base, int index, unsigned char value);
extern "C" void _Z14SetByteInRangePhih(void* base, int index, unsigned char value);
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);

// USA: func_ov008_0218aa24
extern "C" ARM void func_ov008_0218aa24(Self0218aa24* self) {
    char buf80[0x80];
    char buf40[0x40];
    char name[0x30];

    void* win = GetGlobalField0x1c020421a0();
    GameState* gs = GameState::GetInstance();
    __clear(buf40, 0x40);
    func_02046380(win);
    _Z22SetIndexedName02046574P11Obj02046574iPc(win, 0, data_ov008_0218b590);
    _Z17StoreInArray0x8b0P11StoreStructii(win, 2, 0x21);
    func_02046608(win, 10, _Z14FindEntryByKeyP8TableA68i(self->texts, 0x1f8), buf40, 0x100, 0, 0);
    int width = (func_020420e8(buf40, 0) + 0x17) & ~7;
    if (width < 0x58) width = 0x58;
    _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(self->list, 0, 2);
    self->c9 = 0;
    self->bc = 0x20 - (width >> 3);
    self->be = 0;
    self->c0 = 8;
    self->c2 = 3;
    self->b8 = width >> 3;
    self->ba = 7;
    self->c4 = 10;
    self->c6 = 12;
    self->cd = 1;
    memset(self->text, 0, 0x960);
    __clear(name, 0x30);

    int vocation;
    unsigned char level;
    int female;
    unsigned char rank;
    int scroll;
    const void* codes;
    if (self->quest == 0) {
        int fail = 0;
        Member0218aa24* m = (Member0218aa24*)gs->GetPartyMemberByIndex(self->member);
        Ent0218aa24* ent = 0;
        if (m == 0) {
            fail = 1;
        } else {
            ent = _Z15GetFieldAt0x150Ph(m);
            if (ent == 0) fail = 1;
        }
        if (fail) {
            func_ov008_0218b240(self);
            return;
        }
        PartyData0218aa24* data = m->data;
        vocation = data->vocation;
        rank = data->rank[vocation].count;
        scroll = data->scroll[vocation];
        codes = self->codes;
        female = data->female;
        level = ent->level;
    } else {
        Quest0218aa24* quest = self->quest;
        vocation = quest->kind;
        scroll = quest->scroll;
        female = quest->female;
        rank = quest->rank;
        level = quest->level;
        codes = quest;
    }
    func_02042764(codes, name, 1);
    _Z23FindElementByC40205d81cP15Struct_0205d81ci(self->list, 0);
    AppendXYTag(self->text, (width - func_020420e8(name, 0)) / 2, 3);
    AppendString02042058(self->text, name);
    AppendLineXTag02041cf4(self->text, 0x7fff, 2, width - 2, 0xf);

    char* str;
    if (female) {
        str = _Z14FindEntryByKeyP8TableA68i(self->texts, (short)(vocation + 0x46));
    } else {
        str = _Z14FindEntryByKeyP8TableA68i(self->texts, (short)vocation);
    }
    int x = (width - func_020420e8(str, 0)) / 2;
    if (rank != 0) x -= 5;
    AppendXYTag(self->text, x, 0x12);
    AppendString02042058(self->text, str);
    if (rank != 0) {
        if (rank >= 10) {
            rank = 10;
            AppendPaletteTag(self->text, 0xd);
        } else {
            AppendPaletteTag(self->text, 5);
        }
        int x2 = x + func_020420e8(str, 0);
        str = _Z14FindEntryByKeyP8TableA68i(self->texts, (short)(rank + 0x12c));
        AppendXYTag(self->text, x2 + 2, 0x12);
        AppendString02042058(self->text, str);
        AppendPaletteTag(self->text, 0xf);
    }

    func_02046380(win);
    _Z17StoreInArray0x8b0P11StoreStructii(win, 0, scroll);
    _Z14SetByteAtIndexPhih(win, 0, 0);
    _Z14SetByteInRangePhih(win, 0, 3);
    func_02046608(win, 10, _Z14FindEntryByKeyP8TableA68i(self->texts, 0x1f6), buf80, 0x100, 0, 0);
    AppendXYTag(self->text, (width >> 1) - 13, 0x1e);
    AppendString02042058(self->text, buf80);
    AppendLineXTag02041cf4(self->text, 0x7fff, 2, width - 2, 0x28);
    memset(buf80, 0, 0x80);
    _Z22SetIndexedName02046574P11Obj02046574iPc(win, 0, _Z14FindEntryByKeyP8TableA68i(self->texts, (short)(self->e1c_title + 0x1f9)));
    _Z17StoreInArray0x8b0P11StoreStructii(win, 2, self->e1c_scroll);
    func_02046608(win, 10, _Z14FindEntryByKeyP8TableA68i(self->texts, 0x1f8), buf80, 0x100, 0, 0);
    AppendXYTag(self->text, 12, 0x2a);
    AppendString02042058(self->text, buf80);
    func_0205d304(self->list, self->text, 0, 0, 0, 1, 0, 0);
    self->link->level115 = (signed char)level;
    self->link->level13d = (signed char)level;
}

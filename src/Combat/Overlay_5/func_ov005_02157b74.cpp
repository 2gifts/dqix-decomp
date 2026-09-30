#include <globaldefs.h>

struct GameState;

struct ItemDef02157b74 {
    unsigned int pad0 : 27;
    unsigned int sound : 2;
    unsigned int pad1 : 3;
};

struct Item02157b74 {
    ItemDef02157b74* def;          // 0x00
    int f4;                        // 0x04
    unsigned int equipType : 4;    // 0x08
    unsigned int pad0 : 14;
    unsigned int cursed : 1;
    unsigned int pad1 : 13;
    int fc;                        // 0x0c
    unsigned int pad2 : 20;        // 0x10
    unsigned int kind : 8;
    unsigned int pad3 : 4;
};

struct Linked02157b74 {
    char pad0[0x18];
    short id;                      // 0x18
};

struct Equip02157b74 {
    char pad0[0x16];
    short linkedId;                // 0x16
};

struct Combatant02157b74 {
    char pad0[4];
    short id;                      // 0x04
    char pad1[0x150 - 6];
    void* model;                   // 0x150
};

struct Context02157b74 {
    char pad0[0x4fc];
    int actor;                     // 0x4fc
    char pad1[0x634 - 0x500];
    unsigned short flags;          // 0x634
};

struct Entry02157b74 {
    short id;                      // 0x00
    signed char state;             // 0x02
    char pad[0x1c - 3];
};

struct Menu02157b74 {
    char pad0[0xdf4];
    void* items;                   // 0x0df4
    char pad1[0x1a34 - 0xdf8];
    char cursor[0x2d90 - 0x1a34];  // 0x1a34
    Entry02157b74 entries[0x18];   // 0x2d90
    char pad2[0x3da8 - 0x3030];
    unsigned char f3da8;           // 0x3da8
    unsigned char f3da9;
    unsigned char f3daa;           // 0x3daa
    unsigned char f3dab;
    unsigned short f3dac;          // 0x3dac
    char pad3[0x3dbb - 0x3dae];
    signed char selected;          // 0x3dbb
    unsigned char tab;             // 0x3dbc
    char pad4[0x3dcc - 0x3dbd];
    unsigned int dirty;            // 0x3dcc
    unsigned char pad5;
    unsigned char message;         // 0x3dd1
    unsigned char nextMessage;     // 0x3dd2
};

extern "C" GameState* _ZN9GameState11GetInstanceEv();
extern "C" char* func_ov017_0218b5b0();
extern "C" Context02157b74* _Z19GetField1c_021a193cPi(int p);
extern "C" Combatant02157b74* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState* gs, int idx);
extern "C" char* _Z17GetPtrField0x2a04P9GameState(GameState* gs);
extern "C" short _Z28GetHalfwordEntryFromField150P22Field150Holder02052df8i(Combatant02157b74* c, int slot);
extern "C" Item02157b74* _Z24FindElementByKey020dedd0P17Container020dedd0i(void* container, short key);
extern "C" void func_02052d7c(Combatant02157b74* c, int slot, short id);
extern "C" void* _Z15GetFieldAt0x150Ph(Combatant02157b74* c);
extern "C" void func_0208358c(void* model, Item02157b74* item, int arg);
extern "C" void func_02083738(void* model, int type);
extern "C" void _Z23SetPtrFieldByte021583fcP14Holder021583fcc(Combatant02157b74* c, char val);
extern "C" Equip02157b74* _Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c(Combatant02157b74* c);
extern "C" int func_ov005_0215840c(Menu02157b74* self, int id);
extern "C" void func_02083e28(void* model, int arg);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void func_0207c378(char* list, short key, int amount, int category);
extern "C" void _Z28DispatchByIdxAndCond021551fcPchi(Menu02157b74* self, int byteVal, int cond);
extern "C" void func_ov005_02155544(Menu02157b74* self);
extern "C" void func_ov005_021555c0(Menu02157b74* self);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(void* obj, int a, int b);
extern "C" int func_020dd4c4(signed char id, Item02157b74* item);
extern "C" Linked02157b74* _Z26Forward10BitFields020deda4iiP14Fields020deda4(void* container, int kind, Item02157b74* item);
extern "C" void _Z16TrySetFlags0x130Pht(Combatant02157b74* c, unsigned short flags);
extern "C" int func_0207c7a0(char* list, short key, int category);
extern "C" int _Z33FindEntryIndexInKeyedList0207caa4P17KeyedList0207caa4ii(char* list, short key, int category);
extern "C" void _Z33DecrementKeyedStackAmount0207c484P17KeyedList0207c484iii(char* list, short key, int amount, int category);
extern "C" void _Z27SetEntryInKeyedList0207cb38P17KeyedList0207cb38iiic(char* list, int index, int category, short key, char amount);
extern "C" void _Z13NoOp_021e4e1cv(Context02157b74* ctx, int actor, short key, int category);
extern "C" void func_ov005_02154d18(void* obj, int a, int b);
extern "C" void func_ov005_02154d50(void* obj, int a, int b);

extern signed char data_ov005_0215cd40[];
extern unsigned char data_ov005_0215cd38[];
extern char data_02108760[];
extern unsigned char data_ov005_0215cd30[];

// USA: func_ov005_02157b74
extern "C" ARM void func_ov005_02157b74(Menu02157b74* self, int key, int keepStock) {
    char* bag;
    GameState* gs = _ZN9GameState11GetInstanceEv();
    Context02157b74* ctx = _Z19GetField1c_021a193cPi(*(int*)(func_ov017_0218b5b0() + 0x3708));
    int bareArg;
    int actor = ctx->actor;
    Combatant02157b74* who = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, actor);
    if (who == 0) return;

    bag = _Z17GetPtrField0x2a04P9GameState(gs);

    if (key == 0xffff) {
        int slot = data_ov005_0215cd40[self->tab];
        short cur = _Z28GetHalfwordEntryFromField150P22Field150Holder02052df8i(who, slot);
        Item02157b74* item = _Z24FindElementByKey020dedd0P17Container020dedd0i(self->items, cur);
        if (item == 0) return;

        if (item->cursed == 1) {
            self->message = 0xc;
            self->dirty |= 0x8000;
            return;
        }

        short bareKey = -1;
        bareArg = -1;
        if (slot == 0) {
            bareArg = 0;
            bareKey = 0x3e8;
        }
        func_02052d7c(who, slot, -1);
        void* model = _Z15GetFieldAt0x150Ph(who);
        Item02157b74* bare = _Z24FindElementByKey020dedd0P17Container020dedd0i(self->items, bareKey);
        if (bare != 0) {
            func_0208358c(model, bare, bareArg);
        } else {
            func_02083738(model, item->equipType);
            if (item->equipType == 7) {
                _Z23SetPtrFieldByte021583fcP14Holder021583fcc(who, 1);
            }
        }
        if (slot == 0) {
            _Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c(who)->linkedId = -1;
        }
        if (cur == 0x4680) {
            if (func_ov005_0215840c(self, who->id) != 0) {
                if (self->message == 0xa && keepStock != 0) {
                    self->nextMessage = 0xe;
                } else {
                    self->message = 0xe;
                }
            }
        }
        func_02083e28(who->model, 0);
        func_ov017_021c9e00(who->id, 0, 0, 1);
        ctx->flags |= 4;
        if (keepStock == 0) {
            func_0207c378(bag + 0x1d4, cur, 1, data_ov005_0215cd38[self->tab]);
        }
        self->entries[self->selected].id = -1;
        _Z28DispatchByIdxAndCond021551fcPchi(self, _Z19GetField1c_021a193cPi(*(int*)(func_ov017_0218b5b0() + 0x3708))->actor, 1);
        func_ov005_02155544(self);
        self->dirty |= 0x10;
        self->f3da8 = 0;
        self->f3dac = self->tab;
        if (keepStock == 0) {
            func_ov005_021555c0(self);
            for (int i = 8; i < 0x18; i++) {
                if (cur == self->entries[i].id && self->entries[i].state == 1) {
                    self->dirty |= 0x40;
                    self->f3daa = 0;
                    break;
                }
            }
        }
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(data_02108760, 0x5c, 0);
        self->dirty |= 0x200;
        self->dirty |= 1;
        return;
    }

    Item02157b74* item = _Z24FindElementByKey020dedd0P17Container020dedd0i(self->items, key);
    if (item == 0) return;

    unsigned int kind = item->kind;
    int slot = -1;
    switch (kind) {
    case 0x73: slot = 8; break;
    case 0x62: slot = 0; break;
    case 0x70: slot = 1; break;
    case 0x61: slot = 4; break;
    case 0x67: slot = 4; break;
    case 0x72: slot = 5; break;
    case 0x6d: slot = 6; break;
    case 0x77: slot = 7; break;
    case 0x63: slot = 9; break;
    }

    int refusal = func_020dd4c4(who->id, item);
    if (refusal != 0) {
        if (refusal & 0x100) {
            self->message = 5;
            return;
        }
        if (refusal & 0x80) {
            self->message = 2;
            if (_Z28GetHalfwordEntryFromField150P22Field150Holder02052df8i(who, 9) == 0x4680) {
                self->message = 7;
            }
            return;
        }
        if (refusal & 0x10) {
            self->message = 6;
            return;
        }
        if (refusal & 2) {
            self->message = 4;
            return;
        }
        if (refusal & 1) {
            self->message = 3;
            return;
        }
        if (refusal & 4) {
            self->message = 1;
        }
        return;
    }

    short old = _Z28GetHalfwordEntryFromField150P22Field150Holder02052df8i(who, slot);
    if (old == (short)key) return;

    Item02157b74* oldItem = _Z24FindElementByKey020dedd0P17Container020dedd0i(self->items, old);
    if (oldItem != 0 && oldItem->cursed == 1) {
        self->message = 0xc;
        self->dirty |= 0x8000;
        return;
    }

    if (slot >= 0) {
        if (old == 0x4680) {
            if (func_ov005_0215840c(self, who->id) != 0) {
                self->message = 0xe;
            }
        }
        func_02052d7c(who, slot, (unsigned short)key);
        void* model = _Z15GetFieldAt0x150Ph(who);
        func_0208358c(model, item, -1);
        func_02083e28(model, 0);
        func_ov017_021c9e00(who->id, 0, 0, 1);
        if (item->equipType == 7) {
            _Z23SetPtrFieldByte021583fcP14Holder021583fcc(who, 1);
        }
        _Z28DispatchByIdxAndCond021551fcPchi(self, _Z19GetField1c_021a193cPi(*(int*)(func_ov017_0218b5b0() + 0x3708))->actor, 1);
    }

    if (kind == 0x62) {
        Linked02157b74* linked = _Z26Forward10BitFields020deda4iiP14Fields020deda4(self->items, 0x61, item);
        if (linked != 0) {
            _Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c(who)->linkedId = linked->id;
        }
    }

    if (item->cursed == 1) {
        if (self->message == 0xe) {
            self->nextMessage = 0xe;
        }
        self->message = 0xd;
        self->dirty |= 0x8000;
        _Z16TrySetFlags0x130Pht(who, 4);
        func_ov017_021c9e00(actor, 0, 0, 1);
    }

    if (item->def->sound == 1) {
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(data_02108760, 3, 0);
    } else if (item->def->sound == 2) {
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(data_02108760, 4, 0);
    }

    ctx->flags |= 4;

    unsigned char category = data_ov005_0215cd30[self->tab];
    signed char newCount = func_0207c7a0(bag + 0x1d4, key, category);
    signed char oldCount = func_0207c7a0(bag + 0x1d4, old, category);
    if (newCount == 1 && oldCount == 0) {
        int index = _Z33FindEntryIndexInKeyedList0207caa4P17KeyedList0207caa4ii(bag + 0x1d4, key, category);
        _Z33DecrementKeyedStackAmount0207c484P17KeyedList0207c484iii(bag + 0x1d4, key, 1, category);
        if (index >= 0) {
            _Z27SetEntryInKeyedList0207cb38P17KeyedList0207cb38iiic(bag + 0x1d4, index, category, old, 1);
        } else {
            func_0207c378(bag + 0x1d4, old, 1, category);
        }
    } else {
        _Z33DecrementKeyedStackAmount0207c484P17KeyedList0207c484iii(bag + 0x1d4, key, 1, category);
        func_0207c378(bag + 0x1d4, old, 1, category);
    }

    _Z13NoOp_021e4e1cv(ctx, actor, key, data_ov005_0215cd30[self->tab]);
    func_ov005_02155544(self);
    self->dirty |= 0x10;
    self->f3da8 = 0;
    self->f3dac = self->tab;
    self->selected = self->tab;
    func_ov005_02154d18(self->cursor, 0x85000, 0x17000);
    func_ov005_02154d50(self->cursor, 0x76000, 0x16000);
    func_ov005_021555c0(self);
    for (int i = 8; i < 0x18; i++) {
        if (old == self->entries[i].id && self->entries[i].state == 1) {
            self->dirty |= 0x40;
            self->f3daa = 0;
            break;
        }
    }
    self->dirty |= 0x200;
    self->dirty |= 1;
}

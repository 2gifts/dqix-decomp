#include <globaldefs.h>
#if defined(jpn)
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif

struct Container020e0310;
struct GameState;

struct NameParts02176634 {
    char* singular;
    char* plural;
    unsigned int flags;
};

struct Formatter02176634 {
    NameParts02176634* target;
    char pad4[0x10 - 0x4];
    NameParts02176634* subject;
    char pad14[0x18 - 0x14];
    NameParts02176634* item;
    char pad1c[LOW_REGION(0x28,0x5c) - 0x1c];
    char* textBuffer;
#if defined(jpn)
    char* GetTextBuffer() const { char* value = textBuffer; return value; }
#endif
};

struct Window02176634 {
    char pad0[0xa0];
    short left;
    short top;
    short x;
    short y;
    short field_0xa8;
    short field_0xaa;
    short field_0xac;
    short field_0xae;
    unsigned char field_0xb0;
    unsigned char id;
};

struct Menu02176634 {
    char pad0[0x70];
    signed char slots[0xb8 - 0x70];
    char messages[0x188 - 0xb8];
    Window02176634 window;
    char pad23a[LOW_REGION(0x1fa3,0x1d6b) - 0x188 - sizeof(Window02176634)];
    signed char slot;
    char pad1d6c[0x1d7a - 0x1d6c];
    unsigned char dispatched;
};

struct Entry02176634 {
    char pad0[0x1e];
    short cursor;
    char pad20[0x44 - 0x20];
    int x;
    int y;
    int combatantId;
};

struct Skill02176634 {
    unsigned int field_00;
    unsigned int skill : 12;
    unsigned int field_04 : 20;
    char pad8[0x2c - 0x8];
    unsigned int field_2c_0 : 10;
    unsigned int kind : 4;
    unsigned int field_2c_14 : 18;
};

struct Item02176634 {
    void* def;
    int f4;
    unsigned int category : 4;
    unsigned int rank : 5;
    unsigned int pad1 : 9;
    unsigned int cursed : 1;
    unsigned int pad2 : 13;
    char padc[0x18 - 0xc];
    short id;
};

struct Node02176634 {
    char pad0[0x4c];
    int combatantId;
};

struct Stats02176634 {
    char pad0[0x14];
    unsigned int flags;
};

struct Combatant02176634 {
#if defined(jpn)
    char pad0[0x134];
    char* name;
    char* GetName() const { char* value = name; return value; }
#else
    char pad0[0x138];
#endif
    Stats02176634* stats;
};

struct PartyData02176634 {
    char pad0[0xa8];
    unsigned int flags;
};

extern "C" void func_ov000_02177184(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_02177454(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_0217768c(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_021779b4(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_02177bf0(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_02177e50(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_02178074(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_021784d4(Menu02176634*, Entry02176634*, int, int);
struct Struct02170fd0;
void CallHandlerIfF38Set02170fd0(Struct02170fd0*, int);
extern "C" void func_ov000_021787b8(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_02178ba8(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_02179018(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_021794cc(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_0217992c(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_02179b70(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_02179f94(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_0217a514(Menu02176634*, Entry02176634*, int, int);
Formatter02176634* GetGlobalField0x1c020421a0();
extern "C" void func_02046380(Formatter02176634*);
extern "C" void __clear(void*, int);
void Clear12Bytes020e46c4(void*);
extern "C" void* memset(void*, int, unsigned int);
void InitObjFromCombatantId020e4bf4(void*, int);
char* GetFieldByKey020e0434(Container020e0310*, int);
struct Obj02046574;
void SetIndexedName02046574(Obj02046574*, int, char*);
extern "C" Node02176634* func_ov000_02161318(Menu02176634*, int);
Skill02176634* GetBoundedField420_0217199c(void*, int);
int GetAdjustedByteField0x1d6b(void*);
Item02176634* FindElementByComputedKey021815e4(char*);
extern "C" GameState* _ZN9GameState11GetInstanceEv();
char* GetPtrField0x2a04(GameState*);
Combatant02176634* GetCombatantWithFlag0x100(GameState*, int);
PartyData02176634* GetFieldAt0x150(unsigned char*);
struct Outer_02054000;
Item02176634* GetActiveSub_02054000(Outer_02054000*);
void DispatchIfCountPositive020dcf7c(int, void*);
void ResetAndDispatchActorContext0209c6d8(void*, short);
extern "C" void func_0207c378(char*, short, int, int);
extern "C" void func_02052d7c(Combatant02176634*, int, short);
struct KeyedList0207c484;
void DecrementKeyedStackAmount0207c484(KeyedList0207c484*, int, int, int);
void TrySetFlags0x130(unsigned char*, unsigned short);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void func_02046608(Formatter02176634*, int, char*, char*, int, int, int);
extern "C" void func_ov000_0217ab8c(Entry02176634*, int, int);
#if defined(jpn)
extern "C" void func_0205d304(Window02176634*, char*, int, int, int, int, int);
extern "C" void func_0203bdf4(void*, char*);
extern "C" int func_020dd4c4(int, Item02176634*);
extern "C" void func_020474a8(Formatter02176634*, int, char*, char*);
int AppendString02042058(char*, const char*);
extern unsigned int data_ov000_02184550[];
#else
extern "C" void func_0205d304(Window02176634*, char*, int, int, int, int, int, int);
#endif

struct MessagePair02176634 {
    unsigned short key;
    short message;
};

extern MessagePair02176634 data_ov000_0218352a[];
extern MessagePair02176634 data_ov000_0218352c[];
extern char data_02109bf4[];

// USA: func_ov000_02176634
extern "C" ARM void func_ov000_02176634(Menu02176634* menu, Entry02176634* entry, int mode, int a, int b) {
#if defined(jpn)
    char* buf;
#endif
    int x;
    int y;
    short left;
    short top;
    Item02176634* elem;
    char* bag;
    Combatant02176634* combatant;
    PartyData02176634* data;
    short item;
    int handled;
#if !defined(jpn)
    char* buf;
#endif
    int combatantId;
    if (mode < 0 || entry == NULL) {
        return;
    }
    x = entry->x;
    y = entry->y;
    switch (mode) {
    case 1:
        func_ov000_02177184(menu, entry, a, b);
        return;
    case 2:
        func_ov000_02177454(menu, entry, a, b);
        return;
    case 3:
        func_ov000_0217768c(menu, entry, a, b);
        return;
    case 4:
        func_ov000_021779b4(menu, entry, a, b);
        return;
    case 5:
        func_ov000_02177bf0(menu, entry, a, b);
        return;
    case 6:
        func_ov000_02177e50(menu, entry, a, b);
        return;
    case 7:
        func_ov000_02178074(menu, entry, a, b);
        return;
    case 8:
        func_ov000_021784d4(menu, entry, a, b);
        return;
    case 13:
        CallHandlerIfF38Set02170fd0((Struct02170fd0*)entry, 0);
        return;
    case 14:
        func_ov000_021787b8(menu, entry, a, b);
        return;
    case 15:
        func_ov000_02178ba8(menu, entry, a, b);
        return;
    case 16:
        func_ov000_02179018(menu, entry, a, b);
        return;
    case 17:
        func_ov000_021794cc(menu, entry, a, b);
        return;
    case 18:
    case 19:
    case 20:
        func_ov000_0217992c(menu, entry, a, b);
        return;
    case 21:
        func_ov000_02179b70(menu, entry, a, b);
        return;
    case 23:
        func_ov000_02179f94(menu, entry, a, b);
        return;
    case 25:
        func_ov000_0217a514(menu, entry, a, b);
        return;
    }

    Formatter02176634* formatter = GetGlobalField0x1c020421a0();
    func_02046380(formatter);
#if defined(jpn)
    char name[0x20];
    __clear(name, 0x20);
    int kind;
    buf = GetGlobalField0x1c020421a0()->GetTextBuffer();
    memset(buf, 0, 0x800);
    memset(buf, 0, 0x800);
    func_0203bdf4((char*)entry + 0x88, name);
    left = (x >> 3) + 9;
    top = (short)(y >> 3) + 1;
    switch (mode) {
    case 0xc:
        kind = 0xc;
        AppendString02042058(buf, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7554));
        break;
    case 0x29:
        kind = 0x29;
        SetIndexedName02046574((Obj02046574*)formatter, 1, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7558));
        func_020474a8(formatter, 10, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7555), buf);
        break;
    case 0x2a:
        kind = 0x2a;
        SetIndexedName02046574((Obj02046574*)formatter, 1, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7557));
        func_020474a8(formatter, 10, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7555), buf);
        break;
    case 0x2b: {
        Node02176634* node = func_ov000_02161318(menu, menu->slots[menu->slot]);
        if (node != NULL) {
            memset(name, 0, 0x20);
            func_0203bdf4((char*)node + 0x88, name);
        }
        kind = 0x2b;
        SetIndexedName02046574((Obj02046574*)formatter, 0, name);
        func_020474a8(formatter, 10, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x23), buf);
        break;
    }
    case 0x1a: {
        short msgId = 0x7544;
        Skill02176634* skill = GetBoundedField420_0217199c(entry, entry->cursor);
        if (skill != NULL && skill->kind == 6) msgId = 0x22;
        kind = 0x1a;
        AppendString02042058(buf, GetFieldByKey020e0434((Container020e0310*)menu->messages, msgId));
        break;
    }
    case 0x1b:
        kind = 0x1b;
        SetIndexedName02046574((Obj02046574*)formatter, 0, name);
        SetIndexedName02046574((Obj02046574*)formatter, 1, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7545));
        func_020474a8(formatter, 10, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7547), buf);
        break;
    case 0x1c:
        kind = 0x1c;
        SetIndexedName02046574((Obj02046574*)formatter, 0, name);
        SetIndexedName02046574((Obj02046574*)formatter, 1, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7546));
        func_020474a8(formatter, 10, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7547), buf);
        break;
    case 0x1d:
        kind = 0x1d;
        SetIndexedName02046574((Obj02046574*)formatter, 0, name);
        func_020474a8(formatter, 10, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7548), buf);
        break;
    case 0x1e: {
        short msgId = 0x18;
        Skill02176634* skill = GetBoundedField420_0217199c(entry, entry->cursor);
        if (skill != NULL) {
            for (int i = 0; data_ov000_0218352a[i].key != 0; i++) {
                if (data_ov000_0218352a[i].key == skill->skill) {
                    msgId = data_ov000_0218352c[i].key;
                    break;
                }
            }
        }
        kind = 0x1e;
        func_020474a8(formatter, 10, GetFieldByKey020e0434((Container020e0310*)menu->messages, msgId), buf);
        break;
    }
    case 0x1f: {
        Item02176634* selected = FindElementByComputedKey021815e4((char*)menu);
        int flags = func_020dd4c4(GetAdjustedByteField0x1d6b(menu), selected);
        short msgId = 0x1a;
        for (unsigned char i = 0; data_ov000_02184550[i] != 0; i++) {
            if (flags & data_ov000_02184550[i]) {
                msgId = (short)(i + 0x1a);
                break;
            }
        }
        kind = 0x1f;
        func_020474a8(formatter, 10, GetFieldByKey020e0434((Container020e0310*)menu->messages, msgId), buf);
        break;
    }
    case 0x20: {
        menu->dispatched = 0;
        short msgId = 0x14;
        combatantId = GetAdjustedByteField0x1d6b(menu);
        elem = FindElementByComputedKey021815e4((char*)menu);
        GameState* gs = _ZN9GameState11GetInstanceEv();
        bag = GetPtrField0x2a04(gs);
        combatant = GetCombatantWithFlag0x100(gs, combatantId);
        data = GetFieldAt0x150((unsigned char*)combatant);
        Item02176634* sub = GetActiveSub_02054000((Outer_02054000*)combatant);
        kind = 0x20;
        item = elem->id;
        SetIndexedName02046574((Obj02046574*)formatter, 0, combatant->GetName());
        SetIndexedName02046574((Obj02046574*)formatter, 1, (char*)elem->f4);

        if (sub != NULL && elem->id == sub->id) {
            msgId += 2;
            item = -1;
        }
        handled = 0;
        if (sub != NULL && sub->id > 0 && sub->category == 0 && sub->rank <= 0xb && sub->cursed) {
            handled = 1;
            msgId = 0x25;
            SetIndexedName02046574((Obj02046574*)formatter, 1, (char*)sub->f4);
            ResetAndDispatchActorContext0209c6d8(data_02109bf4, 0x3d);
            menu->dispatched = 1;
        }
        if (handled == 0) {
            if (sub != NULL) {
                func_0207c378(bag + 0x1d4, sub->id, 1, sub->category);
            }
            func_02052d7c(combatant, 7, item);
            DecrementKeyedStackAmount0207c484((KeyedList0207c484*)(bag + 0x1d4), item, 1, 0);
            if (combatant->stats->flags & 1) msgId++;
            if (elem->cursed) {
                msgId = 0x24;
                TrySetFlags0x130((unsigned char*)combatant, 4);
                data->flags |= 4;
                func_ov017_021c9e00(combatantId, 0, 0, 1);
                ResetAndDispatchActorContext0209c6d8(data_02109bf4, 0x3d);
                menu->dispatched = 1;
            }
        }
        func_020474a8(formatter, 10, GetFieldByKey020e0434((Container020e0310*)menu->messages, msgId), buf);
        break;
    }
    case 0x25:
        kind = 0x25;
        SetIndexedName02046574((Obj02046574*)formatter, 0, name);
        SetIndexedName02046574((Obj02046574*)formatter, 1, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7545));
        func_020474a8(formatter, 10, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7555), buf);
        break;
    case 0x26:
        kind = 0x26;
        SetIndexedName02046574((Obj02046574*)formatter, 0, name);
        SetIndexedName02046574((Obj02046574*)formatter, 1, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7546));
        func_020474a8(formatter, 10, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7555), buf);
        break;
    case 0x27:
        kind = 0x27;
        SetIndexedName02046574((Obj02046574*)formatter, 0, name);
        SetIndexedName02046574((Obj02046574*)formatter, 1, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7556));
        func_020474a8(formatter, 10, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7555), buf);
        break;
    case 0x28:
        kind = 0x28;
        SetIndexedName02046574((Obj02046574*)formatter, 1, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7559));
        func_020474a8(formatter, 10, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7555), buf);
        break;
    default:
        return;
    }

#else
    char singular[0x80];
    char plural[0x80];
    __clear(singular, 0x80);
    __clear(plural, 0x80);
    NameParts02176634 targetName;
    NameParts02176634 itemName;
    Clear12Bytes020e46c4(&itemName);
    itemName.singular = singular;
    itemName.plural = plural;
    int kind;
    short msgId = 0x7554;
    buf = GetGlobalField0x1c020421a0()->textBuffer;
    memset(buf, 0, 0x960);
    memset(buf, 0, 0x960);
    InitObjFromCombatantId020e4bf4(&targetName, entry->combatantId);
    left = (x >> 3) + 9;
    top = (short)(y >> 3) + 1;
    formatter->target = &targetName;
    formatter->subject = &targetName;

    switch (mode) {
    case 0xc:
        kind = 0xc;
        break;
    case 0x29:
        kind = 0x29;
        SetIndexedName02046574((Obj02046574*)formatter, 1, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7558));
        msgId = 0x7555;
        break;
    case 0x2a:
        kind = 0x2a;
        SetIndexedName02046574((Obj02046574*)formatter, 1, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7557));
        msgId = 0x7555;
        break;
    case 0x2b: {
        Node02176634* node = func_ov000_02161318(menu, menu->slots[menu->slot]);
        if (node != NULL) {
            InitObjFromCombatantId020e4bf4(&targetName, node->combatantId);
        }
        kind = 0x2b;
        msgId = 0x23;
        break;
    }
    case 0x1a: {
        msgId = 0x7544;
        Skill02176634* skill = GetBoundedField420_0217199c(entry, entry->cursor);
        if (skill != NULL && skill->kind == 6) {
            msgId = 0x22;
        }
        kind = 0x1a;
        break;
    }
    case 0x1b:
        kind = 0x1b;
        SetIndexedName02046574((Obj02046574*)formatter, 1, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7545));
        msgId = 0x7547;
        break;
    case 0x1c:
        kind = 0x1c;
        SetIndexedName02046574((Obj02046574*)formatter, 1, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7546));
        msgId = 0x7547;
        break;
    case 0x1d:
        kind = 0x1d;
        msgId = 0x7548;
        break;
    case 0x1e: {
        msgId = 0x18;
        Skill02176634* skill = GetBoundedField420_0217199c(entry, entry->cursor);
        if (skill != NULL) {
            for (int i = 0; data_ov000_0218352a[i].key != 0; i++) {
                if (data_ov000_0218352a[i].key == skill->skill) {
                    msgId = data_ov000_0218352c[i].key;
                    break;
                }
            }
        }
        kind = 0x1e;
        break;
    }
    case 0x20: {
        menu->dispatched = 0;
        msgId = 0x14;
        combatantId = GetAdjustedByteField0x1d6b(menu);
        elem = FindElementByComputedKey021815e4((char*)menu);
        GameState* gs = _ZN9GameState11GetInstanceEv();
        bag = GetPtrField0x2a04(gs);
        combatant = GetCombatantWithFlag0x100(gs, combatantId);
        data = GetFieldAt0x150((unsigned char*)combatant);
        Item02176634* sub = GetActiveSub_02054000((Outer_02054000*)combatant);
        kind = 0x20;
        item = elem->id;
        InitObjFromCombatantId020e4bf4(&targetName, combatantId);
        if (sub != NULL && elem->id == sub->id) {
            msgId += 2;
            item = -1;
        }
        handled = 0;
        if (sub != NULL && sub->id > 0 && sub->category == 0 && sub->rank <= 0xb && sub->cursed) {
            handled = 1;
            msgId = 0x25;
            DispatchIfCountPositive020dcf7c(sub->id, &itemName);
            formatter->item = &itemName;
            ResetAndDispatchActorContext0209c6d8(data_02109bf4, 0x3d);
            menu->dispatched = 1;
        }
        if (handled == 0) {
            if (sub != NULL) {
                func_0207c378(bag + 0x1d4, sub->id, 1, sub->category);
            }
            if (item < 0) {
                DispatchIfCountPositive020dcf7c(sub->id, &itemName);
            } else {
                DispatchIfCountPositive020dcf7c(item, &itemName);
            }
            formatter->item = &itemName;
            func_02052d7c(combatant, 7, item);
            DecrementKeyedStackAmount0207c484((KeyedList0207c484*)(bag + 0x1d4), item, 1, 0);
            if (combatant->stats->flags & 1) {
                msgId++;
            }
            if (elem->cursed) {
                msgId = 0x24;
                TrySetFlags0x130((unsigned char*)combatant, 4);
                data->flags |= 4;
                func_ov017_021c9e00(combatantId, 0, 0, 1);
                ResetAndDispatchActorContext0209c6d8(data_02109bf4, 0x3d);
                menu->dispatched = 1;
            }
        }
        break;
    }
    case 0x25:
        kind = 0x25;
        SetIndexedName02046574((Obj02046574*)formatter, 1, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7545));
        msgId = 0x7555;
        break;
    case 0x26:
        kind = 0x26;
        SetIndexedName02046574((Obj02046574*)formatter, 1, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7546));
        msgId = 0x7555;
        break;
    case 0x27:
        kind = 0x27;
        SetIndexedName02046574((Obj02046574*)formatter, 1, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7556));
        msgId = 0x7555;
        break;
    case 0x28:
        kind = 0x28;
        SetIndexedName02046574((Obj02046574*)formatter, 1, GetFieldByKey020e0434((Container020e0310*)menu->messages, 0x7559));
        msgId = 0x7555;
        break;
    default:
        return;
    }

    func_02046608(formatter, 10, GetFieldByKey020e0434((Container020e0310*)menu->messages, msgId), buf, 0xa4, 0, 0);
#endif
    func_ov000_0217ab8c(entry, a, b);
    Window02176634* window = &menu->window;
    window->left = 8;
    window->top = 7;
    window->x = left;
    window->y = top;
    window->field_0xa8 = 10;
    window->field_0xaa = 4;
    window->field_0xac = 10;
    window->field_0xae = 0x11;
    window->id = kind;
#if defined(jpn)
    func_0205d304(window, buf, 0, 1, 0, 1, 0);
#else
    func_0205d304(window, buf, 0, 1, 0, 1, 0, 0);
    func_02046380(formatter);
#endif
}

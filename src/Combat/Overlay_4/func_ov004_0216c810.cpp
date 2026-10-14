#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj0205e9f4;
struct Actor0209c3b4;
struct TableA68;
struct Struct0200fb08;
struct Obj_02184ad8;

void SetModeClamped0209ca70(void* obj, int val);
void SetStateAndDispatch0205e9f4(struct Obj0205e9f4* obj, int state);
void SetStateAndDispatch0209c3b4(struct Actor0209c3b4* actor, int val);
void SetByte0x7f70(void* obj, unsigned char value);
void* SetFieldAndClearBufferIfType7_0216b1c4(void* a, int id);
void* GetNodeIfType6_0216ae9c(void* a, int id);
unsigned char NormalizeField5_0200fb08(struct Struct0200fb08* obj);
void SetField1c8True_02184ad8(struct Obj_02184ad8* obj);
void* FindEntryByKey(struct TableA68* table, int key);

class UiNode0216c810 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16();
    virtual void SetPalette(int pal);
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30();
    virtual void SetColor(int color);
    char pad4[8];
    unsigned char flagsC;
};

struct MessageWindow0216c810 {
    char pad0[0x998];
    int busy;
    char pad99c[0x19af - 0x99c];
    unsigned char flag19af;
    char pad19b0[0x19ca - 0x19b0];
    unsigned char flag19ca;
};

struct BattleState0216c810 {
    char pad0[0x7f73];
    unsigned char pendingCount;
};

struct Bytes6 {
    unsigned char v[6];
};

struct MenuState02171034 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char flag2;
    unsigned char state3;
    unsigned char byte4;
    char pad5[5];
    unsigned short messageId;
    int cursorY;
};

extern "C" void* func_ov011_021849c8(void* a);
extern "C" UiNode0216c810* func_ov023_021f6880(void* list, int key);
extern "C" int func_ov023_021f6f10(void* node);
extern "C" void func_ov011_021848a0(void* a, int val);
extern "C" void func_ov004_0216b498(void* a, int mode, int sub);
extern "C" int func_ov004_0216b2c8(void* obj, int id, int a, int b);
extern "C" void func_ov004_0216b20c(void* a0, int key, int b, int c);
extern "C" void func_ov023_021f9ba8(void* node, unsigned short count);
extern "C" struct TableA68* func_ov023_021fa598(void* node);
MessageWindow0216c810* GetGlobalField0x1c020421a0();
extern "C" void func_0204500c(MessageWindow0216c810* win, void* entry, int a, int b);
extern "C" void func_ov023_021f8120(void* node);
extern "C" void func_ov023_021f7eb8(void* node, void* a, int buf, int mode, int a5, int a6, int a7, int a8, int a9, int a10);
extern "C" void func_ov004_0216ba70(void* a);

extern char data_02109bf4[];
extern struct Obj0205e9f4 data_02108760;
extern MenuState02171034 data_ov004_02171034;
extern Bytes6 data_ov004_02170174;

// USA: func_ov004_0216c810
extern "C" ARM int func_ov004_0216c810(void* a) {
    GameState* gs;
    BattleState0216c810* bs;
    int mode;
    int sub;
    int msg;
    UiNode0216c810* node;

    SetModeClamped0209ca70(data_02109bf4, 3);
    SetStateAndDispatch0205e9f4(&data_02108760, 3);
    data_ov004_02171034.byte4 = 3;
    data_ov004_02171034.byte1 = 3;
    data_ov004_02171034.messageId = 0;
    if (data_ov004_02171034.state3 != 4) {
        SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)data_02109bf4, 2);
    }
    gs = GameState::GetInstance();
    GetPtrField0x2a04(gs);
    mode = 0;
    sub = 0;
    data_ov004_02171034.flag2 = 0;
    func_ov023_021f6880(func_ov011_021849c8(a), 0xb)->flagsC |= 8;

    if (data_ov004_02171034.state3 == 0) {
        func_ov023_021f6880(func_ov011_021849c8(a), 1)->flagsC |= 8;
        func_ov011_021848a0(a, 0xc9);
        return 0;
    } else if (data_ov004_02171034.state3 == 1) {
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0xc);
        if (node) node->flagsC &= ~8;
        mode = 1;
        sub = 0;
        msg = 0x12e;
        SetFieldAndClearBufferIfType7_0216b1c4(a, msg);
        data_ov004_02171034.messageId = msg;
        func_ov004_0216b498(a, mode, sub);
        for (int i = 0; i < 3; i++) {
            func_ov004_0216b2c8(a, msg, i + 0x32, i);
        }
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0x32);
        if (node) {
            node->SetPalette(8);
            node->SetColor(8);
        }
        func_ov004_0216b20c(a, 0x33, 0x96, 0);
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0x34);
        if (node) {
            node->SetPalette(0xa);
            node->SetColor(0xa);
        }
        bs = (BattleState0216c810*)gs;
        int count = bs->pendingCount;
        if (count > 0) {
            UiNode0216c810* found = func_ov023_021f6880(func_ov011_021849c8(a), 0x12e);
            UiNode0216c810* counter;
            if (found == 0) {
                counter = 0;
            } else if (func_ov023_021f6f10(found) != 7) {
                counter = 0;
            } else {
                counter = found;
            }
            if (counter) {
                func_ov023_021f9ba8(counter, count);
            }
            bs->pendingCount = 0;
        }
    } else if (data_ov004_02171034.state3 == 2) {
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0xc);
        if (node) node->flagsC &= ~8;
        mode = 2;
        sub = 0;
        msg = 0x12d;
        SetFieldAndClearBufferIfType7_0216b1c4(a, msg);
        data_ov004_02171034.messageId = msg;
        func_ov004_0216b498(a, mode, sub);
        for (int i = 0; i < 2; i++) {
            func_ov004_0216b2c8(a, msg, i + 0x32, i);
        }
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0x32);
        if (node) {
            node->SetPalette(5);
            node->SetColor(5);
        }
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0x33);
        if (node) {
            node->SetPalette(0xa);
            node->SetColor(0xa);
        }
    } else if (data_ov004_02171034.state3 == 3) {
        mode = 3;
        msg = 0x12c;
        SetFieldAndClearBufferIfType7_0216b1c4(a, msg);
        data_ov004_02171034.messageId = msg;
        func_ov004_0216b498(a, mode, sub);
        func_ov004_0216b2c8(a, msg, 0x32, sub);
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0x32);
        if (node) {
            node->SetPalette(8);
            node->SetColor(8);
        }
    } else if (data_ov004_02171034.state3 == 4) {
        SetByte0x7f70(gs, 0);
        func_ov011_021848a0(a, 0x190);
        return 0;
    } else if (data_ov004_02171034.state3 == 5) {
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0xc);
        if (node) node->flagsC &= ~8;
        mode = 1;
        sub = 0;
        msg = 0x12e;
        SetFieldAndClearBufferIfType7_0216b1c4(a, msg);
        data_ov004_02171034.messageId = msg;
        func_ov004_0216b498(a, mode, sub);
        for (int i = 0; i < 3; i++) {
            func_ov004_0216b2c8(a, msg, i + 0x32, i);
        }
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0x32);
        if (node) {
            node->SetPalette(0);
            node->SetColor(0);
        }
        func_ov004_0216b20c(a, 0x33, 0x96, 0);
        node = func_ov023_021f6880(func_ov011_021849c8(a), 0x34);
        if (node) {
            node->SetPalette(0xa);
            node->SetColor(0xa);
        }
    } else if (data_ov004_02171034.state3 == 6) {
        SetByte0x7f70(gs, 0);
        void* list = func_ov011_021849c8(a);
        UiNode0216c810* box = func_ov023_021f6880(list, 1);
        if (box == 0) return 0;
        if (func_ov023_021f6f10(box) != 0xb) return 0;
        box->flagsC |= 8;
        UiNode0216c810* text = func_ov023_021f6880(list, 0x192);
        if (text == 0) return 0;
        if (func_ov023_021f6f10(text) != 4) return 0;
        struct TableA68* table = func_ov023_021fa598(text);
        MessageWindow0216c810* win = GetGlobalField0x1c020421a0();
        win->busy = 1;
        func_0204500c(win, FindEntryByKey(table, 0x5dc), 0, 0xe3);
        win->flag19ca = 0;
        win->flag19af = 0;
        SetByte0x7f70(gs, 0);
        return 0;
    } else if (data_ov004_02171034.state3 == 7) {
        SetByte0x7f70(gs, 0);
        func_ov011_021848a0(a, 0x258);
        return 0;
    }

    SetField1c8True_02184ad8((struct Obj_02184ad8*)a);
    int y;
    void* panel = GetNodeIfType6_0216ae9c(a, 0xd2);
    func_ov023_021f8120(panel);
    y = 0x60;
    unsigned char kind = NormalizeField5_0200fb08((struct Struct0200fb08*)GameState::GetInstance());
    Bytes6 rows = data_ov004_02170174;
    int n;
    switch (mode) {
    case 0:
        func_ov023_021f7eb8(panel, a, y, 1, 1, 0x12, 5, 0, 1, 0);
        y += 0xb40;
        break;
    case 1:
        switch (sub) {
        case 0:
            n = rows.v[kind];
            func_ov023_021f7eb8(panel, a, y, 1, 1, n, 6, 0, 1, 0);
            y += n * 0xc0;
            break;
        default:
            n = rows.v[kind];
            func_ov023_021f7eb8(panel, a, y, 1, 1, n, 6, 0, 1, 0);
            y += n * 0xc0;
            break;
        }
        break;
    case 2:
        n = rows.v[kind];
        func_ov023_021f7eb8(panel, a, y, 1, 1, n, 5, 0, 1, 0);
        y += n * 0xa0;
        break;
    case 3:
        func_ov023_021f7eb8(panel, a, y, 1, 1, 0xc, 3, 0, 1, 0);
        y += 0xb40;
        break;
    }
    data_ov004_02171034.cursorY = y;
    SetField1c8True_02184ad8((struct Obj_02184ad8*)a);
    if (mode == 1 && data_ov004_02171034.state3 != 5) {
        func_ov004_0216ba70(a);
    }
    return 0;
}

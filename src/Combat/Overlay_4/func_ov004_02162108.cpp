#include <globaldefs.h>

struct MenuState02162108 {
    unsigned char pad0[6];
    signed char field6;
    unsigned char field7;
    unsigned char pad8[3];
    signed char fieldB;
    char* textBuf;
    unsigned char pad10[0xc];
    int combatantId;
};

struct MenuEntry02162108 {
    short ids[7];
    unsigned char vals[7];
    unsigned char active;
};

struct MenuPage02162108 {
    struct MenuEntry02162108 entries[26];
    unsigned char cursor;
    unsigned char pad23d[2];
    unsigned char count;
};

class Node02162108 {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0c();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1c();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2c();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3c();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4c();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5c();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6c();
    virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7c();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8c();
    virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9c();
    virtual void vfa0(); virtual void vfa4(); virtual void vfa8(); virtual void vfac();
    virtual void vfb0(); virtual void vfb4(); virtual void vfb8(); virtual void vfbc();
    virtual void vfc0(); virtual void vfc4(); virtual void vfc8(); virtual void vfcc();
    virtual void vfd0(); virtual void vfd4();
    virtual void SetState(int arg);

    unsigned char pad4[8];
    unsigned char flags;
    unsigned char padd[0x13];
    void* data;
};

struct TableA68;

extern "C" void memset(void* dst, int value, int size);
extern "C" void __clear(void* buf, int n);
extern "C" void* func_ov011_021849c8(void* self);
extern "C" Node02162108* func_ov004_0215e47c(void* a, int key);
extern "C" void func_ov004_0215e574(void* a, unsigned short key, int c, int d, int e);
void SetField38IfState8_0215e49c(void*, int, int);
extern "C" Node02162108* func_ov023_021f6880(void* list, int key);
extern "C" int func_ov023_021f6f10(Node02162108* node);
extern "C" struct TableA68* func_ov023_021fa598(Node02162108* node);
extern "C" char* _Z23FindEntryByKey_02072a68P8TableA68i(struct TableA68* table, short key);
char* FindSubstring_020d2f88(char* str, char* sub);
int GetGlobalField0x1c020421a0(void);
extern "C" void func_02046608(int g, int mode, char* fmt, char* dst, int size, int a, int b);
void SetNodeFieldsAndMaybeNotify_0215f6f4(void* a, short v1, short v2, int flag);

extern struct MenuState02162108 data_ov004_021707e8;
extern struct MenuPage02162108 data_ov004_02170b90[];
extern struct MenuPage02162108 data_ov004_02170dd0;
extern int data_ov004_0216fe90[];
extern short data_ov004_02170818[];
extern unsigned char data_ov004_02170814[];
extern char data_ov004_02170527[];

// USA: func_ov004_02162108
extern "C" ARM int func_ov004_02162108(void* self) {
    int state;
    int btn;
    void* obj;
    int dim;
    int side;
    int j;
    int i;
    int st;
    int k;
    short id;
    Node02162108* node;
    int found;
    int idx;
    int next;
    unsigned char mark[2];
    struct MenuPage02162108* page;

    data_ov004_021707e8.field7 = 0x67;
    dim = 0;
    memset(data_ov004_021707e8.textBuf, 0, 0x800);
    obj = func_ov011_021849c8(self);
    if (data_ov004_021707e8.field6 == 0) {
        node = func_ov004_0215e47c(self, 3);
        if (node != 0) node->flags &= ~4;
    } else {
        node = func_ov004_0215e47c(self, 3);
        if (node != 0) node->flags |= 4;
    }
    func_ov004_0215e574(self, 0xc, 0xff, 0, 0);

    if (data_ov004_02170b90[1].count != 0) {
        for (i = 0xd; i < 0xf; i++) SetField38IfState8_0215e49c(self, i, 0x3a);
        for (i = 0xf; i < 0x1d; i++) SetField38IfState8_0215e49c(self, i, 0x11e);
        SetField38IfState8_0215e49c(self, 0x31, 0x3a);
        SetField38IfState8_0215e49c(self, 0x32, 0x3a);
        for (j = 0; j < 3; j++) {
            node = func_ov023_021f6880(obj, j + 0x65);
            if (node != 0) node->flags &= ~8;
        }
        func_ov004_0215e574(self, 0xc, 0xff, 0, 0);

        page = &data_ov004_02170dd0;
        if (page->count <= 1) page->cursor = 0;
        next = page->cursor;
        if (next >= 26) next = 0;
        side = 0;
        __clear(mark, 2);
        found = 0;
        for (i = next; i < 26; i++) {
            idx = data_ov004_0216fe90[i];
            if (!page->entries[idx - 1].active) continue;
            {
                int cid = data_ov004_021707e8.combatantId;
                int off;
                short* ids;
                st = 0xf;
                if (idx != data_ov004_02170818[cid] && idx <= 0xe) st = 3;
                if (idx == 0xd && data_ov004_02170814[cid] != 0) st = 0xf;
                if (st == 0xf) mark[side] = 1;
                id = side + 0xd;
                ids = page->entries[idx - 1].ids;
                SetField38IfState8_0215e49c(self, id, i + 0x19f);
                if (side == 0) {
                    func_ov004_0215e574(self, id, 0x80, 0, 0);
                } else {
                    func_ov004_0215e574(self, id, 0x80, 0x80, 0);
                }
                node = func_ov023_021f6880(obj, id);
                if (node != 0) node->SetState(st);

                for (k = 0; k < 7; k++) {
                    int key = ids[k];
                    short n;
                    Node02162108* msg;
                    if (key < 0) break;
                    n = k;
                    if (side == 0) {
                        id = n + 0xf;
                        off = 0;
                    } else {
                        id = n + 0x16;
                        off = 7;
                    }
                    msg = func_ov004_0215e47c(self, 0x320);
                    if (msg != 0 && func_ov023_021f6f10(msg) == 4) {
                        int indent;
                        char* text;
                        struct TableA68* table;
                        Node02162108* label;
                        table = func_ov023_021fa598(msg);
                        text = data_ov004_021707e8.textBuf + (k + off) * 0x80;
                        memset(text, 0, 0x80);
                        indent = 0;
                        if (FindSubstring_020d2f88(_Z23FindEntryByKey_02072a68P8TableA68i(table, key), data_ov004_02170527)) indent = 0x14;
                        func_02046608(GetGlobalField0x1c020421a0(), 0, _Z23FindEntryByKey_02072a68P8TableA68i(table, key), text, 0x78 - indent, 0, 0);
                        label = func_ov004_0215e47c(self, id);
                        if (label != 0 && func_ov023_021f6f10(label) == 8) label->data = text;
                    }
                    node = func_ov023_021f6880(obj, id);
                    if (node != 0) node->SetState(st);
                }
            }
            next = i + 1;
            found = 1;
            if (++side == 2) break;
        }
        if (found) {
            int avail = 0;
            for (; next < 26; next++) {
                if (page->entries[data_ov004_0216fe90[next] - 1].active) {
                    avail = 1;
                    break;
                }
            }
            if (!avail) next = 26;
            page->cursor = next;
        }
        if (mark[0] == 0 && mark[1] == 0) dim = 1;
    } else {
        void* obj2;
        for (i = 0xd; i < 0xf; i++) SetField38IfState8_0215e49c(self, i, 0x3a);
        for (i = 0xf; i < 0x1d; i++) SetField38IfState8_0215e49c(self, i, 0x11e);
        obj2 = func_ov011_021849c8(self);
        for (i = 0; i < 3; i++) {
            node = func_ov023_021f6880(obj2, i + 0x65);
            if (node != 0) node->flags |= 8;
        }
        SetField38IfState8_0215e49c(self, 0x31, 0x1e0);
        SetField38IfState8_0215e49c(self, 0x32, 0x1e3);
        func_ov004_0215e574(self, 0x31, 0xff, 0, 0);
        func_ov004_0215e574(self, 0x32, 0xff, 0, 0);
        if (data_ov004_021707e8.field6 == 0) {
            node = func_ov004_0215e47c(self, 3);
            if (node != 0) node->flags &= ~4;
        }
    }

    state = 0xf;
    if (dim) state = 3;
    node = func_ov023_021f6880(obj, 0xc);
    if (node != 0 && func_ov023_021f6f10(node) == 8) node->SetState(state);
    for (btn = 0; btn < 4; btn++) {
        node = func_ov023_021f6880(obj, btn + 0x64);
        if (node != 0 && func_ov023_021f6f10(node) == 0x13) node->SetState(state);
    }
    SetNodeFieldsAndMaybeNotify_0215f6f4(self, data_ov004_021707e8.fieldB, data_ov004_021707e8.field6, dim);
    return 0;
}

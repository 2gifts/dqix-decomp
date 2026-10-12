#include <globaldefs.h>

#if defined(jpn)
enum { field6=4,field7=6,field8=7,fieldB=8 };
#else
enum { field6=6,field7=7,field8=8,fieldB=0xb };
#endif

extern "C" void* func_ov011_021849c8(void* p);
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* _Z25GetCombatantWithFlag0x100P9GameStatei(void* gameState, int id);
extern int GetFieldAt0x150(unsigned char* obj);
extern "C" void _Z19ClearField00209a804Pi(int* field);
struct Ctx0209a810 { void* field0; };
extern "C" void _Z33SetupAndRunBufferedScript0209a810P11Ctx0209a810Pv(Ctx0209a810* ctx, void* value);
extern "C" void _Z27SetField38IfState8_0215e49cPvis(void* a, int key, int value);
extern "C" int _Z27CheckAfterTwoCalls_0215e460v(void);
extern "C" void func_ov004_0215e574(void* a, int key, int c, int d, int e);
extern "C" void _Z36SetNodeFieldsAndMaybeNotify_0215f6f4Pvssi(void* a, short v1, short v2, int flag);

struct TagNode02161514 {
    char pad0[0xc];
    unsigned char field0xc;
};
extern "C" TagNode02161514* func_ov004_0215e47c(void* a, int key);

class FNode02161514 {
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
};
extern "C" FNode02161514* func_ov023_021f6880(void* obj, int key);

struct Entry02161514 {
    unsigned short id;
    unsigned short level;
};
struct Buf02161514 {
    char pad[0x10c];
    Entry02161514 rows[13][20];
    int counts[13];
};

extern unsigned char data_ov004_021707e8;
extern int data_ov004_02170854[];
extern unsigned char data_ov004_0216fde8[];
extern unsigned char data_ov004_02170838[];
extern unsigned char data_ov004_02170820[];
#define D0 (&data_ov004_021707e8)
#define D1 (data_ov004_02170854)

// USA: func_ov004_02161514
extern "C" ARM int func_ov004_02161514(void* a) {
    Ctx0209a810 ctx;
    Buf02161514 buf;
    void* obj;
    int showAll;
    unsigned char flag;
    int t;
    unsigned char* field;
    unsigned int limit;
    int count;
    Entry02161514* rows;
    unsigned char cnt;
    int i;
    int j;
    unsigned char k;
    int same;
    FNode02161514* node;

    D0[field7] = 0x65;
    obj = func_ov011_021849c8(a);
    showAll = 0;
    flag = 0;
    if (D0[2] != D1[D0[field8]]) flag = 1;

    func_ov004_0215e47c(a, 3)->field0xc |= 4;

    t = D1[D0[field8]];
    if (t != 1 && t != 4 && t != 7) {
        unsigned char* combatant = (unsigned char*)_Z25GetCombatantWithFlag0x100P9GameStatei(_ZN9GameState11GetInstanceEv(), *(int*)(D0 + 0x1c));
        if (!combatant) return 0;
        field = (unsigned char*)GetFieldAt0x150(combatant);
        if (!field) return 0;
        limit = *(unsigned short*)(field + D1[D0[field8]] * 2 + 0x16c);
        _Z19ClearField00209a804Pi((int*)&ctx);
        _Z33SetupAndRunBufferedScript0209a810P11Ctx0209a810Pv(&ctx, &buf);
        count = buf.counts[D1[D0[field8]]];
        rows = buf.rows[D1[D0[field8]]];
        cnt = 0;

        for (i = 0xc; i < 0x30; i++) _Z27SetField38IfState8_0215e49cPvis(a, i, 0x3a);
        _Z27SetField38IfState8_0215e49cPvis(a, 0x31, 0x3a);
        _Z27SetField38IfState8_0215e49cPvis(a, 0x32, 0x3a);
        _Z27SetField38IfState8_0215e49cPvis(a, 0xc, 0x3b);
        _Z27SetField38IfState8_0215e49cPvis(a, 0xd, 1);
        if (_Z27CheckAfterTwoCalls_0215e460v()) {
            _Z27SetField38IfState8_0215e49cPvis(a, 0xe, 4);
        } else {
            _Z27SetField38IfState8_0215e49cPvis(a, 0xe, D1[D0[field8]] + 4);
        }

        if (D0[2] != D1[D0[field8]]) {
            for (k = 0; k < 3; k++) {
                node = func_ov023_021f6880(obj, k + 0xc);
                if (node) node->SetState(3);
            }
            node = func_ov023_021f6880(obj, 0x64);
            if (node) node->SetState(3);
        } else {
            for (k = 0; k < 3; k++) {
                node = func_ov023_021f6880(obj, k + 0xc);
                if (node) node->SetState(0xf);
            }
            node = func_ov023_021f6880(obj, 0x64);
            if (node) node->SetState(0xf);
        }

        for (i = 0; i < count; i++) {
            unsigned short id = rows[i].id;
            unsigned short level = rows[i].level;
            if (level != 0 && level <= limit) {
                int st;
                _Z27SetField38IfState8_0215e49cPvis(a, cnt + 0xf, id + 0x3f);
                st = 0xf;
                if (D0[2] != D1[D0[field8]]) st = 3;
                node = func_ov023_021f6880(obj, cnt + 0xf);
                if (node) node->SetState(st);
                cnt++;
            }
        }

        if (cnt == 0) {
            showAll = 1;
            for (j = 0xc; j < 0x30; j++) _Z27SetField38IfState8_0215e49cPvis(a, j, 0x3a);
            _Z27SetField38IfState8_0215e49cPvis(a, 0x31, 0x1e1);
            _Z27SetField38IfState8_0215e49cPvis(a, 0x32, 0x1e3);
            func_ov004_0215e574(a, 0x31, 0xff, 0, 0);
            func_ov004_0215e574(a, 0x32, 0xff, 0, 0);
            _Z27SetField38IfState8_0215e49cPvis(a, 0xc, 0x3b);
            _Z27SetField38IfState8_0215e49cPvis(a, 0xd, 1);
            if (_Z27CheckAfterTwoCalls_0215e460v()) {
                _Z27SetField38IfState8_0215e49cPvis(a, 0xe, 4);
            } else {
                _Z27SetField38IfState8_0215e49cPvis(a, 0xe, D1[D0[field8]] + 4);
            }
            same = 1;
            if (D0[2] != D1[D0[field8]]) same = 0;
            for (i = 0; i < 5; i++) {
                node = func_ov023_021f6880(obj, data_ov004_0216fde8[i]);
                if (node) {
                    if (same) node->SetState(0xf);
                    else node->SetState(3);
                }
            }
        }
    } else {
        int st;
        showAll = 1;
        for (j = 0xc; j < 0x30; j++) _Z27SetField38IfState8_0215e49cPvis(a, j, 0x3a);
        _Z27SetField38IfState8_0215e49cPvis(a, 0x31, 0x1e1);
        _Z27SetField38IfState8_0215e49cPvis(a, 0x32, 0x1e3);
        func_ov004_0215e574(a, 0x31, 0xff, 0, 0);
        func_ov004_0215e574(a, 0x32, 0xff, 0, 0);
        _Z27SetField38IfState8_0215e49cPvis(a, 0xc, 0x3b);
        _Z27SetField38IfState8_0215e49cPvis(a, 0xd, 1);
        if (_Z27CheckAfterTwoCalls_0215e460v()) {
            _Z27SetField38IfState8_0215e49cPvis(a, 0xe, 4);
        } else {
            _Z27SetField38IfState8_0215e49cPvis(a, 0xe, D1[D0[field8]] + 4);
        }
        same = 1;
        if (D0[2] != D1[D0[field8]]) same = 0;
        for (i = 0; i < 5; i++) {
            node = func_ov023_021f6880(obj, data_ov004_0216fde8[i]);
            if (node) {
                if (same) node->SetState(0xf);
                else node->SetState(3);
            }
        }
        st = 0xf;
        if (!same) st = 3;
        node = func_ov023_021f6880(obj, 0x64);
        if (node) node->SetState(st);
        if (*(signed char*)(D0 + field6) == 0) {
            TagNode02161514* tag = func_ov004_0215e47c(a, 3);
            if (tag) tag->field0xc &= ~4;
        }
    }

    if (showAll) {
        unsigned char n = 0;
        int m;
        for (m = 1; m < 0xd; m++) {
            if (data_ov004_02170838[m]) n++;
            if (n > 1) break;
        }
        if (n <= 1) func_ov004_0215e47c(a, 3)->field0xc &= ~4;
    }

    {
        int d;
        *(signed char*)(D0 + fieldB) = data_ov004_02170820[D1[D0[field8]] - 1];
        d = *(signed char*)(D0 + fieldB) - data_ov004_02170820[D0[2] - 1];
        if (d < 0) d += *(signed char*)(D0 + field6);
        *(signed char*)(D0 + fieldB) = d;
    }
    _Z36SetNodeFieldsAndMaybeNotify_0215f6f4Pvssi(a, *(signed char*)(D0 + fieldB), *(signed char*)(D0 + field6), flag);
    return 0;
}

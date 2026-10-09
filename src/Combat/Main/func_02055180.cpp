#include <globaldefs.h>

struct S02055080;

extern void* GetField0x4OrNull(struct S02055080* obj);
extern void* GetField0x4Field0x0OrNull(struct S02055080* obj);
extern void* GetField0x4Field0x4OrNull(struct S02055080* obj);
extern void* GetSubField0x8(struct S02055080* p);
extern void* GetSubField0xC(struct S02055080* p);
extern void* GetSubField0x18(struct S02055080* p);
extern void* GetField0x4Field0x1cOrNull(struct S02055080* obj);
extern void* GetField0x4Field0x20OrNull(struct S02055080* obj);
extern void* GetField0x4Field0x0Field0x0OrNull(struct S02055080* obj);
extern "C" void func_020546c8(struct S02055080* sl);

struct S02055080 {
    void* alloc;
    void* fieldSub;
};

struct Group9 {
    void* a[9];
};

struct Group2 {
    void* a[2];
};

struct Group1 {
    void* a[1];
};

struct Group4 {
    void* a[4];
};

struct Group3x3 {
    void* a[3];
    void* b[3];
    void* c[3];
};

#define RELOCATE(slot) (slot) = (char*)sl->fieldSub + (int)(slot)

// USA: func_02055180
extern "C" ARM int func_02055180(struct S02055080* sl, void* arg1, void* arg2, void* arg3) {
    if (arg1 == 0) {
        return 0;
    }
    if (arg2 == 0) {
        return 0;
    }
    if (arg3 == 0) {
        return 0;
    }

    sl->alloc    = arg1;
    sl->fieldSub = arg2;

    struct Group9* g9 = (struct Group9*)GetField0x4OrNull(sl);
    if (g9 == 0) {
        return 0;
    }
    for (int i = 0; i < 9; i++) {
        RELOCATE(g9->a[i]);
    }

    struct Group2* g2 = (struct Group2*)GetField0x4Field0x0OrNull(sl);
    if (g2 == 0) {
        return 0;
    }
    RELOCATE(g2->a[0]);
    RELOCATE(g2->a[1]);

    struct Group3x3* g3 = (struct Group3x3*)GetField0x4Field0x4OrNull(sl);
    if (g3 == 0) {
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        RELOCATE(g3->a[i]);
        RELOCATE(g3->b[i]);
        RELOCATE(g3->c[i]);
    }

    struct Group1* g1 = (struct Group1*)GetSubField0x8(sl);
    if (g1 == 0) {
        return 0;
    }
    RELOCATE(g1->a[0]);

    struct Group4* g4 = (struct Group4*)GetSubField0xC(sl);
    if (g4 == 0) {
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        RELOCATE(g4->a[i]);
    }

    struct Group2* g5 = (struct Group2*)GetSubField0x18(sl);
    if (g5 == 0) {
        return 0;
    }
    for (int i = 0; i < 2; i++) {
        RELOCATE(g5->a[i]);
    }

    struct Group2* g6 = (struct Group2*)GetField0x4Field0x1cOrNull(sl);
    if (g6 == 0) {
        return 0;
    }
    for (int i = 0; i < 2; i++) {
        RELOCATE(g6->a[i]);
    }

    struct Group2* g7 = (struct Group2*)GetField0x4Field0x20OrNull(sl);
    if (g7 == 0) {
        return 0;
    }
    RELOCATE(g7->a[1]);

    struct Group4* g8 = (struct Group4*)GetField0x4Field0x0Field0x0OrNull(sl);
    if (g8 == 0) {
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        RELOCATE(g8->a[i]);
    }

    func_020546c8(sl);
    return 1;
}
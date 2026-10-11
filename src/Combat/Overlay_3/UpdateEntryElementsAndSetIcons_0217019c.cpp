#include <globaldefs.h>

struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(struct Cont0205d1e0* obj);
struct Cont0205d228;
void CallFunc0204c8f0OverList0x9c(struct Cont0205d228* obj);
extern "C" void func_0205da88(void* obj, int a, int b, int c);
struct Cont0205d274;
void CallFunc0204b04cOverList0x98(struct Cont0205d274* obj);
extern "C" void func_ov003_0217033c(char* base);
#if defined(jpn)
#define func_ov003_021704e8 func_ov003_0216fd3c
extern "C" void func_ov003_0216fb7c(void* self);
#define MaybeSetElem_021702e4 func_ov003_0216fb7c
#else
struct S021702e4;
void MaybeSetElem_021702e4(struct S021702e4* self);
#endif
extern "C" void func_ov003_021704e8(char* obj);
struct S021702e4;
extern "C" void* func_02012fe4(void);
struct Obj0216dee4;
void SetElemFields0216dee4(struct Obj0216dee4* obj, int idx, int v14, int v18, int v22, int v25, int v26);

struct Ctx0217019c {
    char pad0[1];
    signed char field1;
    char pad2[0x3a];
    void* field3c;
    char pad3[0x3b0 - 0x40];
    int arr3b0[8];
};

// USA: func_ov003_0217019c  (semantic: UpdateEntryElementsAndSetIcons_0217019c)
extern "C" ARM void func_ov003_0217019c(struct Ctx0217019c* self) {
    if (self->field3c == 0) return;
    signed char f1 = self->field1;
    if (f1 == 0 || f1 == 1 || f1 == 7) return;

    ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)self->field3c);
    CallFunc0204c8f0OverList0x9c((struct Cont0205d228*)self->field3c);
    func_0205da88(self->field3c, 2, 1, 1);
    CallFunc0204b04cOverList0x98((struct Cont0205d274*)self->field3c);

    func_ov003_0217033c((char*)self);
    func_ov003_021704e8((char*)self);
    MaybeSetElem_021702e4((struct S021702e4*)self);

#if !defined(jpn)
    signed char f1b = self->field1;
    switch (f1b) {
        case 0:
        case 1:
            return;
    }
    func_02012fe4();

    int v14 = 0x51;
    int v18 = 0x2e;
    int v22 = 0x40;
    for (int i = 0; i < 8; i++) {
        int val = self->arr3b0[i];
        if (val < 0) return;
        SetElemFields0216dee4((struct Obj0216dee4*)((char*)self + 0x68), val + 9, v14, v18, v22, 2, 3);
        v22 += 1;
        v18 += 0x10;
    }
#endif
}

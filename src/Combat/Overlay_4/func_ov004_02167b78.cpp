#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_02167b78 func_ov004_02168074
#endif
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void func_ov004_0216794c(short* p1, short* p2, short* p3, short* p4, int* p5);
int GetGlobalField0x1c020421a0(void);
extern "C" void func_02046380(void* g);
struct Obj02046574;
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
extern "C" int func_ov004_02167908(void* a1, int b);
struct StoreStruct;
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);
void* Clear12Bytes020e46c4(void* p);
void DispatchIfCountPositive020dcf7c(int count, void* buf);

struct A2Struct02167b78 {
    short f0;
    short f2;
};
extern struct A2Struct02167b78 data_ov004_02170010[];

struct Sub24_02167b78 {
    void* a;
    void* b;
};
struct Handle24_02167b78 {
    void* bufA;
    struct Sub24_02167b78* sub;
    void* bufB;
};
extern struct Handle24_02167b78 data_ov004_02171024;

struct Local78 {
    short shortD;
    short shortC;
    short shortB;
    short shortA;
    int intE;
};

// USA: func_ov004_02167b78  (semantic: ComputeAndStoreArrayEntries_02167b78)
extern "C" ARM int func_ov004_02167b78(void* a1, struct A2Struct02167b78* a2) {
    struct Local78 local;
    func_ov004_0216794c(&local.shortA, &local.shortB, &local.shortC, &local.shortD, &local.intE);

    int sum = (short)(local.shortA + local.shortB);
    if (sum > 0x50) sum = 0x50;

    void* g = (void*)GetGlobalField0x1c020421a0();
    func_02046380(g);

    GameObject* c = GameState::GetInstance()->GetUnknownGameObject();
    if (c != 0) {
        SetIndexedName02046574((struct Obj02046574*)g, 0, *(char**)((char*)c + 0x134));
    }

    int haveX = func_ov004_02167908(a1, 5);

    StoreInArray0x8b0((struct StoreStruct*)g, 0, local.shortA);
    StoreInArray0x8b0((struct StoreStruct*)g, 1, local.shortB);
    StoreInArray0x8b0((struct StoreStruct*)g, 2, local.shortC);
    StoreInArray0x8b0((struct StoreStruct*)g, 3, sum);

    if (haveX != 0) {
        if (a2 == 0) {
            int idx = local.intE;
            if (idx >= 0) {
                a2 = &data_ov004_02170010[idx];
            }
        }
        if (a2 != 0) {
            if (data_ov004_02171024.sub != 0 && data_ov004_02171024.bufA != 0 && data_ov004_02171024.bufB != 0) {
                Clear12Bytes020e46c4(data_ov004_02171024.sub);
                data_ov004_02171024.sub->a = data_ov004_02171024.bufA;
                data_ov004_02171024.sub->b = data_ov004_02171024.bufB;
                memset(data_ov004_02171024.bufA, 0, 0x80);
                memset(data_ov004_02171024.bufB, 0, 0x80);
            }
            DispatchIfCountPositive020dcf7c(a2->f2, data_ov004_02171024.sub);
            *(void**)((char*)g + 0x18) = data_ov004_02171024.sub;
            StoreInArray0x8b0((struct StoreStruct*)g, 2, a2->f0);
        }
    }
    return 0;
}

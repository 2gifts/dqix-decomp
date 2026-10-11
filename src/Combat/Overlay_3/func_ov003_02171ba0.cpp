#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue71C_618 = 0x618 };
enum { kRegionValue72C_628 = 0x628 };
enum { kRegionValue724_620 = 0x620 };
#else
enum { kRegionValue71C_618 = 0x71c };
enum { kRegionValue72C_628 = 0x72c };
enum { kRegionValue724_620 = 0x724 };
#endif


struct SearchStruct;
extern "C" void* func_0202ae18(void);
void* GetData02100044(void);
int TestFlagBitAt0xe(struct SearchStruct*, int);
void RemoveSearchEntry0202c21c(struct SearchStruct*, int);
extern "C" void func_0202b0f4(void*);

struct Element0202bad4;
struct ElementArray0202bad4;
Element0202bad4* GetElementAt0x10Stride0xc0(struct ElementArray0202bad4*, int);

extern "C" void func_ov003_02171e1c(void*, void*);
int CheckSlotsAllFree0205e488(void*);

struct Obj02171ba0 {
    unsigned char field0;
    char pad1[0x199 - 1];
    unsigned char field199;
    char pad2[kRegionValue71C_618 - 0x19a];
    int field71c;
    int field720;
    char pad3[kRegionValue72C_628 - kRegionValue724_620];
    unsigned int field72c;
};

// USA: func_ov003_02171ba0
// JPN: func_ov003_02170e5c
extern "C" ARM void func_ov003_02171ba0(struct Obj02171ba0* obj) {
    GameState* battle = GameState::GetInstance();
    struct SearchStruct* searchPtr = (struct SearchStruct*)func_0202ae18();
    void* ptr2 = GetData02100044();

    if (TestFlagBitAt0xe(searchPtr, obj->field199)) {
        RemoveSearchEntry0202c21c(searchPtr, obj->field199);
    }
    obj->field72c += battle->GetEffectiveDeltaTime();
    if (obj->field72c > 0xbb8) {
        func_0202b0f4(searchPtr);
        obj->field0 = 0;
        return;
    }
    if (TestFlagBitAt0xe(searchPtr, 0) && obj->field71c == 0) {
        GetElementAt0x10Stride0xc0((struct ElementArray0202bad4*)searchPtr, obj->field199);
        func_0202b0f4(searchPtr);
        obj->field0 = 0;
        return;
    }
    if (obj->field720 != 0 && obj->field71c != 0) {
        struct Element0202bad4* elem = GetElementAt0x10Stride0xc0((struct ElementArray0202bad4*)searchPtr, obj->field199);
        func_ov003_02171e1c(obj, (char*)elem + 0x68);
        func_0202b0f4(searchPtr);
        obj->field0 = 0;
    }
    if (CheckSlotsAllFree0205e488(ptr2) != 0) {
        obj->field720 = 1;
    }
}

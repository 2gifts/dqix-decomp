#include <globaldefs.h>
#if defined(jpn)
enum { kRegion12c0 = 0x1150 };
enum { kRegion410 = 0x428 };
enum { kRegionf1c = 0xda0 };
#else
enum { kRegion12c0 = 0x12c0 };
enum { kRegion410 = 0x410 };
enum { kRegionf1c = 0xf1c };
#endif


int GetGlobalField0x1c020421a0();
void Forward0204359c(void* obj, int count);
extern "C" void func_020439b0(void* obj, int flag);

struct Obj0205d2bc;
void InitEntries0205d2bc(Obj0205d2bc* obj);

extern "C" void func_ov003_02170280(void* obj);
extern "C" void func_ov003_0215ca68(void* obj);
void EmptyStub_02173f04(void* obj);

struct S0216d53c {
    char pad0[4];
    short field4;
    short field6;
    char pad1[kRegion12c0 - 0x8];
    void* field12c0;
};

// JPN: func_ov003_0216d010
// USA: func_ov003_0216d53c  (semantic: DispatchStateByField4And6_0216d53c)
extern "C" ARM void func_ov003_0216d53c(S0216d53c* obj) {
    int g = GetGlobalField0x1c020421a0();
    Forward0204359c((void*)g, 2);
    func_020439b0((void*)g, 0);

    void* p = obj->field12c0;
    if (p) {
        if (obj->field6 == 0 || obj->field6 == 1 || obj->field4 == 2) {
            InitEntries0205d2bc((Obj0205d2bc*)p);
        }
    }

    if (obj->field4 == 4) {
        if (obj->field6 > 0) {
            func_ov003_02170280((char*)obj + kRegion410);
            return;
        }
    }
    if (obj->field4 == 3) {
        if (obj->field6 == 1) {
            func_ov003_0215ca68((char*)obj + 0x14);
        }
        return;
    }
    if (obj->field4 == 5 && obj->field6 == 6) {
        EmptyStub_02173f04((char*)obj + kRegionf1c);
    }
    return;
}

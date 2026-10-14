#include <globaldefs.h>

struct Obj020bd984;
void DestroyAllocator020bd984(struct Obj020bd984*);
void InitObjectFields0203a914(void*);
extern void* CreateAllocatorHolderInRegion_020bd914(void* start, unsigned int size);
struct Holder020bd110;
int InitStreamHolder020bd110(struct Holder020bd110* obj, const char* path, int arg2, int arg3);
extern "C" int func_020be6c4(void* obj);
void InitAllocatorsAndVmPoolOnce_020be9e8(void* arg0, void* arg1);
struct Obj020bdac0;
int SaveStateAndAllocateChild020bdac0(struct Obj020bdac0*);

struct Obj0203a974 {
    void* field0;
    char pad[0x9c];
    int field_a0;
};

// USA: func_0203a974  (semantic: InitAllocatorAndStream_0203a974)
extern "C" ARM void func_0203a974(struct Obj0203a974* obj, const char* path, void* start, unsigned int size, void* arg5) {
    void* p;
    if (size <= 1) {
        return;
    }
    p = obj->field0;
    if (p == 0) {
        goto skip_both;
    }
    if (p == 0) {
        goto skip_destroy;
    }
    DestroyAllocator020bd984((struct Obj020bd984*)p);
skip_destroy:
    InitObjectFields0203a914(obj);
skip_both:
    obj->field0 = CreateAllocatorHolderInRegion_020bd914(start, size);
    InitStreamHolder020bd110((struct Holder020bd110*)((char*)obj + 4), path, (int)obj->field0, 0);
    if (func_020be6c4(obj->field0) == 0) {
        return;
    }
    if (arg5 != 0) {
        InitAllocatorsAndVmPoolOnce_020be9e8(0, obj->field0);
    }
    obj->field_a0 = SaveStateAndAllocateChild020bdac0((struct Obj020bdac0*)obj->field0);
}

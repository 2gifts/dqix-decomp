#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_02012fe4(void);
extern void* GetGlobalPtr021075f4(void);

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

struct Obj_021849bc;
int GetField114Masked_021849bc(struct Obj_021849bc* obj, int mask);
void SetFlags114_021849ac(void* obj, unsigned int mask);

extern "C" void func_0203e0a0(void* g, unsigned short val);
void* ResetOverlayAndAllocator_0219bf74(void);
void ClearSlotsAndProcess_021a27e8(void);

struct Struct_0203cfb4;
void Init0203cfb4(struct Struct_0203cfb4* obj);

extern "C" void func_ov017_021a316c(int obj);
void SetBitsInField4(unsigned int* obj, unsigned int mask);

extern "C" void func_ov017_0219b938(int obj);
extern "C" void _ZN13SafeAllocator5ResetEv(void* thisPtr);

// USA: func_ov011_02184cc0  (semantic: DispatchTaggedKeyCase_02184cc0)
extern "C" ARM int func_ov011_02184cc0(struct TaggedNumber02184c30* tagged) {
    int p1 = func_ov017_0218b5b0();
    struct Obj_021849bc* obj2 = (struct Obj_021849bc*)func_ov017_021b2164();
    void* g = GetGlobalPtr021075f4();
    void* s = func_02012fe4();

    switch (GetTaggedValueAsInt_02184c30(tagged)) {
    case 0:
        if (GetField114Masked_021849bc(obj2, 1)) return 1;
        func_0203e0a0(g, *(unsigned short*)s);
        ResetOverlayAndAllocator_0219bf74();
        SetFlags114_021849ac(obj2, 1);
        break;
    case 1:
        if (GetField114Masked_021849bc(obj2, 2)) return 1;
        func_0203e0a0(g, *(unsigned short*)s);
        ((void(*)(int))ClearSlotsAndProcess_021a27e8)(p1);
        Init0203cfb4((struct Struct_0203cfb4*)g);
        func_ov017_021a316c(p1);
        SetBitsInField4((unsigned int*)p1, 8);
        SetBitsInField4((unsigned int*)p1, 0x10);
        SetFlags114_021849ac(obj2, 2);
        break;
    case 2:
        if (GetField114Masked_021849bc(obj2, 4)) return 1;
        func_ov017_0219b938(p1);
        _ZN13SafeAllocator5ResetEv((void*)(p1 + 0x9c));
        SetFlags114_021849ac(obj2, 4);
        break;
    }
    return 1;
}

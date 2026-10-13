#include <globaldefs.h>

#if defined(jpn)
#define REGION_VALUE(j, u) (j)
#else
#define REGION_VALUE(j, u) (u)
#endif

struct Container0205a3d0;
struct Elem0205a3d0;
void SetEntryFlag2ByKey0205a370(struct Container0205a3d0* c, int key);
struct Elem0205a3d0* FindEntryByHalfword0205a3d0(struct Container0205a3d0* c, int key);
void SetEntryPosition(struct Container0205a3d0* c, int key, short a, short b);
void SetEntryByte14ByKey0205a42c(struct Container0205a3d0* c, int key, int val);

struct Container0205a330;
void IterateEntries0205a330(struct Container0205a330* c, int arg);

extern "C" void func_0205ae8c(void* obj);

// USA: func_ov002_0215b0a8
// KEEP-NAME
extern "C" ARM void func_ov002_0215b0a8(char* obj) {
    if ((*(int*)(obj + REGION_VALUE(0x22ac, 0x247c)) & 8) == 0) {
        return;
    }
    struct Container0205a3d0* c = *(struct Container0205a3d0**)(*(char**)(obj + REGION_VALUE(0x19c0, 0x1a68)) + 0x3c);
    SetEntryFlag2ByKey0205a370(c, 0);
    struct Elem0205a3d0* e = FindEntryByHalfword0205a3d0(c, 0);
    if (e != 0) {
        *(unsigned char*)((char*)e + 0x15) |= 8;
    }
    IterateEntries0205a330((struct Container0205a330*)c, *(int*)(obj + REGION_VALUE(0x1a68, 0x1ba0)));
    SetEntryPosition(c, 0, 0xd7, 0x96);
    SetEntryByte14ByKey0205a42c(c, 0, 0);
    func_0205ae8c(*(void**)(obj + REGION_VALUE(0x19c0, 0x1a68)));
}

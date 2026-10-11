#if defined(jpn)
#define R(j,u) (j)
#define func_ov023_021dd4cc func_ov023_021ddcbc
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void* loader, int id);
extern "C" void func_ov023_021dd4cc(void* p, int flag);

// USA: func_ov006_02155710  (semantic: SetParamsAndDispatch_02155710)
extern "C" ARM void func_ov006_02155710(void* obj, unsigned short paramB, unsigned char paramC) {
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    int id1 = *(int*)((char*)obj + R(0x954, 0xad4));
    if (id1 >= 0) {
        _ZN16BackgroundLoader10RemoveTaskEi(loader, id1);
        *(int*)((char*)obj + R(0x954, 0xad4)) = -1;
    }
    *(int*)((char*)obj + R(0x954, 0xad4)) = -1;
    *(unsigned char*)((char*)obj + R(0x95e, 0xade)) = 0;

    unsigned short flags = *(unsigned short*)((char*)obj + R(0x962, 0xae2));
    *(unsigned short*)((char*)obj + R(0x962, 0xae2)) = flags | 2;
    func_ov023_021dd4cc((char*)obj + R(0x964, 0xae4), 2);

    *(unsigned short*)((char*)obj + R(0x10b4, 0x12b8)) = paramB;
    *(unsigned char*)((char*)obj + R(0x10b6, 0x12ba)) = paramC;

    unsigned short flags2 = *(unsigned short*)((char*)obj + R(0x962, 0xae2));
    *(unsigned short*)((char*)obj + R(0x962, 0xae2)) = flags2 & ~1;

    int id2 = *(int*)((char*)obj + R(0x958, 0xad8));
    if (id2 >= 0) {
        _ZN16BackgroundLoader10RemoveTaskEi(loader, id2);
        *(int*)((char*)obj + R(0x958, 0xad8)) = -1;
    }
    *(int*)((char*)obj + R(0x958, 0xad8)) = -1;
    *(unsigned char*)((char*)obj + R(0x95f, 0xadf)) = 0;
}

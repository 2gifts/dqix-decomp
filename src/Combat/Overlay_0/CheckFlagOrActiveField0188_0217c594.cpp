#include <globaldefs.h>

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(void* a, int b);
extern unsigned short data_02114e30;
extern int data_ov000_02184294;

#if defined(jpn)
enum { activeObjectOffset = 0 };
#else
enum { activeObjectOffset = 8 };
#endif

// USA: func_ov000_0217c594  (semantic: CheckFlagOrActiveField0188_0217c594)
extern "C" ARM int func_ov000_0217c594(void* objRaw, int limit) {
    unsigned char* obj = (unsigned char*)objRaw;
    unsigned char v = obj[0x956];
    if ((int)v < limit) {
        v = v + 1;
        obj[0x956] = v;
        return 0;
    }
    *(void**)((char*)&data_ov000_02184294 + activeObjectOffset) = objRaw;
    int a = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
    int b = _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(obj + 0x188, 0x14);
    return (a | b) != 0;
}

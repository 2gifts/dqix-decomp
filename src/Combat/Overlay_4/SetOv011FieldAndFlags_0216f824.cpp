#include <globaldefs.h>

extern "C" void func_ov011_021848a0(void* obj, int val);
int GetGlobalField0x1c020421a0(void);

struct Struct02171048_0216f824 { char pad[0x4]; char* ptr; };
extern Struct02171048_0216f824 data_ov004_02171048;

// USA: func_ov004_0216f824
ARM int SetOv011FieldAndFlags_0216f824(void* obj) {
#if defined(jpn)
    enum { regionalFieldOffset = 0x218 };
#else
    enum { regionalFieldOffset = 0x2c8 };
#endif
    func_ov011_021848a0(obj, 0x67);
    *(int*)((char*)GetGlobalField0x1c020421a0() + regionalFieldOffset) = 1;
    data_ov004_02171048.ptr[0x31] = 1;
    return 0;
}

#include <globaldefs.h>

struct Data0217c094 {
#if defined(jpn)
    void* field8;
    int field0;
    int field4;
#else
    int field0;
    int field4;
    void* field8;
#endif
};
extern Data0217c094 data_ov000_02184294;
extern unsigned short data_02114e30;
extern char data_02114e54;

extern "C" void func_ov000_02175628(void* obj);
ARM int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" void func_ov000_021756b8(void* obj);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02176e3c(void* obj, int zero, int val, int arg1, int arg2, int one);

// USA: func_ov000_0217c094
extern "C" ARM int func_ov000_0217c094(char* obj) {
    func_ov000_02175628(data_ov000_02184294.field8);
    int t = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x802);
    if (t != 0 || *((unsigned char*)&data_02114e54 + 0x55) != 0) {
        func_ov000_021756b8(data_ov000_02184294.field8);
        char* sub = obj + 8;
        signed char idx1 = *(volatile signed char*)(sub + 0x10);
        *(unsigned char*)(sub + idx1 + 8) = 0;
        *(signed char*)(sub + 0x10) = *(volatile signed char*)(sub + 0x10) - 1;
        func_ov000_0217ab8c(obj, data_ov000_02184294.field4, data_ov000_02184294.field0);
        func_ov000_02176e3c(data_ov000_02184294.field8, (int)obj, *(signed char*)(obj + *(volatile signed char*)(obj + 0x18) + 0x10), data_ov000_02184294.field4, data_ov000_02184294.field0, 0);
    }
    return -1;
}

#include <globaldefs.h>

extern "C" void func_0204c684(void* buf);
int InitBufferFromDataField4_021ddc34(void* obj, short a, short b, short c, short d);
extern "C" void func_ov023_021db634(void* a, void* buf);
extern "C" int func_ov023_021ddc98(void* buf, int val, unsigned short len, int flag);
extern int data_ov023_021ff9e0[];

#if defined(jpn)
#define TEXT_FLAGS 0x6f0
#define TEXT_POSITION 0x6d8
#else
#define TEXT_FLAGS 0x774
#define TEXT_POSITION 0x75c
#endif

// USA: func_ov023_021e0eb8
ARM void InitAndAppendTextB_021e0eb8(void* obj) {
    char buf[0xe0];
    func_0204c684(buf);

    if (InitBufferFromDataField4_021ddc34(buf, 0, 0, 0x1c, 6)) {
        if (!(*(unsigned short*)((char*)obj + TEXT_FLAGS) & 0x400)) {
            func_ov023_021db634((char*)obj + 0xcc, buf);
        }

        int result = func_ov023_021ddc98(buf, *(int*)((char*)obj + TEXT_POSITION), (unsigned short)data_ov023_021ff9e0[3], 0);
        *(int*)((char*)obj + TEXT_POSITION) = *(int*)((char*)obj + TEXT_POSITION) + result;
    }
}

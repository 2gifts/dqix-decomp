#include <globaldefs.h>

extern "C" void func_0204c684(void* buf);
int InitBufferFromDataField4_021ddc34(void* obj, short a, short b, short c, short d);
#if defined(jpn)
#define func_ov023_021dcedc func_ov023_021dd7e0
#endif
extern "C" void func_ov023_021dcedc(void* obj, void* buf);
extern "C" int func_ov023_021ddc98(void* buf, int val, unsigned short len, int flag);
extern int data_ov023_021ff9e0[];

struct Obj021dd344 {
    #if defined(jpn)
    char pad[0x717];
#else
    char pad[0x79b];
#endif
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
};

#if defined(jpn)
#define TEXT_POSITION 0x6d8
#define TEXT_SAVED_POSITION 0x6dc
#define TEXT_LAST_LENGTH 0x6e0
#else
#define TEXT_POSITION 0x75c
#define TEXT_SAVED_POSITION 0x760
#define TEXT_LAST_LENGTH 0x764
#endif

// USA: func_ov023_021dd344
extern "C" ARM void func_ov023_021dd344(struct Obj021dd344* obj) {
    if (!obj->flag1) return;

    char buf[0xe0];
    func_0204c684(buf);

    if (!InitBufferFromDataField4_021ddc34(buf, 3, 0x10, 0x1a, 6)) return;

    func_ov023_021dcedc(obj, buf);

    if (*(int*)((char*)obj + TEXT_SAVED_POSITION) != 0) {
        func_ov023_021ddc98(buf, *(int*)((char*)obj + TEXT_SAVED_POSITION), (unsigned short)data_ov023_021ff9e0[3], 1);
    } else {
        int result = func_ov023_021ddc98(buf, *(int*)((char*)obj + TEXT_POSITION), (unsigned short)data_ov023_021ff9e0[3], 1);
        *(int*)((char*)obj + TEXT_SAVED_POSITION) = *(int*)((char*)obj + TEXT_POSITION);
        *(int*)((char*)obj + TEXT_LAST_LENGTH) = result;
        *(int*)((char*)obj + TEXT_POSITION) = *(int*)((char*)obj + TEXT_POSITION) + result;
    }
}

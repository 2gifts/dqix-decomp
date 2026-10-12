#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_02154748 func_ov004_02155de0
#endif


extern "C" void func_ov004_02153978(void* self, short* a, short* b, short* c);
extern "C" void func_ov023_021f645c(void* a, int b, unsigned short c, int d);
extern "C" void func_ov023_021f64a8(void* a, int b, int c, int d);
extern "C" void func_ov004_021536e0(void* a, int b, int c);

struct Entry6_021546c0 { short id; short id2; unsigned char field4; unsigned char field5; };
extern Entry6_021546c0* data_ov004_021707c0;
void FindAndCopyFields_021546c0(Entry6_021546c0* arr, int key1, int key2, unsigned char* out1, unsigned char* out2);

// USA: func_ov004_02154748  (semantic: SyncEntryFields27And28Alt_02154748)
extern "C" ARM int func_ov004_02154748(void* a) {
    short fa, f8, f6;
    func_ov004_02153978(a, &fa, &f8, &f6);
    unsigned short tmp = (unsigned short)(f8 - 1);
    unsigned short v = (unsigned short)(tmp + 0x25);
    func_ov023_021f645c(a, 0x27, 5, 0xf);
    func_ov023_021f645c(a, 0x28, v, 0xf);

    unsigned char out1, out2;
    FindAndCopyFields_021546c0(data_ov004_021707c0, f8, -1, &out1, &out2);
    func_ov023_021f64a8(a, 0x38, out2, 0xf);
#if !defined(jpn)
    func_ov004_021536e0(a, 0x38, 0x19);
#endif
    return 0;
}

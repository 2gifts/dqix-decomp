#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"


struct Element020de650;
struct Container020dedd0;
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);

void InitFields_021db0d4(void* obj, int flag);
extern int data_ov023_021ffa0c;

struct Obj021dcb70;
unsigned char LookupByField8_021dcb70(struct Obj021dcb70* p);

extern "C" void __clear(void* buf, int len);
extern "C" void func_ov023_021dde00(void* obj);
extern "C" void func_ov023_021dbd10(void* a, void* b);


extern char data_ov023_021fdba9[];
extern char data_ov023_021fdbbe[];
extern char data_ov023_021fdbd5[];
extern char data_ov023_021fdbeb[];
extern char data_ov023_021fdbfd[];
extern char data_ov023_021fdc12[];

#if defined(jpn)
extern char data_ov023_021fce87[];
extern char data_ov023_021fce9f[];
#endif
// JPN: func_ov023_021e029c
// USA: func_ov023_021dfc90  (semantic: SomeDispatch_021dfc90)
extern "C" ARM int func_ov023_021dfc90(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x600, regionalOffset1=0xec, regionalOffset2=0xf5, regionalOffset3=0x6d8, regionalOffset4=0xf7, regionalOffset5=0x6dc, regionalOffset6=0x6e4, regionalOffset7=0xf8, regionalOffset8=0xf0, regionalOffset9=0xf4, regionalOffset10=0x6b0};
#else
 enum {regionalOffset0=0x700, regionalOffset1=0x70, regionalOffset2=0x79, regionalOffset3=0x75c, regionalOffset4=0x7b, regionalOffset5=0x760, regionalOffset6=0x768, regionalOffset7=0x7c, regionalOffset8=0x74, regionalOffset9=0x78, regionalOffset10=0x734};
#endif
    int listPtr = (int)BackgroundLoader::GetInstance();

    if (*(void**)((char*)obj + 0x48) != 0) {
        short key = *(short*)((char*)obj + regionalOffset0 + regionalOffset1);
        *(void**)((char*)obj + 0x50) = FindElementByKey020dedd0((struct Container020dedd0*)*(void**)((char*)obj + 0x48), key);
    }

    int flag = 0;
    void* node = *(void**)((char*)obj + 0x50);
    if (node != 0) {
        unsigned int field = ((unsigned int)*(int*)((char*)node + 8) << 0x14) >> 0x1d;
        if (field == 5) flag = 1;
    }

    InitFields_021db0d4(&data_ov023_021ffa0c, flag);

    unsigned char lookupResult = LookupByField8_021dcb70((struct Obj021dcb70*)*(void**)((char*)obj + 0x50));
    signed char field779 = *(signed char*)((char*)obj + regionalOffset0 + regionalOffset2);
    int r5 = lookupResult;

    if (r5 == field779) {
        *(int*)((char*)obj + regionalOffset3) = 0x3800;
        if (*(signed char*)((char*)obj + regionalOffset0 + regionalOffset4) == 1) {
            *(int*)((char*)obj + regionalOffset3) = 0x2800;
        }
        *(int*)((char*)obj + regionalOffset5) = 0;
        *(int*)((char*)obj + regionalOffset6) = 0;
        func_ov023_021dde00(obj);
        func_ov023_021dbd10((char*)obj + 0xcc, *(void**)((char*)obj + 0x50));
        *(void**)((char*)obj + 0x4c) = *(void**)((char*)obj + 0x50);
        *(void**)((char*)obj + 0x50) = 0;

        if (*(signed char*)((char*)obj + regionalOffset0 + regionalOffset7) == 1) {
            unsigned int* reg = (unsigned int*)0x4001000;
            unsigned int bits = 0x12;
            if (r5 != 0) bits |= 1;
            *reg = (*reg & ~0x1f00) | (bits << 8);
        }

        *(unsigned short*)((char*)obj + regionalOffset0 + regionalOffset8) |= 0x2000;
        return 2;
    }

    char buf1[0x40];
#if defined(jpn)

#else
    char buf2[0x40];
#endif

    __clear(buf1, 0x40);
#if defined(jpn)

#else
    __clear(buf2, 0x40);
#endif


#if defined(jpn)

#else
    int useTwoStrings = 0;
#endif

    if (r5 == 0) {
        unsigned char m = *(unsigned char*)((char*)obj + regionalOffset0 + regionalOffset9);
        switch (m) {
        case 0:
            goto dfdfc021dfc90;
        case 1:
            sprintf(buf1, data_ov023_021fdba9);
            goto tail021dfc90;
        case 2:
            sprintf(buf1, data_ov023_021fdbbe);
            goto tail021dfc90;
        default:
            goto tail021dfc90;
        }
    }

dfdfc021dfc90:
    if (!(*(unsigned short*)((char*)obj + regionalOffset0 + regionalOffset8) & 4)) goto e4c021dfc90;
    if (*(unsigned char*)((char*)obj + regionalOffset0 + regionalOffset9) == 0) goto e24021dfc90;
    if (*(int*)((char*)obj + regionalOffset10) <= 0) goto e4c021dfc90;
e24021dfc90:
#if defined(jpn)
    sprintf(buf1, data_ov023_021fce87, r5);
#else
    sprintf(buf1, data_ov023_021fdbd5, r5);
    sprintf(buf2, data_ov023_021fdbeb, r5);
    useTwoStrings = 1;
#endif

    goto tail021dfc90;
e4c021dfc90:
#if defined(jpn)
    sprintf(buf1, data_ov023_021fce9f, r5);
#else
    sprintf(buf1, data_ov023_021fdbfd, r5);
    sprintf(buf2, data_ov023_021fdc12, r5);
    useTwoStrings = 1;
#endif


tail021dfc90:
    {
        int result;
#if defined(jpn)
        result = ((BackgroundLoader*)(listPtr))->QueueLoadFile(buf1, (SafeAllocator*)0);
#else
        if (useTwoStrings) {
            result = ((BackgroundLoader*)(listPtr))->QueueLoadFileInGP2((const char*)((int)buf1), (const char*)((int)buf2), (SafeAllocator*)(0));
        } else {
            result = ((BackgroundLoader*)(listPtr))->QueueLoadFile((const char*)((int)buf1), (SafeAllocator*)(0));
        }

#endif
        *(int*)((char*)obj + regionalOffset10) = result;
    }
    return 1;
}
